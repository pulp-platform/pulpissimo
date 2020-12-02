
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

#ifndef __INCLUDE_ARCHI_RTC_RTC_V2_H__
#define __INCLUDE_ARCHI_RTC_RTC_V2_H__

#ifndef LANGUAGE_ASSEMBLY

#include <stdint.h>
#include "archi/utils.h"

#endif




//
// REGISTERS
//

// Clock register
#define RTC_CLOCK_OFFSET                         0x0

// Alarm register
#define RTC_ALARM_OFFSET                         0x4

// Timer register
#define RTC_TIMER_OFFSET                         0x8

// Date register
#define RTC_DATE_OFFSET                          0xc



//
// REGISTERS FIELDS
//

// First digit of clock seconds. (access: R/W)
#define RTC_CLOCK_SECONDS_0_BIT                                      0
#define RTC_CLOCK_SECONDS_0_WIDTH                                    4
#define RTC_CLOCK_SECONDS_0_MASK                                     0xf

// Second digit of clock seconds. (access: R/W)
#define RTC_CLOCK_SECONDS_1_BIT                                      4
#define RTC_CLOCK_SECONDS_1_WIDTH                                    4
#define RTC_CLOCK_SECONDS_1_MASK                                     0xf0

// First digit of clock minutes. (access: R/W)
#define RTC_CLOCK_MINUTES_0_BIT                                      8
#define RTC_CLOCK_MINUTES_0_WIDTH                                    4
#define RTC_CLOCK_MINUTES_0_MASK                                     0xf00

// Second digit of clock minutes. (access: R/W)
#define RTC_CLOCK_MINUTES_1_BIT                                      12
#define RTC_CLOCK_MINUTES_1_WIDTH                                    4
#define RTC_CLOCK_MINUTES_1_MASK                                     0xf000

// First digit of clock hours. (access: R/W)
#define RTC_CLOCK_HOURS_0_BIT                                        16
#define RTC_CLOCK_HOURS_0_WIDTH                                      4
#define RTC_CLOCK_HOURS_0_MASK                                       0xf0000

// Second digit of clock hours. (access: R/W)
#define RTC_CLOCK_HOURS_1_BIT                                        20
#define RTC_CLOCK_HOURS_1_WIDTH                                      2
#define RTC_CLOCK_HOURS_1_MASK                                       0x300000

// MSB part of second counter initial value. The second counter is incremented every 1/32768 seconds and is incrementing by 1 the number of seconds when it reaches 32768. When the clock is written, bits 0 to 4 are set to 0 and bits 5 to 14 are set to the value of this field. (access: R/W)
#define RTC_CLOCK_INIT_SEC_COUNT_BIT                                 22
#define RTC_CLOCK_INIT_SEC_COUNT_WIDTH                               10
#define RTC_CLOCK_INIT_SEC_COUNT_MASK                                0xffc00000

// First digit of alarm seconds. (access: R/W)
#define RTC_ALARM_SECONDS_0_BIT                                      0
#define RTC_ALARM_SECONDS_0_WIDTH                                    8
#define RTC_ALARM_SECONDS_0_MASK                                     0xff

// Second digit of alarm seconds. (access: R/W)
#define RTC_ALARM_SECONDS_1_BIT                                      0
#define RTC_ALARM_SECONDS_1_WIDTH                                    8
#define RTC_ALARM_SECONDS_1_MASK                                     0xff

// First digit of alarm minutes. (access: R/W)
#define RTC_ALARM_MINUTES_0_BIT                                      8
#define RTC_ALARM_MINUTES_0_WIDTH                                    8
#define RTC_ALARM_MINUTES_0_MASK                                     0xff00

// Second digit of alarm minutes. (access: R/W)
#define RTC_ALARM_MINUTES_1_BIT                                      8
#define RTC_ALARM_MINUTES_1_WIDTH                                    8
#define RTC_ALARM_MINUTES_1_MASK                                     0xff00

// First digit of alarm hours. (access: R/W)
#define RTC_ALARM_HOURS_0_BIT                                        16
#define RTC_ALARM_HOURS_0_WIDTH                                      6
#define RTC_ALARM_HOURS_0_MASK                                       0x3f0000

// Second digit of alarm hours. (access: R/W)
#define RTC_ALARM_HOURS_1_BIT                                        16
#define RTC_ALARM_HOURS_1_WIDTH                                      6
#define RTC_ALARM_HOURS_1_MASK                                       0x3f0000

