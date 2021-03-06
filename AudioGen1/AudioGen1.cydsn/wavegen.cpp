//--------------------------------------------------------------------------------------
// Generates a single sample of a 256 sample long waveform
//
// char shape is SINESHAPE, PULSESHAPE, RAMPSHAPE, or DCSHAPE
// float duty, float amp
// char sample is 0x00 to 0xFF
//
// Shapes are ~ +-127, scaled by amp/100, then output ranged 0 to 255 (but type int)
#include <math.h>
#include "wavegen.h"

WaveGenerator::WaveGenerator( void )
{
    masterAmp = 0;
    rampAmp = 0;
    sineAmp = 0;
    pulseAmp = 0;
    pulseDuty = 0;
    sampleNumber = 0;

}

void WaveGenerator::resetOffset( void )
{
    sampleNumber = 0;

}


int WaveGenerator::getSample( void )
{
    float tempRamp = 0;
    int8_t tempSine = 0;
    int8_t tempPulse = 0;
    uint8_t retVal;

    if(rampAmp)
    {
        tempRamp = ((((float)sampleNumber) - 128 ) * (float)rampAmp) / 255;
    }

    if( sineAmp )
    {
        tempSine = int8_t((int16_t)(127 * sin(((float)sampleNumber * 3.141592)/128)) * sineAmp / 255);
    }

    if( pulseAmp )
    {
		//Is sample beyond duty cycle?
		if ( sampleNumber < pulseDuty )
		{
			tempPulse = int8_t( pulseAmp >> 1 );
		}
		else
		{
			tempPulse = int8_t(pulseAmp >> 1 ) * -1;
		}
    }

    sampleNumber++;


 	//cast
	retVal = (((((int16_t)tempRamp + (int16_t)tempSine + (int16_t)tempPulse) / 1) * masterAmp / 255 ));

    return retVal;

}

void WaveGenerator::setParameters( uint8_t masterAmpVar, uint8_t rampAmpVar, uint8_t sineAmpVar, uint8_t pulseAmpVar, uint8_t pulseDutyVar )
{
    masterAmp = masterAmpVar;
    rampAmp = rampAmpVar;
    sineAmp = sineAmpVar;
    pulseAmp = pulseAmpVar;
    pulseDuty = pulseDutyVar;
}



