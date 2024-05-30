/*
 * kk_srec.h: A simple library for reading Motorola SREC hex files.
 * Intended mainly for embedded systems, and thus somewhat optimised
 * for size at the expense of error handling and elegance.
 *
 *
 *      USAGE
 *      -----
 * 
 * To read an SREC ASCII file into binary data, the library is used
 * as follows:
 *
 *      struct srec_state srec;
 *      srec_begin_read(srec);
 *      srec_read_bytes(&srec, my_input_bytes, length_of_my_input_bytes);
 *      srec_end_read(&srec);
 *
 * The function `srec_read_bytes` may be called any number of times with
 * any amount of data at a time (i.e., it does not need to be called with
 * full lines at a time). At any time during a call to `srec_read_bytes`
 * or `srec_end_read`, the callback function `srec_data_read` may be
 * called by the library.
 *
 * The callback `srec_data_read` must be provided by the user, e.g.,
 * as follows:
 *
 *      void srec_data_read (struct srec_state *srec,
 *                           srec_record_number_t record_type,
 *                           srec_address_t address,
 *                           uint8_t *data, srec_count_t length,
 *                           srec_bool_t checksum_error) {
 *          if (!checksum_error && SREC_IS_DATA(record_type)) {
 *              (void) fseek(outfile, address, SEEK_SET);
 *              (void) fwrite(data, 1, length, outfile);
 *          } else if (SREC_IS_TERMINATION(record_type)) {
 *              (void) fclose(outfile);
 *          }
 *      }
 *
 * For a more complete implementation, see `srec2bin.c`.
 * 
 *
 * Copyright (c) 2015 Kimmo Kulovesi, http://arkku.com/
 * Provided with absolutely no warranty, use at your own risk only.
 * Use and distribute freely, mark modified copies as such.
 */

#ifndef KK_SREC_H
#define KK_SREC_H

#define KK_SREC_VERSION "2015-03-06"

#include <stdint.h>

typedef uint_least32_t srec_address_t;
typedef int srec_count_t;
typedef uint_fast8_t srec_bool_t;

enum srec_record_number {
    SREC_HEADER             = 0,    // header with ASCII data
    SREC_DATA_16BIT         = 1,    // payload with 16-bit address
    SREC_DATA_24BIT         = 2,    // payload with 24-bit address
    SREC_DATA_32BIT         = 3,    // payload with 32-bit address
    SREC_COUNT_16BIT        = 5,    // 16-bit count of payload records
    SREC_COUNT_24BIT        = 6,    // 24-bit count of payload records
    SREC_TERMINATION_32BIT  = 7,    // termination & 32-bit start address
    SREC_TERMINATION_24BIT  = 8,    // termination & 24-bit start address
    SREC_TERMINATION_16BIT  = 9     // termination & 16-bit start address
};

typedef uint_fast8_t srec_record_number_t;

// Maximum supported byte count field value - in theory it is possible to
// have values up to 255, but there is some documentation that specifies 37
// as the limit (this translates to a maximum of 2+2+74 = 78 total characters
// on a line). Specifying a lower length saves memory by making the data
// structure smaller (handy for small embedded systems), but causes an error
// if the input byte count exceeds the limit.
#ifndef SREC_LINE_MAX_BYTE_COUNT
#define SREC_LINE_MAX_BYTE_COUNT 37
#endif

typedef struct srec_state {
    uint8_t         flags;
    uint8_t         byte_count;
    uint8_t         length;
    uint8_t         data[SREC_LINE_MAX_BYTE_COUNT + 1];
} kk_srec_t;

// Begin reading
void srec_begin_read(struct srec_state *srec);

// Read a single character
void srec_read_byte(struct srec_state *srec, char chr);

// Read `count` characters from `data`
void srec_read_bytes(struct srec_state * restrict srec,
                     const char * restrict data,
                     srec_count_t count);

// End reading (may call `srec_data_read` if there is data waiting)
void srec_end_read(struct srec_state *srec);

// Callback - this must be provided by the user of the library.
// The arguments are as follows:
//      srec            - Pointer to the srec_state structure
//      record_type     - Record type number (0-9)
//      address         - Address field of the record (16-32 bits)
//      data            - Pointer to the start of the data payload
//      length          - Length of data
//      checksum_error  - 0 iff the checksum was valid, non-zero on error
//
// The `data` array may be modified at will, the last writable index being
// `data[length]` (even though the last data byte read is one index earlier).
//
// Note that while the interpreted record is passed entirely as arguments,
// the raw data is available in the `srec` structure, which includes the
// address and checksum as part of data. One may also wish to check that
// `srec->length` and `srec->byte_count` are equal - otherwise there is an
// error (such as truncated input).
extern void srec_data_read(struct srec_state *srec,
                           srec_record_number_t record_type,
                           srec_address_t address,
                           uint8_t *data, srec_count_t length,
                           srec_bool_t checksum_error);

// Is the S-Record type a header record?
#define SREC_IS_HEADER(rnum)        (!(rnum))

// Is the S-Record type a payload data record?
#define SREC_IS_DATA(rnum)          ((rnum) && ((rnum) <= 3))

// Is the S-Record type a termination + start address record?
#define SREC_IS_TERMINATION(rnum)   ((rnum) >= 7)

// Is the S-Record type a record count record?
#define SREC_IS_COUNT(rnum)         (((rnum) == 5) || ((rnum) == 6))

// Number of address bytes in a given S-Record type (2-4 for 16-32-bit)
// (the obfuscated magic formula works for all valid record numbers: 0-3, 5-9)
#define SREC_ADDRESS_BYTE_COUNT(rnum) (2 + ((((rnum) & 1) || !(rnum)) ? ((rnum) & 2) : 1))


#endif // !KK_SREC_H
