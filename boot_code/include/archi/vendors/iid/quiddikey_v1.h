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

#ifndef __ARCHI_IID_QUIDDIKEY_V1_H__
#define __ARCHI_IID_QUIDDIKEY_V1_H__

// Registers offset definition
#define APB_QK_CR_OFFSET       				(0x00)
#define APB_QK_SR_OFFSET       				(0x08)
#define APB_QK_AR_OFFSET       				(0x0C)
#define APB_QK_IER_OFFSET      				(0x10)
#define APB_QK_IMR_OFFSET      				(0x14)
#define APB_QK_ISR_OFFSET      				(0x18)
#define APB_QK_KEY_DEST_OFFSET 				(0x20)
#define APB_QK_DIR_OFFSET      				(0xA0)
#define APB_QK_DOR_OFFSET      				(0xA8)
#define APB_QK_MISC_OFFSET     				(0xC0)
#define APB_QK_IF_SR_OFFSET    				(0xD0)
#define APB_QK_TEST_OFFSET     				(0xD8)
#define APB_QK_HW_RUC0_OFFSET  				(0xE0)
#define APB_QK_HW_RUC1_OFFSET  				(0xE4)
#define APB_QK_HW_SET_OFFSET   				(0xF0)
#define APB_QK_HW_INFO_OFFSET  				(0xF4)
#define APB_QK_HW_ID_OFFSET    				(0xF8)
#define APB_QK_HW_VER_OFFSET   				(0xFC)

// Registers bitfields offset, mask, value definition
// Configuration Register
#define APB_QK_CR_ZEROISE_BIT        				(0)
#define APB_QK_CR_ZEROISE_BITS       				(1)
#define APB_QK_CR_ZEROISE_MASK       				ARCHI_REG_MASK(APB_QK_CR_ZEROISE_BIT,       APB_QK_CR_ZEROISE_BITS)
#define APB_QK_CR_ZEROISE_ENA        				(1<<APB_QK_CR_ZEROISE_BIT)
#define APB_QK_CR_ZEROISE_DIS        				(0<<APB_QK_CR_ZEROISE_BIT)

#define APB_QK_CR_ENROLL_BIT         				(1)
#define APB_QK_CR_ENROLL_BITS        				(1)
#define APB_QK_CR_ENROLL_MASK        				ARCHI_REG_MASK(APB_QK_CR_ENROLL_BIT,        APB_QK_CR_ENROLL_BITS)
#define APB_QK_CR_ENROLL_ENA         			 	(1<<APB_QK_CR_ENROLL_BIT)
#define APB_QK_CR_ENROLL_DIS         			 	(0<<APB_QK_CR_ENROLL_BIT)

#define APB_QK_CR_START_BIT          				(2)
#define APB_QK_CR_START_BITS         				(1)
#define APB_QK_CR_START_MASK         				ARCHI_REG_MASK(APB_QK_CR_START_BIT,         APB_QK_CR_START_BITS)
#define APB_QK_CR_START_ENA          				(1<<APB_QK_CR_START_BIT)
#define APB_QK_CR_START_DIS          				(0<<APB_QK_CR_START_BIT)

#define APB_QK_CR_STOP_BIT           				(5)
#define APB_QK_CR_STOP_BITS          				(1)
#define APB_QK_CR_STOP_MASK          				ARCHI_REG_MASK(APB_QK_CR_STOP_BIT,          APB_QK_CR_STOP_BITS)
#define APB_QK_CR_STOP_ENA           				(1<<APB_QK_CR_STOP_BIT)
#define APB_QK_CR_STOP_DIS           				(0<<APB_QK_CR_STOP_BIT)

#define APB_QK_CR_GET_KEY_BIT        				(6)
#define APB_QK_CR_GET_KEY_BITS       				(1)
#define APB_QK_CR_GET_KEY_MASK       				ARCHI_REG_MASK(APB_QK_CR_GET_KEY_BIT,       APB_QK_CR_GET_KEY_BITS)
#define APB_QK_CR_GET_KEY_ENA        				(1<<APB_QK_CR_GET_KEY_BIT)
#define APB_QK_CR_GET_KEY_DIS        				(0<<APB_QK_CR_GET_KEY_BIT)

#define APB_QK_CR_UNWRAP_BIT         				(7)
#define APB_QK_CR_UNWRAP_BITS        				(1)
#define APB_QK_CR_UNWRAP_MASK        				ARCHI_REG_MASK(APB_QK_CR_UNWRAP_BIT,        APB_QK_CR_UNWRAP_MASK)
#define APB_QK_CR_UNWRAP_ENA         				(1<<APB_QK_CR_UNWRAP_BIT)
#define APB_QK_CR_UNWRAP_DIS         				(0<<APB_QK_CR_UNWRAP_BIT)

