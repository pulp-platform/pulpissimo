/*
 * Copyright (C) 2018 GreenWaves Technologies
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

#ifndef __ARCHI_RTC_H__
#define __ARCHI_RTC_H__

/*
 *  The RTC should be used through the APB interface. In this header file, there are:
 *      -   APB registers which are direct access registers, with ADDR: ( SOC_PERIPHERALS_BASE_ADDR + 0x7000 + APB_RTC_**_OFFSET)
 *      -   RTC registers which are indirect access registers. These regs should be R/W via the APB registers.
 *
 *  For distinguishing these two types of registers:
 *      -   APB registers:  All the defines are named in UPPER_CASE
 *      -   RTC registers:  All the difines are named in Initial_Capitalization
 *
 *  ARCHI_RTC_ADDR = ( SOC_PERIPHERALS_BASE_ADDR + 0x8000 )
 */


#define RTC_RTC_INT_EVENT       ARCHI_SOC_EVENT_RTC_IRQ
#define RTC_RTC_APB_EVENT       ARCHI_SOC_EVENT_RTC_APB_IRQ

//  Address of APB registers
#define APB_RTC_STAT_OFFSET                 0x00
#define APB_RTC_CTRL_OFFSET                 0x04
#define APB_RTC_DATA_OFFSET                 0x08
#define APB_RTC_IRQ_CTRL_OFFSET             0x10
#define APB_RTC_IRQ_MASK_OFFSET             0x14
#define APB_RTC_IRQ_FLAG_OFFSET             0x18

#define APB_RTC_STAT_REG_ADDR               (ARCHI_RTC_ADDR + APB_RTC_STAT_OFFSET)
#define APB_RTC_CTRL_REG_ADDR               (ARCHI_RTC_ADDR + APB_RTC_CTRL_OFFSET)
#define APB_RTC_DATA_REG_ADDR               (ARCHI_RTC_ADDR + APB_RTC_DATA_OFFSET)
#define APB_RTC_IRQ_CTRL_REG_ADDR           (ARCHI_RTC_ADDR + APB_RTC_IRQ_CTRL_OFFSET)
#define APB_RTC_IRQ_MASK_REG_ADDR           (ARCHI_RTC_ADDR + APB_RTC_IRQ_MASK_OFFSET)
#define APB_RTC_IRQ_FLAG_REG_ADDR           (ARCHI_RTC_ADDR + APB_RTC_IRQ_FLAG_OFFSET)

//  Bit field of APB registers
#define APB_RTC_NOIRQ_REQ                   0x00    //   APB_RTC_Status  [0:1]
#define APB_RTC_IRQ_REQ                     0x01    //   APB_RTC_Status  [0:1]
#define APB_RTC_READ                        0x00
#define APB_RTC_WRITE                       0x01
#define APB_IRQ_HIGH_LEVEL                  0x00    // The generated INT_APB is a high level
#define APB_IRQ_LOW_LEVEL                   0x01    // The generated INT_APB is a low level
#define APB_IRQ_HIGH_LEVEL_PULSE            0x02    // The generated INT_APB is a high level pulse with a duration of 1 CKIN cycle
#define APB_IRQ_LOW_LEVEL_PULSE             0x03    // The generated INT_APB is a low level pulse with a duration of 1 CKIN cycle
#define APB_WRITE_IRQ_MASKED                0x01    // 0x0 APB Write Operation Irq Enabled
#define APB_READ_IRQ_MASKED                 0x01    // 0x0 APB Read Operation Irq Enabled
#define APB_W_Flag                          0x02    // b'1 of APB_RTC_IRQ_FLAG_REG_ADDR
#define APB_R_Flag                          0x01    // b'0 of APB_RTC_IRQ_FLAG_REG_ADDR
#define APB_SR_MASK                         0x03

