/**
 *
 * @file bl_bootload.h
 * 
 * @defgroup generic_bootloader_8bit Generic 8-Bit Bootloader
 * 
 * @brief This file contains API prototypes and other datatypes for the 8-bit Bootloader library.
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

#ifndef BL_BOOTLOADER_H
#define BL_BOOTLOADER_H

#include <stdint.h>
#include "bl_boot_config.h"


/**
 * @ingroup generic_bootloader_8bit
 * @def MINOR_VERSION
 * This is a macro for firmware minor version.
 */
#define MINOR_VERSION                (0x08U)
/**
 * @ingroup generic_bootloader_8bit
 * @def MAJOR_VERSION
 * This is a macro for firmware major version.
 */
#define MAJOR_VERSION                (0x00U)

/**
 * @ingroup generic_bootloader_8bit
 * @def NEW_RESET_VECTOR
 * This is a macro for new reset vercor.
 */
#define  NEW_RESET_VECTOR            (0x3000)
/**
 * @ingroup generic_bootloader_8bit
 * @def NEW_INTERRUPT_VECTOR_HIGH
 * This is a macro for new high interrupt vector.
 */
#define  NEW_INTERRUPT_VECTOR_HIGH   (0x3008)
/**
 * @ingroup generic_bootloader_8bit
 * @def NEW_INTERRUPT_VECTOR_LOW
 * This is a macro for new low interrupt vector.
 */
#define  NEW_INTERRUPT_VECTOR_LOW    (0x3018)
/**
 * @ingroup generic_bootloader_8bit
 * @def CONFIGURATION_BYTES_START
 * This is a macro for starting address of device configuration bytes.
 */
#define  CONFIGURATION_BYTES_START   (0x300000)
/**
 * @ingroup generic_bootloader_8bit
 * @def USER_ID_START_U
 * This is a macro for starting address of device user ID.
 */
#define  USER_ID_START_U             (0x200000)

#define  _str(x)  #x
#define  str(x)   _str(x)
/**
 * @ingroup generic_bootloader_8bit
 * @def BL_FRAME_DATA_SIZE
 * This is a macro for bootloader frame data size.
 */
#define  BL_FRAME_DATA_SIZE           (PROGMEM_PAGE_SIZE)
/**
 * @ingroup generic_bootloader_8bit
 * @def APPLICATION_VALID
 * This is a macro for value to indicate application valid verification.
 */
#define APPLICATION_VALID             (0x55U)

/**
 * @ingroup generic_bootloader_8bit
 * @def IO_PIN_ENTRY_GetInputValue
 * This is a macro to get the value of IO PIN ENTRY.
 */
#define IO_PIN_ENTRY_GetInputValue    BL_ENTRY_GetValue
/**
 * @ingroup generic_bootloader_8bit
 * @def IO_PIN_ENTRY_RUN_BL
 * This is a macro for expected value of IO PIN ENTRY.
 */
#define IO_PIN_ENTRY_RUN_BL           (0)

/**
 * @ingroup generic_bootloader_8bit
 * @def BL_INDICATOR_ON
 * This is a macro to turn ON the bootloader indicator.
 */
#define BL_INDICATOR_ON               BL_INDICATOR_SetLow
/**
 * @ingroup generic_bootloader_8bit
 * @def BL_INDICATOR_OFF
 * This is a macro to turn OFF the bootloader indicator.
 */
#define BL_INDICATOR_OFF              BL_INDICATOR_SetHigh 
/**
 * @ingroup generic_bootloader_8bit
 * @def BL_HEADER
 * This is a macro to hold offset of bootloader header.
 */
#define BL_HEADER                    (9U)
/**
 * @ingroup generic_bootloader_8bit
 * @def DEVICE_ID_START_ADDRESS
 * This is a macro to hold starting address of device ID.
 */
#define DEVICE_ID_START_ADDRESS      (0x3FFFFEU)
/**
 * @ingroup generic_bootloader_8bit
 * @def EEPROM_START_ADDRESS_U
 * This is a macro for starting address of EEPROM.
 */
#define EEPROM_START_ADDRESS_U      (0x380000U)
/**
 * @ingroup generic_bootloader_8bit
 * @def EEPROM_SIZE_U
 * This is a macro to hold size of EEPROM.
 */
#define EEPROM_SIZE_U               (0x400U)

/**
 * @ingroup generic_bootloader_8bit
 * @def ERROR_INVALID_COMMAND
 * This is a macro to check invalid command.
 */
#define ERROR_INVALID_COMMAND        (0xFFU)
/**
 * @ingroup generic_bootloader_8bit
 * @def ERROR_ADDRESS_OUT_OF_RANGE
 * This is a macro to check out of range address error.
 */
#define ERROR_ADDRESS_OUT_OF_RANGE   (0xFEU)
/**
 * @ingroup generic_bootloader_8bit
 * @def COMMAND_SUCCESS
 * This is a macro to hold the value to be sent to 
 * host for reception of a successful command.
 */
#define COMMAND_SUCCESS              (0x01U)
/**
 * @ingroup generic_bootloader_8bit
 * @def COMMAND_PROCESSING_ERROR
 * This is a macro to indicate error in processing the received command.
 */