#define APB_QK_CR_WRAP_GEN_RAND_BIT  				(8)
#define APB_QK_CR_WRAP_GEN_RAND_BITS 				(1)
#define APB_QK_CR_WRAP_GEN_RAND_MASK 				ARCHI_REG_MASK(APB_QK_CR_WRAP_GEN_RAND_BIT, APB_QK_CR_WRAP_GEN_RAND_BITS)
#define APB_QK_CR_WRAP_GEN_RAND_ENA  				(1<<APB_QK_CR_WRAP_GEN_RAND_BIT)
#define APB_QK_CR_WRAP_GEN_RAND_DIS  				(0<<APB_QK_CR_WRAP_GEN_RAND_BIT)

#define APB_QK_CR_WRAP_BIT           				(9)
#define APB_QK_CR_WRAP_BITS          				(1)
#define APB_QK_CR_WRAP_MASK          				ARCHI_REG_MASK(APB_QK_CR_WRAP_BIT,          APB_QK_CR_WRAP_BITS)
#define APB_QK_CR_WRAP_ENA           				(1<<APB_QK_CR_WRAP_BIT)
#define APB_QK_CR_WRAP_DIS           				(0<<APB_QK_CR_WRAP_BIT)

#define APB_QK_CR_GEN_RAND_BIT       				(15)
#define APB_QK_CR_GEN_RAND_BITS      				(1)
#define APB_QK_CR_GEN_RAND_MASK      				ARCHI_REG_MASK(APB_QK_CR_GEN_RAND_BIT,      APB_QK_CR_GEN_RAND_BITS)
#define APB_QK_CR_GEN_RAND_ENA       				(1<<APB_QK_CR_GEN_RAND_BIT)
#define APB_QK_CR_GEN_RAND_DIS       				(0<<APB_QK_CR_GEN_RAND_BIT)


// Status Register
#define APB_QK_SR_BUSY_BIT       					(0)
#define APB_QK_SR_BUSY_BITS       					(1)
#define APB_QK_SR_BUSY_MASK       					ARCHI_REG_MASK(APB_QK_SR_BUSY_BIT, APB_QK_SR_BUSY_BIT)
#define APB_QK_SR_BUSY_TRUE         				(1 << APB_QK_SR_BUSY_BIT)
#define APB_QK_SR_BUSY_FALSE         				(0 << APB_QK_SR_BUSY_BIT)

#define APB_QK_SR_LAST_OP_BIT       				(1)
#define APB_QK_SR_LAST_OP_BITS       				(1)
#define APB_QK_SR_LAST_OP_MASK       				ARCHI_REG_MASK(APB_QK_SR_LAST_OP_BIT, APB_QK_SR_LAST_OP_BITS)
#define APB_QK_SR_LAST_OP_OK         				(1 << APB_QK_SR_LAST_OP_BIT)
#define APB_QK_SR_LAST_OP_FAIL         				(0 << APB_QK_SR_LAST_OP_BIT)

#define APB_QK_SR_LAST_OP_ERR_BIT       			(2)
#define APB_QK_SR_LAST_OP_ERR_BITS       			(1)
#define APB_QK_SR_LAST_OP_ERR_MASK       			ARCHI_REG_MASK(APB_QK_SR_LAST_OP_ERR_BIT, APB_QK_SR_LAST_OP_ERR_BITS)
#define APB_QK_SR_LAST_OP_ERR_FAIL         			(1 << APB_QK_SR_LAST_OP_ERR_BIT)
#define APB_QK_SR_LAST_OP_ERR_OK         			(0 << APB_QK_SR_LAST_OP_ERR_BIT)

#define APB_QK_SR_ZEROIZED_BIT       				(3)
#define APB_QK_SR_ZEROIZED_BITS       				(1)
#define APB_QK_SR_ZEROIZED_MASK       				ARCHI_REG_MASK(APB_QK_SR_ZEROIZED_BIT, APB_QK_SR_ZEROIZED_BITS)
#define APB_QK_SR_ZEROIZED_ZER_ST         			(1 << APB_QK_SR_ZEROIZED_BIT)
#define APB_QK_SR_ZEROIZED_LOCK_ST         			(0 << APB_QK_SR_ZEROIZED_BIT)

#define APB_QK_SR_REJECTED_BIT       				(4)
#define APB_QK_SR_REJECTED_BITS       				(1)
#define APB_QK_SR_REJECTED_MASK       				ARCHI_REG_MASK(APB_QK_SR_REJECTED_BIT, APB_QK_SR_REJECTED_BITS)
#define APB_QK_SR_REJECTED_REJ         				(1 << APB_QK_SR_REJECTED_BIT)
#define APB_QK_SR_REJECTED_OK         				(0 << APB_QK_SR_REJECTED_BIT)

