/**
 *
 * @file bl_boot_verify.c
 *
 * @ingroup generic_bootloader_8bit
 *
 * @brief This source file provides the options verification schemes which can be used by the bootloader to verify application image.
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

#include <stdint.h>
#include <stdbool.h>
#include "../bl_bootload.h"



typedef enum
{
    OK,
    FAIL,
    ERROR
} validation_status_t;

static void BL_CalculateChecksum(flash_address_t startAddress, uint32_t length, uint16_t *checkSum);
static validation_status_t BL_ValidateChecksum(flash_address_t startAddress, uint32_t length, flash_address_t checkAddress);



// Checksum validation/calculation functions
static void BL_CalculateChecksum(flash_address_t startAddress, uint32_t length, uint16_t *checkSum)
{
    for (uint32_t i = 0; i < length; i += 2U)
    {
        *checkSum += (uint16_t)FLASH_Read(startAddress);
        startAddress++;
        *checkSum += ((uint16_t)FLASH_Read(startAddress)) << 8;
        startAddress++;
    }
}

/**
 * @brief This function validates the checksum on the APP section and compares it 
 *      to the checksum that is calculated and stored by the postBuild script in the 
 *      end application project
 * @param [in] startAddress - starting address of FLASH memory region to be considered for Checksum
 * @param [in] length - number of bytes from startAddress to be considered for Checksum
 * @param [in] checkAddress - pointer to initial and final Checkum
 * @retval validation_status_t - OK if passes; 
 *                          FAIL if validation did not pass;
 *                          ERROR if memory reference issue occured;
 */
static validation_status_t BL_ValidateChecksum(flash_address_t startAddress, uint32_t length, flash_address_t checkAddress)
{

    validation_status_t status = ERROR;
    uint16_t refChecksum = 0;
    uint16_t check_sum = 0;

    bool refAddrInsideEvaluatedArea = (((checkAddress + 1U) >= startAddress) && (checkAddress < (startAddress + length)));
    bool refAddrOutsideFlash = ((checkAddress + 1U) >= PROGMEM_SIZE);

    if ((length == 0U) || ((startAddress + length) > PROGMEM_SIZE))
    {
        status = ERROR;
    }
    else if (refAddrInsideEvaluatedArea || refAddrOutsideFlash)
    {
        status = ERROR;
    }
    else
    {
        BL_CalculateChecksum(startAddress, length, &check_sum);
        refChecksum = (uint16_t)(FLASH_Read(checkAddress+1U) << 8U | FLASH_Read(checkAddress));
        if (refChecksum != check_sum)
        {
            status = FAIL;
        }
        else
        {
            status = OK;
        }
    }

    return status;
}

bool BL_bootVerify(void)
{
    bool retVal;
// **************************************************************************************
//  Calculate a checksum over the application area and compare to pre-calculated checksum from application image
// **************************************************************************************
    validation_status_t checksumPassed = BL_ValidateChecksum(START_OF_APP, CHECKSUM_LENGTH, CHECKSUM_ADDRESS);

    if (checksumPassed == OK)
    {
        retVal = true;
    }
    else
    {
        retVal = false;
    }

    return retVal;
}

