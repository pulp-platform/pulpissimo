/*
 * Copyright (C) 2017 ETH Zurich and University of Bologna
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

#ifndef __HAL_RAB_V1_H__
#define __HAL_RAB_V1_H__

#include "archi-host/phys_addr.h"
#include "archi-host/virt_addr.h"

#include "archi/rab/rab_v1.h"

#include "hal/pulp.h"   // ARCHI_RAB_CFG_ADDR
#include "hal/utils.h"  // BIT_* functions

#include <errno.h>      // ENOENT
#include <stdint.h>     // for uint8_t

//#ifndef LOG_LVL_RAB_CFG
//    #define LOG_LVL_RAB_CFG LOG_ERR
//#endif

// This struct represents the L1 TLB entry information for PULP.
typedef struct {
    virt_addr_t va_start, va_end;
    phys_addr_t offset;
    uint8_t     flags;
} rab_cfg_val_t;

typedef uint8_t rab_l2_set_t;

// This struct represents the L2 TLB entry information for PULP.
typedef struct {
    virt_pfn_t      virt_pfn;
    phys_pfn_t      phys_pfn;
    uint8_t         flags;
    rab_l2_set_t    set;
} rab_cfg_l2_val_t;

// This struct represents a miss in the RAB Miss Hardware FIFO.
typedef struct rab_miss_t {
    virt_addr_t   virt_addr;
    int           core_id;
    int           cluster_id;
    int           intra_cluster_id;
    uint8_t       is_prefetch;
} rab_miss_t;

/** @name Main RAB TLB entry configuration functions
 *
 * @{
 */

/** Configure a RAB L1 TLB slice.

  \param    begin           First virtual address to be mapped.
  \param    end             Address of the next byte after the last virtual address to be mapped.
  \param    phys_addr       Pointer to the physical address to which the RAB slice shall map.
  \param    rab_slice       Pointer to the RAB slice to be configured.
  \param    rdonly          Defines memory accesses through the new slice as read-only (if not 0) or
                            as read-write (if 0).
  \param    cache_coherent  Defines memory accesses through the new slice as coherent with the
                            caches of the host (if not 0) or as not necessarily coherent (if 0).

  \return   0 if the RAB slice has been configured successfully; negative value with an errno on
            errors.
*/
static inline int config_rab_slice(const virt_addr_t begin, const virt_addr_t end,
        const phys_addr_t* const phys_addr, rab_cfg_t* const rab_slice,
        const unsigned char rdonly, const unsigned char cache_coherent);

/** Configure a RAB L2 TLB entry.

  \param    virt_pfn        Virtual page frame number to be mapped.
  \param    phys_addr       Physical page frame number to which the L2 TLB entry shall map.
  \param    l2_set          Index of the set in which the L2 TLB entry shall be configured.
  \param    l2_set_off      Offset of the L2 TLB entry within the set to be configured.
  \param    rdonly          Defines memory accesses through the new slice as read-only (if not 0) or
                            as read-write (if 0).
  \param    cache_coherent  Defines memory accesses through the new slice as coherent with the
                            caches of the host (if not 0) or as not necessarily coherent (if 0).

  \return   0 if the RAB L2 TLB entry has been configured successfully; negative value with an errno
            on errors.
*/
static inline int config_rab_l2_entry(const virt_pfn_t virt_pfn,
        const phys_pfn_t phys_pfn, const rab_l2_set_t set, const unsigned char entry,
        const unsigned char rdonly, const unsigned char cache_coherent);

//!@}

/** @name RAB TLB entry inspection functions
 *
 * @{
 */

/** Print a RAB L1 TLB configuration value to standard output.

  \param    cfg_val Pointer to the struct on PULP containing the configuration.

  \return   0 if printing was successful; negative value with an errno on errors.
*/
int print_rab_cfg_val(const rab_cfg_val_t* const cfg_val);

/** Print the current RAB L1 TLB configuration.

  \param    begin       Pointer to the first RAB slice to be printed.
  \param    end         Pointer to the RAB slice after the last to be printed.
  \param    only_valid  If 0, all RAB slices are printed; otherwise, only valid slices are printed.

  \return   0 if the RAB configuration was printed successfully; negative value with an errno on
            errors.
*/
int print_rab_cfg(const rab_cfg_t* const begin, const rab_cfg_t* const end,
        const unsigned only_valid);

/** Print a RAB L2 TLB configuration value to standard output.

  \param    varam_ptr Pointer to the virtual address RAM of the L2 TLB entry to be configured.
  \param    param_ptr Pointer to the physical address RAM of the L2 TLB entry to be configured.
  \param    cfg_val   Pointer to the struct on PULP containing the configuration.

  \return   0 if printing was successful; negative value with an errno on errors.
*/
int print_rab_cfg_l2_val(const rab_cfg_l2_varam_t* const varam_ptr,
        const rab_cfg_l2_param_t* const param_ptr, const rab_cfg_l2_val_t* const cfg_val,
        const unsigned char entry);

