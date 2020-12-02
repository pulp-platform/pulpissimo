
/* THIS FILE HAS BEEN GENERATED, DO NOT MODIFY IT.
 */

/*
 * Copyright (C) 2018 ETH Zurich, University of Bologna
 * and GreenWaves Technologies
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __INCLUDE_ARCHI_MAESTRO_MAESTRO_V1_NEW_H__
#define __INCLUDE_ARCHI_MAESTRO_MAESTRO_V1_NEW_H__

#ifndef LANGUAGE_ASSEMBLY

#include <stdint.h>
#include "archi/utils.h"

#endif




//
// REGISTERS
//

// PICL control register
#define MAESTRO_DLC_PCTRL_OFFSET                 0x0

// PICL data read register
#define MAESTRO_PRDATA_OFFSET                    0x4

// Status register
#define MAESTRO_DLC_SR_OFFSET                    0x8

// Interrupt Mask register
#define MAESTRO_DLC_IMR_OFFSET                   0xc

// Interrupt flag register
#define MAESTRO_DLC_IFR_OFFSET                   0x10

// icu_ok interrupt flag register
#define MAESTRO_DLC_IOIFR_OFFSET                 0x14

// icu_delayed interrupt flag register
#define MAESTRO_DLC_IDIFR_OFFSET                 0x18

// icu_mode_changed interrupt flags register
#define MAESTRO_DLC_IMCIFR_OFFSET                0x1c



//
// REGISTERS FIELDS
//

// Start of PICL access sequence. A rising edge of the start bit starts a PICL picl transfer. Start bit remains high until the end of the sequence, which means that no new access can be performed if an access is on going. (access: R/W)
#define MAESTRO_DLC_PCTRL_START_BIT                                  0
#define MAESTRO_DLC_PCTRL_START_WIDTH                                1
#define MAESTRO_DLC_PCTRL_START_MASK                                 0x1
#define MAESTRO_DLC_PCTRL_START_RESET                                0x0

// Address of the transfer on the PICL bus. (access: R/W)
#define MAESTRO_DLC_PCTRL_PADDR_BIT                                  1
#define MAESTRO_DLC_PCTRL_PADDR_WIDTH                                14
#define MAESTRO_DLC_PCTRL_PADDR_MASK                                 0x7ffe
#define MAESTRO_DLC_PCTRL_PADDR_RESET                                0x0

// Direction of the transfer on the PICL bus. dir = 1 means read operation, dir = 0 means write operation. (access: R/W)
#define MAESTRO_DLC_PCTRL_DIR_BIT                                    15
#define MAESTRO_DLC_PCTRL_DIR_WIDTH                                  1
#define MAESTRO_DLC_PCTRL_DIR_MASK                                   0x8000
#define MAESTRO_DLC_PCTRL_DIR_RESET                                  0x0

// Data to write on the PICL bus. (access: R/W)
#define MAESTRO_DLC_PCTRL_PWDATA_BIT                                 16
#define MAESTRO_DLC_PCTRL_PWDATA_WIDTH                               16
#define MAESTRO_DLC_PCTRL_PWDATA_MASK                                0xffff0000
#define MAESTRO_DLC_PCTRL_PWDATA_RESET                               0x0

// Data read on the PICL bus. This data is valid after a PICL read operation, when the picl_busy bit of the DLC_SR register becomes low. (access: R)
#define MAESTRO_PRDATA_PRDATA_BIT                                    0
#define MAESTRO_PRDATA_PRDATA_WIDTH                                  8
#define MAESTRO_PRDATA_PRDATA_MASK                                   0xff
#define MAESTRO_PRDATA_PRDATA_RESET                                  0x0

// This bit is set to 1 if when a SCU sequence is on going. This bit is cleared at the end of the sequence. (access: R)
#define MAESTRO_DLC_SR_PICL_BUSY_BIT                                 0
#define MAESTRO_DLC_SR_PICL_BUSY_WIDTH                               1
#define MAESTRO_DLC_SR_PICL_BUSY_MASK                                0x1
#define MAESTRO_DLC_SR_PICL_BUSY_RESET                               0x0

// This bit is set to 1 if when a SCU sequence is on going. This bit is cleared at the end of the sequence. (access: R)
#define MAESTRO_DLC_SR_SCU_BUSY_BIT                                  1
#define MAESTRO_DLC_SR_SCU_BUSY_WIDTH                                1
#define MAESTRO_DLC_SR_SCU_BUSY_MASK                                 0x2
#define MAESTRO_DLC_SR_SCU_BUSY_RESET                                0x0

// A read return the current value of the mask. Writing 1 set the mask, writing 0 clears the mask. (access: R/W)
#define MAESTRO_DLC_IMR_ICU_OK_MASK_BIT                              0
#define MAESTRO_DLC_IMR_ICU_OK_MASK_WIDTH                            1
#define MAESTRO_DLC_IMR_ICU_OK_MASK_MASK                             0x1
#define MAESTRO_DLC_IMR_ICU_OK_MASK_RESET                            0x0

// A read return the current value of the mask. Writing 1 set the mask, writing 0 clears the mask. (access: R/W)
#define MAESTRO_DLC_IMR_ICU_DELAYED_MASK_BIT                         1
#define MAESTRO_DLC_IMR_ICU_DELAYED_MASK_WIDTH                       1
#define MAESTRO_DLC_IMR_ICU_DELAYED_MASK_MASK                        0x2
#define MAESTRO_DLC_IMR_ICU_DELAYED_MASK_RESET                       0x0

// A read return the current value of the mask. Writing 1 set the mask, writing 0 clears the mask. (access: R/W)
#define MAESTRO_DLC_IMR_ICU_MODE_CHANGED_MASK_BIT                    2
#define MAESTRO_DLC_IMR_ICU_MODE_CHANGED_MASK_WIDTH                  1
#define MAESTRO_DLC_IMR_ICU_MODE_CHANGED_MASK_MASK                   0x4
#define MAESTRO_DLC_IMR_ICU_MODE_CHANGED_MASK_RESET                  0x0

// A read return the current value of the mask. Writing 1 set the mask, writing 0 clears the mask. (access: R/W)
#define MAESTRO_DLC_IMR_PICL_OK_MASK_BIT                             3
#define MAESTRO_DLC_IMR_PICL_OK_MASK_WIDTH                           1
#define MAESTRO_DLC_IMR_PICL_OK_MASK_MASK                            0x8
#define MAESTRO_DLC_IMR_PICL_OK_MASK_RESET                           0x0

// A read return the current value of the mask. Writing 1 set the mask, writing 0 clears the mask. (access: R/W)
#define MAESTRO_DLC_IMR_SCU_OK_MASK_BIT                              4
#define MAESTRO_DLC_IMR_SCU_OK_MASK_WIDTH                            1
#define MAESTRO_DLC_IMR_SCU_OK_MASK_MASK                             0x10
#define MAESTRO_DLC_IMR_SCU_OK_MASK_RESET                            0x0

// Set to 1 when at least one of the bit of the DLC_IOIFR register is set. Cleared when reading DCL_IOIFR register. (access: R)
#define MAESTRO_DLC_IFR_ICU_OK_FLAG_BIT                              0
#define MAESTRO_DLC_IFR_ICU_OK_FLAG_WIDTH                            1
#define MAESTRO_DLC_IFR_ICU_OK_FLAG_MASK                             0x1
#define MAESTRO_DLC_IFR_ICU_OK_FLAG_RESET                            0x0

// Set to 1 when at least one of the bit of the DLC_IDIFR register is set. Cleared when reading DCL_IDIFR register. (access: R)
#define MAESTRO_DLC_IFR_ICU_DELAYED_FLAG_BIT                         1
#define MAESTRO_DLC_IFR_ICU_DELAYED_FLAG_WIDTH                       1
#define MAESTRO_DLC_IFR_ICU_DELAYED_FLAG_MASK                        0x2
#define MAESTRO_DLC_IFR_ICU_DELAYED_FLAG_RESET                       0x0

// Set to 1 when at least one of the bit of the DLC_IMCIFR register is set. Cleared when reading DCL_IMCIFR register. (access: R)
#define MAESTRO_DLC_IFR_ICU_MODE_CHANGED_FLAG_BIT                    2
#define MAESTRO_DLC_IFR_ICU_MODE_CHANGED_FLAG_WIDTH                  1
#define MAESTRO_DLC_IFR_ICU_MODE_CHANGED_FLAG_MASK                   0x4
#define MAESTRO_DLC_IFR_ICU_MODE_CHANGED_FLAG_RESET                  0x0

// Set to 1 when PICL transfer is finish. Cleared writting 1 to the bit 3 of the DLC_IFR register. (access: R)
#define MAESTRO_DLC_IFR_PICL_OK_FLAG_BIT                             3
#define MAESTRO_DLC_IFR_PICL_OK_FLAG_WIDTH                           1
#define MAESTRO_DLC_IFR_PICL_OK_FLAG_MASK                            0x8
#define MAESTRO_DLC_IFR_PICL_OK_FLAG_RESET                           0x0

// Set to 1 when SCU sequence is finished. Cleared when writting 1 to the bit 4 of the DLC_IFR register. (access: R)
#define MAESTRO_DLC_IFR_SCU_OK_FLAG_BIT                              4
#define MAESTRO_DLC_IFR_SCU_OK_FLAG_WIDTH                            1
#define MAESTRO_DLC_IFR_SCU_OK_FLAG_MASK                             0x10
#define MAESTRO_DLC_IFR_SCU_OK_FLAG_RESET                            0x0

// Bit <x> set to 1 when a rising edge of the signal i_icu_ok_irq[ <x> ] occurs and MSP is requester of the change mode order of the ICU <x>. A read this register clears the register and the bit icu_ok_flag of the DLC_IFR register. (access: R)
#define MAESTRO_DLC_IOIFR_ICU_OK_FLAGS_BIT                           1
#define MAESTRO_DLC_IOIFR_ICU_OK_FLAGS_WIDTH                         31
#define MAESTRO_DLC_IOIFR_ICU_OK_FLAGS_MASK                          0xfffffffe
#define MAESTRO_DLC_IOIFR_ICU_OK_FLAGS_RESET                         0x0

// Bit <x> set to 1 when a rising edge of the signal i_icu_delayed_irq[ <x> ] occurs and MSP is requester of the change mode order of the ICU <x>. A read this register clears the register and the bit icu_delayed_flag of the DLC_IFR register. (access: R)
#define MAESTRO_DLC_IDIFR_ICU_DELAYED_FLAGS_BIT                      1
#define MAESTRO_DLC_IDIFR_ICU_DELAYED_FLAGS_WIDTH                    31
#define MAESTRO_DLC_IDIFR_ICU_DELAYED_FLAGS_MASK                     0xfffffffe
#define MAESTRO_DLC_IDIFR_ICU_DELAYED_FLAGS_RESET                    0x0

// Bit <x> set to 1 when a rising edge of the signal i_icu_mode_changed_irq[ <x> ] occurs. A read this register clears the register and the bit icu_mode_changed_flag of the DLC_IFR register. (access: R)
#define MAESTRO_DLC_IMCIFR_ICU_MODE_CHANGED_FLAGS_BIT                1
#define MAESTRO_DLC_IMCIFR_ICU_MODE_CHANGED_FLAGS_WIDTH              31
#define MAESTRO_DLC_IMCIFR_ICU_MODE_CHANGED_FLAGS_MASK               0xfffffffe
#define MAESTRO_DLC_IMCIFR_ICU_MODE_CHANGED_FLAGS_RESET              0x0



//
// REGISTERS STRUCTS
//

#ifndef LANGUAGE_ASSEMBLY

typedef union {
  struct {
    unsigned int start           :1 ; // Start of PICL access sequence. A rising edge of the start bit starts a PICL picl transfer. Start bit remains high until the end of the sequence, which means that no new access can be performed if an access is on going.
    unsigned int paddr           :14; // Address of the transfer on the PICL bus.
    unsigned int dir             :1 ; // Direction of the transfer on the PICL bus. dir = 1 means read operation, dir = 0 means write operation.
    unsigned int pwdata          :16; // Data to write on the PICL bus.
  };
  unsigned int raw;
} __attribute__((packed)) maestro_dlc_pctrl_t;

typedef union {
  struct {
    unsigned int prdata          :8 ; // Data read on the PICL bus. This data is valid after a PICL read operation, when the picl_busy bit of the DLC_SR register becomes low.
  };
  unsigned int raw;
} __attribute__((packed)) maestro_prdata_t;

typedef union {
  struct {
    unsigned int picl_busy       :1 ; // This bit is set to 1 if when a SCU sequence is on going. This bit is cleared at the end of the sequence.
    unsigned int scu_busy        :1 ; // This bit is set to 1 if when a SCU sequence is on going. This bit is cleared at the end of the sequence.
  };
  unsigned int raw;
} __attribute__((packed)) maestro_dlc_sr_t;

typedef union {
  struct {
    unsigned int icu_ok_mask     :1 ; // A read return the current value of the mask. Writing 1 set the mask, writing 0 clears the mask.
    unsigned int icu_delayed_mask:1 ; // A read return the current value of the mask. Writing 1 set the mask, writing 0 clears the mask.
    unsigned int icu_mode_changed_mask:1 ; // A read return the current value of the mask. Writing 1 set the mask, writing 0 clears the mask.
    unsigned int picl_ok_mask    :1 ; // A read return the current value of the mask. Writing 1 set the mask, writing 0 clears the mask.
    unsigned int scu_ok_mask     :1 ; // A read return the current value of the mask. Writing 1 set the mask, writing 0 clears the mask.
  };
  unsigned int raw;
} __attribute__((packed)) maestro_dlc_imr_t;

typedef union {
  struct {
    unsigned int icu_ok_flag     :1 ; // Set to 1 when at least one of the bit of the DLC_IOIFR register is set. Cleared when reading DCL_IOIFR register.
    unsigned int icu_delayed_flag:1 ; // Set to 1 when at least one of the bit of the DLC_IDIFR register is set. Cleared when reading DCL_IDIFR register.
    unsigned int icu_mode_changed_flag:1 ; // Set to 1 when at least one of the bit of the DLC_IMCIFR register is set. Cleared when reading DCL_IMCIFR register.
    unsigned int picl_ok_flag    :1 ; // Set to 1 when PICL transfer is finish. Cleared writting 1 to the bit 3 of the DLC_IFR register.
    unsigned int scu_ok_flag     :1 ; // Set to 1 when SCU sequence is finished. Cleared when writting 1 to the bit 4 of the DLC_IFR register.
  };
  unsigned int raw;
} __attribute__((packed)) maestro_dlc_ifr_t;

typedef union {
  struct {
    unsigned int padding0:1 ;
    unsigned int icu_ok_flags    :31; // Bit <x> set to 1 when a rising edge of the signal i_icu_ok_irq[ <x> ] occurs and MSP is requester of the change mode order of the ICU <x>. A read this register clears the register and the bit icu_ok_flag of the DLC_IFR register.
  };
  unsigned int raw;
} __attribute__((packed)) maestro_dlc_ioifr_t;

typedef union {
  struct {
    unsigned int padding0:1 ;
    unsigned int icu_delayed_flags:31; // Bit <x> set to 1 when a rising edge of the signal i_icu_delayed_irq[ <x> ] occurs and MSP is requester of the change mode order of the ICU <x>. A read this register clears the register and the bit icu_delayed_flag of the DLC_IFR register.
  };
  unsigned int raw;
} __attribute__((packed)) maestro_dlc_idifr_t;

typedef union {
  struct {
    unsigned int padding0:1 ;
    unsigned int icu_mode_changed_flags:31; // Bit <x> set to 1 when a rising edge of the signal i_icu_mode_changed_irq[ <x> ] occurs. A read this register clears the register and the bit icu_mode_changed_flag of the DLC_IFR register.
  };
  unsigned int raw;
} __attribute__((packed)) maestro_dlc_imcifr_t;

#endif



//
// REGISTERS STRUCTS
//

#ifdef __GVSOC__

class vp_maestro_dlc_pctrl : public vp::reg_32
{
public:
  inline void start_set(uint32_t value) { this->set_field(value, MAESTRO_DLC_PCTRL_START_BIT, MAESTRO_DLC_PCTRL_START_WIDTH); }
  inline uint32_t start_get() { return this->get_field(MAESTRO_DLC_PCTRL_START_BIT, MAESTRO_DLC_PCTRL_START_WIDTH); }
  inline void paddr_set(uint32_t value) { this->set_field(value, MAESTRO_DLC_PCTRL_PADDR_BIT, MAESTRO_DLC_PCTRL_PADDR_WIDTH); }
  inline uint32_t paddr_get() { return this->get_field(MAESTRO_DLC_PCTRL_PADDR_BIT, MAESTRO_DLC_PCTRL_PADDR_WIDTH); }
  inline void dir_set(uint32_t value) { this->set_field(value, MAESTRO_DLC_PCTRL_DIR_BIT, MAESTRO_DLC_PCTRL_DIR_WIDTH); }
  inline uint32_t dir_get() { return this->get_field(MAESTRO_DLC_PCTRL_DIR_BIT, MAESTRO_DLC_PCTRL_DIR_WIDTH); }
  inline void pwdata_set(uint32_t value) { this->set_field(value, MAESTRO_DLC_PCTRL_PWDATA_BIT, MAESTRO_DLC_PCTRL_PWDATA_WIDTH); }
  inline uint32_t pwdata_get() { return this->get_field(MAESTRO_DLC_PCTRL_PWDATA_BIT, MAESTRO_DLC_PCTRL_PWDATA_WIDTH); }
};

class vp_maestro_prdata : public vp::reg_32
{
public:
  inline void prdata_set(uint32_t value) { this->set_field(value, MAESTRO_PRDATA_PRDATA_BIT, MAESTRO_PRDATA_PRDATA_WIDTH); }
  inline uint32_t prdata_get() { return this->get_field(MAESTRO_PRDATA_PRDATA_BIT, MAESTRO_PRDATA_PRDATA_WIDTH); }
};

class vp_maestro_dlc_sr : public vp::reg_32
{
public:
  inline void picl_busy_set(uint32_t value) { this->set_field(value, MAESTRO_DLC_SR_PICL_BUSY_BIT, MAESTRO_DLC_SR_PICL_BUSY_WIDTH); }
  inline uint32_t picl_busy_get() { return this->get_field(MAESTRO_DLC_SR_PICL_BUSY_BIT, MAESTRO_DLC_SR_PICL_BUSY_WIDTH); }
  inline void scu_busy_set(uint32_t value) { this->set_field(value, MAESTRO_DLC_SR_SCU_BUSY_BIT, MAESTRO_DLC_SR_SCU_BUSY_WIDTH); }
  inline uint32_t scu_busy_get() { return this->get_field(MAESTRO_DLC_SR_SCU_BUSY_BIT, MAESTRO_DLC_SR_SCU_BUSY_WIDTH); }
};

class vp_maestro_dlc_imr : public vp::reg_32
{
public:
  inline void icu_ok_mask_set(uint32_t value) { this->set_field(value, MAESTRO_DLC_IMR_ICU_OK_MASK_BIT, MAESTRO_DLC_IMR_ICU_OK_MASK_WIDTH); }
  inline uint32_t icu_ok_mask_get() { return this->get_field(MAESTRO_DLC_IMR_ICU_OK_MASK_BIT, MAESTRO_DLC_IMR_ICU_OK_MASK_WIDTH); }
  inline void icu_delayed_mask_set(uint32_t value) { this->set_field(value, MAESTRO_DLC_IMR_ICU_DELAYED_MASK_BIT, MAESTRO_DLC_IMR_ICU_DELAYED_MASK_WIDTH); }
  inline uint32_t icu_delayed_mask_get() { return this->get_field(MAESTRO_DLC_IMR_ICU_DELAYED_MASK_BIT, MAESTRO_DLC_IMR_ICU_DELAYED_MASK_WIDTH); }
  inline void icu_mode_changed_mask_set(uint32_t value) { this->set_field(value, MAESTRO_DLC_IMR_ICU_MODE_CHANGED_MASK_BIT, MAESTRO_DLC_IMR_ICU_MODE_CHANGED_MASK_WIDTH); }
  inline uint32_t icu_mode_changed_mask_get() { return this->get_field(MAESTRO_DLC_IMR_ICU_MODE_CHANGED_MASK_BIT, MAESTRO_DLC_IMR_ICU_MODE_CHANGED_MASK_WIDTH); }
  inline void picl_ok_mask_set(uint32_t value) { this->set_field(value, MAESTRO_DLC_IMR_PICL_OK_MASK_BIT, MAESTRO_DLC_IMR_PICL_OK_MASK_WIDTH); }
  inline uint32_t picl_ok_mask_get() { return this->get_field(MAESTRO_DLC_IMR_PICL_OK_MASK_BIT, MAESTRO_DLC_IMR_PICL_OK_MASK_WIDTH); }
  inline void scu_ok_mask_set(uint32_t value) { this->set_field(value, MAESTRO_DLC_IMR_SCU_OK_MASK_BIT, MAESTRO_DLC_IMR_SCU_OK_MASK_WIDTH); }
  inline uint32_t scu_ok_mask_get() { return this->get_field(MAESTRO_DLC_IMR_SCU_OK_MASK_BIT, MAESTRO_DLC_IMR_SCU_OK_MASK_WIDTH); }
};

class vp_maestro_dlc_ifr : public vp::reg_32
{
public:
  inline void icu_ok_flag_set(uint32_t value) { this->set_field(value, MAESTRO_DLC_IFR_ICU_OK_FLAG_BIT, MAESTRO_DLC_IFR_ICU_OK_FLAG_WIDTH); }
  inline uint32_t icu_ok_flag_get() { return this->get_field(MAESTRO_DLC_IFR_ICU_OK_FLAG_BIT, MAESTRO_DLC_IFR_ICU_OK_FLAG_WIDTH); }
  inline void icu_delayed_flag_set(uint32_t value) { this->set_field(value, MAESTRO_DLC_IFR_ICU_DELAYED_FLAG_BIT, MAESTRO_DLC_IFR_ICU_DELAYED_FLAG_WIDTH); }
  inline uint32_t icu_delayed_flag_get() { return this->get_field(MAESTRO_DLC_IFR_ICU_DELAYED_FLAG_BIT, MAESTRO_DLC_IFR_ICU_DELAYED_FLAG_WIDTH); }
  inline void icu_mode_changed_flag_set(uint32_t value) { this->set_field(value, MAESTRO_DLC_IFR_ICU_MODE_CHANGED_FLAG_BIT, MAESTRO_DLC_IFR_ICU_MODE_CHANGED_FLAG_WIDTH); }
  inline uint32_t icu_mode_changed_flag_get() { return this->get_field(MAESTRO_DLC_IFR_ICU_MODE_CHANGED_FLAG_BIT, MAESTRO_DLC_IFR_ICU_MODE_CHANGED_FLAG_WIDTH); }
  inline void picl_ok_flag_set(uint32_t value) { this->set_field(value, MAESTRO_DLC_IFR_PICL_OK_FLAG_BIT, MAESTRO_DLC_IFR_PICL_OK_FLAG_WIDTH); }
  inline uint32_t picl_ok_flag_get() { return this->get_field(MAESTRO_DLC_IFR_PICL_OK_FLAG_BIT, MAESTRO_DLC_IFR_PICL_OK_FLAG_WIDTH); }
  inline void scu_ok_flag_set(uint32_t value) { this->set_field(value, MAESTRO_DLC_IFR_SCU_OK_FLAG_BIT, MAESTRO_DLC_IFR_SCU_OK_FLAG_WIDTH); }
  inline uint32_t scu_ok_flag_get() { return this->get_field(MAESTRO_DLC_IFR_SCU_OK_FLAG_BIT, MAESTRO_DLC_IFR_SCU_OK_FLAG_WIDTH); }
};

class vp_maestro_dlc_ioifr : public vp::reg_32
{
public:
  inline void icu_ok_flags_set(uint32_t value) { this->set_field(value, MAESTRO_DLC_IOIFR_ICU_OK_FLAGS_BIT, MAESTRO_DLC_IOIFR_ICU_OK_FLAGS_WIDTH); }
  inline uint32_t icu_ok_flags_get() { return this->get_field(MAESTRO_DLC_IOIFR_ICU_OK_FLAGS_BIT, MAESTRO_DLC_IOIFR_ICU_OK_FLAGS_WIDTH); }
};

class vp_maestro_dlc_idifr : public vp::reg_32
{
public:
  inline void icu_delayed_flags_set(uint32_t value) { this->set_field(value, MAESTRO_DLC_IDIFR_ICU_DELAYED_FLAGS_BIT, MAESTRO_DLC_IDIFR_ICU_DELAYED_FLAGS_WIDTH); }
  inline uint32_t icu_delayed_flags_get() { return this->get_field(MAESTRO_DLC_IDIFR_ICU_DELAYED_FLAGS_BIT, MAESTRO_DLC_IDIFR_ICU_DELAYED_FLAGS_WIDTH); }
};

class vp_maestro_dlc_imcifr : public vp::reg_32
{
public:
  inline void icu_mode_changed_flags_set(uint32_t value) { this->set_field(value, MAESTRO_DLC_IMCIFR_ICU_MODE_CHANGED_FLAGS_BIT, MAESTRO_DLC_IMCIFR_ICU_MODE_CHANGED_FLAGS_WIDTH); }
  inline uint32_t icu_mode_changed_flags_get() { return this->get_field(MAESTRO_DLC_IMCIFR_ICU_MODE_CHANGED_FLAGS_BIT, MAESTRO_DLC_IMCIFR_ICU_MODE_CHANGED_FLAGS_WIDTH); }
};

#endif



//
// REGISTERS GLOBAL STRUCT
//

#ifndef LANGUAGE_ASSEMBLY

typedef struct {
  unsigned int dlc_pctrl       ; // PICL control register
  unsigned int prdata          ; // PICL data read register
  unsigned int dlc_sr          ; // Status register
  unsigned int dlc_imr         ; // Interrupt Mask register
  unsigned int dlc_ifr         ; // Interrupt flag register
  unsigned int dlc_ioifr       ; // icu_ok interrupt flag register
  unsigned int dlc_idifr       ; // icu_delayed interrupt flag register
  unsigned int dlc_imcifr      ; // icu_mode_changed interrupt flags register
} __attribute__((packed)) maestro_maestro_t;

#endif



//
// REGISTERS ACCESS FUNCTIONS
//

#ifndef LANGUAGE_ASSEMBLY

static inline uint32_t maestro_dlc_pctrl_get(uint32_t base) { return ARCHI_READ(base, MAESTRO_DLC_PCTRL_OFFSET); }
static inline void maestro_dlc_pctrl_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, MAESTRO_DLC_PCTRL_OFFSET, value); }

static inline uint32_t maestro_prdata_get(uint32_t base) { return ARCHI_READ(base, MAESTRO_PRDATA_OFFSET); }
static inline void maestro_prdata_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, MAESTRO_PRDATA_OFFSET, value); }

static inline uint32_t maestro_dlc_sr_get(uint32_t base) { return ARCHI_READ(base, MAESTRO_DLC_SR_OFFSET); }
static inline void maestro_dlc_sr_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, MAESTRO_DLC_SR_OFFSET, value); }

static inline uint32_t maestro_dlc_imr_get(uint32_t base) { return ARCHI_READ(base, MAESTRO_DLC_IMR_OFFSET); }
static inline void maestro_dlc_imr_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, MAESTRO_DLC_IMR_OFFSET, value); }

static inline uint32_t maestro_dlc_ifr_get(uint32_t base) { return ARCHI_READ(base, MAESTRO_DLC_IFR_OFFSET); }
static inline void maestro_dlc_ifr_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, MAESTRO_DLC_IFR_OFFSET, value); }

static inline uint32_t maestro_dlc_ioifr_get(uint32_t base) { return ARCHI_READ(base, MAESTRO_DLC_IOIFR_OFFSET); }
static inline void maestro_dlc_ioifr_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, MAESTRO_DLC_IOIFR_OFFSET, value); }

static inline uint32_t maestro_dlc_idifr_get(uint32_t base) { return ARCHI_READ(base, MAESTRO_DLC_IDIFR_OFFSET); }
static inline void maestro_dlc_idifr_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, MAESTRO_DLC_IDIFR_OFFSET, value); }

static inline uint32_t maestro_dlc_imcifr_get(uint32_t base) { return ARCHI_READ(base, MAESTRO_DLC_IMCIFR_OFFSET); }
static inline void maestro_dlc_imcifr_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, MAESTRO_DLC_IMCIFR_OFFSET, value); }

#endif



//
// REGISTERS FIELDS MACROS
//

#ifndef LANGUAGE_ASSEMBLY

#define MAESTRO_DLC_PCTRL_START_GET(value)                 (ARCHI_BEXTRACTU((value),1,0))
#define MAESTRO_DLC_PCTRL_START_GETS(value)                (ARCHI_BEXTRACT((value),1,0))
#define MAESTRO_DLC_PCTRL_START_SET(value,field)           (ARCHI_BINSERT((value),(field),1,0))
#define MAESTRO_DLC_PCTRL_START(val)                       ((val) << 0)

#define MAESTRO_DLC_PCTRL_PADDR_GET(value)                 (ARCHI_BEXTRACTU((value),14,1))
#define MAESTRO_DLC_PCTRL_PADDR_GETS(value)                (ARCHI_BEXTRACT((value),14,1))
#define MAESTRO_DLC_PCTRL_PADDR_SET(value,field)           (ARCHI_BINSERT((value),(field),14,1))
#define MAESTRO_DLC_PCTRL_PADDR(val)                       ((val) << 1)

#define MAESTRO_DLC_PCTRL_DIR_GET(value)                   (ARCHI_BEXTRACTU((value),1,15))
#define MAESTRO_DLC_PCTRL_DIR_GETS(value)                  (ARCHI_BEXTRACT((value),1,15))
#define MAESTRO_DLC_PCTRL_DIR_SET(value,field)             (ARCHI_BINSERT((value),(field),1,15))
#define MAESTRO_DLC_PCTRL_DIR(val)                         ((val) << 15)

#define MAESTRO_DLC_PCTRL_PWDATA_GET(value)                (ARCHI_BEXTRACTU((value),16,16))
#define MAESTRO_DLC_PCTRL_PWDATA_GETS(value)               (ARCHI_BEXTRACT((value),16,16))
#define MAESTRO_DLC_PCTRL_PWDATA_SET(value,field)          (ARCHI_BINSERT((value),(field),16,16))
#define MAESTRO_DLC_PCTRL_PWDATA(val)                      ((val) << 16)

#define MAESTRO_PRDATA_PRDATA_GET(value)                   (ARCHI_BEXTRACTU((value),8,0))
#define MAESTRO_PRDATA_PRDATA_GETS(value)                  (ARCHI_BEXTRACT((value),8,0))
#define MAESTRO_PRDATA_PRDATA_SET(value,field)             (ARCHI_BINSERT((value),(field),8,0))
#define MAESTRO_PRDATA_PRDATA(val)                         ((val) << 0)

#define MAESTRO_DLC_SR_PICL_BUSY_GET(value)                (ARCHI_BEXTRACTU((value),1,0))
#define MAESTRO_DLC_SR_PICL_BUSY_GETS(value)               (ARCHI_BEXTRACT((value),1,0))
#define MAESTRO_DLC_SR_PICL_BUSY_SET(value,field)          (ARCHI_BINSERT((value),(field),1,0))
#define MAESTRO_DLC_SR_PICL_BUSY(val)                      ((val) << 0)

#define MAESTRO_DLC_SR_SCU_BUSY_GET(value)                 (ARCHI_BEXTRACTU((value),1,1))
#define MAESTRO_DLC_SR_SCU_BUSY_GETS(value)                (ARCHI_BEXTRACT((value),1,1))
#define MAESTRO_DLC_SR_SCU_BUSY_SET(value,field)           (ARCHI_BINSERT((value),(field),1,1))
#define MAESTRO_DLC_SR_SCU_BUSY(val)                       ((val) << 1)

#define MAESTRO_DLC_IMR_ICU_OK_MASK_GET(value)             (ARCHI_BEXTRACTU((value),1,0))
#define MAESTRO_DLC_IMR_ICU_OK_MASK_GETS(value)            (ARCHI_BEXTRACT((value),1,0))
#define MAESTRO_DLC_IMR_ICU_OK_MASK_SET(value,field)       (ARCHI_BINSERT((value),(field),1,0))
#define MAESTRO_DLC_IMR_ICU_OK_MASK(val)                   ((val) << 0)

#define MAESTRO_DLC_IMR_ICU_DELAYED_MASK_GET(value)        (ARCHI_BEXTRACTU((value),1,1))
#define MAESTRO_DLC_IMR_ICU_DELAYED_MASK_GETS(value)       (ARCHI_BEXTRACT((value),1,1))
#define MAESTRO_DLC_IMR_ICU_DELAYED_MASK_SET(value,field)  (ARCHI_BINSERT((value),(field),1,1))
#define MAESTRO_DLC_IMR_ICU_DELAYED_MASK(val)              ((val) << 1)

#define MAESTRO_DLC_IMR_ICU_MODE_CHANGED_MASK_GET(value)   (ARCHI_BEXTRACTU((value),1,2))
#define MAESTRO_DLC_IMR_ICU_MODE_CHANGED_MASK_GETS(value)  (ARCHI_BEXTRACT((value),1,2))
#define MAESTRO_DLC_IMR_ICU_MODE_CHANGED_MASK_SET(value,field) (ARCHI_BINSERT((value),(field),1,2))
#define MAESTRO_DLC_IMR_ICU_MODE_CHANGED_MASK(val)         ((val) << 2)

#define MAESTRO_DLC_IMR_PICL_OK_MASK_GET(value)            (ARCHI_BEXTRACTU((value),1,3))
#define MAESTRO_DLC_IMR_PICL_OK_MASK_GETS(value)           (ARCHI_BEXTRACT((value),1,3))
#define MAESTRO_DLC_IMR_PICL_OK_MASK_SET(value,field)      (ARCHI_BINSERT((value),(field),1,3))
#define MAESTRO_DLC_IMR_PICL_OK_MASK(val)                  ((val) << 3)

#define MAESTRO_DLC_IMR_SCU_OK_MASK_GET(value)             (ARCHI_BEXTRACTU((value),1,4))
#define MAESTRO_DLC_IMR_SCU_OK_MASK_GETS(value)            (ARCHI_BEXTRACT((value),1,4))
#define MAESTRO_DLC_IMR_SCU_OK_MASK_SET(value,field)       (ARCHI_BINSERT((value),(field),1,4))
#define MAESTRO_DLC_IMR_SCU_OK_MASK(val)                   ((val) << 4)

#define MAESTRO_DLC_IFR_ICU_OK_FLAG_GET(value)             (ARCHI_BEXTRACTU((value),1,0))
#define MAESTRO_DLC_IFR_ICU_OK_FLAG_GETS(value)            (ARCHI_BEXTRACT((value),1,0))
#define MAESTRO_DLC_IFR_ICU_OK_FLAG_SET(value,field)       (ARCHI_BINSERT((value),(field),1,0))
#define MAESTRO_DLC_IFR_ICU_OK_FLAG(val)                   ((val) << 0)

#define MAESTRO_DLC_IFR_ICU_DELAYED_FLAG_GET(value)        (ARCHI_BEXTRACTU((value),1,1))
#define MAESTRO_DLC_IFR_ICU_DELAYED_FLAG_GETS(value)       (ARCHI_BEXTRACT((value),1,1))
#define MAESTRO_DLC_IFR_ICU_DELAYED_FLAG_SET(value,field)  (ARCHI_BINSERT((value),(field),1,1))
#define MAESTRO_DLC_IFR_ICU_DELAYED_FLAG(val)              ((val) << 1)

#define MAESTRO_DLC_IFR_ICU_MODE_CHANGED_FLAG_GET(value)   (ARCHI_BEXTRACTU((value),1,2))
#define MAESTRO_DLC_IFR_ICU_MODE_CHANGED_FLAG_GETS(value)  (ARCHI_BEXTRACT((value),1,2))
#define MAESTRO_DLC_IFR_ICU_MODE_CHANGED_FLAG_SET(value,field) (ARCHI_BINSERT((value),(field),1,2))
#define MAESTRO_DLC_IFR_ICU_MODE_CHANGED_FLAG(val)         ((val) << 2)

#define MAESTRO_DLC_IFR_PICL_OK_FLAG_GET(value)            (ARCHI_BEXTRACTU((value),1,3))
#define MAESTRO_DLC_IFR_PICL_OK_FLAG_GETS(value)           (ARCHI_BEXTRACT((value),1,3))
#define MAESTRO_DLC_IFR_PICL_OK_FLAG_SET(value,field)      (ARCHI_BINSERT((value),(field),1,3))
#define MAESTRO_DLC_IFR_PICL_OK_FLAG(val)                  ((val) << 3)

#define MAESTRO_DLC_IFR_SCU_OK_FLAG_GET(value)             (ARCHI_BEXTRACTU((value),1,4))
#define MAESTRO_DLC_IFR_SCU_OK_FLAG_GETS(value)            (ARCHI_BEXTRACT((value),1,4))
#define MAESTRO_DLC_IFR_SCU_OK_FLAG_SET(value,field)       (ARCHI_BINSERT((value),(field),1,4))
#define MAESTRO_DLC_IFR_SCU_OK_FLAG(val)                   ((val) << 4)

#define MAESTRO_DLC_IOIFR_ICU_OK_FLAGS_GET(value)          (ARCHI_BEXTRACTU((value),31,1))
#define MAESTRO_DLC_IOIFR_ICU_OK_FLAGS_GETS(value)         (ARCHI_BEXTRACT((value),31,1))
#define MAESTRO_DLC_IOIFR_ICU_OK_FLAGS_SET(value,field)    (ARCHI_BINSERT((value),(field),31,1))
#define MAESTRO_DLC_IOIFR_ICU_OK_FLAGS(val)                ((val) << 1)

#define MAESTRO_DLC_IDIFR_ICU_DELAYED_FLAGS_GET(value)     (ARCHI_BEXTRACTU((value),31,1))
#define MAESTRO_DLC_IDIFR_ICU_DELAYED_FLAGS_GETS(value)    (ARCHI_BEXTRACT((value),31,1))
#define MAESTRO_DLC_IDIFR_ICU_DELAYED_FLAGS_SET(value,field) (ARCHI_BINSERT((value),(field),31,1))
#define MAESTRO_DLC_IDIFR_ICU_DELAYED_FLAGS(val)           ((val) << 1)

#define MAESTRO_DLC_IMCIFR_ICU_MODE_CHANGED_FLAGS_GET(value) (ARCHI_BEXTRACTU((value),31,1))
#define MAESTRO_DLC_IMCIFR_ICU_MODE_CHANGED_FLAGS_GETS(value) (ARCHI_BEXTRACT((value),31,1))
#define MAESTRO_DLC_IMCIFR_ICU_MODE_CHANGED_FLAGS_SET(value,field) (ARCHI_BINSERT((value),(field),31,1))
#define MAESTRO_DLC_IMCIFR_ICU_MODE_CHANGED_FLAGS(val)     ((val) << 1)

#endif



//
// GROUP wiu
//

#define MAESTRO_WIU_OFFSET                       0x0



//
// REGISTERS
//

// Interrupt Sequence Processing Mask registers
#define MAESTRO_WIU_ISPMR_0_OFFSET               0x0

// Interrupt Sequence Processing Mask registers
#define MAESTRO_WIU_ISPMR_1_OFFSET               0x1

// Interrupt Flag register
#define MAESTRO_WIU_IFR_0_OFFSET                 0x2

// Interrupt Flag register
#define MAESTRO_WIU_IFR_1_OFFSET                 0x3

// Interrupt Control registers
#define MAESTRO_WIU_ICR_0_OFFSET                 0x4

// Interrupt Control registers
#define MAESTRO_WIU_ICR_1_OFFSET                 0x5

// Interrupt Control registers
#define MAESTRO_WIU_ICR_2_OFFSET                 0x6

// Interrupt Control registers
#define MAESTRO_WIU_ICR_3_OFFSET                 0x7

// Interrupt Control registers
#define MAESTRO_WIU_ICR_4_OFFSET                 0x8

// Interrupt Control registers
#define MAESTRO_WIU_ICR_5_OFFSET                 0x9

// Interrupt Control registers
#define MAESTRO_WIU_ICR_6_OFFSET                 0xa

// Interrupt Control registers
#define MAESTRO_WIU_ICR_7_OFFSET                 0xb

// Interrupt Control registers
#define MAESTRO_WIU_ICR_8_OFFSET                 0xc

// Interrupt Control registers
#define MAESTRO_WIU_ICR_9_OFFSET                 0xd

// Interrupt Control registers
#define MAESTRO_WIU_ICR_10_OFFSET                0xe

// Interrupt Control registers
#define MAESTRO_WIU_ICR_11_OFFSET                0xf

// Interrupt Control registers
#define MAESTRO_WIU_ICR_12_OFFSET                0x10

// Interrupt Control registers
#define MAESTRO_WIU_ICR_13_OFFSET                0x11

// Interrupt Control registers
#define MAESTRO_WIU_ICR_14_OFFSET                0x12

// Interrupt Control registers
#define MAESTRO_WIU_ICR_15_OFFSET                0x13



//
// REGISTERS FIELDS
//

// A read of this register return the value of the mask. Writing 1 to the bit <x>, set the mask of the interrupt i_irq[ <x> ] (access: R/W)
#define MAESTRO_WIU_ISPMR_0_MASK_MODECHG_EN_IRQ_BIT                  0
#define MAESTRO_WIU_ISPMR_0_MASK_MODECHG_EN_IRQ_WIDTH                8
#define MAESTRO_WIU_ISPMR_0_MASK_MODECHG_EN_IRQ_MASK                 0xff
#define MAESTRO_WIU_ISPMR_0_MASK_MODECHG_EN_IRQ_RESET                0x0

// A read of this register return the value of the mask. Writing 1 to the bit <x>, set the mask of the interrupt i_irq[ <x> ] (access: R/W)
#define MAESTRO_WIU_ISPMR_1_MASK_MODECHG_EN_IRQ_BIT                  0
#define MAESTRO_WIU_ISPMR_1_MASK_MODECHG_EN_IRQ_WIDTH                8
#define MAESTRO_WIU_ISPMR_1_MASK_MODECHG_EN_IRQ_MASK                 0xff
#define MAESTRO_WIU_ISPMR_1_MASK_MODECHG_EN_IRQ_RESET                0x0

// Bit <x> is set when a rising egde of the signal i_irq [ 8 * <n> + <x> ] occurs or when writing the bit <x> to 1. Bit <x> is cleared when the associated SCU sequence is finished or when writing 0 to the bit <x> of the WIU_ISPMR_m register or when writing the bit <x> to 0. (access: R/W)
#define MAESTRO_WIU_IFR_0_FLAG_IRQ_BIT                               0
#define MAESTRO_WIU_IFR_0_FLAG_IRQ_WIDTH                             8
#define MAESTRO_WIU_IFR_0_FLAG_IRQ_MASK                              0xff
#define MAESTRO_WIU_IFR_0_FLAG_IRQ_RESET                             0x0

// Bit <x> is set when a rising egde of the signal i_irq [ 8 * <n> + <x> ] occurs or when writing the bit <x> to 1. Bit <x> is cleared when the associated SCU sequence is finished or when writing 0 to the bit <x> of the WIU_ISPMR_m register or when writing the bit <x> to 0. (access: R/W)
#define MAESTRO_WIU_IFR_1_FLAG_IRQ_BIT                               0
#define MAESTRO_WIU_IFR_1_FLAG_IRQ_WIDTH                             8
#define MAESTRO_WIU_IFR_1_FLAG_IRQ_MASK                              0xff
#define MAESTRO_WIU_IFR_1_FLAG_IRQ_RESET                             0x0

// Defines the sequence which has to be executed when the interrupt i_irq[ <p> ] becomes active (access: R/W)
#define MAESTRO_WIU_ICR_0_SEQ_SEL_IRQ_0_BIT                          0
#define MAESTRO_WIU_ICR_0_SEQ_SEL_IRQ_0_WIDTH                        5
#define MAESTRO_WIU_ICR_0_SEQ_SEL_IRQ_0_MASK                         0x1f
#define MAESTRO_WIU_ICR_0_SEQ_SEL_IRQ_0_RESET                        0x0

// Defines the sequence which has to be executed when the interrupt i_irq[ <p> ] becomes active (access: R/W)
#define MAESTRO_WIU_ICR_1_SEQ_SEL_IRQ_1_BIT                          0
#define MAESTRO_WIU_ICR_1_SEQ_SEL_IRQ_1_WIDTH                        5
#define MAESTRO_WIU_ICR_1_SEQ_SEL_IRQ_1_MASK                         0x1f
#define MAESTRO_WIU_ICR_1_SEQ_SEL_IRQ_1_RESET                        0x0

// Defines the sequence which has to be executed when the interrupt i_irq[ <p> ] becomes active (access: R/W)
#define MAESTRO_WIU_ICR_2_SEQ_SEL_IRQ_2_BIT                          0
#define MAESTRO_WIU_ICR_2_SEQ_SEL_IRQ_2_WIDTH                        5
#define MAESTRO_WIU_ICR_2_SEQ_SEL_IRQ_2_MASK                         0x1f
#define MAESTRO_WIU_ICR_2_SEQ_SEL_IRQ_2_RESET                        0x0

// Defines the sequence which has to be executed when the interrupt i_irq[ <p> ] becomes active (access: R/W)
#define MAESTRO_WIU_ICR_3_SEQ_SEL_IRQ_3_BIT                          0
#define MAESTRO_WIU_ICR_3_SEQ_SEL_IRQ_3_WIDTH                        5
#define MAESTRO_WIU_ICR_3_SEQ_SEL_IRQ_3_MASK                         0x1f
#define MAESTRO_WIU_ICR_3_SEQ_SEL_IRQ_3_RESET                        0x0

// Defines the sequence which has to be executed when the interrupt i_irq[ <p> ] becomes active (access: R/W)
#define MAESTRO_WIU_ICR_4_SEQ_SEL_IRQ_4_BIT                          0
#define MAESTRO_WIU_ICR_4_SEQ_SEL_IRQ_4_WIDTH                        5
#define MAESTRO_WIU_ICR_4_SEQ_SEL_IRQ_4_MASK                         0x1f
#define MAESTRO_WIU_ICR_4_SEQ_SEL_IRQ_4_RESET                        0x0

// Defines the sequence which has to be executed when the interrupt i_irq[ <p> ] becomes active (access: R/W)
#define MAESTRO_WIU_ICR_5_SEQ_SEL_IRQ_5_BIT                          0
#define MAESTRO_WIU_ICR_5_SEQ_SEL_IRQ_5_WIDTH                        5
#define MAESTRO_WIU_ICR_5_SEQ_SEL_IRQ_5_MASK                         0x1f
#define MAESTRO_WIU_ICR_5_SEQ_SEL_IRQ_5_RESET                        0x0

// Defines the sequence which has to be executed when the interrupt i_irq[ <p> ] becomes active (access: R/W)
#define MAESTRO_WIU_ICR_6_SEQ_SEL_IRQ_6_BIT                          0
#define MAESTRO_WIU_ICR_6_SEQ_SEL_IRQ_6_WIDTH                        5
#define MAESTRO_WIU_ICR_6_SEQ_SEL_IRQ_6_MASK                         0x1f
#define MAESTRO_WIU_ICR_6_SEQ_SEL_IRQ_6_RESET                        0x0

// Defines the sequence which has to be executed when the interrupt i_irq[ <p> ] becomes active (access: R/W)
#define MAESTRO_WIU_ICR_7_SEQ_SEL_IRQ_7_BIT                          0
#define MAESTRO_WIU_ICR_7_SEQ_SEL_IRQ_7_WIDTH                        5
#define MAESTRO_WIU_ICR_7_SEQ_SEL_IRQ_7_MASK                         0x1f
#define MAESTRO_WIU_ICR_7_SEQ_SEL_IRQ_7_RESET                        0x0

// Defines the sequence which has to be executed when the interrupt i_irq[ <p> ] becomes active (access: R/W)
#define MAESTRO_WIU_ICR_8_SEQ_SEL_IRQ_8_BIT                          0
#define MAESTRO_WIU_ICR_8_SEQ_SEL_IRQ_8_WIDTH                        5
#define MAESTRO_WIU_ICR_8_SEQ_SEL_IRQ_8_MASK                         0x1f
#define MAESTRO_WIU_ICR_8_SEQ_SEL_IRQ_8_RESET                        0x0

// Defines the sequence which has to be executed when the interrupt i_irq[ <p> ] becomes active (access: R/W)
#define MAESTRO_WIU_ICR_9_SEQ_SEL_IRQ_9_BIT                          0
#define MAESTRO_WIU_ICR_9_SEQ_SEL_IRQ_9_WIDTH                        5
#define MAESTRO_WIU_ICR_9_SEQ_SEL_IRQ_9_MASK                         0x1f
#define MAESTRO_WIU_ICR_9_SEQ_SEL_IRQ_9_RESET                        0x0

// Defines the sequence which has to be executed when the interrupt i_irq[ <p> ] becomes active (access: R/W)
#define MAESTRO_WIU_ICR_10_SEQ_SEL_IRQ_10_BIT                        0
#define MAESTRO_WIU_ICR_10_SEQ_SEL_IRQ_10_WIDTH                      5
#define MAESTRO_WIU_ICR_10_SEQ_SEL_IRQ_10_MASK                       0x1f
#define MAESTRO_WIU_ICR_10_SEQ_SEL_IRQ_10_RESET                      0x0

// Defines the sequence which has to be executed when the interrupt i_irq[ <p> ] becomes active (access: R/W)
#define MAESTRO_WIU_ICR_11_SEQ_SEL_IRQ_11_BIT                        0
#define MAESTRO_WIU_ICR_11_SEQ_SEL_IRQ_11_WIDTH                      5
#define MAESTRO_WIU_ICR_11_SEQ_SEL_IRQ_11_MASK                       0x1f
#define MAESTRO_WIU_ICR_11_SEQ_SEL_IRQ_11_RESET                      0x0

// Defines the sequence which has to be executed when the interrupt i_irq[ <p> ] becomes active (access: R/W)
#define MAESTRO_WIU_ICR_12_SEQ_SEL_IRQ_12_BIT                        0
#define MAESTRO_WIU_ICR_12_SEQ_SEL_IRQ_12_WIDTH                      5
#define MAESTRO_WIU_ICR_12_SEQ_SEL_IRQ_12_MASK                       0x1f
#define MAESTRO_WIU_ICR_12_SEQ_SEL_IRQ_12_RESET                      0x0

// Defines the sequence which has to be executed when the interrupt i_irq[ <p> ] becomes active (access: R/W)
#define MAESTRO_WIU_ICR_13_SEQ_SEL_IRQ_13_BIT                        0
#define MAESTRO_WIU_ICR_13_SEQ_SEL_IRQ_13_WIDTH                      5
#define MAESTRO_WIU_ICR_13_SEQ_SEL_IRQ_13_MASK                       0x1f
#define MAESTRO_WIU_ICR_13_SEQ_SEL_IRQ_13_RESET                      0x0

// Defines the sequence which has to be executed when the interrupt i_irq[ <p> ] becomes active (access: R/W)
#define MAESTRO_WIU_ICR_14_SEQ_SEL_IRQ_14_BIT                        0
#define MAESTRO_WIU_ICR_14_SEQ_SEL_IRQ_14_WIDTH                      5
#define MAESTRO_WIU_ICR_14_SEQ_SEL_IRQ_14_MASK                       0x1f
#define MAESTRO_WIU_ICR_14_SEQ_SEL_IRQ_14_RESET                      0x0

// Defines the sequence which has to be executed when the interrupt i_irq[ <p> ] becomes active (access: R/W)
#define MAESTRO_WIU_ICR_15_SEQ_SEL_IRQ_15_BIT                        0
#define MAESTRO_WIU_ICR_15_SEQ_SEL_IRQ_15_WIDTH                      5
#define MAESTRO_WIU_ICR_15_SEQ_SEL_IRQ_15_MASK                       0x1f
#define MAESTRO_WIU_ICR_15_SEQ_SEL_IRQ_15_RESET                      0x0



//
// REGISTERS STRUCTS
//

#ifndef LANGUAGE_ASSEMBLY

typedef union {
  struct {
    unsigned int mask_modechg_en_irq:8 ; // A read of this register return the value of the mask. Writing 1 to the bit <x>, set the mask of the interrupt i_irq[ <x> ]
  };
  unsigned int raw;
} __attribute__((packed)) maestro_wiu_ispmr_0_t;

typedef union {
  struct {
    unsigned int mask_modechg_en_irq:8 ; // A read of this register return the value of the mask. Writing 1 to the bit <x>, set the mask of the interrupt i_irq[ <x> ]
  };
  unsigned int raw;
} __attribute__((packed)) maestro_wiu_ispmr_1_t;

typedef union {
  struct {
    unsigned int flag_irq        :8 ; // Bit <x> is set when a rising egde of the signal i_irq [ 8 * <n> + <x> ] occurs or when writing the bit <x> to 1. Bit <x> is cleared when the associated SCU sequence is finished or when writing 0 to the bit <x> of the WIU_ISPMR_m register or when writing the bit <x> to 0.
  };
  unsigned int raw;
} __attribute__((packed)) maestro_wiu_ifr_0_t;

typedef union {
  struct {
    unsigned int flag_irq        :8 ; // Bit <x> is set when a rising egde of the signal i_irq [ 8 * <n> + <x> ] occurs or when writing the bit <x> to 1. Bit <x> is cleared when the associated SCU sequence is finished or when writing 0 to the bit <x> of the WIU_ISPMR_m register or when writing the bit <x> to 0.
  };
  unsigned int raw;
} __attribute__((packed)) maestro_wiu_ifr_1_t;

typedef union {
  struct {
    unsigned int seq_sel_irq_0   :5 ; // Defines the sequence which has to be executed when the interrupt i_irq[ <p> ] becomes active
  };
  unsigned int raw;
} __attribute__((packed)) maestro_wiu_icr_0_t;

typedef union {
  struct {
    unsigned int seq_sel_irq_1   :5 ; // Defines the sequence which has to be executed when the interrupt i_irq[ <p> ] becomes active
  };
  unsigned int raw;
} __attribute__((packed)) maestro_wiu_icr_1_t;

typedef union {
  struct {
    unsigned int seq_sel_irq_2   :5 ; // Defines the sequence which has to be executed when the interrupt i_irq[ <p> ] becomes active
  };
  unsigned int raw;
} __attribute__((packed)) maestro_wiu_icr_2_t;

typedef union {
  struct {
    unsigned int seq_sel_irq_3   :5 ; // Defines the sequence which has to be executed when the interrupt i_irq[ <p> ] becomes active
  };
  unsigned int raw;
} __attribute__((packed)) maestro_wiu_icr_3_t;

typedef union {
  struct {
    unsigned int seq_sel_irq_4   :5 ; // Defines the sequence which has to be executed when the interrupt i_irq[ <p> ] becomes active
  };
  unsigned int raw;
} __attribute__((packed)) maestro_wiu_icr_4_t;

typedef union {
  struct {
    unsigned int seq_sel_irq_5   :5 ; // Defines the sequence which has to be executed when the interrupt i_irq[ <p> ] becomes active
  };
  unsigned int raw;
} __attribute__((packed)) maestro_wiu_icr_5_t;

typedef union {
  struct {
    unsigned int seq_sel_irq_6   :5 ; // Defines the sequence which has to be executed when the interrupt i_irq[ <p> ] becomes active
  };
  unsigned int raw;
} __attribute__((packed)) maestro_wiu_icr_6_t;

typedef union {
  struct {
    unsigned int seq_sel_irq_7   :5 ; // Defines the sequence which has to be executed when the interrupt i_irq[ <p> ] becomes active
  };
  unsigned int raw;
} __attribute__((packed)) maestro_wiu_icr_7_t;

typedef union {
  struct {
    unsigned int seq_sel_irq_8   :5 ; // Defines the sequence which has to be executed when the interrupt i_irq[ <p> ] becomes active
  };
  unsigned int raw;
} __attribute__((packed)) maestro_wiu_icr_8_t;

typedef union {
  struct {
    unsigned int seq_sel_irq_9   :5 ; // Defines the sequence which has to be executed when the interrupt i_irq[ <p> ] becomes active
  };
  unsigned int raw;
} __attribute__((packed)) maestro_wiu_icr_9_t;

typedef union {
  struct {
    unsigned int seq_sel_irq_10  :5 ; // Defines the sequence which has to be executed when the interrupt i_irq[ <p> ] becomes active
  };
  unsigned int raw;
} __attribute__((packed)) maestro_wiu_icr_10_t;

typedef union {
  struct {
    unsigned int seq_sel_irq_11  :5 ; // Defines the sequence which has to be executed when the interrupt i_irq[ <p> ] becomes active
  };
  unsigned int raw;
} __attribute__((packed)) maestro_wiu_icr_11_t;

typedef union {
  struct {
    unsigned int seq_sel_irq_12  :5 ; // Defines the sequence which has to be executed when the interrupt i_irq[ <p> ] becomes active
  };
  unsigned int raw;
} __attribute__((packed)) maestro_wiu_icr_12_t;

typedef union {
  struct {
    unsigned int seq_sel_irq_13  :5 ; // Defines the sequence which has to be executed when the interrupt i_irq[ <p> ] becomes active
  };
  unsigned int raw;
} __attribute__((packed)) maestro_wiu_icr_13_t;

typedef union {
  struct {
    unsigned int seq_sel_irq_14  :5 ; // Defines the sequence which has to be executed when the interrupt i_irq[ <p> ] becomes active
  };
  unsigned int raw;
} __attribute__((packed)) maestro_wiu_icr_14_t;

typedef union {
  struct {
    unsigned int seq_sel_irq_15  :5 ; // Defines the sequence which has to be executed when the interrupt i_irq[ <p> ] becomes active
  };
  unsigned int raw;
} __attribute__((packed)) maestro_wiu_icr_15_t;

#endif



//
// REGISTERS STRUCTS
//

#ifdef __GVSOC__

class vp_maestro_wiu_ispmr_0 : public vp::reg_8
{
public:
  inline void mask_modechg_en_irq_set(uint8_t value) { this->set_field(value, MAESTRO_WIU_ISPMR_0_MASK_MODECHG_EN_IRQ_BIT, MAESTRO_WIU_ISPMR_0_MASK_MODECHG_EN_IRQ_WIDTH); }
  inline uint8_t mask_modechg_en_irq_get() { return this->get_field(MAESTRO_WIU_ISPMR_0_MASK_MODECHG_EN_IRQ_BIT, MAESTRO_WIU_ISPMR_0_MASK_MODECHG_EN_IRQ_WIDTH); }
};

class vp_maestro_wiu_ispmr_1 : public vp::reg_8
{
public:
  inline void mask_modechg_en_irq_set(uint8_t value) { this->set_field(value, MAESTRO_WIU_ISPMR_1_MASK_MODECHG_EN_IRQ_BIT, MAESTRO_WIU_ISPMR_1_MASK_MODECHG_EN_IRQ_WIDTH); }
  inline uint8_t mask_modechg_en_irq_get() { return this->get_field(MAESTRO_WIU_ISPMR_1_MASK_MODECHG_EN_IRQ_BIT, MAESTRO_WIU_ISPMR_1_MASK_MODECHG_EN_IRQ_WIDTH); }
};

class vp_maestro_wiu_ifr_0 : public vp::reg_8
{
public:
  inline void flag_irq_set(uint8_t value) { this->set_field(value, MAESTRO_WIU_IFR_0_FLAG_IRQ_BIT, MAESTRO_WIU_IFR_0_FLAG_IRQ_WIDTH); }
  inline uint8_t flag_irq_get() { return this->get_field(MAESTRO_WIU_IFR_0_FLAG_IRQ_BIT, MAESTRO_WIU_IFR_0_FLAG_IRQ_WIDTH); }
};

class vp_maestro_wiu_ifr_1 : public vp::reg_8
{
public:
  inline void flag_irq_set(uint8_t value) { this->set_field(value, MAESTRO_WIU_IFR_1_FLAG_IRQ_BIT, MAESTRO_WIU_IFR_1_FLAG_IRQ_WIDTH); }
  inline uint8_t flag_irq_get() { return this->get_field(MAESTRO_WIU_IFR_1_FLAG_IRQ_BIT, MAESTRO_WIU_IFR_1_FLAG_IRQ_WIDTH); }
};

class vp_maestro_wiu_icr_0 : public vp::reg_8
{
public:
  inline void seq_sel_irq_0_set(uint8_t value) { this->set_field(value, MAESTRO_WIU_ICR_0_SEQ_SEL_IRQ_0_BIT, MAESTRO_WIU_ICR_0_SEQ_SEL_IRQ_0_WIDTH); }
  inline uint8_t seq_sel_irq_0_get() { return this->get_field(MAESTRO_WIU_ICR_0_SEQ_SEL_IRQ_0_BIT, MAESTRO_WIU_ICR_0_SEQ_SEL_IRQ_0_WIDTH); }
};

class vp_maestro_wiu_icr_1 : public vp::reg_8
{
public:
  inline void seq_sel_irq_1_set(uint8_t value) { this->set_field(value, MAESTRO_WIU_ICR_1_SEQ_SEL_IRQ_1_BIT, MAESTRO_WIU_ICR_1_SEQ_SEL_IRQ_1_WIDTH); }
  inline uint8_t seq_sel_irq_1_get() { return this->get_field(MAESTRO_WIU_ICR_1_SEQ_SEL_IRQ_1_BIT, MAESTRO_WIU_ICR_1_SEQ_SEL_IRQ_1_WIDTH); }
};

class vp_maestro_wiu_icr_2 : public vp::reg_8
{
public:
  inline void seq_sel_irq_2_set(uint8_t value) { this->set_field(value, MAESTRO_WIU_ICR_2_SEQ_SEL_IRQ_2_BIT, MAESTRO_WIU_ICR_2_SEQ_SEL_IRQ_2_WIDTH); }
  inline uint8_t seq_sel_irq_2_get() { return this->get_field(MAESTRO_WIU_ICR_2_SEQ_SEL_IRQ_2_BIT, MAESTRO_WIU_ICR_2_SEQ_SEL_IRQ_2_WIDTH); }
};

class vp_maestro_wiu_icr_3 : public vp::reg_8
{
public:
  inline void seq_sel_irq_3_set(uint8_t value) { this->set_field(value, MAESTRO_WIU_ICR_3_SEQ_SEL_IRQ_3_BIT, MAESTRO_WIU_ICR_3_SEQ_SEL_IRQ_3_WIDTH); }
  inline uint8_t seq_sel_irq_3_get() { return this->get_field(MAESTRO_WIU_ICR_3_SEQ_SEL_IRQ_3_BIT, MAESTRO_WIU_ICR_3_SEQ_SEL_IRQ_3_WIDTH); }
};

class vp_maestro_wiu_icr_4 : public vp::reg_8
{
public:
  inline void seq_sel_irq_4_set(uint8_t value) { this->set_field(value, MAESTRO_WIU_ICR_4_SEQ_SEL_IRQ_4_BIT, MAESTRO_WIU_ICR_4_SEQ_SEL_IRQ_4_WIDTH); }
  inline uint8_t seq_sel_irq_4_get() { return this->get_field(MAESTRO_WIU_ICR_4_SEQ_SEL_IRQ_4_BIT, MAESTRO_WIU_ICR_4_SEQ_SEL_IRQ_4_WIDTH); }
};

class vp_maestro_wiu_icr_5 : public vp::reg_8
{
public:
  inline void seq_sel_irq_5_set(uint8_t value) { this->set_field(value, MAESTRO_WIU_ICR_5_SEQ_SEL_IRQ_5_BIT, MAESTRO_WIU_ICR_5_SEQ_SEL_IRQ_5_WIDTH); }
  inline uint8_t seq_sel_irq_5_get() { return this->get_field(MAESTRO_WIU_ICR_5_SEQ_SEL_IRQ_5_BIT, MAESTRO_WIU_ICR_5_SEQ_SEL_IRQ_5_WIDTH); }
};

class vp_maestro_wiu_icr_6 : public vp::reg_8
{
public:
  inline void seq_sel_irq_6_set(uint8_t value) { this->set_field(value, MAESTRO_WIU_ICR_6_SEQ_SEL_IRQ_6_BIT, MAESTRO_WIU_ICR_6_SEQ_SEL_IRQ_6_WIDTH); }
  inline uint8_t seq_sel_irq_6_get() { return this->get_field(MAESTRO_WIU_ICR_6_SEQ_SEL_IRQ_6_BIT, MAESTRO_WIU_ICR_6_SEQ_SEL_IRQ_6_WIDTH); }
};

class vp_maestro_wiu_icr_7 : public vp::reg_8
{
public:
  inline void seq_sel_irq_7_set(uint8_t value) { this->set_field(value, MAESTRO_WIU_ICR_7_SEQ_SEL_IRQ_7_BIT, MAESTRO_WIU_ICR_7_SEQ_SEL_IRQ_7_WIDTH); }
  inline uint8_t seq_sel_irq_7_get() { return this->get_field(MAESTRO_WIU_ICR_7_SEQ_SEL_IRQ_7_BIT, MAESTRO_WIU_ICR_7_SEQ_SEL_IRQ_7_WIDTH); }
};

class vp_maestro_wiu_icr_8 : public vp::reg_8
{
public:
  inline void seq_sel_irq_8_set(uint8_t value) { this->set_field(value, MAESTRO_WIU_ICR_8_SEQ_SEL_IRQ_8_BIT, MAESTRO_WIU_ICR_8_SEQ_SEL_IRQ_8_WIDTH); }
  inline uint8_t seq_sel_irq_8_get() { return this->get_field(MAESTRO_WIU_ICR_8_SEQ_SEL_IRQ_8_BIT, MAESTRO_WIU_ICR_8_SEQ_SEL_IRQ_8_WIDTH); }
};

class vp_maestro_wiu_icr_9 : public vp::reg_8
{
public:
  inline void seq_sel_irq_9_set(uint8_t value) { this->set_field(value, MAESTRO_WIU_ICR_9_SEQ_SEL_IRQ_9_BIT, MAESTRO_WIU_ICR_9_SEQ_SEL_IRQ_9_WIDTH); }
  inline uint8_t seq_sel_irq_9_get() { return this->get_field(MAESTRO_WIU_ICR_9_SEQ_SEL_IRQ_9_BIT, MAESTRO_WIU_ICR_9_SEQ_SEL_IRQ_9_WIDTH); }
};

class vp_maestro_wiu_icr_10 : public vp::reg_8
{
public:
  inline void seq_sel_irq_10_set(uint8_t value) { this->set_field(value, MAESTRO_WIU_ICR_10_SEQ_SEL_IRQ_10_BIT, MAESTRO_WIU_ICR_10_SEQ_SEL_IRQ_10_WIDTH); }
  inline uint8_t seq_sel_irq_10_get() { return this->get_field(MAESTRO_WIU_ICR_10_SEQ_SEL_IRQ_10_BIT, MAESTRO_WIU_ICR_10_SEQ_SEL_IRQ_10_WIDTH); }
};

class vp_maestro_wiu_icr_11 : public vp::reg_8
{
public:
  inline void seq_sel_irq_11_set(uint8_t value) { this->set_field(value, MAESTRO_WIU_ICR_11_SEQ_SEL_IRQ_11_BIT, MAESTRO_WIU_ICR_11_SEQ_SEL_IRQ_11_WIDTH); }
  inline uint8_t seq_sel_irq_11_get() { return this->get_field(MAESTRO_WIU_ICR_11_SEQ_SEL_IRQ_11_BIT, MAESTRO_WIU_ICR_11_SEQ_SEL_IRQ_11_WIDTH); }
};

class vp_maestro_wiu_icr_12 : public vp::reg_8
{
public:
  inline void seq_sel_irq_12_set(uint8_t value) { this->set_field(value, MAESTRO_WIU_ICR_12_SEQ_SEL_IRQ_12_BIT, MAESTRO_WIU_ICR_12_SEQ_SEL_IRQ_12_WIDTH); }
  inline uint8_t seq_sel_irq_12_get() { return this->get_field(MAESTRO_WIU_ICR_12_SEQ_SEL_IRQ_12_BIT, MAESTRO_WIU_ICR_12_SEQ_SEL_IRQ_12_WIDTH); }
};

class vp_maestro_wiu_icr_13 : public vp::reg_8
{
public:
  inline void seq_sel_irq_13_set(uint8_t value) { this->set_field(value, MAESTRO_WIU_ICR_13_SEQ_SEL_IRQ_13_BIT, MAESTRO_WIU_ICR_13_SEQ_SEL_IRQ_13_WIDTH); }
  inline uint8_t seq_sel_irq_13_get() { return this->get_field(MAESTRO_WIU_ICR_13_SEQ_SEL_IRQ_13_BIT, MAESTRO_WIU_ICR_13_SEQ_SEL_IRQ_13_WIDTH); }
};

class vp_maestro_wiu_icr_14 : public vp::reg_8
{
public:
  inline void seq_sel_irq_14_set(uint8_t value) { this->set_field(value, MAESTRO_WIU_ICR_14_SEQ_SEL_IRQ_14_BIT, MAESTRO_WIU_ICR_14_SEQ_SEL_IRQ_14_WIDTH); }
  inline uint8_t seq_sel_irq_14_get() { return this->get_field(MAESTRO_WIU_ICR_14_SEQ_SEL_IRQ_14_BIT, MAESTRO_WIU_ICR_14_SEQ_SEL_IRQ_14_WIDTH); }
};

class vp_maestro_wiu_icr_15 : public vp::reg_8
{
public:
  inline void seq_sel_irq_15_set(uint8_t value) { this->set_field(value, MAESTRO_WIU_ICR_15_SEQ_SEL_IRQ_15_BIT, MAESTRO_WIU_ICR_15_SEQ_SEL_IRQ_15_WIDTH); }
  inline uint8_t seq_sel_irq_15_get() { return this->get_field(MAESTRO_WIU_ICR_15_SEQ_SEL_IRQ_15_BIT, MAESTRO_WIU_ICR_15_SEQ_SEL_IRQ_15_WIDTH); }
};

#endif



//
// REGISTERS GLOBAL STRUCT
//

#ifndef LANGUAGE_ASSEMBLY

typedef struct {
  unsigned int wiu_ispmr_0     ; // Interrupt Sequence Processing Mask registers
  unsigned int wiu_ispmr_1     ; // Interrupt Sequence Processing Mask registers
  unsigned int wiu_ifr_0       ; // Interrupt Flag register
  unsigned int wiu_ifr_1       ; // Interrupt Flag register
  unsigned int wiu_icr_0       ; // Interrupt Control registers
  unsigned int wiu_icr_1       ; // Interrupt Control registers
  unsigned int wiu_icr_2       ; // Interrupt Control registers
  unsigned int wiu_icr_3       ; // Interrupt Control registers
  unsigned int wiu_icr_4       ; // Interrupt Control registers
  unsigned int wiu_icr_5       ; // Interrupt Control registers
  unsigned int wiu_icr_6       ; // Interrupt Control registers
  unsigned int wiu_icr_7       ; // Interrupt Control registers
  unsigned int wiu_icr_8       ; // Interrupt Control registers
  unsigned int wiu_icr_9       ; // Interrupt Control registers
  unsigned int wiu_icr_10      ; // Interrupt Control registers
  unsigned int wiu_icr_11      ; // Interrupt Control registers
  unsigned int wiu_icr_12      ; // Interrupt Control registers
  unsigned int wiu_icr_13      ; // Interrupt Control registers
  unsigned int wiu_icr_14      ; // Interrupt Control registers
  unsigned int wiu_icr_15      ; // Interrupt Control registers
} __attribute__((packed)) maestro_wiu_t;

#endif



//
// REGISTERS ACCESS FUNCTIONS
//

#ifndef LANGUAGE_ASSEMBLY

static inline uint32_t maestro_wiu_ispmr_0_get(uint32_t base) { return ARCHI_READ(base, MAESTRO_WIU_ISPMR_0_OFFSET); }
static inline void maestro_wiu_ispmr_0_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, MAESTRO_WIU_ISPMR_0_OFFSET, value); }

static inline uint32_t maestro_wiu_ispmr_1_get(uint32_t base) { return ARCHI_READ(base, MAESTRO_WIU_ISPMR_1_OFFSET); }
static inline void maestro_wiu_ispmr_1_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, MAESTRO_WIU_ISPMR_1_OFFSET, value); }

static inline uint32_t maestro_wiu_ifr_0_get(uint32_t base) { return ARCHI_READ(base, MAESTRO_WIU_IFR_0_OFFSET); }
static inline void maestro_wiu_ifr_0_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, MAESTRO_WIU_IFR_0_OFFSET, value); }

static inline uint32_t maestro_wiu_ifr_1_get(uint32_t base) { return ARCHI_READ(base, MAESTRO_WIU_IFR_1_OFFSET); }
static inline void maestro_wiu_ifr_1_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, MAESTRO_WIU_IFR_1_OFFSET, value); }

static inline uint32_t maestro_wiu_icr_0_get(uint32_t base) { return ARCHI_READ(base, MAESTRO_WIU_ICR_0_OFFSET); }
static inline void maestro_wiu_icr_0_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, MAESTRO_WIU_ICR_0_OFFSET, value); }

static inline uint32_t maestro_wiu_icr_1_get(uint32_t base) { return ARCHI_READ(base, MAESTRO_WIU_ICR_1_OFFSET); }
static inline void maestro_wiu_icr_1_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, MAESTRO_WIU_ICR_1_OFFSET, value); }

static inline uint32_t maestro_wiu_icr_2_get(uint32_t base) { return ARCHI_READ(base, MAESTRO_WIU_ICR_2_OFFSET); }
static inline void maestro_wiu_icr_2_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, MAESTRO_WIU_ICR_2_OFFSET, value); }

static inline uint32_t maestro_wiu_icr_3_get(uint32_t base) { return ARCHI_READ(base, MAESTRO_WIU_ICR_3_OFFSET); }
static inline void maestro_wiu_icr_3_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, MAESTRO_WIU_ICR_3_OFFSET, value); }

static inline uint32_t maestro_wiu_icr_4_get(uint32_t base) { return ARCHI_READ(base, MAESTRO_WIU_ICR_4_OFFSET); }
static inline void maestro_wiu_icr_4_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, MAESTRO_WIU_ICR_4_OFFSET, value); }

static inline uint32_t maestro_wiu_icr_5_get(uint32_t base) { return ARCHI_READ(base, MAESTRO_WIU_ICR_5_OFFSET); }
static inline void maestro_wiu_icr_5_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, MAESTRO_WIU_ICR_5_OFFSET, value); }

static inline uint32_t maestro_wiu_icr_6_get(uint32_t base) { return ARCHI_READ(base, MAESTRO_WIU_ICR_6_OFFSET); }
static inline void maestro_wiu_icr_6_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, MAESTRO_WIU_ICR_6_OFFSET, value); }

static inline uint32_t maestro_wiu_icr_7_get(uint32_t base) { return ARCHI_READ(base, MAESTRO_WIU_ICR_7_OFFSET); }
static inline void maestro_wiu_icr_7_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, MAESTRO_WIU_ICR_7_OFFSET, value); }

static inline uint32_t maestro_wiu_icr_8_get(uint32_t base) { return ARCHI_READ(base, MAESTRO_WIU_ICR_8_OFFSET); }
static inline void maestro_wiu_icr_8_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, MAESTRO_WIU_ICR_8_OFFSET, value); }

static inline uint32_t maestro_wiu_icr_9_get(uint32_t base) { return ARCHI_READ(base, MAESTRO_WIU_ICR_9_OFFSET); }
static inline void maestro_wiu_icr_9_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, MAESTRO_WIU_ICR_9_OFFSET, value); }

static inline uint32_t maestro_wiu_icr_10_get(uint32_t base) { return ARCHI_READ(base, MAESTRO_WIU_ICR_10_OFFSET); }
static inline void maestro_wiu_icr_10_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, MAESTRO_WIU_ICR_10_OFFSET, value); }

static inline uint32_t maestro_wiu_icr_11_get(uint32_t base) { return ARCHI_READ(base, MAESTRO_WIU_ICR_11_OFFSET); }
static inline void maestro_wiu_icr_11_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, MAESTRO_WIU_ICR_11_OFFSET, value); }

static inline uint32_t maestro_wiu_icr_12_get(uint32_t base) { return ARCHI_READ(base, MAESTRO_WIU_ICR_12_OFFSET); }
static inline void maestro_wiu_icr_12_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, MAESTRO_WIU_ICR_12_OFFSET, value); }

static inline uint32_t maestro_wiu_icr_13_get(uint32_t base) { return ARCHI_READ(base, MAESTRO_WIU_ICR_13_OFFSET); }
static inline void maestro_wiu_icr_13_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, MAESTRO_WIU_ICR_13_OFFSET, value); }

static inline uint32_t maestro_wiu_icr_14_get(uint32_t base) { return ARCHI_READ(base, MAESTRO_WIU_ICR_14_OFFSET); }
static inline void maestro_wiu_icr_14_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, MAESTRO_WIU_ICR_14_OFFSET, value); }

static inline uint32_t maestro_wiu_icr_15_get(uint32_t base) { return ARCHI_READ(base, MAESTRO_WIU_ICR_15_OFFSET); }
static inline void maestro_wiu_icr_15_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, MAESTRO_WIU_ICR_15_OFFSET, value); }

#endif



//
// REGISTERS FIELDS MACROS
//

#ifndef LANGUAGE_ASSEMBLY

#define MAESTRO_WIU_ISPMR_0_MASK_MODECHG_EN_IRQ_GET(value) (ARCHI_BEXTRACTU((value),8,0))
#define MAESTRO_WIU_ISPMR_0_MASK_MODECHG_EN_IRQ_GETS(value) (ARCHI_BEXTRACT((value),8,0))
#define MAESTRO_WIU_ISPMR_0_MASK_MODECHG_EN_IRQ_SET(value,field) (ARCHI_BINSERT((value),(field),8,0))
#define MAESTRO_WIU_ISPMR_0_MASK_MODECHG_EN_IRQ(val)       ((val) << 0)

#define MAESTRO_WIU_ISPMR_1_MASK_MODECHG_EN_IRQ_GET(value) (ARCHI_BEXTRACTU((value),8,0))
#define MAESTRO_WIU_ISPMR_1_MASK_MODECHG_EN_IRQ_GETS(value) (ARCHI_BEXTRACT((value),8,0))
#define MAESTRO_WIU_ISPMR_1_MASK_MODECHG_EN_IRQ_SET(value,field) (ARCHI_BINSERT((value),(field),8,0))
#define MAESTRO_WIU_ISPMR_1_MASK_MODECHG_EN_IRQ(val)       ((val) << 0)

#define MAESTRO_WIU_IFR_0_FLAG_IRQ_GET(value)              (ARCHI_BEXTRACTU((value),8,0))
#define MAESTRO_WIU_IFR_0_FLAG_IRQ_GETS(value)             (ARCHI_BEXTRACT((value),8,0))
#define MAESTRO_WIU_IFR_0_FLAG_IRQ_SET(value,field)        (ARCHI_BINSERT((value),(field),8,0))
#define MAESTRO_WIU_IFR_0_FLAG_IRQ(val)                    ((val) << 0)

#define MAESTRO_WIU_IFR_1_FLAG_IRQ_GET(value)              (ARCHI_BEXTRACTU((value),8,0))
#define MAESTRO_WIU_IFR_1_FLAG_IRQ_GETS(value)             (ARCHI_BEXTRACT((value),8,0))
#define MAESTRO_WIU_IFR_1_FLAG_IRQ_SET(value,field)        (ARCHI_BINSERT((value),(field),8,0))
#define MAESTRO_WIU_IFR_1_FLAG_IRQ(val)                    ((val) << 0)

#define MAESTRO_WIU_ICR_0_SEQ_SEL_IRQ_0_GET(value)         (ARCHI_BEXTRACTU((value),5,0))
#define MAESTRO_WIU_ICR_0_SEQ_SEL_IRQ_0_GETS(value)        (ARCHI_BEXTRACT((value),5,0))
#define MAESTRO_WIU_ICR_0_SEQ_SEL_IRQ_0_SET(value,field)   (ARCHI_BINSERT((value),(field),5,0))
#define MAESTRO_WIU_ICR_0_SEQ_SEL_IRQ_0(val)               ((val) << 0)

#define MAESTRO_WIU_ICR_1_SEQ_SEL_IRQ_1_GET(value)         (ARCHI_BEXTRACTU((value),5,0))
#define MAESTRO_WIU_ICR_1_SEQ_SEL_IRQ_1_GETS(value)        (ARCHI_BEXTRACT((value),5,0))
#define MAESTRO_WIU_ICR_1_SEQ_SEL_IRQ_1_SET(value,field)   (ARCHI_BINSERT((value),(field),5,0))
#define MAESTRO_WIU_ICR_1_SEQ_SEL_IRQ_1(val)               ((val) << 0)

#define MAESTRO_WIU_ICR_2_SEQ_SEL_IRQ_2_GET(value)         (ARCHI_BEXTRACTU((value),5,0))
#define MAESTRO_WIU_ICR_2_SEQ_SEL_IRQ_2_GETS(value)        (ARCHI_BEXTRACT((value),5,0))
#define MAESTRO_WIU_ICR_2_SEQ_SEL_IRQ_2_SET(value,field)   (ARCHI_BINSERT((value),(field),5,0))
#define MAESTRO_WIU_ICR_2_SEQ_SEL_IRQ_2(val)               ((val) << 0)

#define MAESTRO_WIU_ICR_3_SEQ_SEL_IRQ_3_GET(value)         (ARCHI_BEXTRACTU((value),5,0))
#define MAESTRO_WIU_ICR_3_SEQ_SEL_IRQ_3_GETS(value)        (ARCHI_BEXTRACT((value),5,0))
#define MAESTRO_WIU_ICR_3_SEQ_SEL_IRQ_3_SET(value,field)   (ARCHI_BINSERT((value),(field),5,0))
#define MAESTRO_WIU_ICR_3_SEQ_SEL_IRQ_3(val)               ((val) << 0)

#define MAESTRO_WIU_ICR_4_SEQ_SEL_IRQ_4_GET(value)         (ARCHI_BEXTRACTU((value),5,0))
#define MAESTRO_WIU_ICR_4_SEQ_SEL_IRQ_4_GETS(value)        (ARCHI_BEXTRACT((value),5,0))
#define MAESTRO_WIU_ICR_4_SEQ_SEL_IRQ_4_SET(value,field)   (ARCHI_BINSERT((value),(field),5,0))
#define MAESTRO_WIU_ICR_4_SEQ_SEL_IRQ_4(val)               ((val) << 0)

#define MAESTRO_WIU_ICR_5_SEQ_SEL_IRQ_5_GET(value)         (ARCHI_BEXTRACTU((value),5,0))
#define MAESTRO_WIU_ICR_5_SEQ_SEL_IRQ_5_GETS(value)        (ARCHI_BEXTRACT((value),5,0))
#define MAESTRO_WIU_ICR_5_SEQ_SEL_IRQ_5_SET(value,field)   (ARCHI_BINSERT((value),(field),5,0))
#define MAESTRO_WIU_ICR_5_SEQ_SEL_IRQ_5(val)               ((val) << 0)

#define MAESTRO_WIU_ICR_6_SEQ_SEL_IRQ_6_GET(value)         (ARCHI_BEXTRACTU((value),5,0))
#define MAESTRO_WIU_ICR_6_SEQ_SEL_IRQ_6_GETS(value)        (ARCHI_BEXTRACT((value),5,0))
#define MAESTRO_WIU_ICR_6_SEQ_SEL_IRQ_6_SET(value,field)   (ARCHI_BINSERT((value),(field),5,0))
#define MAESTRO_WIU_ICR_6_SEQ_SEL_IRQ_6(val)               ((val) << 0)

#define MAESTRO_WIU_ICR_7_SEQ_SEL_IRQ_7_GET(value)         (ARCHI_BEXTRACTU((value),5,0))
#define MAESTRO_WIU_ICR_7_SEQ_SEL_IRQ_7_GETS(value)        (ARCHI_BEXTRACT((value),5,0))
#define MAESTRO_WIU_ICR_7_SEQ_SEL_IRQ_7_SET(value,field)   (ARCHI_BINSERT((value),(field),5,0))
#define MAESTRO_WIU_ICR_7_SEQ_SEL_IRQ_7(val)               ((val) << 0)

#define MAESTRO_WIU_ICR_8_SEQ_SEL_IRQ_8_GET(value)         (ARCHI_BEXTRACTU((value),5,0))
#define MAESTRO_WIU_ICR_8_SEQ_SEL_IRQ_8_GETS(value)        (ARCHI_BEXTRACT((value),5,0))
#define MAESTRO_WIU_ICR_8_SEQ_SEL_IRQ_8_SET(value,field)   (ARCHI_BINSERT((value),(field),5,0))
#define MAESTRO_WIU_ICR_8_SEQ_SEL_IRQ_8(val)               ((val) << 0)

#define MAESTRO_WIU_ICR_9_SEQ_SEL_IRQ_9_GET(value)         (ARCHI_BEXTRACTU((value),5,0))
#define MAESTRO_WIU_ICR_9_SEQ_SEL_IRQ_9_GETS(value)        (ARCHI_BEXTRACT((value),5,0))
#define MAESTRO_WIU_ICR_9_SEQ_SEL_IRQ_9_SET(value,field)   (ARCHI_BINSERT((value),(field),5,0))
#define MAESTRO_WIU_ICR_9_SEQ_SEL_IRQ_9(val)               ((val) << 0)

#define MAESTRO_WIU_ICR_10_SEQ_SEL_IRQ_10_GET(value)       (ARCHI_BEXTRACTU((value),5,0))
#define MAESTRO_WIU_ICR_10_SEQ_SEL_IRQ_10_GETS(value)      (ARCHI_BEXTRACT((value),5,0))
#define MAESTRO_WIU_ICR_10_SEQ_SEL_IRQ_10_SET(value,field) (ARCHI_BINSERT((value),(field),5,0))
#define MAESTRO_WIU_ICR_10_SEQ_SEL_IRQ_10(val)             ((val) << 0)

#define MAESTRO_WIU_ICR_11_SEQ_SEL_IRQ_11_GET(value)       (ARCHI_BEXTRACTU((value),5,0))
#define MAESTRO_WIU_ICR_11_SEQ_SEL_IRQ_11_GETS(value)      (ARCHI_BEXTRACT((value),5,0))
#define MAESTRO_WIU_ICR_11_SEQ_SEL_IRQ_11_SET(value,field) (ARCHI_BINSERT((value),(field),5,0))
#define MAESTRO_WIU_ICR_11_SEQ_SEL_IRQ_11(val)             ((val) << 0)

#define MAESTRO_WIU_ICR_12_SEQ_SEL_IRQ_12_GET(value)       (ARCHI_BEXTRACTU((value),5,0))
#define MAESTRO_WIU_ICR_12_SEQ_SEL_IRQ_12_GETS(value)      (ARCHI_BEXTRACT((value),5,0))
#define MAESTRO_WIU_ICR_12_SEQ_SEL_IRQ_12_SET(value,field) (ARCHI_BINSERT((value),(field),5,0))
#define MAESTRO_WIU_ICR_12_SEQ_SEL_IRQ_12(val)             ((val) << 0)

#define MAESTRO_WIU_ICR_13_SEQ_SEL_IRQ_13_GET(value)       (ARCHI_BEXTRACTU((value),5,0))
#define MAESTRO_WIU_ICR_13_SEQ_SEL_IRQ_13_GETS(value)      (ARCHI_BEXTRACT((value),5,0))
#define MAESTRO_WIU_ICR_13_SEQ_SEL_IRQ_13_SET(value,field) (ARCHI_BINSERT((value),(field),5,0))
#define MAESTRO_WIU_ICR_13_SEQ_SEL_IRQ_13(val)             ((val) << 0)

#define MAESTRO_WIU_ICR_14_SEQ_SEL_IRQ_14_GET(value)       (ARCHI_BEXTRACTU((value),5,0))
#define MAESTRO_WIU_ICR_14_SEQ_SEL_IRQ_14_GETS(value)      (ARCHI_BEXTRACT((value),5,0))
#define MAESTRO_WIU_ICR_14_SEQ_SEL_IRQ_14_SET(value,field) (ARCHI_BINSERT((value),(field),5,0))
#define MAESTRO_WIU_ICR_14_SEQ_SEL_IRQ_14(val)             ((val) << 0)

#define MAESTRO_WIU_ICR_15_SEQ_SEL_IRQ_15_GET(value)       (ARCHI_BEXTRACTU((value),5,0))
#define MAESTRO_WIU_ICR_15_SEQ_SEL_IRQ_15_GETS(value)      (ARCHI_BEXTRACT((value),5,0))
#define MAESTRO_WIU_ICR_15_SEQ_SEL_IRQ_15_SET(value,field) (ARCHI_BINSERT((value),(field),5,0))
#define MAESTRO_WIU_ICR_15_SEQ_SEL_IRQ_15(val)             ((val) << 0)

#endif



//
// GROUP icu
//



//
// REGISTERS
//

// ICU control register
#define MAESTRO_ICU_CTRL_OFFSET                  0x0

// ICU mode register
#define MAESTRO_ICU_MODE_OFFSET                  0x1

// Island mode register
#define MAESTRO_ISLAND_MODE_OFFSET               0x2

// DMU mode register 0
#define MAESTRO_DMU_MODE_OFFSET                  0x3



//
// REGISTERS FIELDS
//

// When a new mode corresponding to one of sixteen mode of the island mode table of the ICU is written as mode transition sequence is started to reach the written mode. (access: R/W)
#define MAESTRO_ICU_CTRL_ICU_CTRL_BIT                                0
#define MAESTRO_ICU_CTRL_ICU_CTRL_WIDTH                              4
#define MAESTRO_ICU_CTRL_ICU_CTRL_MASK                               0xf
#define MAESTRO_ICU_CTRL_ICU_CTRL_RESET                              0x0

// Returns the current mode of the ICU when icu_mode_defined is low. (access: R)
#define MAESTRO_ICU_MODE_ICU_MODE_BIT                                0
#define MAESTRO_ICU_MODE_ICU_MODE_WIDTH                              4
#define MAESTRO_ICU_MODE_ICU_MODE_MASK                               0xf
#define MAESTRO_ICU_MODE_ICU_MODE_RESET                              0xf

// When high, indicates that the current mode of the ICU is not defined in the mode table of the ICU When low, the value of the current mode is given by the icu_mode bits (access: R)
#define MAESTRO_ICU_MODE_ICU_MODE_DEFINED_BIT                        4
#define MAESTRO_ICU_MODE_ICU_MODE_DEFINED_WIDTH                      1
#define MAESTRO_ICU_MODE_ICU_MODE_DEFINED_MASK                       0x10
#define MAESTRO_ICU_MODE_ICU_MODE_DEFINED_RESET                      0x1

// Mode of the island. (access: R)
#define MAESTRO_ISLAND_MODE_ISL_MODE_BIT                             0
#define MAESTRO_ISLAND_MODE_ISL_MODE_WIDTH                           2
#define MAESTRO_ISLAND_MODE_ISL_MODE_MASK                            0x3
#define MAESTRO_ISLAND_MODE_ISL_MODE_RESET                           0x0

// Mode of the DMU 0. (access: R)
#define MAESTRO_DMU_MODE_ISL_MODE_BIT                                0
#define MAESTRO_DMU_MODE_ISL_MODE_WIDTH                              2
#define MAESTRO_DMU_MODE_ISL_MODE_MASK                               0x3
#define MAESTRO_DMU_MODE_ISL_MODE_RESET                              0x0



//
// REGISTERS STRUCTS
//

#ifndef LANGUAGE_ASSEMBLY

typedef union {
  struct {
    unsigned int icu_ctrl        :4 ; // When a new mode corresponding to one of sixteen mode of the island mode table of the ICU is written as mode transition sequence is started to reach the written mode.
  };
  unsigned int raw;
} __attribute__((packed)) maestro_icu_ctrl_t;

typedef union {
  struct {
    unsigned int icu_mode        :4 ; // Returns the current mode of the ICU when icu_mode_defined is low.
    unsigned int icu_mode_defined:1 ; // When high, indicates that the current mode of the ICU is not defined in the mode table of the ICU When low, the value of the current mode is given by the icu_mode bits
  };
  unsigned int raw;
} __attribute__((packed)) maestro_icu_mode_t;

typedef union {
  struct {
    unsigned int isl_mode        :2 ; // Mode of the island.
  };
  unsigned int raw;
} __attribute__((packed)) maestro_island_mode_t;

typedef union {
  struct {
    unsigned int isl_mode        :2 ; // Mode of the DMU 0.
  };
  unsigned int raw;
} __attribute__((packed)) maestro_dmu_mode_t;

#endif



//
// REGISTERS STRUCTS
//

#ifdef __GVSOC__

class vp_maestro_icu_ctrl : public vp::reg_8
{
public:
  inline void icu_ctrl_set(uint8_t value) { this->set_field(value, MAESTRO_ICU_CTRL_ICU_CTRL_BIT, MAESTRO_ICU_CTRL_ICU_CTRL_WIDTH); }
  inline uint8_t icu_ctrl_get() { return this->get_field(MAESTRO_ICU_CTRL_ICU_CTRL_BIT, MAESTRO_ICU_CTRL_ICU_CTRL_WIDTH); }
};

class vp_maestro_icu_mode : public vp::reg_8
{
public:
  inline void icu_mode_set(uint8_t value) { this->set_field(value, MAESTRO_ICU_MODE_ICU_MODE_BIT, MAESTRO_ICU_MODE_ICU_MODE_WIDTH); }
  inline uint8_t icu_mode_get() { return this->get_field(MAESTRO_ICU_MODE_ICU_MODE_BIT, MAESTRO_ICU_MODE_ICU_MODE_WIDTH); }
  inline void icu_mode_defined_set(uint8_t value) { this->set_field(value, MAESTRO_ICU_MODE_ICU_MODE_DEFINED_BIT, MAESTRO_ICU_MODE_ICU_MODE_DEFINED_WIDTH); }
  inline uint8_t icu_mode_defined_get() { return this->get_field(MAESTRO_ICU_MODE_ICU_MODE_DEFINED_BIT, MAESTRO_ICU_MODE_ICU_MODE_DEFINED_WIDTH); }
};

class vp_maestro_island_mode : public vp::reg_8
{
public:
  inline void isl_mode_set(uint8_t value) { this->set_field(value, MAESTRO_ISLAND_MODE_ISL_MODE_BIT, MAESTRO_ISLAND_MODE_ISL_MODE_WIDTH); }
  inline uint8_t isl_mode_get() { return this->get_field(MAESTRO_ISLAND_MODE_ISL_MODE_BIT, MAESTRO_ISLAND_MODE_ISL_MODE_WIDTH); }
};

class vp_maestro_dmu_mode : public vp::reg_8
{
public:
  inline void isl_mode_set(uint8_t value) { this->set_field(value, MAESTRO_DMU_MODE_ISL_MODE_BIT, MAESTRO_DMU_MODE_ISL_MODE_WIDTH); }
  inline uint8_t isl_mode_get() { return this->get_field(MAESTRO_DMU_MODE_ISL_MODE_BIT, MAESTRO_DMU_MODE_ISL_MODE_WIDTH); }
};

#endif



//
// REGISTERS GLOBAL STRUCT
//

#ifndef LANGUAGE_ASSEMBLY

typedef struct {
  unsigned int icu_ctrl        ; // ICU control register
  unsigned int icu_mode        ; // ICU mode register
  unsigned int island_mode     ; // Island mode register
  unsigned int dmu_mode        ; // DMU mode register 0
} __attribute__((packed)) maestro_icu_t;

#endif



//
// REGISTERS ACCESS FUNCTIONS
//

#ifndef LANGUAGE_ASSEMBLY

static inline uint32_t maestro_icu_ctrl_get(uint32_t base) { return ARCHI_READ(base, MAESTRO_ICU_CTRL_OFFSET); }
static inline void maestro_icu_ctrl_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, MAESTRO_ICU_CTRL_OFFSET, value); }

static inline uint32_t maestro_icu_mode_get(uint32_t base) { return ARCHI_READ(base, MAESTRO_ICU_MODE_OFFSET); }
static inline void maestro_icu_mode_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, MAESTRO_ICU_MODE_OFFSET, value); }

static inline uint32_t maestro_island_mode_get(uint32_t base) { return ARCHI_READ(base, MAESTRO_ISLAND_MODE_OFFSET); }
static inline void maestro_island_mode_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, MAESTRO_ISLAND_MODE_OFFSET, value); }

static inline uint32_t maestro_dmu_mode_get(uint32_t base) { return ARCHI_READ(base, MAESTRO_DMU_MODE_OFFSET); }
static inline void maestro_dmu_mode_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, MAESTRO_DMU_MODE_OFFSET, value); }

#endif



//
// REGISTERS FIELDS MACROS
//

#ifndef LANGUAGE_ASSEMBLY

#define MAESTRO_ICU_CTRL_ICU_CTRL_GET(value)               (ARCHI_BEXTRACTU((value),4,0))
#define MAESTRO_ICU_CTRL_ICU_CTRL_GETS(value)              (ARCHI_BEXTRACT((value),4,0))
#define MAESTRO_ICU_CTRL_ICU_CTRL_SET(value,field)         (ARCHI_BINSERT((value),(field),4,0))
#define MAESTRO_ICU_CTRL_ICU_CTRL(val)                     ((val) << 0)

#define MAESTRO_ICU_MODE_ICU_MODE_GET(value)               (ARCHI_BEXTRACTU((value),4,0))
#define MAESTRO_ICU_MODE_ICU_MODE_GETS(value)              (ARCHI_BEXTRACT((value),4,0))
#define MAESTRO_ICU_MODE_ICU_MODE_SET(value,field)         (ARCHI_BINSERT((value),(field),4,0))
#define MAESTRO_ICU_MODE_ICU_MODE(val)                     ((val) << 0)

#define MAESTRO_ICU_MODE_ICU_MODE_DEFINED_GET(value)       (ARCHI_BEXTRACTU((value),1,4))
#define MAESTRO_ICU_MODE_ICU_MODE_DEFINED_GETS(value)      (ARCHI_BEXTRACT((value),1,4))
#define MAESTRO_ICU_MODE_ICU_MODE_DEFINED_SET(value,field) (ARCHI_BINSERT((value),(field),1,4))
#define MAESTRO_ICU_MODE_ICU_MODE_DEFINED(val)             ((val) << 4)

#define MAESTRO_ISLAND_MODE_ISL_MODE_GET(value)            (ARCHI_BEXTRACTU((value),2,0))
#define MAESTRO_ISLAND_MODE_ISL_MODE_GETS(value)           (ARCHI_BEXTRACT((value),2,0))
#define MAESTRO_ISLAND_MODE_ISL_MODE_SET(value,field)      (ARCHI_BINSERT((value),(field),2,0))
#define MAESTRO_ISLAND_MODE_ISL_MODE(val)                  ((val) << 0)

#define MAESTRO_DMU_MODE_ISL_MODE_GET(value)               (ARCHI_BEXTRACTU((value),2,0))
#define MAESTRO_DMU_MODE_ISL_MODE_GETS(value)              (ARCHI_BEXTRACT((value),2,0))
#define MAESTRO_DMU_MODE_ISL_MODE_SET(value,field)         (ARCHI_BINSERT((value),(field),2,0))
#define MAESTRO_DMU_MODE_ISL_MODE(val)                     ((val) << 0)

#endif



//
// CUSTOM FIELDS
//
#define MAESTRO_ICU_SUPPLY_EXT 0x0
#define MAESTRO_ICU_SUPPLY_RET 0x1
#define MAESTRO_ICU_SUPPLY_CKOFF 0x2
#define MAESTRO_ICU_SUPPLY_ON 0x3
#define MAESTRO_ICU_REGU_NONE 0x7
#define MAESTRO_ICU_REGU_OFF 0x0
#define MAESTRO_ICU_REGU_RV 0x1
#define MAESTRO_ICU_REGU_LV 0x2
#define MAESTRO_ICU_REGU_MV 0x3
#define MAESTRO_ICU_REGU_NV 0x4
#define MAESTRO_ICU_CLK_FNONE 0x7
#define MAESTRO_ICU_CLK_FOFF 0x0
#define MAESTRO_ICU_CLK_LF 0x1
#define MAESTRO_ICU_CLK_MF 0x2
#define MAESTRO_ICU_CLK_NF 0x3

#endif
