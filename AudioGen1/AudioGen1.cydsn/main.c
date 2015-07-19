//**********************************************************************//
//  BEERWARE LICENSE
//
//  This code is free for any use provided that if you meet the author
//  in person, you buy them a beer.
//
//  This license block is BeerWare itself.
//
//  Beer target:  Marshall Taylor
//  Debited:  July 9, 2015
//
//**********************************************************************//

extern "C"
{
#include <project.h>
}

#include "stdint.h"

//SynthVoice Includes
#include "SynthVoice.h"

//Globals

SynthVoice mySynthVoiceA;
SynthVoice mySynthVoiceB;
SynthVoice mySynthVoiceC;
SynthVoice mySynthVoiceD;
SynthVoice mySynthVoiceE;
SynthVoice mySynthVoiceF;
SynthVoice mySynthVoiceG;
SynthVoice mySynthVoiceH;
SynthVoice mySynthVoiceI;
SynthVoice mySynthVoiceJ;
SynthVoice mySynthVoiceK;
SynthVoice mySynthVoiceL;
SynthVoice mySynthVoiceM;
SynthVoice mySynthVoiceN;
SynthVoice mySynthVoiceO;
SynthVoice mySynthVoiceP;
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
    //VDAC8_1_SetValue((uint8_t)temp);
    
    if( temp >= 0x80 )
    {
        //UserLED_Write(1);
    }
    else
    {
        //UserLED_Write(0);
    }
}

CY_ISR(SampleISR)
{
    volatile int fuckoffCypress;
    isrDuty_Write(1);
    SampleTimer_ReadStatusRegister();
    volatile int outTemp;
    outTemp = mySynthVoiceA.tick();
    outTemp += mySynthVoiceB.tick();
    outTemp += mySynthVoiceC.tick();
    outTemp += mySynthVoiceD.tick();
    outTemp += mySynthVoiceE.tick();
    outTemp += mySynthVoiceF.tick();
    outTemp += mySynthVoiceG.tick();
    outTemp += mySynthVoiceH.tick();
    outTemp += mySynthVoiceI.tick();
    outTemp += mySynthVoiceJ.tick();
    outTemp += mySynthVoiceK.tick();
    outTemp += mySynthVoiceL.tick();
    outTemp += mySynthVoiceM.tick();
    outTemp += mySynthVoiceN.tick();
    outTemp += mySynthVoiceO.tick();
    outTemp += mySynthVoiceP.tick();
    outTemp = (float)outTemp/3;
    fuckoffCypress = outTemp;
    //outTemp += 128;
    
    fuckoffCypress = outTemp;
    VDAC8_1_SetValue((unsigned int)(Filter_1_Read8(Filter_1_CHANNEL_A)) + 128u);
    //VDAC8_1_SetValue(outTemp);
    Filter_1_Write24(Filter_1_CHANNEL_A, (outTemp << 16)|0x00FFFF );
    isrDuty_Write(0);

}


