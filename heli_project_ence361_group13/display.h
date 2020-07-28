/**********************************************************
//
// display.h - display module handling all display processing
// Created on 11/04/2019
//
// Authors: Annabelle Ritchie, Karan Naidu, Emily Tideswell
// Group 13, Thursday PM lab
**********************************************************/

#ifndef DISPLAY_H_
#define DISPLAY_H_

//*****************************************************************************
//
// initializes the Orbit OLED display
//
//*****************************************************************************
void
initDisplay (void);

//*****************************************************************************
//
// Function to display the mean ADC value (10-bit value, note) and sample count.
//
//*****************************************************************************
void
displayAltYaw(int meanAlt, int meanYaw);

#endif /* DISPLAY_H_ */
