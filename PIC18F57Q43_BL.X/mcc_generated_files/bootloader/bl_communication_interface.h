/**
 * 
 * @file bl_communication_interface.h
 * 
 * @ingroup generic_bootloader_8bit
 * 
 * @brief This file contains the communication interface API prototypes required by the Bootloader library
 *
 * @version BOOTLOADER Driver Version 3.0.0
*/

/*
© [2023] Microchip Technology Inc. and its subsidiaries.

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

#ifndef BL_COMMUNICATION_INTERFACE_H
#define BL_COMMUNICATION_INTERFACE_H
 
#include <stdlib.h>
#include <stdbool.h>
#include "../system/system.h"

/**
 * @ingroup generic_bootloader_8bit
 * @brief This API innitializes the communication for bootloader library.
 * @param none
 * @retval none
 */
void BL_CommunicationModuleInit(void);

/**
 * @ingroup generic_bootloader_8bit
 * @brief This API reads given length of bytes from communication channel.
 * @param [out] *data - Pointer to data buffer to hold the bytes read from communication channel
 * @param [in] dataLength - Length in bytes to be read from given communication channel
 * @retval none
 */
void BL_CommunicationModuleRead(uint8_t *data, size_t dataLength);

/**
 * @ingroup generic_bootloader_8bit
 * @brief This API writes given length of bytes over the communication channel.
 * @param [in] *data - Pointer to data buffer to hold the bytes to be written to communication channel
 * @param [in] dataLength - Length in bytes to be written to given communication channel
 * @retval none
 */
void BL_CommunicationModuleWrite(uint8_t *data, size_t dataLength);

/**
 * @ingroup generic_bootloader_8bit
 * @brief This API waits for the last byte to shift out before starting autobaud.
 * @param none
 * @retval true if communication module is ready
 * @retval false if communication module is busy
 */
bool BL_CommunicationModuleIsReady(void);

#endif //BL_COMMUNICATION_INTERFACE_H

