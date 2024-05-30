/*
 * kk_srec.c: A simple library for reading Motorola SREC hex files.
 *
 * Copyright (c) 2015 Kimmo Kulovesi, http://arkku.com/
 * Provided with absolutely no warranty, use at your own risk only.
 * Use and distribute freely, mark modified copies as such.
 */

#include "kk_srec.h"

#define SREC_START 'S'

#define SREC_RECORD_TYPE_MASK 0xF0
#define SREC_READ_STATE_MASK 0x0F

enum srec_read_state {
    READ_WAIT_FOR_START = 0,
    READ_RECORD_TYPE,
    READ_GOT_RECORD_TYPE,   // dummy to make for alternating "high" and "low"
    READ_COUNT_HIGH,
    READ_COUNT_LOW,
    READ_DATA_HIGH,
    READ_DATA_LOW
};

void
srec_begin_read (struct srec_state *srec) {
    srec->flags = 0;
    srec->byte_count = 0;
    srec->length = 0;
}

void
srec_read_byte (struct srec_state *srec, char byte) {
    uint_fast8_t b = (uint_fast8_t) byte;
    uint_fast8_t state = (srec->flags & SREC_READ_STATE_MASK);
    srec->flags ^= state; // turn off the old state

    if (b >= '0' && b <= '9') {
        b -= '0';
    } else if (b >= 'A' && b <= 'F') {
        b -= 'A' - 10;
    } else if (b >= 'a' && b <= 'f') {
        b -= 'a' - 10;
    } else if (b == SREC_START) {
        // sync to a new record at any state
        state = READ_RECORD_TYPE;
        goto end_read;
    } else {
        // ignore unknown characters (e.g., extra whitespace)
        goto save_read_state;
    }

    if (!(++state & 1)) {
        // high nybble, store temporarily at end of data:
        b <<= 4;
        if (state != READ_GOT_RECORD_TYPE) {
            srec->data[srec->length] = b;
        } else {
            ++state;
            srec->flags = b;
        }
    } else {
        // low nybble, combine with stored high nybble:
        b = (srec->data[srec->length] |= b);
        switch (state >> 1) {
        default:
            // remain in initial state while waiting for S
            return;
        case (READ_COUNT_LOW >> 1):
            srec->byte_count = b;
#if SREC_LINE_MAX_BYTE_COUNT < 255
            if (b > SREC_LINE_MAX_BYTE_COUNT) {
                srec_end_read(srec);
                return;
            }
#endif
            break;
        case (READ_DATA_LOW >> 1):
            if (++(srec->length) < srec->byte_count) {
                state = READ_DATA_HIGH;
                goto save_read_state;
            }
            // end of line
            state = READ_WAIT_FOR_START;
        end_read:
            srec_end_read(srec);
        }
    }
save_read_state:
    srec->flags |= state;
}

void
srec_read_bytes (struct srec_state * restrict srec,
                 const char * restrict data,
                 srec_count_t count) {
    while (count > 0) {
        srec_read_byte(srec, *data++);
        --count;
    }
}

void
srec_end_read (struct srec_state *srec) {
    uint8_t *r = srec->data;
    uint8_t *eptr;
    srec_address_t address = 0;
    uint_fast8_t type = (srec->flags & SREC_RECORD_TYPE_MASK) >> 4;
    uint8_t sum = srec->length;

    if (!srec->byte_count) {
        return;
    }

    // validate the checksum (one's complement of 8-bit sum)
    for (eptr = r + sum; r != eptr; ++r) {
        sum += *r;
    }
    ++sum; // sum is now 0 if the checksum was correct

    // combine the address bytes
    r = srec->data;
    eptr = r + SREC_ADDRESS_BYTE_COUNT(type); // byte count >= 2
    do {
        address <<= 8;
        address |= *r;
    } while (++r != eptr);

    r = srec->data + srec->length;
    srec_data_read(srec, type, address, eptr,
                   (srec_count_t) ((r > eptr) ? ((r - eptr) - 1) : 0), sum);

    srec->flags = 0;
    srec->length = 0;
    srec->byte_count = 0;
}
