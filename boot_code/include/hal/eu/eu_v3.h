/*
 * Copyright (C) 2018 ETH Zurich and University of Bologna
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

#ifndef __HAL_EU_EU_V3_H__
#define __HAL_EU_EU_V3_H__

#include "archi/eu/eu_v3.h"
#include "archi/pulp.h"
#include "hal/pulp_io.h"



/** @name Event management
 *  The following function can be used for selecting which events can wake-up the core, put the core the sleep, clear events and so on.
 */
/**@{*/

/** Clock-gated load. 
 * On architectures that support it, this executes the special p.elw instruction which is used to put the core in idle mode until it receives an event.
  On other architectures, it executes a classic read which has the same effect but does not handle correctly interrupts while the core is sleeping.
  \param base   The base address of the event unit.
  \param offset The offset in the event unit where to load from. Depending on this offset, this will trigger different behaviors (barrier, wait, wait&clear, etc).
  \return       The loaded value, after the core has been waken-up. This value depends on the feature which is accessed.
  */
#if defined(__OPTIMIZE__)
static inline unsigned int evt_read32(unsigned int base, unsigned int offset)
{
  unsigned int value;
  #if !defined(__LLVM__) && ((defined(OR1K_VERSION) && OR1K_VERSION >= 5) || (defined(RISCV_VERSION) && RISCV_VERSION >= 4))
  value = __builtin_pulp_event_unit_read((int *)base, offset);
  #else
  __asm__ __volatile__ ("" : : : "memory");
  value = pulp_read32(base + offset);
  __asm__ __volatile__ ("" : : : "memory");
  #endif
  return value;
}
#else
#define evt_read32(base,offset) \
  ({ \
    __builtin_pulp_event_unit_read((int *)base, offset); \
  })
#endif

/** Get event status. 
  Return the value of the event status register. This register contains one bit per event, 1 means the event is set. Note that this register is actually used
  as a status register for both events and interrupts, so clearing one will clear the other. This register is a buffer, which means if an event is received
  while its bit is already at 1, the event is somehow lost as the bit stays at 1. Thus events should be used as Linux signals.
  \return       The content of the status register.
  */
static inline unsigned int eu_evt_status()
{
  return pulp_read32(ARCHI_EU_DEMUX_ADDR + EU_CORE_BUFFER);
}

/** Get active events. 
  Same as eu_evt_status, but the content of the status register is ANDed with the content of the event mask register so that
  only relevant events (that can wake-up the core) are shown. It can for example be used to know which events must be handled
  after a core wake-up as the core has been waken-up due to one of them.
  \return       The content of the status register ANDed with the event mask register.
  */
static inline unsigned int eu_evt_statusMasked()
{
  return pulp_read32(ARCHI_EU_DEMUX_ADDR + EU_CORE_BUFFER_MASKED);
}

/** Clear some bits of the event status register. 
  This allows clearing events after they have been received so that they do not prevent the core from sleeping anymore.  
  \param evtMask Bits to be cleared. 1 means the bit must be cleared, 0 it should remain the same.
  */
static inline void eu_evt_clr(unsigned int evtMask)
{
  pulp_write32(ARCHI_EU_DEMUX_ADDR + EU_CORE_BUFFER_CLEAR, evtMask);
}

/** Modify the event mask. 
  The event mask tells the event unit which events can wake-up the core. When the core executes the p.elw instruction it goes to sleep unless
  there is one bit which is set in both the event mask and the event status register. If the event is received while the core is already sleeping
  and the corresponding bit is set in the event mask, the core is waken-up and cannot go back to sleep until either the event mask or the event status
  register is modified (usually the bit is cleared using eu_evt_clr)
  \param evtMask Value to write to the event mask. There is 1 bit per event, 1 means it can wake-up the core, 0 it cannot
  */
static inline void eu_evt_mask(unsigned int evtMask)
{
  pulp_write32(ARCHI_EU_DEMUX_ADDR + EU_CORE_MASK, evtMask);
}

