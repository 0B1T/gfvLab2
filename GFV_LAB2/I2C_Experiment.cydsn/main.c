#include "project.h"
#include "writeTempToUART.h"
#include "readTemp.h"
#include "twoComplementConverter.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    int tempStore = 0;
    float tempFinal = 0.0;

    UART_1_Start();
    UART_1_PutString("I2C Experiment UART Driver Startet\n\r");
    I2C_1_Start();
    UART_1_PutString("I2C Experiment I2C Driver Startet\n\n\r");
    
    for(;;)
    {
        // LM75_1:
        tempStore = readTemp(0x48);
        tempFinal = twoComplementConverter(&tempStore);
        writeTempToUART(tempFinal,1);
        
        // LM75_2:
        tempStore = readTemp(0x49);
        tempFinal = twoComplementConverter(&tempStore);
        writeTempToUART(tempFinal,2);
        
        UART_1_PutString("\n\r");
        
        CyDelay(1000);
    }
}