#define APB_QK_SR_DI_REQ_BIT       				    (5)
#define APB_QK_SR_DI_REQ_BITS       				(1)
#define APB_QK_SR_DI_REQ_MASK       				ARCHI_REG_MASK(APB_QK_SR_DI_REQ_BIT, APB_QK_SR_DI_REQ_BITS)
#define APB_QK_SR_DI_REQ_REQ         				(1 << APB_QK_SR_DI_REQ_BIT)
#define APB_QK_SR_DI_REQ_NO         				(0 << APB_QK_SR_DI_REQ_BIT)

#define APB_QK_SR_DO_REQ_BIT       				    (6)
#define APB_QK_SR_DO_REQ_BITS       				(1)
#define APB_QK_SR_DO_REQ_MASK       				ARCHI_REG_MASK(APB_QK_SR_DO_REQ_BIT, APB_QK_SR_DO_REQ_BITS)
#define APB_QK_SR_DO_REQ_REQ         				(1 << APB_QK_SR_DO_REQ_BIT)
#define APB_QK_SR_DO_REQ_NO         				(0 << APB_QK_SR_DO_REQ_BIT)


// allow Register
#define APB_QK_AR_ENROLL_BIT       				    (1)
#define APB_QK_AR_ENROLL_BITS       				(1)
#define APB_QK_AR_ENROLL_MASK       				ARCHI_REG_MASK(APB_QK_AR_ENROLL_BIT, APB_QK_AR_ENROLL_BITS)
#define APB_QK_AR_ENROLL_ENA         				(1 << APB_QK_AR_ENROLL_BIT)
#define APB_QK_AR_ENROLL_DIS        				(0 << APB_QK_AR_ENROLL_BIT)

#define APB_QK_AR_START_BIT       				    (2)
#define APB_QK_AR_START_BITS       				(1)
#define APB_QK_AR_START_MASK       				ARCHI_REG_MASK(APB_QK_AR_START_BIT, APB_QK_AR_START_BITS)
#define APB_QK_AR_START_ENA         				(1 << APB_QK_AR_START_BIT)
#define APB_QK_AR_START_DIS        				(0 << APB_QK_AR_START_BIT)

#define APB_QK_AR_STOP_BIT       				    (5)
#define APB_QK_AR_STOP_BITS       				(1)
#define APB_QK_AR_STOP_MASK       				ARCHI_REG_MASK(APB_QK_AR_STOP_BIT, APB_QK_AR_STOP_BITS)
#define APB_QK_AR_STOP_ENA         				(1 << APB_QK_AR_STOP_BIT)
#define APB_QK_AR_STOP_DIS        				(0 << APB_QK_AR_STOP_BIT)

#define APB_QK_AR_GET_KEY_BIT       				    (6)
#define APB_QK_AR_GET_KEY_BITS       				(1)
#define APB_QK_AR_GET_KEY_MASK       				ARCHI_REG_MASK(APB_QK_AR_GET_KEY_BIT, APB_QK_AR_GET_KEY_BITS)
#define APB_QK_AR_GET_KEY_ENA         				(1 << APB_QK_AR_GET_KEY_BIT)
#define APB_QK_AR_GET_KEY_DIS        				(0 << APB_QK_AR_GET_KEY_BIT)

#define APB_QK_AR_UNWRAP_BIT       				    (7)
#define APB_QK_AR_UNWRAP_BITS       				(1)
#define APB_QK_AR_UNWRAP_MASK       				ARCHI_REG_MASK(APB_QK_AR_UNWRAP_BIT, APB_QK_AR_UNWRAP_BITS)
#define APB_QK_AR_UNWRAP_ENA         				(1 << APB_QK_AR_UNWRAP_BIT)
#define APB_QK_AR_UNWRAP_DIS        				(0 << APB_QK_AR_UNWRAP_BIT)

#define APB_QK_AR_WRAP_GEN_RAND_BIT       				    (8)
#define APB_QK_AR_WRAP_GEN_RAND_BITS       				(1)
#define APB_QK_AR_WRAP_GEN_RAND_MASK       				ARCHI_REG_MASK(APB_QK_AR_WRAP_GEN_RAND_BIT, APB_QK_AR_WRAP_GEN_RAND_BITS)
#define APB_QK_AR_WRAP_GEN_RAND_ENA         				(1 << APB_QK_AR_WRAP_GEN_RAND_BIT)
#define APB_QK_AR_WRAP_GEN_RAND_DIS        				(0 << APB_QK_AR_WRAP_GEN_RAND_BIT)