// Alarm enable. When set to 1, an event is generated when the alarm is matching the clock. (access: R/W)
#define RTC_ALARM_ENABLE_BIT                                         31
#define RTC_ALARM_ENABLE_WIDTH                                       1
#define RTC_ALARM_ENABLE_MASK                                        0x80000000

// Timer target. When the timer is enabled, an event is generated when the timer counter is matching this field. (access: R/W)
#define RTC_TIMER_TARGET_BIT                                         0
#define RTC_TIMER_TARGET_WIDTH                                       17
#define RTC_TIMER_TARGET_MASK                                        0x1ffff

// Timer retrig. When set to 1, the timer is still enabled after an event is generated when the timer counter is matching the timer target. If it is set to 0, the timer is disabled after the event is generated. (access: R/W)
#define RTC_TIMER_RETRIG_BIT                                         30
#define RTC_TIMER_RETRIG_WIDTH                                       1
#define RTC_TIMER_RETRIG_MASK                                        0x40000000

// Timer enable. When set to 1, the timer counter is incremented every 1/32768 seconds and an event is generated when the timer counter is matching the timer target. (access: R/W)
#define RTC_TIMER_ENABLE_BIT                                         31
#define RTC_TIMER_ENABLE_WIDTH                                       1
#define RTC_TIMER_ENABLE_MASK                                        0x80000000

// First digit of date day. (access: R/W)
#define RTC_DATE_DAY_0_BIT                                           0
#define RTC_DATE_DAY_0_WIDTH                                         6
#define RTC_DATE_DAY_0_MASK                                          0x3f

// Second digit of date day. (access: R/W)
#define RTC_DATE_DAY_1_BIT                                           0
#define RTC_DATE_DAY_1_WIDTH                                         6
#define RTC_DATE_DAY_1_MASK                                          0x3f

// First digit of date month. (access: R/W)
#define RTC_DATE_MONTH_0_BIT                                         8
#define RTC_DATE_MONTH_0_WIDTH                                       5
#define RTC_DATE_MONTH_0_MASK                                        0x1f00

// Second digit of date month. (access: R/W)
#define RTC_DATE_MONTH_1_BIT                                         8
#define RTC_DATE_MONTH_1_WIDTH                                       5
#define RTC_DATE_MONTH_1_MASK                                        0x1f00

// First digit of date year. (access: R/W)
#define RTC_DATE_YEAR_0_BIT                                          16
#define RTC_DATE_YEAR_0_WIDTH                                        14
#define RTC_DATE_YEAR_0_MASK                                         0x3fff0000

// Second digit of date year. (access: R/W)
#define RTC_DATE_YEAR_1_BIT                                          16
#define RTC_DATE_YEAR_1_WIDTH                                        14
#define RTC_DATE_YEAR_1_MASK                                         0x3fff0000



//
// REGISTERS STRUCTS
//

#ifndef LANGUAGE_ASSEMBLY

typedef union {
  struct {
    unsigned int seconds_0       :4 ; // First digit of clock seconds.
    unsigned int seconds_1       :4 ; // Second digit of clock seconds.
    unsigned int minutes_0       :4 ; // First digit of clock minutes.
    unsigned int minutes_1       :4 ; // Second digit of clock minutes.
    unsigned int hours_0         :4 ; // First digit of clock hours.
    unsigned int hours_1         :2 ; // Second digit of clock hours.
    unsigned int init_sec_count  :10; // MSB part of second counter initial value. The second counter is incremented every 1/32768 seconds and is incrementing by 1 the number of seconds when it reaches 32768. When the clock is written, bits 0 to 4 are set to 0 and bits 5 to 14 are set to the value of this field.
  };
  unsigned int raw;
} __attribute__((packed)) rtc_clock_t;

typedef union {
  struct {
    unsigned int seconds_0       :8 ; // First digit of alarm seconds.
    unsigned int seconds_1       :8 ; // Second digit of alarm seconds.
    unsigned int minutes_0       :8 ; // First digit of alarm minutes.
    unsigned int minutes_1       :8 ; // Second digit of alarm minutes.
    unsigned int hours_0         :6 ; // First digit of alarm hours.
    unsigned int hours_1         :6 ; // Second digit of alarm hours.
    unsigned int padding0:9 ;
    unsigned int enable          :1 ; // Alarm enable. When set to 1, an event is generated when the alarm is matching the clock.
  };
  unsigned int raw;
} __attribute__((packed)) rtc_alarm_t;

