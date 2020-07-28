/**********************************************************
//
// adcControl.h - ADC module for setting up altitude interrupts
// Created on 12/05/2019
//
// Authors: Annabelle Ritchie, Karan Naidu, Emily Tideswell
// Group 13, Thursday PM lab
// Contributions:  P.J. Bones   UCECE -- provided base code
**********************************************************/

#ifndef ADCCONTROL_H_
#define ADCCONTROL_H_

//*****************************************************************************
//
// The interrupt handler for the for SysTick interrupt.
//
//*****************************************************************************
void
SysTickIntHandler(void);

//*****************************************************************************
//
// Initialisation functions for the clock (incl. SysTick), ADC, display
//
//*****************************************************************************
void
initClock (void);

//*****************************************************************************
//
// Initializes ADC for altitude pin handler.
//
//*****************************************************************************
void
initADC (void);

#endif /* ADCCONTROL_H_ */
