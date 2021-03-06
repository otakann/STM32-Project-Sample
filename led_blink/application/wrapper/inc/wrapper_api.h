/*
 *  Copyright (C) 2018, ZhaoZhenge, All Rights Reserved
 *  SPDX-License-Identifier: Apache-2.0
 *
 *  Licensed under the Apache License, Version 2.0 (the "License"); you may
 *  not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 *  WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */
 
/**************************************************************
**  STM32 MCU program develop platform
**************************************************************/
/** 
 * @file        wrapper_api.h
 * @brief       common wrapper API
 * @author      zhaozhenge@outlook.com
 *
 * @version     00.00.01 
 *              - 2019/04/08 : zhaozhenge@outlook.com 
 *                  -# New
 */

#ifndef _WRAP_API_H_
#define _WRAP_API_H_

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************
**  Include
**************************************************************/

#include "FreeRTOS.h"

/**************************************************************
**  Symbol
**************************************************************/

#define THREAD_CB       StaticTask_t        /*!< Thread contrl block */
#define EVENT_CB        StaticEventGroup_t  /*!< Event flag contrl block */
#define MQ_CB           StaticQueue_t       /*!< Message queue contrl block */
#define SEM_CB          StaticSemaphore_t   /*!< Semaphore contrl block */

#define SAFE_IT_PRIO    configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY

#define HEAP_MEM_START  (0x10000000)        /*!< Start memory address of heap */
#define HEAP_MEM_SIZE   (32 * 1024)         /*!< Total memory size of heap */

/**************************************************************
**  Interface
**************************************************************/

/**
 * @brief               Initial system wrapper
 * @retval              0               success
 * @retval              -1              fail
 * @author              zhaozhenge@outlook.com
 * @date                2019/04/28
 */
extern int WRAPPER_INIT(void);

/**
 * @brief               Thread safe memory allocate function
 * @param[in]           WantedSize      Memory size that want to allocate
 * @return              Memory address allocated successfully
 * @note                NULL maybe returned when no memory enough
 * @author              zhaozhenge@outlook.com
 * @date                2019/04/28
 */
extern void* SAFE_MALLOC(size_t WantedSize);

/**
 * @brief               Thread safe memory free function
 * @param[in]           Pv              Memory address that allocated from the heap handle
 * @return              None
 * @author              zhaozhenge@outlook.com
 * @date                2019/04/28
 */
extern void SAFE_FREE(void* Pv);

/**
 * @brief               Enter interrupt
 * @return              None
 * @author              zhaozhenge@outlook.com
 * @date                2019/05/16
 */
extern void EXIT_ENTRY(void);

/**
 * @brief               Leave interrupt
 * @return              None
 * @author              zhaozhenge@outlook.com
 * @date                2019/05/16
 */
extern void EXIT_LEAVE(void);

#ifdef __cplusplus
}
#endif

#endif /* _WRAP_API_H_ */