typedef union {
  struct {
    unsigned int target          :17; // Timer target. When the timer is enabled, an event is generated when the timer counter is matching this field.
    unsigned int padding0:13;
    unsigned int retrig          :1 ; // Timer retrig. When set to 1, the timer is still enabled after an event is generated when the timer counter is matching the timer target. If it is set to 0, the timer is disabled after the event is generated.
    unsigned int enable          :1 ; // Timer enable. When set to 1, the timer counter is incremented every 1/32768 seconds and an event is generated when the timer counter is matching the timer target.
  };
  unsigned int raw;
} __attribute__((packed)) rtc_timer_t;

typedef union {
  struct {
    unsigned int day_0           :6 ; // First digit of date day.
    unsigned int day_1           :6 ; // Second digit of date day.
    unsigned int padding0:2 ;
    unsigned int month_0         :5 ; // First digit of date month.
    unsigned int month_1         :5 ; // Second digit of date month.
    unsigned int padding1:3 ;
    unsigned int year_0          :14; // First digit of date year.
    unsigned int year_1          :14; // Second digit of date year.
  };
  unsigned int raw;
} __attribute__((packed)) rtc_date_t;

#endif



//
// REGISTERS STRUCTS
//

#ifdef __GVSOC__

class vp_rtc_clock : public vp::reg_32
{
public:
  inline void seconds_0_set(uint32_t value) { this->set_field(value, RTC_CLOCK_SECONDS_0_BIT, RTC_CLOCK_SECONDS_0_WIDTH); }
  inline uint32_t seconds_0_get() { return this->get_field(RTC_CLOCK_SECONDS_0_BIT, RTC_CLOCK_SECONDS_0_WIDTH); }
  inline void seconds_1_set(uint32_t value) { this->set_field(value, RTC_CLOCK_SECONDS_1_BIT, RTC_CLOCK_SECONDS_1_WIDTH); }
  inline uint32_t seconds_1_get() { return this->get_field(RTC_CLOCK_SECONDS_1_BIT, RTC_CLOCK_SECONDS_1_WIDTH); }
  inline void minutes_0_set(uint32_t value) { this->set_field(value, RTC_CLOCK_MINUTES_0_BIT, RTC_CLOCK_MINUTES_0_WIDTH); }
  inline uint32_t minutes_0_get() { return this->get_field(RTC_CLOCK_MINUTES_0_BIT, RTC_CLOCK_MINUTES_0_WIDTH); }
  inline void minutes_1_set(uint32_t value) { this->set_field(value, RTC_CLOCK_MINUTES_1_BIT, RTC_CLOCK_MINUTES_1_WIDTH); }
  inline uint32_t minutes_1_get() { return this->get_field(RTC_CLOCK_MINUTES_1_BIT, RTC_CLOCK_MINUTES_1_WIDTH); }
  inline void hours_0_set(uint32_t value) { this->set_field(value, RTC_CLOCK_HOURS_0_BIT, RTC_CLOCK_HOURS_0_WIDTH); }
  inline uint32_t hours_0_get() { return this->get_field(RTC_CLOCK_HOURS_0_BIT, RTC_CLOCK_HOURS_0_WIDTH); }
  inline void hours_1_set(uint32_t value) { this->set_field(value, RTC_CLOCK_HOURS_1_BIT, RTC_CLOCK_HOURS_1_WIDTH); }
  inline uint32_t hours_1_get() { return this->get_field(RTC_CLOCK_HOURS_1_BIT, RTC_CLOCK_HOURS_1_WIDTH); }
  inline void init_sec_count_set(uint32_t value) { this->set_field(value, RTC_CLOCK_INIT_SEC_COUNT_BIT, RTC_CLOCK_INIT_SEC_COUNT_WIDTH); }
  inline uint32_t init_sec_count_get() { return this->get_field(RTC_CLOCK_INIT_SEC_COUNT_BIT, RTC_CLOCK_INIT_SEC_COUNT_WIDTH); }
};