int main()
{
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */


    //ADC_DelSig_1_IRQ_Enable();
    //ADC_DelSig_1_Start();
    //ADC_DelSig_1_IRQ_StartEx(InterruptHandler);
    //ADC_DelSig_1_StartConvert();

    isr_1_StartEx(SampleISR);
    SampleTimer_Start();
    
    VDAC8_1_Start();
    
    Filter_1_Start();

    mySynthVoiceA.init();
    mySynthVoiceA.buildTable();
    
    mySynthVoiceB.init();
    mySynthVoiceB.buildTable();
    
    mySynthVoiceC.init();
    mySynthVoiceC.buildTable();
    
    mySynthVoiceD.init();
    mySynthVoiceD.buildTable();

    mySynthVoiceE.init();
    mySynthVoiceE.buildTable();
    
    mySynthVoiceF.init();
    mySynthVoiceF.buildTable();
    
    mySynthVoiceG.init();
    mySynthVoiceG.buildTable();
    
    mySynthVoiceH.init();
    mySynthVoiceH.buildTable();
    
    mySynthVoiceI.init();
    mySynthVoiceI.buildTable();
    
    mySynthVoiceJ.init();
    mySynthVoiceJ.buildTable();
    
    mySynthVoiceK.init();
    mySynthVoiceK.buildTable();
    
    mySynthVoiceL.init();
    mySynthVoiceL.buildTable();
    
    mySynthVoiceM.init();
    mySynthVoiceM.buildTable();
    
    mySynthVoiceN.init();
    mySynthVoiceN.buildTable();
    
    mySynthVoiceO.init();
    mySynthVoiceO.sineEnabled = 1;
    mySynthVoiceO.rampEnabled = 0;
    mySynthVoiceO.buildTable();
    
    mySynthVoiceP.init();
    mySynthVoiceP.sineEnabled = 1;
    mySynthVoiceP.rampEnabled = 0;
    mySynthVoiceP.buildTable();
    
    
    mySynthVoiceA.fineTune = 1.0;
    mySynthVoiceB.fineTune = 1.01;
    mySynthVoiceC.fineTune = 0.98;
    mySynthVoiceD.fineTune = 1.0015;
    mySynthVoiceE.fineTune = 1.005;
    mySynthVoiceF.fineTune = 0.996;
    mySynthVoiceG.fineTune = 1.0;
    mySynthVoiceH.fineTune = 1.0;
    mySynthVoiceI.fineTune = 1.0022;
    mySynthVoiceJ.fineTune = 0.9981;
    mySynthVoiceK.fineTune = 1.0;
    mySynthVoiceL.fineTune = 1.0;
    mySynthVoiceM.fineTune = 1.0;
    mySynthVoiceN.fineTune = 1.0;
    mySynthVoiceO.fineTune = 1.0;
    mySynthVoiceP.fineTune = 1.0;
	mySynthVoiceA.outVolume = 130;
    mySynthVoiceB.outVolume = 20;
    mySynthVoiceC.outVolume = 20;
    mySynthVoiceD.outVolume = 40;
    mySynthVoiceE.outVolume = 20;
    mySynthVoiceF.outVolume = 20;
    mySynthVoiceG.outVolume = 100;
    mySynthVoiceH.outVolume = 160;
    mySynthVoiceI.outVolume = 80;
    mySynthVoiceJ.outVolume = 80;
    mySynthVoiceK.outVolume = 0;
    mySynthVoiceL.outVolume = 0;
    mySynthVoiceM.outVolume = 0;
    mySynthVoiceN.outVolume = 0;
    mySynthVoiceO.outVolume = 80;
    mySynthVoiceP.outVolume = 30;
    mySynthVoiceA.setFreq(60);
    mySynthVoiceB.setFreq(60);
    mySynthVoiceC.setFreq(60);
    mySynthVoiceD.setFreq(60);
    mySynthVoiceE.setFreq(60);
    mySynthVoiceF.setFreq(60);
    mySynthVoiceG.setFreq(48);
    mySynthVoiceH.setFreq(36);
    mySynthVoiceI.setFreq(36);
    mySynthVoiceJ.setFreq(36);
    mySynthVoiceK.setFreq(60);
    mySynthVoiceL.setFreq(60);
    mySynthVoiceM.setFreq(60);
    mySynthVoiceN.setFreq(60);
    mySynthVoiceO.setFreq(79);
    mySynthVoiceP.setFreq(94);

    
    AudioOutBuffer_Start();
    
    CyGlobalIntEnable;
    
    //isr_1_Enable();
    
    /* CyGlobalIntEnable; */ /* Uncomment this line to enable global interrupts. */
    volatile long i = 0;
    while(1)
    {
        for(i = 0; i < 1000; i++)
        {
        }
        /* Place your application code here. */
        UserLED_Write(UserLED_Read()^1);
        //VDAC8_1_SetValue(0xFF);


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
