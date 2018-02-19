/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
//#include "ui.h"

void writeTempToUART(float temp);

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
 
    UART_1_Start();
    UART_1_PutString("I2C Experiment UART Driver Startet\r\n");
    I2C_1_Start();
    UART_1_PutString("I2C Experiment I2C Driver Startet\r\n");
 
    uint8_t startStatus = 0;
    uint8_t readByte1 = 0;
    uint8_t readByte2 = 0;
    char buffer[8];
    
    for(;;)
    {
        startStatus = I2C_1_MasterSendStart(0x48, 1);
        
        if (I2C_1_MSTR_NO_ERROR == startStatus)
        {
            readByte1 = I2C_1_MasterReadByte(I2C_1_ACK_DATA);
            readByte2 = I2C_1_MasterReadByte(I2C_1_NAK_DATA);
        }
        
        I2C_1_MasterSendStop();
        
//        if (I2C_1_MSTR_NO_ERROR == startStatus) UART_1_PutString("No error!\r\n");
        
        CyDelay(1000);     // Waits 1 sec.
        
//        UART_1_PutString(itoa(readByte2, buffer, 10));
        if (itoa(readByte2, buffer, 10) == 0)
            writeTempToUART((~readByte1 + 1) * -1);
        else
            writeTempToUART((~readByte1 + 1) * -1 + 0.5);
    }
}

void writeTempToUART(float temp)
{
    char outputBuffer[256];

    snprintf(outputBuffer, sizeof(outputBuffer), "Temp: %3.1f \r\n", temp);

    UART_1_PutString(outputBuffer);
}