class vp_rtc_alarm : public vp::reg_32
{
public:
  inline void seconds_0_set(uint32_t value) { this->set_field(value, RTC_ALARM_SECONDS_0_BIT, RTC_ALARM_SECONDS_0_WIDTH); }
  inline uint32_t seconds_0_get() { return this->get_field(RTC_ALARM_SECONDS_0_BIT, RTC_ALARM_SECONDS_0_WIDTH); }
  inline void seconds_1_set(uint32_t value) { this->set_field(value, RTC_ALARM_SECONDS_1_BIT, RTC_ALARM_SECONDS_1_WIDTH); }
  inline uint32_t seconds_1_get() { return this->get_field(RTC_ALARM_SECONDS_1_BIT, RTC_ALARM_SECONDS_1_WIDTH); }
  inline void minutes_0_set(uint32_t value) { this->set_field(value, RTC_ALARM_MINUTES_0_BIT, RTC_ALARM_MINUTES_0_WIDTH); }
  inline uint32_t minutes_0_get() { return this->get_field(RTC_ALARM_MINUTES_0_BIT, RTC_ALARM_MINUTES_0_WIDTH); }
  inline void minutes_1_set(uint32_t value) { this->set_field(value, RTC_ALARM_MINUTES_1_BIT, RTC_ALARM_MINUTES_1_WIDTH); }
  inline uint32_t minutes_1_get() { return this->get_field(RTC_ALARM_MINUTES_1_BIT, RTC_ALARM_MINUTES_1_WIDTH); }
  inline void hours_0_set(uint32_t value) { this->set_field(value, RTC_ALARM_HOURS_0_BIT, RTC_ALARM_HOURS_0_WIDTH); }
  inline uint32_t hours_0_get() { return this->get_field(RTC_ALARM_HOURS_0_BIT, RTC_ALARM_HOURS_0_WIDTH); }
  inline void hours_1_set(uint32_t value) { this->set_field(value, RTC_ALARM_HOURS_1_BIT, RTC_ALARM_HOURS_1_WIDTH); }
  inline uint32_t hours_1_get() { return this->get_field(RTC_ALARM_HOURS_1_BIT, RTC_ALARM_HOURS_1_WIDTH); }
  inline void enable_set(uint32_t value) { this->set_field(value, RTC_ALARM_ENABLE_BIT, RTC_ALARM_ENABLE_WIDTH); }
  inline uint32_t enable_get() { return this->get_field(RTC_ALARM_ENABLE_BIT, RTC_ALARM_ENABLE_WIDTH); }
};

class vp_rtc_timer : public vp::reg_32
{
public:
  inline void target_set(uint32_t value) { this->set_field(value, RTC_TIMER_TARGET_BIT, RTC_TIMER_TARGET_WIDTH); }
  inline uint32_t target_get() { return this->get_field(RTC_TIMER_TARGET_BIT, RTC_TIMER_TARGET_WIDTH); }
  inline void retrig_set(uint32_t value) { this->set_field(value, RTC_TIMER_RETRIG_BIT, RTC_TIMER_RETRIG_WIDTH); }
  inline uint32_t retrig_get() { return this->get_field(RTC_TIMER_RETRIG_BIT, RTC_TIMER_RETRIG_WIDTH); }
  inline void enable_set(uint32_t value) { this->set_field(value, RTC_TIMER_ENABLE_BIT, RTC_TIMER_ENABLE_WIDTH); }
  inline uint32_t enable_get() { return this->get_field(RTC_TIMER_ENABLE_BIT, RTC_TIMER_ENABLE_WIDTH); }
};

