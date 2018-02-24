#include "writeTempToUART.h"
#include "stdio.h"

void writeTempToUART(float temp, int unit)
{
    char outputBuffer[256];
    
    snprintf(outputBuffer, sizeof(outputBuffer), "Temperature of LM75_%d is: %.1f \r\n", unit, temp);

    UART_1_PutString(outputBuffer);
}