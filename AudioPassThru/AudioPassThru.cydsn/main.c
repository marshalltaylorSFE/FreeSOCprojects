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
#include <project.h>

/*******************************************************************************
* Function Name: InterruptHandler
********************************************************************************
*
* Summary:
*   The Interrupt Service Routine for isr_1.
*
* Parameters:
*   None.
*
* Return:
*   void.
*
*******************************************************************************/
CY_ISR(InterruptHandler)
{
    /* Get the result */
    int16_t temp = ADC_DelSig_1_GetResult16();
    VDAC8_1_SetValue((uint8_t)temp);
    
    if( temp >= 0x80 )
    {
        UserLED_Write(1);
    }
    else
    {
        UserLED_Write(0);
    }
}

int main()
{
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    CyGlobalIntEnable;


    ADC_DelSig_1_IRQ_Enable();
    
    ADC_DelSig_1_Start();

    ADC_DelSig_1_IRQ_StartEx(InterruptHandler);
    
    ADC_DelSig_1_StartConvert();
    
    VDAC8_1_Start();
    
    //isr_1_Enable();
    
    /* CyGlobalIntEnable; */ /* Uncomment this line to enable global interrupts. */
    volatile long i = 0;
    while(1)
    {
        for(i = 0; i < 100000; i++)
        {
        }
        /* Place your application code here. */
        //UserLED_Write(UserLED_Read()^1);


    }
    
    return 0;
    
}

/*
void isr_1_Interrupt(void)
{
    //Stuff
    if( (uint8_t)ADC_DelSig_1_GetResult8() >= 0x80 )
    {
        UserLED_Write(1);
    }
    else
    {
        UserLED_Write(0);
    }
}   
*/

/* [] END OF FILE */