class vp_rtc_date : public vp::reg_32
{
public:
  inline void day_0_set(uint32_t value) { this->set_field(value, RTC_DATE_DAY_0_BIT, RTC_DATE_DAY_0_WIDTH); }
  inline uint32_t day_0_get() { return this->get_field(RTC_DATE_DAY_0_BIT, RTC_DATE_DAY_0_WIDTH); }
  inline void day_1_set(uint32_t value) { this->set_field(value, RTC_DATE_DAY_1_BIT, RTC_DATE_DAY_1_WIDTH); }
  inline uint32_t day_1_get() { return this->get_field(RTC_DATE_DAY_1_BIT, RTC_DATE_DAY_1_WIDTH); }
  inline void month_0_set(uint32_t value) { this->set_field(value, RTC_DATE_MONTH_0_BIT, RTC_DATE_MONTH_0_WIDTH); }
  inline uint32_t month_0_get() { return this->get_field(RTC_DATE_MONTH_0_BIT, RTC_DATE_MONTH_0_WIDTH); }
  inline void month_1_set(uint32_t value) { this->set_field(value, RTC_DATE_MONTH_1_BIT, RTC_DATE_MONTH_1_WIDTH); }
  inline uint32_t month_1_get() { return this->get_field(RTC_DATE_MONTH_1_BIT, RTC_DATE_MONTH_1_WIDTH); }
  inline void year_0_set(uint32_t value) { this->set_field(value, RTC_DATE_YEAR_0_BIT, RTC_DATE_YEAR_0_WIDTH); }
  inline uint32_t year_0_get() { return this->get_field(RTC_DATE_YEAR_0_BIT, RTC_DATE_YEAR_0_WIDTH); }
  inline void year_1_set(uint32_t value) { this->set_field(value, RTC_DATE_YEAR_1_BIT, RTC_DATE_YEAR_1_WIDTH); }
  inline uint32_t year_1_get() { return this->get_field(RTC_DATE_YEAR_1_BIT, RTC_DATE_YEAR_1_WIDTH); }
};

#endif



//
// REGISTERS GLOBAL STRUCT
//

#ifndef LANGUAGE_ASSEMBLY

typedef struct {
  unsigned int clock           ; // Clock register
  unsigned int alarm           ; // Alarm register
  unsigned int timer           ; // Timer register
  unsigned int date            ; // Date register
} __attribute__((packed)) rtc_rtc_t;

#endif



//
// REGISTERS ACCESS FUNCTIONS
//

#ifndef LANGUAGE_ASSEMBLY

static inline uint32_t rtc_clock_get(uint32_t base) { return ARCHI_READ(base, RTC_CLOCK_OFFSET); }
static inline void rtc_clock_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, RTC_CLOCK_OFFSET, value); }

static inline uint32_t rtc_alarm_get(uint32_t base) { return ARCHI_READ(base, RTC_ALARM_OFFSET); }
static inline void rtc_alarm_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, RTC_ALARM_OFFSET, value); }

static inline uint32_t rtc_timer_get(uint32_t base) { return ARCHI_READ(base, RTC_TIMER_OFFSET); }
static inline void rtc_timer_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, RTC_TIMER_OFFSET, value); }

static inline uint32_t rtc_date_get(uint32_t base) { return ARCHI_READ(base, RTC_DATE_OFFSET); }
static inline void rtc_date_set(uint32_t base, uint32_t value) { ARCHI_WRITE(base, RTC_DATE_OFFSET, value); }

#endif



//
// REGISTERS FIELDS MACROS
//

#ifndef LANGUAGE_ASSEMBLY

#define RTC_CLOCK_SECONDS_0_GET(value)                     (ARCHI_BEXTRACTU((value),4,0))
#define RTC_CLOCK_SECONDS_0_GETS(value)                    (ARCHI_BEXTRACT((value),4,0))
#define RTC_CLOCK_SECONDS_0_SET(value,field)               (ARCHI_BINSERT((value),(field),4,0))
#define RTC_CLOCK_SECONDS_0(val)                           ((val) << 0)

#define RTC_CLOCK_SECONDS_1_GET(value)                     (ARCHI_BEXTRACTU((value),4,4))
#define RTC_CLOCK_SECONDS_1_GETS(value)                    (ARCHI_BEXTRACT((value),4,4))
#define RTC_CLOCK_SECONDS_1_SET(value,field)               (ARCHI_BINSERT((value),(field),4,4))
#define RTC_CLOCK_SECONDS_1(val)                           ((val) << 4)

#define RTC_CLOCK_MINUTES_0_GET(value)                     (ARCHI_BEXTRACTU((value),4,8))
#define RTC_CLOCK_MINUTES_0_GETS(value)                    (ARCHI_BEXTRACT((value),4,8))
#define RTC_CLOCK_MINUTES_0_SET(value,field)               (ARCHI_BINSERT((value),(field),4,8))
#define RTC_CLOCK_MINUTES_0(val)                           ((val) << 8)

#define RTC_CLOCK_MINUTES_1_GET(value)                     (ARCHI_BEXTRACTU((value),4,12))
#define RTC_CLOCK_MINUTES_1_GETS(value)                    (ARCHI_BEXTRACT((value),4,12))
#define RTC_CLOCK_MINUTES_1_SET(value,field)               (ARCHI_BINSERT((value),(field),4,12))
#define RTC_CLOCK_MINUTES_1(val)                           ((val) << 12)

