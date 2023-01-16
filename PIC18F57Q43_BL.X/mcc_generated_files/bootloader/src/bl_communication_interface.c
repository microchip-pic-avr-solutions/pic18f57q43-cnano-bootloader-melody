/**
 *
 * @file bl_communication_interface.c
 *
 * @ingroup generic_bootloader_8bit
 *
 * @brief This source file provides the implementation of the communication interface API prototypes required by the 8-bit Bootloader library
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

#include <stdint.h>
#include <stdbool.h>
#include "../bl_communication_interface.h"

#define  STX   0x55

#define USART_IsRxReady()                       UART1_IsRxReady()
#define USART_Read()                            UART1_Read()
#define USART_Write(data)                       UART1_Write(data)
#define USART_IsTxReady()                       UART1_IsTxReady()
#define USART_IsTxDone()                        UART1_IsTxDone()
#define UART_AutoBaudSet(enable)                UART1_AutoBaudSet(enable)
#define UART_AutoBaudQuery()                    UART1_AutoBaudQuery()
#define USART_AutoBaudDetectErrorReset()        UART1_AutoBaudDetectOverflowReset()
#define USART_IsAutoBaudDetectError()           UART1_IsAutoBaudDetectOverflow()


void BL_CommunicationModuleInit(void)
{

    UART_AutoBaudSet(true);

    while(UART_AutoBaudQuery() != 1)
    {
        if( USART_IsAutoBaudDetectError() == true)
        {
            UART_AutoBaudSet(false);
            USART_AutoBaudDetectErrorReset();
            UART_AutoBaudSet(true); 
        }
    }
}

bool BL_CommunicationModuleIsReady(void)
{
    bool status;

    if (USART_IsTxDone())
    {
        status = true;
    }
    else
    {
        status = false;
    }

    return status;
}

void BL_CommunicationModuleRead(uint8_t *data, size_t dataLength)
{
    size_t commReadDataCount;
    commReadDataCount = 0;

    while (commReadDataCount < dataLength)
    {
        if (USART_IsRxReady())
        {
            *data++ = USART_Read();
            commReadDataCount++;
        }
    }
}

void BL_CommunicationModuleWrite(uint8_t *data, size_t dataLength)
{
    size_t commWriteDataCount;
    commWriteDataCount = 0;

    USART_Write(STX);
    while (commWriteDataCount < dataLength)
    {
        if (USART_IsTxReady())
        {
            USART_Write(*data);
            commWriteDataCount++;
            data++;
        }

    }
}