/** Set part of the event mask to 1. 
  See eu_evt_maskSet
  \param base    The address of the register
  \param evtMask Bit mask used to update the event mask. There is 1 bit per event, 1 means the corresponding bit is set in the event mask.
  */
static inline void eu_evt_maskSet_base(unsigned int base, unsigned int evtMask)
{
#if defined(__riscv__) && !defined(__LLVM__)
  // TODO riscv compiler is not able to factorize the event unit base if we use classic C code
  __asm volatile ("sw %0,%1(%2)" : : "r" (evtMask), "I" (EU_CORE_MASK_OR), "r" (base) );
#else
  pulp_write32(base + EU_CORE_MASK_OR, evtMask);
#endif
}

/** Set part of the event mask to 1. 
  This is similar to eu_evt_mask but for each bit at 1 in the new value, the corresponding bit is set in the event mask and the others remain the same.
  This is useful when the mask must be updated before waiting for a specific event without modifying the other events (this saves a few instructions)
  \param evtMask Bit mask used to update the event mask. There is 1 bit per event, 1 means the corresponding bit is set in the event mask.
  */
static inline void eu_evt_maskSet(unsigned int evtMask)
{
  eu_evt_maskSet_base(ARCHI_EU_DEMUX_ADDR, evtMask);
}

/** Set part of the event mask to 0. 
  This is the opposite of eu_evt_maskSet. For each bit at 1 in the new value, the corresponding bit is set to 0 in the event mask and the others remain the same.
  \param evtMask Bit mask used to update the event mask. There is 1 bit per event, 1 means the corresponding bit is cleared in the event mask.
  */
static inline void eu_evt_maskClr(unsigned int evtMask)
{
#if defined(__riscv__) && !defined(__LLVM__)
  // TODO riscv compiler is not able to factorize the event unit base if we use classic C code
  __asm volatile ("sw %0,%1(%2)" : : "r" (evtMask), "I" (EU_CORE_MASK_AND), "r" (ARCHI_EU_DEMUX_ADDR) );
#else
  pulp_write32(ARCHI_EU_DEMUX_ADDR + EU_CORE_MASK_AND, evtMask);
#endif
}

/** Put the core to sleep mode until it receives an event
  The core goes to sleep until there is one bit at 1 in both the event status register and the event mask register. If it is already the case, when this function is called,
  the core does not go to sleep and this function returns immediately.
  */
static inline unsigned int eu_evt_wait()
{
  return evt_read32(ARCHI_EU_DEMUX_ADDR, EU_CORE_EVENT_WAIT);
}

static inline unsigned int eu_evt_wait_noreplay()
{
  return pulp_read32(ARCHI_EU_DEMUX_ADDR + EU_CORE_EVENT_WAIT);
}

static inline unsigned int eu_wait_for_interrupt()
{
  return pulp_read32(ARCHI_EU_DEMUX_ADDR + EU_CORE_EVENT_WAIT);
}

/** Put the core to sleep mode until it receives an event and clears the active events
  This is similar to eu_evt_wait but when the core is waken-up, the active events are cleared in the status register. An event is active if its bit is at 1 in both
  the event status register and the event mask register.
  */
static inline unsigned int eu_evt_waitAndClr()
{
  return evt_read32(ARCHI_EU_DEMUX_ADDR, EU_CORE_EVENT_WAIT_CLEAR);
}

/** Modify the event mask, put the core to sleep mode until it receives an event, clears the active events and restore the mask.
  This is similar to eu_evt_waitAndClr but the events whose bit is set to 1 in the given mask, are activated in the event mask before going to sleep, and are cleared
  when the core is waken-up.
  Not that this function is using 3 instructions instead of 1 for most of other primitives, as it needs 2 instruction to set and clear the mask.
  \param evtMask Event mask used for activating and deactivating events. Each bit to 1 means the corresponding event is activated before sleeping and deactivated after.
  */
static inline unsigned int eu_evt_maskWaitAndClr(unsigned evtMask)
{
  eu_evt_maskSet(evtMask);
  unsigned int result = eu_evt_waitAndClr();
  eu_evt_maskClr(evtMask);
  return result;
}

