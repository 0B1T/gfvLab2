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

CY_ISR(SPI);
void turnLedOn();
void turnLedOff();

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    SPIM_2_Start();
    UART_1_Start();
    
    UART_1_PutString("\r\nSPI Master startet\r\n");
    UART_1_PutString("Press 'f' to turn LED off\r\n");
    UART_1_PutString("Press 'o' to turn LED on\r\n");
    isr_1_StartEx(SPI);
    

    for(;;)
    {
        
        
        
    }
}

CY_ISR(SPI)
{
    char LED = UART_1_GetChar();
    UART_1_PutChar(LED);
    uint8 status;
    
    if(LED == 'o')
    {
        SPIM_2_ClearTxBuffer();
        turnLedOn();
        UART_1_PutString("\r\nLED turning on\r\n");
        //kode til at læse LED status
        //status = SPIM_2_ReadRxData();
        //if(status == 0b11111111)
        //UART_1_PutString("LED is on\r\n");
    }
    else if(LED == 'f')
    {
        SPIM_2_ClearTxBuffer();
        turnLedOff();
        UART_1_PutString("\r\nLED turned off\r\n");
        //kode til at læse LED status
        //status = SPIM_2_ReadRxData();    
        //if(status == 0b00000000)
        //UART_1_PutString("LED is off\r\n");    
    }
}

void turnLedOn()
{
    SPIM_2_WriteTxData(0b11111111);
}

void turnLedOff()
{
    SPIM_2_WriteTxData(0b00000000);
}
