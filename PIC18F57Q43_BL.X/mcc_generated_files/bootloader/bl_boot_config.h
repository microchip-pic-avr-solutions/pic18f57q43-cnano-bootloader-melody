/**
 *
 * @file bl_boot_config.h
 *
 * @ingroup generic_bootloader_8bit
 *
 * @brief This header file provides the user configuration options for the 8-bit bootloader library.
 *
 * @version BOOTLOADER Driver Version 3.0.0
*/

/*
© [2022] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/ 

#ifndef BL_BOOT_CONFIG_H
#define BL_BOOT_CONFIG_H

#include "../system/system.h"


/**
 * @ingroup generic_bootloader_8bit
 * @def START_OF_APP
 * This is a macro for application start address.
 */
#define START_OF_APP                (0x3000U)
/**
 * @ingroup generic_bootloader_8bit
 * @def PROGMEM_PAGE_SIZE_LOW_BYTE
 * This is a macro for low byte of program page size
 */
#define PROGMEM_PAGE_SIZE_LOW_BYTE  ((uint8_t)(PROGMEM_PAGE_SIZE & 0xFFU))
/**
 * @ingroup generic_bootloader_8bit
 * @def PROGMEM_PAGE_SIZE_HIGH_BYTE
 * This is a macro for high byte of program page size
 */
#define PROGMEM_PAGE_SIZE_HIGH_BYTE ((uint8_t)((PROGMEM_PAGE_SIZE >> 8U) & 0xFFU))
/**
 * @ingroup generic_bootloader_8bit
 * @def STATUS_ADDRESS
 * This is a macro for address of bootloader status byte.
 */
#define STATUS_ADDRESS (flash_address_t)(PROGMEM_SIZE - 2U)


#endif //BL_BOOT_CONFIG_H