static inline unsigned int eu_fc_evt_maskWaitAndClr(unsigned evtMask)
{
  eu_evt_maskSet(evtMask);
  unsigned int result;
  do {
    result = eu_evt_waitAndClr();
  } while (result == 0);
  eu_evt_maskClr(evtMask);
  return result;
}

//!@}




/** @name Interrupt management
 *  Functions for setting-up which IRQ can trigger an interrupt handler, clear interrupts and so on
 */
/**@{*/

static inline unsigned int eu_evt_statusIrqMasked()
{
  return pulp_read32(ARCHI_EU_DEMUX_ADDR + EU_CORE_BUFFER_IRQ_MASKED);
}

static inline void eu_irq_mask(unsigned int irqMask)
{
  pulp_write32(ARCHI_EU_DEMUX_ADDR + EU_CORE_MASK_IRQ, irqMask);
}

static inline void eu_irq_secMask(unsigned int irqMask)
{
  pulp_write32(ARCHI_EU_DEMUX_ADDR + EU_CORE_MASK_SEC_IRQ, irqMask);
}

static inline void eu_irq_maskSet_base(unsigned int base, unsigned int irqMask)
{
  pulp_write32(base + EU_CORE_MASK_IRQ_OR, irqMask);
}

static inline void eu_irq_maskSet(unsigned int irqMask)
{
  eu_irq_maskSet_base(ARCHI_EU_DEMUX_ADDR, irqMask);
}

static inline void eu_irq_maskClr(unsigned int irqMask)
{
  pulp_write32(ARCHI_EU_DEMUX_ADDR + EU_CORE_MASK_IRQ_AND, irqMask);
}

static inline void eu_irq_secMaskSet(unsigned int irqMask)
{
  pulp_write32(ARCHI_EU_DEMUX_ADDR + EU_SEC_DEMUX_OFFSET + EU_SEC_MASK_OR, irqMask);
}

static inline void eu_irq_secMaskClr(unsigned int irqMask)
{
  pulp_write32(ARCHI_EU_DEMUX_ADDR + EU_SEC_DEMUX_OFFSET + EU_SEC_MASK_AND, irqMask);
}

static inline unsigned int eu_irq_status()
{
  return pulp_read32(ARCHI_EU_DEMUX_ADDR + EU_CORE_BUFFER_IRQ_MASKED);
}

//!@}




/** @name SW event trigger.
 *  Functions for triggering SW events which can be used to wake-up cluster cores from SW.
 */
/**@{*/

static inline unsigned int eu_evt_trig_remote_addr(int event)
{
  return ARCHI_CLUSTER_PERIPHERALS_ADDR + ARCHI_EU_OFFSET + EU_SW_EVENTS_AREA_BASE + EU_CORE_TRIGG_SW_EVENT + (event << 2);
}

static inline unsigned int eu_evt_trig_cluster_addr(int cluster, int event)
{
  return ARCHI_CLUSTER_PERIPHERALS_GLOBAL_ADDR(cluster) + ARCHI_EU_OFFSET + EU_SW_EVENTS_AREA_BASE + EU_CORE_TRIGG_SW_EVENT + (event << 2);
}

#ifdef ARCHI_HAS_FC
static inline unsigned int eu_evt_trig_fc_addr(int event)
{
#ifdef ITC_VERSION
  return ARCHI_FC_ITC_ADDR + EU_SW_EVENTS_AREA_BASE + EU_CORE_TRIGG_SW_EVENT + (event << 2);
#else
  return ARCHI_FC_GLOBAL_ADDR + ARCHI_FC_PERIPHERALS_OFFSET + ARCHI_FC_EU_OFFSET + EU_SW_EVENTS_AREA_BASE + EU_CORE_TRIGG_SW_EVENT + (event << 2);
#endif
}
#endif

static inline unsigned int eu_evt_trig_addr(int event)
{
  return ARCHI_EU_DEMUX_ADDR + EU_SW_EVENTS_DEMUX_OFFSET + EU_CORE_TRIGG_SW_EVENT + (event << 2);
}

