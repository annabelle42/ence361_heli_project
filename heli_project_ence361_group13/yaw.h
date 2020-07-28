/**********************************************************
//
// yaw.h - Yaw module for sampling and decoding yaw
// Created on 11/04/2019
//
// Authors: Annabelle Ritchie, Karan Naidu, Emily Tideswell
// Group 13, Thursday PM lab
// Contributions:  P.J. Bones   UCECE -- provided base code
**********************************************************/

#ifndef YAW_H_
#define YAW_H_

#include <stdint.h>

//*****************************************************************************
//
// Initialises the GPIO pins and variables that are used to calculate the yaw.
//
//*****************************************************************************
void initYaw (void);

//*****************************************************************************
//
// Uses the pin changes from the pins connected to the quadrature decoder to
// calculate the yaw direction of the helicopter.
// Doesn't take in to account number of full rotations of the helicopter.
//
//*****************************************************************************
void intHandlerYaw(void);

//*****************************************************************************
//
// The interrupt handler for the for SysTick interrupt.
//
//*****************************************************************************
void SysTickIntHandler(void);

//*****************************************************************************
//
// Interrupt handler for the yaw reference position. Resets the global yaw direction to 0.
//
//*****************************************************************************
void intHandlerYawRef (void);

//*****************************************************************************
//
// A getter function for referenceRotation.
//
//*****************************************************************************
int getYawRef (void);

//*****************************************************************************
//
// Finite state machine for the current yaw phase.
// yawDir = -1 for counterclockwise, +1 for clockwise, 0 for no rotation (or an error)
// yawDir is then added to the global yaw direction.
//
//*****************************************************************************

void yawFSM(void);

//*****************************************************************************
//
// Returns the yaw direction of the helicopter relative to a reference.
//
//*****************************************************************************
int getYaw (void);

#endif /* YAW_H_ */
