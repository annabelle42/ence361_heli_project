/**********************************************************
//
// altitude.h - Altitude module for sampling altitude
// Created on 11/04/2019
//
// Authors: Annabelle Ritchie, Karan Naidu, Emily Tideswell
// Group 13, Thursday PM lab
// Contributions:  P.J. Bones   UCECE -- provided base code
**********************************************************/

#ifndef ALTITUDE_H_
#define ALTITUDE_H_

#include <stdint.h>

int32_t altitudeRef;

//*****************************************************************************
//
// Initialises the circular used to store the altitude samples.
//
//*****************************************************************************
void initAltitude (void);

//*****************************************************************************
//
// Function to take the reference value of the altitude
//
//*****************************************************************************
int getReferenceAltitude (void);

//*****************************************************************************
//
// The handler for the ADC conversion complete interrupt.
// Writes to the circular buffer.
//
//*****************************************************************************
void ADCIntHandlerAlt (void);

//*****************************************************************************
//
// The interrupt handler for the for SysTick interrupt.
//
//*****************************************************************************
void SysTickIntHandler(void);

//*****************************************************************************
//
// Returns the mean value of the altitude from the altitude samples in the
// circular buffer.
//
//*****************************************************************************
int sampleAltitude (void);

#endif /* ALTITUDE_H_ */
