/**********************************************************
//
// altitude.c - Altitude module for sampling altitude
// Created on 11/04/2019
//
// Authors: Annabelle Ritchie, Karan Naidu, Emily Tideswell
// Group 13, Thursday PM lab
// Contributions:  P.J. Bones   UCECE -- provided base code
**********************************************************/

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/adc.h"
#include "driverlib/pwm.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"
#include "driverlib/interrupt.h"
#include "driverlib/debug.h"
#include "utils/ustdlib.h"
#include "circBufT.h"
#include "OrbitOLED/OrbitOLEDInterface.h"
#include "buttons4.h"
#include "altitude.h"

#define BUF_SIZE_ALT 5
static circBuf_t g_altBuffer;       // Buffer of size BUF_SIZE integers (sample values)
int32_t altitudeRef;

//*****************************************************************************
//
// Function to take the reference value of the altitude
//
//*****************************************************************************
int getReferenceAltitude()
{
    uint16_t i;
    int sum;
    int32_t ref;
    sum = 0;
    for (i = 0; i < BUF_SIZE_ALT; i++)
        sum = sum + readCircBuf (&g_altBuffer);
    ref = ((2 * sum + BUF_SIZE_ALT) / 2 / BUF_SIZE_ALT);
    return ref;
}

//*****************************************************************************
//
// Initialises the circular used to store the altitude samples.
//
//*****************************************************************************
void initAltitude (void)
{
    initCircBuf (&g_altBuffer, BUF_SIZE_ALT);
    SysCtlDelay (SysCtlClockGet() / 6);  // quick delay to clear initial noise
    altitudeRef = getReferenceAltitude();

}


//*****************************************************************************
//
// The handler for the ADC conversion complete interrupt.
// Writes to the circular buffer.
//
//*****************************************************************************
void
ADCIntHandlerAlt (void)
{
    uint32_t altValue;

    //
    // Get the single sample from ADC0.  ADC_BASE is defined in
    // inc/hw_memmap.h
    ADCSequenceDataGet(ADC0_BASE, 3, &altValue);
    //
    // Place it in the circular buffer (advancing write index)
    writeCircBuf (&g_altBuffer, altValue);
    //
    // Clean up, clearing the interrupt
    ADCIntClear(ADC0_BASE, 3);
}

//*****************************************************************************
//
// Returns the mean value of the altitude from the altitude samples in the
// circular buffer.
//
//*****************************************************************************
int sampleAltitude (void)
{
    int sum = 0;
    int i;
    int32_t meanAlt;

    for (i = 0; i < BUF_SIZE_ALT; i++)
    {
        sum = sum + readCircBuf (&g_altBuffer);
    }
    // Calculate and display the rounded mean of the buffer contents
    meanAlt = ((((2 * sum + BUF_SIZE_ALT) / 2 / BUF_SIZE_ALT)));

    return meanAlt;
}