#define APB_QK_AR_WRAP_BIT       				    (9)
#define APB_QK_AR_WRAP_BITS       				(1)
#define APB_QK_AR_WRAP_MASK       				ARCHI_REG_MASK(APB_QK_AR_WRAP_BIT, APB_QK_AR_WRAP_BITS)
#define APB_QK_AR_WRAP_ENA         				(1 << APB_QK_AR_WRAP_BIT)
#define APB_QK_AR_WRAP_DIS        				(0 << APB_QK_AR_WRAP_BIT)

#define APB_QK_AR_GEN_RAND_BIT       				    (15)
#define APB_QK_AR_GEN_RAND_BITS       				(1)
#define APB_QK_AR_GEN_RAND_MASK       				ARCHI_REG_MASK(APB_QK_AR_GEN_RAND_BIT, APB_QK_AR_GEN_RAND_BITS)
#define APB_QK_AR_GEN_RAND_ENA         				(1 << APB_QK_AR_GEN_RAND_BIT)
#define APB_QK_AR_GEN_RAND_DIS        				(0 << APB_QK_AR_GEN_RAND_BIT)


// Interrupt Enable Register
#define APB_QK_IER_BIT       				    (0)
#define APB_QK_IER_BITS       				(1)
#define APB_QK_IER_MASK       				ARCHI_REG_MASK(APB_QK_IER_BIT, APB_QK_IER_BITS)
#define APB_QK_IER_ENA         				(1 << APB_QK_IER_BIT)
#define APB_QK_IER_DIS        				(0 << APB_QK_IER_BIT)



// Interrupt Mask Register
#define APB_QK_IMR_BUSY_BIT       				    (0)
#define APB_QK_IMR_BUSY_BITS       				(1)
#define APB_QK_IMR_BUSY_MASK       				ARCHI_REG_MASK(APB_QK_IMR_BUSY_BIT, APB_QK_IMR_BUSY_BITS)
#define APB_QK_IMR_BUSY_ENA         				(1 << APB_QK_IMR_BUSY_BIT)
#define APB_QK_IMR_BUSY_DIS        				(0 << APB_QK_IMR_BUSY_BIT)

#define APB_QK_IMR_OK_BIT       				    (1)
#define APB_QK_IMR_OK_BITS       				(1)
#define APB_QK_IMR_OK_MASK       				ARCHI_REG_MASK(APB_QK_IMR_OK_BIT, APB_QK_IMR_OK_BITS)
#define APB_QK_IMR_OK_ENA         				(1 << APB_QK_IMR_OK_BIT)
#define APB_QK_IMR_OK_DIS        				(0 << APB_QK_IMR_OK_BIT)

#define APB_QK_IMR_ERROR_BIT       				    (2)
#define APB_QK_IMR_ERROR_BITS       				(1)
#define APB_QK_IMR_ERROR_MASK       				ARCHI_REG_MASK(APB_QK_IMR_ERROR_BIT, APB_QK_IMR_ERROR_BITS)
#define APB_QK_IMR_ERROR_ENA         				(1 << APB_QK_IMR_ERROR_BIT)
#define APB_QK_IMR_ERROR_DIS        				(0 << APB_QK_IMR_ERROR_BIT)

#define APB_QK_IMR_ZEROIZED_BIT       				    (3)
#define APB_QK_IMR_ZEROIZED_BITS       				(1)
#define APB_QK_IMR_ZEROIZED_MASK       				ARCHI_REG_MASK(APB_QK_IMR_ZEROIZED_BIT, APB_QK_IMR_ZEROIZED_BITS)
#define APB_QK_IMR_ZEROIZED_ENA         				(1 << APB_QK_IMR_ZEROIZED_BIT)
#define APB_QK_IMR_ZEROIZED_DIS        				(0 << APB_QK_IMR_ZEROIZED_BIT)

#define APB_QK_IMR_REJECTED_BIT       				    (4)
#define APB_QK_IMR_REJECTED_BITS       				(1)
#define APB_QK_IMR_REJECTED_MASK       				ARCHI_REG_MASK(APB_QK_IMR_REJECTED_BIT, APB_QK_IMR_REJECTED_BITS)
#define APB_QK_IMR_REJECTED_ENA         				(1 << APB_QK_IMR_REJECTED_BIT)
#define APB_QK_IMR_REJECTED_DIS        				(0 << APB_QK_IMR_REJECTED_BIT)