//*****************************************************
//  Address of Indirect Access Register
//*****************************************************
#define RTC_Status_Addr                     0x00
#define RTC_Ctrl_Addr                       0x01
#define RTC_Clk_Ctrl_Addr                   0x02
#define RTC_IRQ_Ctrl_Addr                   0x08
#define RTC_IRQ_Mask_Addr                   0x09
#define RTC_IRQ_Flag_Addr                   0x0A
#define RTC_Calendar_Ctrl_Addr              0x10
#define RTC_Calendar_TIME_Addr              0x12
#define RTC_Calendar_DATE_Addr              0x13
#define RTC_Alarm_Ctrl_Addr                 0x18
#define RTC_Alarm1_TIME_Addr                0x1A
#define RTC_Alarm1_DATE_Addr                0x1B
#define RTC_CntDown_Ctrl_Addr               0x20
#define RTC_CntDown1_Init_Addr              0x21
#define RTC_CntDown1_Timer_Addr             0x22
#define RTC_CKIN_DIV1_Addr                  0x28
#define RTC_Ref_Clk_Conf_Addr               0x2A
#define RTC_Test_Addr                       0x30

//  Bit field of RTC indirect Access Register
#define RTC_IRQ_REQ                         0x01    //   RTC_Status  [0:1]
#define RTC_Soft_Reset                      0x01    // 0x00: No soft reset
#define RTC_Calibration_Enable              0x01    // 0x00: Calibration disable
#define RTC_Active_Mode                     0x00
#define RTC_Standby_Mode                    0x01
#define RTC_CKOUT_Auto_Calibrated           0x01    // 0x00: CKOUT not auto calibrated
#define RTC_CKOUT_Not_Generated             0x01    // 0x00: CKOUT is generated
#define RTC_Irq_High_Level                  0x00    // The generated INT_RTC is a high level
#define RTC_Irq_Low_Level                   0x01    // The generated INT_RTC is a low level
#define RTC_Irq_High_Level_Pulse            0x02    // The generated INT_RTC is a high level pulse with a duration of 1 CKIN cycle
#define RTC_Irq_Low_Level_Pulse             0x03    // The generated INT_RTC is a low level pulse with a duration of 1 CKIN cycle
#define RTC_Calibration_Irq_Masked          0x01    // Calibration Irq Enabled
#define RTC_Timer1_Irq_Enable               0x00    // Countdown timer 1 irq enabled
#define RTC_Timer1_Irq_Masked               0x01    // Countdown timer 1 irq masked;
#define RTC_Alarm1_Irq_Enable               0x00    // Alarm 1 irq masked; When 0 Alarm 1 irq enabled
#define RTC_Alarm1_Irq_Masked               0x01    // Alarm 1 irq masked; When 0 Alarm 1 irq enabled
#define RTC_Calendar_Inactive               0x01    // 0x0: Calendar is active
#define RTC_Alarm_Rpt_Mode                  0x01    // 0x0: Single Mode
#define RTC_Alarm_ON                        0x00    // 0x0: Alarm1 is active
#define RTC_Alarm_OFF                       0x01    // 0x0: Alarm1 is active
#define RTC_CountDown1_Rpt_Mode             0x01    // 0x0: Single Mode
#define RTC_CountDown1_Active               0x00    // 0x0: Countdown 1 is active
#define RTC_CountDown1_Inactive             0x01

#define RTC_Irq_Alarm1_Flag                 0x01
#define RTC_Irq_Timer1_Flag                 0x10
#define RTC_Irq_Calibration_Flag            0x1000

#ifndef LANGUAGE_ASSEMBLY

/*  Structure for APB RTC registers  */
typedef union {
  struct {
    unsigned int apb_addr:6;           // Indirect access address, address range [0:3F]
    unsigned int pad:10;
    unsigned int apb_load:1;           /* Indirect access load bit:
                                            0: APB read operation
                                            1: APB write operation
                                       */
    unsigned int pad1:15;
  };
  unsigned int raw;
}Apb_rtc_ctrlT;

typedef union {
  struct {
    unsigned int irq_form:2;
    unsigned int pad:30;
  };
  unsigned int raw;
}Apb_irq_ctrlT;

typedef union {
  struct {
    unsigned int readMask:1;
    unsigned int writeMask:1;
    unsigned int pad:30;
  };
  unsigned int raw;
}Apb_irq_maskT;

