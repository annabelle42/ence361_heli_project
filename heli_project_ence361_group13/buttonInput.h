/**********************************************************
//
// buttonInput.h - module header for handling all button inputs
// Created on 12/05/2019
//
// Authors: Annabelle Ritchie, Karan Naidu, Emily Tideswell
// Group 13, Thursday PM lab
// Contributions:  P.J. Bones   UCECE -- provided base code
**********************************************************/
#ifndef BUTTONINPUT_H_
#define BUTTONINPUT_H_

//*****************************************************************************
//
// Checks for altitude input - ie. UP and DOWN buttons.
//
//*****************************************************************************
void checkForAltitudeInput ();

//*****************************************************************************
//
// Checks for yaw input - ie. LEFT and RIGHT buttons.
//
//*****************************************************************************
void checkForYawInput ();

//*****************************************************************************
//
// Checks for mode input - ie. SELECT button.
//
//*****************************************************************************
int checkForModeInput (void);

#endif /* BUTTONINPUT_H_ */
