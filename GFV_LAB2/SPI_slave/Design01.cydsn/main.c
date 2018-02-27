#include "project.h"

CY_ISR(RX_interrupt); // Opsætning af ISR rutinen


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */ 
    LED_Write(0);   // Skriver et 0 til LED  
    SPIS_1_Start(); // Initier SPI slave
    isr_1_StartEx(RX_interrupt); // ISR rutine
    
      for(;;)
    {
        /* Place your application code here. */
    }
    
}
/* [] END OF FILE */

CY_ISR(RX_interrupt) // ISR rutine
{
    uint8_t recevied; //Variable recevied
        
    recevied = SPIS_1_ReadRxData(); //Læser RX, gemmer data i recevied
    if (recevied == 0b11111111)
    {
        LED_Write(1); //Tænder LED 
        SPIS_1_ClearRxBuffer(); // Rydder RX bufferen
    }
    else if (recevied == 0b00000000)
    {
        LED_Write(0); //Slukker LED 
        SPIS_1_ClearRxBuffer(); //Rydder buffer
    }
}