typedef union{
    Apb_rtc_ctrlT       rtcCtrl;
    Apb_irq_ctrlT       irqCtrl;
    Apb_irq_maskT       irqMask;
    unsigned int        Raw;
}Apb_rtcT;

//=============================================================
/*  Structure for indirect access registers  */

typedef union {
  struct{
    unsigned int rtc_sb:1;
    unsigned int pad:3;
    unsigned int cal_En:1;
    unsigned int pad1:3;
    unsigned int soft_rst:1;
    unsigned int pad2:23;
  };
  unsigned int raw;
}Rtc_ctrlT;

typedef union{
  struct{
    unsigned int clkOut_sb:1;
    unsigned int pad:11;
    unsigned int div1_autoCal:1;
    unsigned int pad1:3;
    unsigned int div1_comp:5;
    unsigned int pad2:11;
  };
  unsigned int raw;
}Rtc_clk_ctrlT;

typedef union{
  struct{
    unsigned int irq_form:2;
    unsigned int pad:30;
  };
  unsigned int raw;
}Rtc_irq_ctrlT;

typedef union{
  struct{
    unsigned int alarm1_masked:1;
    unsigned int pad:3;
    unsigned int timer1_masked:1;
    unsigned int pad1:7;
    unsigned int cal_masked:1;
    unsigned int pad2:19;
  };
  unsigned int raw;
}Rtc_irq_maskT;

typedef union{
  struct{
    unsigned int calend_En:1;
    unsigned int pad:31;
  };
  unsigned int raw;
}Rtc_calend_ctrlT;

typedef union{
  struct{
    unsigned int second_0:4;
    unsigned int second_1:4;
    unsigned int minute_0:4;
    unsigned int minute_1:4;
    unsigned int hour_0:4;
    unsigned int hour_1:4;
  };
  unsigned int raw;
}Rtc_calend_timeT;

typedef union{
  struct{
    unsigned int day_0:4;
    unsigned int day_1:4;
    unsigned int month_0:4;
    unsigned int month_1:4;
    unsigned int year_0:4;
    unsigned int year_1:4;
  };
  unsigned int raw;
}Rtc_calend_dateT;

typedef union{
  struct{
    unsigned int alarm1_En:1;
    unsigned int pad:3;
    unsigned int alarm1_mode:1;
    unsigned int pad1:11;
    unsigned int alarm1_conf:4;
    unsigned int pad2:12;
  };
  unsigned int raw;
}Rtc_alarm_ctrlT;

typedef union{
  struct{
    unsigned int cntDwn1_En:1;
    unsigned int pad:3;
    unsigned int cntDwn1_mode:1;
    unsigned int pad1:27;
  };
  unsigned int raw;
}Rtc_cntDwn_ctrlT;

typedef union {
  struct{
    unsigned int divVal:16;
    unsigned int pad:16;
  };
  unsigned int raw;
}Rtc_CKIN_divT;

typedef union{
  struct{
    unsigned int refClkVal:22;
    unsigned int pad:10;
  };
  unsigned int raw;
}Rtc_ref_clkT;

typedef union{
//    unsigned int        status;
    Rtc_ctrlT           conf;
    Rtc_clk_ctrlT       clkConf;
    Rtc_irq_ctrlT       irqConf;
    Rtc_irq_maskT       irqMask;
//    unsigned int        irqFlag;
    Rtc_calend_ctrlT    calendConf;
//    unsigned int        calendTime;
//    unsigned int        calendDate;
    Rtc_alarm_ctrlT     alarmCtrl;
//    unsigned int        alarmTime;
//    unsigned int        alarmDate;
    Rtc_cntDwn_ctrlT    cntDwnCtrl;
//    unsigned int        cntDwn1InitVal;
//    unsigned int        cntDwn1Val;
    Rtc_CKIN_divT       ckinDiv;
    Rtc_ref_clkT        refClk;
    unsigned int        Raw;
}RtcT;

#endif

#endif