#define COMMAND_PROCESSING_ERROR     (0xFDU)
/**
 * @ingroup generic_bootloader_8bit
 * @def COMMAND_PROCESSING_ERROR
 * This is a macro to indicate overload error in the received command.
 */
#define COMMAND_OVERLOAD_ERROR       (0xFCU)

/**
 * @ingroup generic_bootloader_8bit
 * @def READ_VERSION
 * This macro holds the command to read the version.
 * RD_VER      0x00    Read Version Information.
 */
#define READ_VERSION   (0x00U)
/**
 * @ingroup generic_bootloader_8bit
 * @def READ_FLASH
 * This macro holds the command to read flash.
 * RD_MEM      0x01    Read Program Memory.
 */
#define READ_FLASH     (0x01U)
/**
 * @ingroup generic_bootloader_8bit
 * @def WRITE_FLASH
 * This macro holds the command to write flash.
 * WR_MEM      0x02    Write Program Memory.
 */
#define WRITE_FLASH    (0x02U)
/**
 * @ingroup generic_bootloader_8bit
 * @def ERASE_FLASH
 * This macro holds the command to erase flash.
 * ER_MEM      0x03    Erase Program Memory (NOT supported by PIC16).
 */
#define ERASE_FLASH    (0x03U)
/**
 * @ingroup generic_bootloader_8bit
 * @def READ_EE_DATA
 * This macro holds the command to read EEPROM.
 * RD_EE       0x04    Read EEDATA Memory.
 */
#define READ_EE_DATA   (0x04U)
/**
 * @ingroup generic_bootloader_8bit
 * @def WRITE_EE_DATA
 * This macro holds the command to write EEPROM.
 * WR_EE       0x05    Read EEDATA Memory.
 */
#define WRITE_EE_DATA  (0x05U)
/**
 * @ingroup generic_bootloader_8bit
 * @def READ_CONFIG
 * This macro holds the command to read configiration memory.
 * RD_CONFIG   0x06    Read Config Memory (NOT supported by PIC16).
 */
#define READ_CONFIG    (0x06U)
/**
 * @ingroup generic_bootloader_8bit
 * @def WRITE_CONFIG
 * This macro holds the command to write configiration memory.
 * WT_CONFIG   0x07    Write Config Memory (NOT supported by PIC16).
 */
#define WRITE_CONFIG   (0x07U)
/**
 * @ingroup generic_bootloader_8bit
 * @def CALC_CHECKSUM
 * This macro holds the command to calculate the checksum.
 * CHECKSUM    0x08    Calculate 16 bit checksum of specified region of memory.
 */
#define CALC_CHECKSUM  (0x08U)
/**
 * @ingroup generic_bootloader_8bit
 * @def RESET_DEVICE
 * This macro holds the command reset the target device.
 * RESET       0x09    Reset Device and run application.
 */
#define RESET_DEVICE   (0x09U)
/**
 * @ingroup generic_bootloader_8bit
 * @def WRITE_STATUS
 * This macro holds the command write the firmware upgrade status.
 */
#define WRITE_STATUS   (0x0BU)

/**
 * @ingroup generic_bootloader_8bit
 * @union frame_t
 * @brief This union contains the fields in DFU protocol frame.
 * Frame Format: [<COMMAND><DATALEN><ADDRL><ADDRH><ADDRU><...DATA...>]
 * These values are negative because the FSR is set to PACKET_DATA to minimize FSR reloads.
 */
typedef union
{

    struct
    {
        uint8_t command; /**< Contains the command code */
        uint16_t data_length; /**< Contains the length of data associated to the command */
        uint8_t EE_key_1; /**< Contains the low byte of unlock key */
        uint8_t EE_key_2; /**< Contains the high byte of unlock key */
        uint8_t address_L; /**< Contains the low byte of target memory address */
        uint8_t address_H; /**< Contains the high byte of target memory address */
        uint8_t address_U; /**< Contains the upper byte of target memory address */
        uint8_t address_E; /**< Contains the extended byte of target memory address */
        uint8_t data[BL_FRAME_DATA_SIZE + 1U]; /**< Contains the actual data payload upto 255 bytes*/
    };
    uint8_t buffer[BL_FRAME_DATA_SIZE + 1U + BL_HEADER]; /**< Buffer to store the protocol frame contents including the bootloader header */
} frame_t;



/**
 * @ingroup generic_bootloader_8bit
 * @brief This API checks if firmware upgrade is required. If yes, it runs the bootloader,
 * otherwise it starts the last valid application from the specified reset vector.
 * @param none
 * @retval none
 */
void BL_Initialize(void);

/**
 * @ingroup generic_bootloader_8bit
 * @brief This API check the reset vector to see if there is a valid application present.
 * @param none
 * @retval true if a valid application is present at @ref NEW_RESET_VECTOR
 * @retval false if a valid application is not present at @ref NEW_RESET_VECTOR
 */
bool BL_bootVerify(void);
#endif //BL_BOOTLOADER_H