#define RTC_CLOCK_HOURS_0_GET(value)                       (ARCHI_BEXTRACTU((value),4,16))
#define RTC_CLOCK_HOURS_0_GETS(value)                      (ARCHI_BEXTRACT((value),4,16))
#define RTC_CLOCK_HOURS_0_SET(value,field)                 (ARCHI_BINSERT((value),(field),4,16))
#define RTC_CLOCK_HOURS_0(val)                             ((val) << 16)

#define RTC_CLOCK_HOURS_1_GET(value)                       (ARCHI_BEXTRACTU((value),2,20))
#define RTC_CLOCK_HOURS_1_GETS(value)                      (ARCHI_BEXTRACT((value),2,20))
#define RTC_CLOCK_HOURS_1_SET(value,field)                 (ARCHI_BINSERT((value),(field),2,20))
#define RTC_CLOCK_HOURS_1(val)                             ((val) << 20)

#define RTC_CLOCK_INIT_SEC_COUNT_GET(value)                (ARCHI_BEXTRACTU((value),10,22))
#define RTC_CLOCK_INIT_SEC_COUNT_GETS(value)               (ARCHI_BEXTRACT((value),10,22))
#define RTC_CLOCK_INIT_SEC_COUNT_SET(value,field)          (ARCHI_BINSERT((value),(field),10,22))
#define RTC_CLOCK_INIT_SEC_COUNT(val)                      ((val) << 22)

#define RTC_ALARM_SECONDS_0_GET(value)                     (ARCHI_BEXTRACTU((value),8,0))
#define RTC_ALARM_SECONDS_0_GETS(value)                    (ARCHI_BEXTRACT((value),8,0))
#define RTC_ALARM_SECONDS_0_SET(value,field)               (ARCHI_BINSERT((value),(field),8,0))
#define RTC_ALARM_SECONDS_0(val)                           ((val) << 0)

#define RTC_ALARM_SECONDS_1_GET(value)                     (ARCHI_BEXTRACTU((value),8,0))
#define RTC_ALARM_SECONDS_1_GETS(value)                    (ARCHI_BEXTRACT((value),8,0))
#define RTC_ALARM_SECONDS_1_SET(value,field)               (ARCHI_BINSERT((value),(field),8,0))
#define RTC_ALARM_SECONDS_1(val)                           ((val) << 0)

#define RTC_ALARM_MINUTES_0_GET(value)                     (ARCHI_BEXTRACTU((value),8,8))
#define RTC_ALARM_MINUTES_0_GETS(value)                    (ARCHI_BEXTRACT((value),8,8))
#define RTC_ALARM_MINUTES_0_SET(value,field)               (ARCHI_BINSERT((value),(field),8,8))
#define RTC_ALARM_MINUTES_0(val)                           ((val) << 8)

#define RTC_ALARM_MINUTES_1_GET(value)                     (ARCHI_BEXTRACTU((value),8,8))
#define RTC_ALARM_MINUTES_1_GETS(value)                    (ARCHI_BEXTRACT((value),8,8))
#define RTC_ALARM_MINUTES_1_SET(value,field)               (ARCHI_BINSERT((value),(field),8,8))
#define RTC_ALARM_MINUTES_1(val)                           ((val) << 8)

#define RTC_ALARM_HOURS_0_GET(value)                       (ARCHI_BEXTRACTU((value),6,16))
#define RTC_ALARM_HOURS_0_GETS(value)                      (ARCHI_BEXTRACT((value),6,16))
#define RTC_ALARM_HOURS_0_SET(value,field)                 (ARCHI_BINSERT((value),(field),6,16))
#define RTC_ALARM_HOURS_0(val)                             ((val) << 16)

#define RTC_ALARM_HOURS_1_GET(value)                       (ARCHI_BEXTRACTU((value),6,16))
#define RTC_ALARM_HOURS_1_GETS(value)                      (ARCHI_BEXTRACT((value),6,16))
#define RTC_ALARM_HOURS_1_SET(value,field)                 (ARCHI_BINSERT((value),(field),6,16))
#define RTC_ALARM_HOURS_1(val)                             ((val) << 16)