#define APB_QK_IMR_DI_REQ_BIT       				    (5)
#define APB_QK_IMR_DI_REQ_BITS       				(1)
#define APB_QK_IMR_DI_REQ_MASK       				ARCHI_REG_MASK(APB_QK_IMR_DI_REQ_BIT, APB_QK_IMR_DI_REQ_BITS)
#define APB_QK_IMR_DI_REQ_ENA         				(1 << APB_QK_IMR_DI_REQ_BIT)
#define APB_QK_IMR_DI_REQ_DIS        				(0 << APB_QK_IMR_DI_REQ_BIT)

#define APB_QK_IMR_DO_REQ_BIT       				    (6)
#define APB_QK_IMR_DO_REQ_BITS       				(1)
#define APB_QK_IMR_DO_REQ_MASK       				ARCHI_REG_MASK(APB_QK_IMR_DO_REQ_BIT, APB_QK_IMR_DO_REQ_BITS)
#define APB_QK_IMR_DO_REQ_ENA         				(1 << APB_QK_IMR_DO_REQ_BIT)
#define APB_QK_IMR_DO_REQ_DIS        				(0 << APB_QK_IMR_DO_REQ_BIT)


// Interrupt Status Register
#define APB_QK_ISR_BUSY_BIT       				    (0)
#define APB_QK_ISR_BUSY_BITS       				(1)
#define APB_QK_ISR_BUSY_MASK       				ARCHI_REG_MASK(APB_QK_IMR_BUSY_BIT, APB_QK_IMR_BUSY_BITS)
#define APB_QK_ISR_BUSY         				(1 << APB_QK_IMR_BUSY_BIT)

#define APB_QK_ISR_OK_BIT       				    (1)
#define APB_QK_ISR_OK_BITS       				(1)
#define APB_QK_ISR_OK_MASK       				ARCHI_REG_MASK(APB_QK_IMR_OK_BIT, APB_QK_IMR_OK_BITS)
#define APB_QK_ISR_OK         				(1 << APB_QK_IMR_OK_BIT)

#define APB_QK_ISR_ERROR_BIT       				    (2)
#define APB_QK_ISR_ERROR_BITS       				(1)
#define APB_QK_ISR_ERROR_MASK       				ARCHI_REG_MASK(APB_QK_IMR_ERROR_BIT, APB_QK_IMR_ERROR_BITS)
#define APB_QK_ISR_ERROR         				(1 << APB_QK_IMR_ERROR_BIT)

#define APB_QK_ISR_ZEROIZED_BIT       				    (3)
#define APB_QK_ISR_ZEROIZED_BITS       				(1)
#define APB_QK_ISR_ZEROIZED_MASK       				ARCHI_REG_MASK(APB_QK_IMR_ZEROIZED_BIT, APB_QK_IMR_ZEROIZED_BITS)
#define APB_QK_ISR_ZEROIZED         				(1 << APB_QK_IMR_ZEROIZED_BIT)

#define APB_QK_ISR_REJECTED_BIT       				    (4)
#define APB_QK_ISR_REJECTED_BITS       				(1)
#define APB_QK_ISR_REJECTED_MASK       				ARCHI_REG_MASK(APB_QK_IMR_REJECTED_BIT, APB_QK_IMR_REJECTED_BITS)
#define APB_QK_ISR_REJECTED         				(1 << APB_QK_IMR_REJECTED_BIT)

#define APB_QK_ISR_DI_REQ_BIT       				    (5)
#define APB_QK_ISR_DI_REQ_BITS       				(1)
#define APB_QK_ISR_DI_REQ_MASK       				ARCHI_REG_MASK(APB_QK_IMR_DI_REQ_BIT, APB_QK_IMR_DI_REQ_BITS)
#define APB_QK_ISR_DI_REQ         				(1 << APB_QK_IMR_DI_REQ_BIT)

#define APB_QK_ISR_DO_REQ_BIT       				    (6)
#define APB_QK_ISR_DO_REQ_BITS       				(1)
#define APB_QK_ISR_DO_REQ_MASK       				ARCHI_REG_MASK(APB_QK_IMR_DO_REQ_BIT, APB_QK_IMR_DO_REQ_BITS)
#define APB_QK_ISR_DO_REQ         				(1 << APB_QK_IMR_DO_REQ_BIT)


// Key destination Register
#define APB_QK_KEYDEST_DOR_REG_BIT       				    (0)
#define APB_QK_KEYDEST_DOR_REG_BITS       				(1)
#define APB_QK_KEYDEST_DOR_REG_MASK       				ARCHI_REG_MASK(APB_QK_KEYDEST_DOR_REG_BIT, APB_QK_KEYDEST_DOR_REG_BITS)
#define APB_QK_KEYDEST_DOR_REG_ENA         				(1 << APB_QK_KEYDEST_DOR_REG_BIT)
#define APB_QK_KEYDEST_DOR_REG_DIS         				(0 << APB_QK_KEYDEST_DOR_REG_BIT)