//!@}

/** @name Low-level RAB L1 and L2 TLB entry inspection and manipulation functions
 *
 * @{
 */

/** Read a RAB L1 TLB configuration value to PULP.

  \param    dst Pointer to the PULP struct in which the configuration shall be stored.
  \param    src Pointer to the RAB configuration entry.

  \return   0 if the RAB configuration value has been read successfully; negative value with an
            errno on errors.
*/
static inline int read_rab_cfg_val(rab_cfg_val_t* const dst, const rab_cfg_t* const src);

/** Write a RAB L1 TLB configuration value from PULP.

  \param    dst Pointer to the RAB configuration entry.
  \param    src Pointer to the PULP struct from which the configuration shall be read.

  \return   0 if the RAB configuration value has been written successfully; negative value with an
            errno on errors.
*/
static inline int write_rab_cfg_val(rab_cfg_t* const dst, const rab_cfg_val_t* const src);

/** Disable a RAB L1 TLB slice.

  \param    rab_slice   Pointer to the RAB slice to be disabled.

  \return   0 if the RAB slice has been disabled successfully; negative value with an errno on
            errors.
*/
static inline int disable_rab_slice(rab_cfg_t* const rab_slice);

/** Determine if a RAB L1 TLB slice is enabled.

  \param    cfg_val     Pointer to the PULP representation of the RAB slice to be examined.

  \return   0 if the RAB slice is disabled; 1 if the RAB slice is enabled; negative value with an
            errno on errors.
*/
static inline int rab_slice_is_enabled(const rab_cfg_val_t* const cfg_val);

/** Determine if a virtual address is in the address range of a RAB L1 TLB slice.

  \param    cfg_val     Pointer to the PULP representation of the RAB slice to be examined.
  \param    virt_addr   Virtual address to check for inclusion.

  \return   0 if the virtual address is not in the address range of the RAB slice; 1 if it is;
            negative value with an errno on errors.
*/
static inline int rab_slice_contains_virt_addr(const rab_cfg_val_t* const cfg_val,
        const virt_addr_t virt_addr);

/** Determine the L2 TLB set index of a virtual page frame number.

  \param    virt_pfn    Virtual page frame number to determine the set index of.

  \return   The L2 set index.
*/
static inline rab_l2_set_t page_set(const virt_pfn_t virt_pfn);

/** Write a RAB L2 TLB entry from PULP.

  \param    varam_ptr Pointer to the virtual address RAM of the L2 TLB entry to be configured.
  \param    param_ptr Pointer to the physical address RAM of the L2 TLB entry to be configured.
  \param    src       Pointer to the PULP struct from which the configuration shall be read.

  \return   0 if the RAB configuration value has been written successfully; negative value with an
            errno on errors.
*/
static inline int write_rab_cfg_l2_val(rab_cfg_l2_varam_t* const varam_ptr,
        rab_cfg_l2_param_t* const param_ptr, rab_cfg_l2_val_t * const src);

//!@}

/** @name RAB Miss Hardware FIFO interface functions
 *
 * @{
 */

/** Get miss from RAB Miss FIFO.

  \param    rab_miss    Pointer through which the RAB miss shall be returned.

  \return   0 on success; negative value with an errno on errors.  -ENOENT is returned in case the
            FIFO is empty; in this case, `rab_miss` is not changed.
*/
static inline int get_rab_miss(rab_miss_t* const rab_miss);

//!@}

/// @cond IMPLEM

int read_rab_cfg_val(rab_cfg_val_t* const dst, const rab_cfg_t* const src)
{
    dst->va_start   = src->word[0];
    dst->va_end     = src->word[2];
    copy_phys_addr((phys_addr_t*)&(dst->offset), (phys_addr_t*)&(src->word[4]));
    dst->flags      = (uint8_t)(src->word[6] & 0xFF);

    return 0;
}

int write_rab_cfg_val(rab_cfg_t* const dst, const rab_cfg_val_t* const src)
{
    // Disable slice before writing the new configuration.
    dst->word[6]    = 0;

    dst->word[0]    = src->va_start;
    dst->word[2]    = src->va_end;
    copy_phys_addr((phys_addr_t*)&(dst->word[4]), (phys_addr_t*)&(src->offset));
    dst->word[6]    = (0x000000FF) & (uint32_t)(src->flags);

    return 0;
}

