#include "ui.h"

void handleByteReceived(uint8_t byteReceived)
{
    switch(byteReceived)
    {
        case 'w' :
        {
            UART_1_PutString("Increasing speed\r\n");
        }
        break;
        case 's' :
        {
            UART_1_PutString("Decreasing speed\r\n");
        }
        break;
        
        case '1' :
        {
            UART_1_PutString("Set direction and drives: forwards\r\n");
        }
        break;
        case '2' :
        {
            UART_1_PutString("Set direction and drives: backwards\r\n");
        }
        break;
        
        case '3' :
        {
            UART_1_PutString("Motor mode changed to: Wave-drive\r\n");
        }
        break;
        case '4' :
        {
            UART_1_PutString("Motor mode changed to: Half-step\r\n");
        }
        break;
        case '5' :
        {
            UART_1_PutString("Motor mode changed to: Full-step\r\n");
        }
        break;
        
        case 'd' :
        {
            UART_1_PutString("One full revolution: forwards\r\n");
        }
        break;
        case 'a' :
        {
            UART_1_PutString("One full revolution: backwards\r\n");
        }
        break;
        
        case '0' :
        {
        }
        break;
    }
}