#define APB_QK_KEYDEST_KO_ITF_BIT       				    (1)
#define APB_QK_KEYDEST_KO_ITF_BITS       				(1)
#define APB_QK_KEYDEST_KO_ITF_MASK       				ARCHI_REG_MASK(APB_QK_KEYDEST_KO_ITF_BIT, APB_QK_KEYDEST_KO_ITF_BITS)
#define APB_QK_KEYDEST_KO_ITF_ENA         				(1 << APB_QK_KEYDEST_KO_ITF_BIT)
#define APB_QK_KEYDEST_KO_ITF_DIS         				(0 << APB_QK_KEYDEST_KO_ITF_BIT)


// Data Input Register
#define APB_QK_DIR_BIT       				    (0)
#define APB_QK_DIR_BITS       				(32)
#define APB_QK_DIR_MASK       				ARCHI_REG_MASK(APB_QK_DIR_BIT, APB_QK_DIR_BITS)
 

// Data Output Register
#define APB_QK_DOR_BIT       				    (0)
#define APB_QK_DOR_BITS       				(32)
#define APB_QK_DOR_MASK       				ARCHI_REG_MASK(APB_QK_DOR_BIT, APB_QK_DOR_BITS)



// Miscellaneous Register
#define APB_QK_MISC_ENDIANNESS_BIT       				    (0)
#define APB_QK_MISC_ENDIANNESS_BITS       				(1)
#define APB_QK_MISC_ENDIANNESS_MASK       				ARCHI_REG_MASK(APB_QK_MISC_ENDIANNESS_BIT, APB_QK_MISC_ENDIANNESS_BITS)
#define APB_QK_MISC_ENDIANNESS_BIG         				(1 << APB_QK_MISC_ENDIANNESS_BIT)
#define APB_QK_MISC_ENDIANNESS_LIT         				(0 << APB_QK_MISC_ENDIANNESS_BIT)


// APB Interface Status Register
#define APB_QK_IF_SR_APB_ERROR_BIT       				    (0)
#define APB_QK_IF_SR_APB_ERROR_BITS       				(1)
#define APB_QK_IF_SR_APB_ERROR_MASK       				ARCHI_REG_MASK(APB_QK_IF_SR_APB_ERROR_BIT, APB_QK_IF_SR_APB_ERROR_BITS)
#define APB_QK_IF_SR_APB_ERROR         				(1 << APB_QK_IF_SR_APB_ERROR_BIT)


// TEST Register
#define APB_QK_TEST_BIST_SEL_BIT       				    (0)
#define APB_QK_TEST_BIST_SEL_BITS       				(1)
#define APB_QK_TEST_BIST_SEL_MASK       				ARCHI_REG_MASK(APB_QK_TEST_BIST_SEL_BIT, APB_QK_TEST_BIST_SEL_BITS)
#define APB_QK_TEST_BIST_SEL_ENA         				(1 << APB_QK_TEST_BIST_SEL_BIT)
#define APB_QK_TEST_BIST_SEL_DIS         				(0 << APB_QK_TEST_BIST_SEL_BIT)

#define APB_QK_TEST_BIST_RUN_BIT       				    (4)
#define APB_QK_TEST_BIST_RUN_BITS       				(1)
#define APB_QK_TEST_BIST_RUN_MASK       				ARCHI_REG_MASK(APB_QK_TEST_BIST_RUN_BIT, APB_QK_TEST_BIST_RUN_BITS)
#define APB_QK_TEST_BIST_RUN         				(1 << APB_QK_TEST_BIST_RUN_BIT)

#define APB_QK_TEST_BIST_ACTIV_BIT       				    (5)
#define APB_QK_TEST_BIST_ACTIV_BITS       				(1)
#define APB_QK_TEST_BIST_ACTIV_MASK       				ARCHI_REG_MASK(APB_QK_TEST_BIST_ACTIV_BIT, APB_QK_TEST_BIST_ACTIV_BITS)
#define APB_QK_TEST_BIST_ACTIV         				(1 << APB_QK_TEST_BIST_ACTIV_BIT)

#define APB_QK_TEST_BIST_OK_BIT       				    (6)
#define APB_QK_TEST_BIST_OK_BITS       				(1)
#define APB_QK_TEST_BIST_OK_MASK       				ARCHI_REG_MASK(APB_QK_TEST_BIST_OK_BIT, APB_QK_TEST_BIST_OK_BITS)
#define APB_QK_TEST_BIST_OK        				(1 << APB_QK_TEST_BIST_OK_BIT)