int config_rab_slice(const virt_addr_t begin, const virt_addr_t end,
        const phys_addr_t* const phys_addr, rab_cfg_t* const rab_slice,
        const unsigned char rdonly, const unsigned char cache_coherent)
{
    int ret = 0;

    rab_cfg_val_t cfg = {
        .va_start   = begin,
        .va_end     = end-1,
        .flags      = RAB_CFG_FLAG_EN
                        | RAB_CFG_FLAG_RDEN
                        | (rdonly ? 0 : RAB_CFG_FLAG_WREN)
                        | (cache_coherent ? RAB_CFG_FLAG_COHERENT : 0)
    };
    ret = copy_phys_addr(&(cfg.offset), phys_addr);
    if (ret < 0)
        return ret;

    ret = write_rab_cfg_val(rab_slice, &cfg);
    if (ret < 0)
        return ret;

    //#if LOG_LVL_RAB_CFG >= LOG_DEBUG
    //    printf("[DD] Configured RAB slice:\n");
    //    print_rab_cfg_val(&cfg);
    //    printf("\n");
    //#endif

    return 0;
}

int disable_rab_slice(rab_cfg_t* const rab_slice)
{
    rab_slice->word[6] = 0;
    return 0;
}

int rab_slice_is_enabled(const rab_cfg_val_t* const cfg_val)
{
    return (cfg_val->flags & RAB_CFG_FLAG_EN) == RAB_CFG_FLAG_EN;
}

int rab_slice_contains_virt_addr(const rab_cfg_val_t* const cfg_val,
        const virt_addr_t virt_addr)
{
    return (virt_addr >= cfg_val->va_start) && (virt_addr <= cfg_val->va_end);
}

rab_l2_set_t page_set(const virt_pfn_t virt_pfn)
{
    return (rab_l2_set_t)(virt_pfn & RAB_CFG_L2_SET_PFN_MASK);
}

int write_rab_cfg_l2_val(rab_cfg_l2_varam_t* const varam_ptr,
        rab_cfg_l2_param_t* const param_ptr, rab_cfg_l2_val_t * const src)
{
    // Disable slice before writing the new configuration.
    *varam_ptr = 0;

    *param_ptr = src->phys_pfn;
    *varam_ptr = (src->virt_pfn << 4) | (uint32_t)(src->flags);

    return 0;
}

int config_rab_l2_entry(const virt_pfn_t virt_pfn,
        const phys_pfn_t phys_pfn, const rab_l2_set_t set, const unsigned char entry,
        const unsigned char rdonly, const unsigned char cache_coherent)
{
    int ret = 0;

    rab_cfg_l2_val_t cfg = {
        .virt_pfn   = virt_pfn,
        .phys_pfn   = phys_pfn,
        .flags      = RAB_CFG_FLAG_EN
                        | RAB_CFG_FLAG_RDEN
                        | (rdonly ? 0 : RAB_CFG_FLAG_WREN)
                        | (cache_coherent ? RAB_CFG_FLAG_COHERENT : 0),
        .set        = set
    };

    rab_cfg_l2_varam_t* const varam_ptr = RAB_CFG_L2_VARAM_PTR(set, entry);
    rab_cfg_l2_param_t* const param_ptr = RAB_CFG_L2_PARAM_PTR(set, entry);

    ret = write_rab_cfg_l2_val(varam_ptr, param_ptr, &cfg);
    if (ret < 0)
        return ret;

    //#if ( (LOG_LVL_RAB_CFG >= LOG_DEBUG) || (LOG_LVL_VMM >= LOG_TRACE) )
    //    printf("[DD] Configured RAB L2 TLB entry:\n");
    //    print_rab_cfg_l2_val(varam_ptr, param_ptr, &cfg, entry);
    //    printf("\n");
    //#endif

    return 0;
}

int get_rab_miss(rab_miss_t* const rab_miss)
{
    int ret = 0;

    const uint32_t meta_fifo_val = *(volatile uint32_t*)((unsigned)ARCHI_RAB_CFG_ADDR + 8);
    if (BIT_GET(meta_fifo_val, 31, 1) != 0)
        return -ENOENT; // FIFO is empty.

    rab_miss->virt_addr = *(volatile virt_addr_t*)(ARCHI_RAB_CFG_ADDR);

    rab_miss->core_id = BIT_GET(meta_fifo_val, 0, AXI_ID_WIDTH_CORE);
    rab_miss->intra_cluster_id = BIT_GET(meta_fifo_val, AXI_ID_WIDTH_CORE, AXI_ID_WIDTH_CLUSTER);
    rab_miss->cluster_id
            = BIT_GET(meta_fifo_val, AXI_ID_WIDTH_CLUSTER + AXI_ID_WIDTH_CORE, AXI_ID_WIDTH_SOC);

    const uint32_t axi_user
            = BIT_GET(meta_fifo_val, AXI_ID_WIDTH + RAB_PORT_ID_WIDTH, AXI_USER_WIDTH);
    rab_miss->is_prefetch = (axi_user == BIT_MASK_LSBS(AXI_USER_WIDTH) ? 1 : 0);

    return 0;
}

/// @endcond

#endif