static inline void eu_evt_trig(unsigned int evtAddr, unsigned int coreSet)
{
  pulp_write32(evtAddr, coreSet);
}

static inline void eu_evt_trig_from_id(unsigned int event, unsigned int coreSet)
{
  IP_WRITE(ARCHI_EU_DEMUX_ADDR, EU_SW_EVENTS_DEMUX_OFFSET + EU_CORE_TRIGG_SW_EVENT + (event << 2), coreSet);
}

//!@}



/** @name Hardware barriers.
 *  Functions for managing the hardware barriers which can be used to implement a rendez-vous
 */

// Convert barrier ID into barrier address, that can be used more efficiently by
// subsequent operations (usually leads to only 1 lw or sw)
static inline unsigned int eu_bar_addr(int barId)
{
  return ARCHI_EU_DEMUX_ADDR + EU_BARRIER_DEMUX_OFFSET + EU_BARRIER_AREA_OFFSET_GET(barId);
}

static inline unsigned int eu_bar_id(int barAddr)
{
  return EU_BARRIER_AREA_BARRIERID_GET(barAddr);
}

// All-in-one barrier: Trigger barrier notif, wait for barrier and clear the event
// This also return the pending active events.
// Barrier event must be active for this to work
static inline unsigned int eu_bar_trig_wait_clr(unsigned int barAddr)
{
  return evt_read32(barAddr, EU_HW_BARR_TRIGGER_WAIT_CLEAR);
}

static inline void eu_bar_setup_mask(unsigned int barAddr, unsigned int coreMask, unsigned int targetMask)
{
  IP_WRITE(barAddr, EU_HW_BARR_TRIGGER_MASK, coreMask);
  IP_WRITE(barAddr, EU_HW_BARR_TARGET_MASK, targetMask);
}

static inline void eu_bar_setup(unsigned int barAddr, unsigned int coreMask)
{
  eu_bar_setup_mask(barAddr, coreMask, coreMask);
}

static inline void eu_bar_trigger(unsigned int barAddr, unsigned int mask)
{
  pulp_write32(barAddr + EU_HW_BARR_TRIGGER, mask);
}

//!@}



/** @name SoC events FIFO.
 *  Functions for managing SoC events coming from outside the cluster and pushed by the HW to the SoC event FIFO.
 */
/**@{*/

static inline unsigned int eu_soc_events_pop()
{
  return pulp_read32(ARCHI_CLUSTER_PERIPHERALS_ADDR + ARCHI_EU_OFFSET + EU_SOC_EVENTS_AREA_OFFSET + EU_SOC_EVENTS_CURRENT_EVENT);
}

#ifdef ARCHI_HAS_FC
static inline unsigned int fc_eu_soc_events_pop()
{
#ifdef ARCHI_FC_PERIPHERALS_ADDR
  return pulp_read32(ARCHI_FC_PERIPHERALS_ADDR + ARCHI_EU_OFFSET + EU_SOC_EVENTS_AREA_OFFSET + EU_SOC_EVENTS_CURRENT_EVENT);
#else
  return pulp_read32(ARCHI_SOC_PERIPHERALS_ADDR + ARCHI_EU_OFFSET + EU_SOC_EVENTS_AREA_OFFSET + EU_SOC_EVENTS_CURRENT_EVENT);
#endif
}
#endif

static inline int eu_soc_events_is_valid(unsigned int word)
{
  return (word >> EU_SOC_EVENTS_VALID_BIT) & 1;
}

static inline unsigned int eu_soc_events_get_event(unsigned int word)
{
  return word & EU_SOC_EVENTS_EVENT_MASK;
}

//!@}



/** @name Hardware mutexes.
 *  Functions for managing, locking and unlocking hardware mutexes
 */
/**@{*/

// Convert mutex ID into mutex address, that can be used more efficiently by
// subsequent operations (usually leads to only 1 lw or sw)
static inline unsigned int eu_mutex_addr(int mutexId)
{
  return ARCHI_EU_DEMUX_ADDR + EU_MUTEX_DEMUX_OFFSET + (mutexId << 2);
}