#define APB_QK_TEST_BIST_FAIL_BIT       				    (7)
#define APB_QK_TEST_BIST_FAIL_BITS       				(1)
#define APB_QK_TEST_BIST_FAIL_MASK       				ARCHI_REG_MASK(APB_QK_TEST_BIST_FAIL_BIT, APB_QK_TEST_BIST_FAIL_BITS)
#define APB_QK_TEST_BIST_FAIL         				(1 << APB_QK_TEST_BIST_FAIL_BIT)

#define APB_QK_TEST_BIST_ALLOW_BIT       				    (31)
#define APB_QK_TEST_BIST_ALLOW_BITS       				(1)
#define APB_QK_TEST_BIST_ALLOW_MASK       				ARCHI_REG_MASK(APB_QK_TEST_BIST_ALLOW_BIT, APB_QK_TEST_BIST_ALLOW_BITS)
#define APB_QK_TEST_BIST_ALLOW         				(1 << APB_QK_TEST_BIST_ALLOW_BIT)



// HArdware Restrict UC0 Register
#define APB_QK_HW_RUC0_BIT       				    (0)
#define APB_QK_HW_RUC0_BITS       				(32)
#define APB_QK_HW_RUC0_MASK       				ARCHI_REG_MASK(APB_QK_HW_RUC0_BIT, APB_QK_HW_RUC0_BITS)



// HArdware Restrict UC1 Register
#define APB_QK_HW_RUC1_BIT       				    (0)
#define APB_QK_HW_RUC1_BITS       				(32)
#define APB_QK_HW_RUC1_MASK       				ARCHI_REG_MASK(APB_QK_HW_RUC1_BIT, APB_QK_HW_RUC1_BITS)



// Hardware Settings Register
#define APB_QK_HW_SET_ENROLL_BIT       				    (1)
#define APB_QK_HW_SET_ENROLL_BITS       				(1)
#define APB_QK_HW_SET_ENROLL_MASK       				ARCHI_REG_MASK(APB_QK_HW_SET_ENROLL_BIT, APB_QK_HW_SET_ENROLL_BITS)
#define APB_QK_HW_SET_ENROLL_DIS         				(1 << APB_QK_HW_SET_ENROLL_BIT)
#define APB_QK_HW_SET_ENROLL_ENA         				(0 << APB_QK_HW_SET_ENROLL_BIT)

#define APB_QK_HW_SET_START_BIT       				    (2)
#define APB_QK_HW_SET_START_BITS       				(1)
#define APB_QK_HW_SET_START_MASK       				ARCHI_REG_MASK(APB_QK_HW_SET_START_BIT, APB_QK_HW_SET_START_BITS)
#define APB_QK_HW_SET_START_DIS         				(1 << APB_QK_HW_SET_START_BIT)
#define APB_QK_HW_SET_START_ENA         				(0 << APB_QK_HW_SET_START_BIT)

#define APB_QK_HW_SET_STOP_BIT       				    (5)
#define APB_QK_HW_SET_STOP_BITS       				(1)
#define APB_QK_HW_SET_STOP_MASK       				ARCHI_REG_MASK(APB_QK_HW_SET_STOP_BIT, APB_QK_HW_SET_STOP_BITS)
#define APB_QK_HW_SET_STOP_DIS         				(1 << APB_QK_HW_SET_STOP_BIT)
#define APB_QK_HW_SET_STOP_ENA         				(0 << APB_QK_HW_SET_STOP_BIT)

#define APB_QK_HW_SET_GET_KET_BIT       				    (6)
#define APB_QK_HW_SET_GET_KET_BITS       				(1)
#define APB_QK_HW_SET_GET_KET_MASK       				ARCHI_REG_MASK(APB_QK_HW_SET_GET_KET_BIT, APB_QK_HW_SET_GET_KET_BITS)
#define APB_QK_HW_SET_GET_KET_DIS         				(1 << APB_QK_HW_SET_GET_KET_BIT)
#define APB_QK_HW_SET_GET_KET_ENA         				(0 << APB_QK_HW_SET_GET_KET_BIT)

#define APB_QK_HW_SET_UNWRAP_BIT       				    (7)
#define APB_QK_HW_SET_UNWRAP_BITS       				(1)
#define APB_QK_HW_SET_UNWRAP_MASK       				ARCHI_REG_MASK(APB_QK_HW_SET_UNWRAP_BIT, APB_QK_HW_SET_UNWRAP_BITS)
#define APB_QK_HW_SET_UNWRAP_DIS         				(1 << APB_QK_HW_SET_UNWRAP_BIT)
#define APB_QK_HW_SET_UNWRAP_ENA         				(0 << APB_QK_HW_SET_UNWRAP_BIT)