#define RTC_ALARM_ENABLE_GET(value)                        (ARCHI_BEXTRACTU((value),1,31))
#define RTC_ALARM_ENABLE_GETS(value)                       (ARCHI_BEXTRACT((value),1,31))
#define RTC_ALARM_ENABLE_SET(value,field)                  (ARCHI_BINSERT((value),(field),1,31))
#define RTC_ALARM_ENABLE(val)                              ((val) << 31)

#define RTC_TIMER_TARGET_GET(value)                        (ARCHI_BEXTRACTU((value),17,0))
#define RTC_TIMER_TARGET_GETS(value)                       (ARCHI_BEXTRACT((value),17,0))
#define RTC_TIMER_TARGET_SET(value,field)                  (ARCHI_BINSERT((value),(field),17,0))
#define RTC_TIMER_TARGET(val)                              ((val) << 0)

#define RTC_TIMER_RETRIG_GET(value)                        (ARCHI_BEXTRACTU((value),1,30))
#define RTC_TIMER_RETRIG_GETS(value)                       (ARCHI_BEXTRACT((value),1,30))
#define RTC_TIMER_RETRIG_SET(value,field)                  (ARCHI_BINSERT((value),(field),1,30))
#define RTC_TIMER_RETRIG(val)                              ((val) << 30)

#define RTC_TIMER_ENABLE_GET(value)                        (ARCHI_BEXTRACTU((value),1,31))
#define RTC_TIMER_ENABLE_GETS(value)                       (ARCHI_BEXTRACT((value),1,31))
#define RTC_TIMER_ENABLE_SET(value,field)                  (ARCHI_BINSERT((value),(field),1,31))
#define RTC_TIMER_ENABLE(val)                              ((val) << 31)

#define RTC_DATE_DAY_0_GET(value)                          (ARCHI_BEXTRACTU((value),6,0))
#define RTC_DATE_DAY_0_GETS(value)                         (ARCHI_BEXTRACT((value),6,0))
#define RTC_DATE_DAY_0_SET(value,field)                    (ARCHI_BINSERT((value),(field),6,0))
#define RTC_DATE_DAY_0(val)                                ((val) << 0)

#define RTC_DATE_DAY_1_GET(value)                          (ARCHI_BEXTRACTU((value),6,0))
#define RTC_DATE_DAY_1_GETS(value)                         (ARCHI_BEXTRACT((value),6,0))
#define RTC_DATE_DAY_1_SET(value,field)                    (ARCHI_BINSERT((value),(field),6,0))
#define RTC_DATE_DAY_1(val)                                ((val) << 0)

#define RTC_DATE_MONTH_0_GET(value)                        (ARCHI_BEXTRACTU((value),5,8))
#define RTC_DATE_MONTH_0_GETS(value)                       (ARCHI_BEXTRACT((value),5,8))
#define RTC_DATE_MONTH_0_SET(value,field)                  (ARCHI_BINSERT((value),(field),5,8))
#define RTC_DATE_MONTH_0(val)                              ((val) << 8)

#define RTC_DATE_MONTH_1_GET(value)                        (ARCHI_BEXTRACTU((value),5,8))
#define RTC_DATE_MONTH_1_GETS(value)                       (ARCHI_BEXTRACT((value),5,8))
#define RTC_DATE_MONTH_1_SET(value,field)                  (ARCHI_BINSERT((value),(field),5,8))
#define RTC_DATE_MONTH_1(val)                              ((val) << 8)

#define RTC_DATE_YEAR_0_GET(value)                         (ARCHI_BEXTRACTU((value),14,16))
#define RTC_DATE_YEAR_0_GETS(value)                        (ARCHI_BEXTRACT((value),14,16))
#define RTC_DATE_YEAR_0_SET(value,field)                   (ARCHI_BINSERT((value),(field),14,16))
#define RTC_DATE_YEAR_0(val)                               ((val) << 16)

#define RTC_DATE_YEAR_1_GET(value)                         (ARCHI_BEXTRACTU((value),14,16))
#define RTC_DATE_YEAR_1_GETS(value)                        (ARCHI_BEXTRACT((value),14,16))
#define RTC_DATE_YEAR_1_SET(value,field)                   (ARCHI_BINSERT((value),(field),14,16))
#define RTC_DATE_YEAR_1(val)                               ((val) << 16)

#endif

#endif