static inline void eu_mutex_lock(unsigned int mutexAddr)
{
  evt_read32(mutexAddr, 0);
}

static inline void eu_mutex_lock_from_id(unsigned int id)
{
  evt_read32(ARCHI_EU_DEMUX_ADDR, EU_MUTEX_DEMUX_OFFSET + (id << 2));
}

static inline void eu_mutex_unlock(unsigned int mutexAddr)
{
  __asm__ __volatile__ ("" : : : "memory");
  pulp_write32(mutexAddr, 0);
  __asm__ __volatile__ ("" : : : "memory");
}

static inline void eu_mutex_unlock_from_id(int id)
{
  __asm__ __volatile__ ("" : : : "memory");
  IP_WRITE(ARCHI_EU_DEMUX_ADDR, EU_MUTEX_DEMUX_OFFSET + (id<<2), 0);
  __asm__ __volatile__ ("" : : : "memory");
}

static inline void eu_mutex_init(unsigned int mutexAddr)
{
  pulp_write32(mutexAddr, 0);
}

//!@}



/** @name Hardware dispatcher.
 *  Functions for managing the hardware dispatcher, which can be used to dispatch entry points to sleeping slave cores.
 */
static inline unsigned int eu_dispatch_pop()
{
  eu_evt_maskSet(1<<PULP_DISPATCH_EVENT);
  unsigned int result = evt_read32(ARCHI_EU_DEMUX_ADDR, EU_DISPATCH_DEMUX_OFFSET + EU_DISPATCH_FIFO_ACCESS);
  eu_evt_maskClr(1<<PULP_DISPATCH_EVENT);
  return result;
}

static inline void eu_dispatch_push(unsigned value)
{
  IP_WRITE(ARCHI_EU_DEMUX_ADDR, EU_DISPATCH_DEMUX_OFFSET + EU_DISPATCH_FIFO_ACCESS, value);
}

static inline void eu_dispatch_push_base(unsigned int base, unsigned value)
{
  IP_WRITE(base, EU_DISPATCH_FIFO_ACCESS, value);
}

static inline void eu_dispatch_team_config(unsigned value)
{
  IP_WRITE(ARCHI_EU_DEMUX_ADDR, EU_DISPATCH_DEMUX_OFFSET + EU_DISPATCH_TEAM_CONFIG, value);
}

static inline void eu_dispatch_team_config_base(unsigned int base, unsigned value)
{
  IP_WRITE(base, EU_DISPATCH_TEAM_CONFIG, value);
}

static inline unsigned int eu_dispatch_get_base(unsigned int id)
{
  return ARCHI_EU_DEMUX_ADDR + EU_DISPATCH_DEMUX_OFFSET + EU_DISPATCH_AREA_OFFSET_GET(id);
}

static inline unsigned int eu_dispatch_team_config_read()
{
  return IP_READ(ARCHI_EU_DEMUX_ADDR, EU_DISPATCH_DEMUX_OFFSET + EU_DISPATCH_TEAM_CONFIG);
}

//!@}






/** @name Hardware loops (NOT YET AVAILABLE ON HW).
 *  Functions for managing the hardware loops, which can be used to dispatch a range of indexes to a core set.
 */
static inline unsigned eu_loop_addr(unsigned int id)
{
  return ARCHI_EU_DEMUX_ADDR + EU_LOOP_DEMUX_OFFSET;
}

static inline unsigned int eu_loop_getChunk(unsigned int addr)
{
  return pulp_read32(addr + EU_LOOP_CHUNK);
}

static inline unsigned int eu_loop_getStart(unsigned int addr)
{
  return pulp_read32(addr + EU_LOOP_START);
}

static inline unsigned int eu_loop_getState(unsigned int addr)
{
  return pulp_read32(addr + EU_LOOP_STATE);
}

static inline void eu_loop_setStart(unsigned int addr, unsigned int value)
{
  pulp_write32(addr + EU_LOOP_START, value);
}

static inline void eu_loop_setEnd(unsigned int addr, unsigned int value)
{
  pulp_write32(addr + EU_LOOP_END, value);
}