#define APB_QK_HW_SET_WRAP_GEN_RAND_BIT       				    (8)
#define APB_QK_HW_SET_WRAP_GEN_RAND_BITS       				(1)
#define APB_QK_HW_SET_WRAP_GEN_RAND_MASK       				ARCHI_REG_MASK(APB_QK_HW_SET_WRAP_GEN_RAND_BIT, APB_QK_HW_SET_WRAP_GEN_RAND_BITS)
#define APB_QK_HW_SET_WRAP_GEN_RAND_DIS         				(1 << APB_QK_HW_SET_WRAP_GEN_RAND_BIT)
#define APB_QK_HW_SET_WRAP_GEN_RAND_ENA         				(0 << APB_QK_HW_SET_WRAP_GEN_RAND_BIT)

#define APB_QK_HW_SET_WRAP_BIT       				    (9)
#define APB_QK_HW_SET_WRAP_BITS       				(1)
#define APB_QK_HW_SET_WRAP_MASK       				ARCHI_REG_MASK(APB_QK_HW_SET_WRAP_BIT, APB_QK_HW_SET_WRAP_BITS)
#define APB_QK_HW_SET_WRAP_DIS         				(1 << APB_QK_HW_SET_WRAP_BIT)
#define APB_QK_HW_SET_WRAP_ENA         				(0 << APB_QK_HW_SET_WRAP_BIT)

#define APB_QK_HW_SET_GEN_RAND_BIT       				    (15)
#define APB_QK_HW_SET_GEN_RAND_BITS       				(1)
#define APB_QK_HW_SET_GEN_RAND_MASK       				ARCHI_REG_MASK(APB_QK_HW_SET_GEN_RAND_BIT, APB_QK_HW_SET_GEN_RAND_BITS)
#define APB_QK_HW_SET_GEN_RAND_DIS         				(1 << APB_QK_HW_SET_GEN_RAND_BIT)
#define APB_QK_HW_SET_GEN_RAND_ENA         				(0 << APB_QK_HW_SET_GEN_RAND_BIT)




// Hardware Information Register
#define APB_QK_HW_INFO_CFG_BIST_BIT       				    (22)
#define APB_QK_HW_INFO_CFG_BIST_BITS       				(1)
#define APB_QK_HW_INFO_CFG_BIST_MASK       				ARCHI_REG_MASK(APB_QK_HW_INFO_CFG_BIST_BIT, APB_QK_HW_INFO_CFG_BIST_BITS)
#define APB_QK_HW_INFO_CFG_BIST_INCL         				(1 << APB_QK_HW_INFO_CFG_BIST_BIT)
#define APB_QK_HW_INFO_CFG_BIST_NOT_INCL         				(0 << APB_QK_HW_INFO_CFG_BIST_BIT)

#define APB_QK_HW_INFO_CFG_TYPE_BIT       				    (28)
#define APB_QK_HW_INFO_CFG_TYPE_BITS       				(4)
#define APB_QK_HW_INFO_CFG_TYPE_MASK       				ARCHI_REG_MASK(APB_QK_HW_INFO_CFG_TYPE_BIT, APB_QK_HW_INFO_CFG_TYPE_BITS)
#define APB_QK_HW_INFO_CFG_TYPE_SAFE         				(0b0001 << APB_QK_HW_INFO_CFG_TYPE_BIT)
#define APB_QK_HW_INFO_CFG_TYPE_PLUS        				(0b0010 << APB_QK_HW_INFO_CFG_TYPE_BIT)




// Hardware ID Register
#define APB_QK_HW_ID_BIT       				    (0)
#define APB_QK_HW_ID_BITS       				(32)
#define APB_QK_HW_ID_MASK       				ARCHI_REG_MASK(APB_QK_HW_ID_BIT, APB_QK_HW_ID_BITS)



// Hardware Version Register
#define APB_QK_HW_VER_REV_BIT       				    (0)
#define APB_QK_HW_VER_REV_BITS       				(8)
#define APB_QK_HW_VER_REV_MASK       				ARCHI_REG_MASK(APB_QK_HW_VER_REV_BIT, APB_QK_HW_VER_REV_BITS)

#define APB_QK_HW_VER_MINOR_BIT       				    (8)
#define APB_QK_HW_VER_MINOR_BITS       				(8)
#define APB_QK_HW_VER_MINOR_MASK       				ARCHI_REG_MASK(APB_QK_HW_VER_MINOR_BIT, APB_QK_HW_VER_MINOR_BITS)

#define APB_QK_HW_VER_MAJOR_BIT       				    (16)
#define APB_QK_HW_VER_MAJOR_BITS       				(8)
#define APB_QK_HW_VER_MAJOR_MASK       				ARCHI_REG_MASK(APB_QK_HW_VER_MAJOR_BIT, APB_QK_HW_VER_MAJOR_BITS)

#endif