static inline void eu_loop_setIncr(unsigned int addr, unsigned int value)
{
  pulp_write32(addr + EU_LOOP_INCR, value);
}

static inline void eu_loop_setChunk(unsigned int addr, unsigned int value)
{
  pulp_write32(addr + EU_LOOP_CHUNK, value);
}

static inline void eu_loop_initEpoch(unsigned int addr, unsigned int coreSet)
{
  pulp_write32(addr + EU_LOOP_EPOCH, coreSet);
}

static inline unsigned int eu_loop_getSingle(unsigned int addr)
{
  return pulp_read32(addr + EU_LOOP_SINGLE);
}

//!@}

#if defined(PLP_SOC_EU_HAS_BAR) && PLP_SOC_EU_HAS_BAR == 1
/** @name SoC hardware barriers (NOT YET AVAILABLE ON HW).
 *  Functions for managing the SoC HW barriers, which can be used to implement a rendez-vous between several clusters
 */
static inline unsigned int eu_soc_bar_addr(int barId)
{
  return SOC_EVENT_UNIT_ADDR + EU_SOC_BARRIER_AREA_OFFSET + EU_SOC_BARRIER_AREA_OFFSET_GET(barId);
}

static inline unsigned int eu_soc_bar_id(int barAddr)
{
  return EU_SOC_BARRIER_AREA_BARRIERID_GET(barAddr);
}

static inline void eu_soc_bar_trig(unsigned int barAddr, int clusterMask)
{
  pulp_write32(barAddr + EU_SOC_HW_BARR_TRIGGER, clusterMask);
}

static inline void eu_soc_bar_setup(unsigned int barAddr, unsigned int clusterMask)
{
  pulp_write32(barAddr + EU_SOC_HW_BARR_TRIGGER_MASK, clusterMask);
}

//!@}
#endif



#if defined(PLP_SOC_EU_HAS_LOCK) && PLP_SOC_EU_HAS_LOCK == 1
/** @name SoC HW locks (NOT YET AVAILABLE ON HW).
 *  Functions for managing the SoC HW locks, which can be used to implement a lock between several clusters
 */
static inline unsigned int eu_soc_lock_addr(int lockId)
{
  return SOC_EVENT_UNIT_ADDR + EU_SOC_LOCK_AREA_OFFSET + EU_SOC_LOCK_AREA_OFFSET_GET(lockId);
}

static inline unsigned int eu_soc_lock_id(int lockAddr)
{
  return EU_SOC_LOCK_AREA_LOCKID_GET(lockAddr);
}

static inline void eu_soc_lock_reg(unsigned int lockAddr, int clusterId)
{
  pulp_write32(lockAddr + EU_SOC_LOCK_REG, 1 << clusterId);
}

static inline void eu_soc_lock_unreg(unsigned int lockAddr, int clusterId)
{
  pulp_write32(lockAddr + EU_SOC_LOCK_UNREG, 1 << clusterId);
}

static inline void eu_soc_lock_set(unsigned int lockAddr, unsigned int value)
{
  pulp_write32(lockAddr + EU_SOC_LOCK_VALUE, value);
}

static inline int eu_soc_lock_get(unsigned int lockAddr)
{
  return pulp_read32(lockAddr + EU_SOC_LOCK_VALUE);
}
#endif

#ifdef PULP_CKGATE_OFFSET
// TODO this is not aligned with PULP
static inline void fc_eu_trig(unsigned int event) {
  pulp_write32(0x50000000 + PULP_CKGATE_OFFSET + 0x20C, 1 << event);
}
#endif

static inline unsigned int eu_evt_getClusterBase(unsigned int coreId)
{
  return ARCHI_CLUSTER_PERIPHERALS_ADDR + ARCHI_EU_OFFSET + EU_CORE_AREA_OFFSET_GET(coreId);
}

static inline unsigned int eu_core_base(int coreId)
{
  return ARCHI_CLUSTER_PERIPHERALS_ADDR + ARCHI_EU_OFFSET + EU_CORE_AREA_SIZE * coreId;
}

//!@}


#endif
