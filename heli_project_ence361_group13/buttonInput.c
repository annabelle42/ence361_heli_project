/**********************************************************
//
// buttonInput.c - module for handling all button inputs
// Created on 12/05/2019
//
// Authors: Annabelle Ritchie, Karan Naidu, Emily Tideswell
// Group 13, Thursday PM lab
// Contributions:  P.J. Bones   UCECE -- provided base code
**********************************************************/
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_ints.h"
#include "driverlib/adc.h"
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"
#include "driverlib/debug.h"
#include "utils/ustdlib.h"
#include "stdlib.h"
#include "OrbitOLED/OrbitOLEDInterface.h"
#include "buttons4.h"
#include "circBufT.h"
#include "display.h"
#include "altitude.h"
#include "yaw.h"
#include "kernel.h"
#include "control.h"
#include "buttonInput.h"
#include "uart.h"

int8_t upPushes = 0, downPushes = 0, rightPushes = 0, leftPushes = 0, selectPushes = 0;

//*****************************************************************************
//
// Checks for altitude input - ie. UP and DOWN buttons.
//
//*****************************************************************************
void checkForAltitudeInput ()
{
    uint8_t butState = checkButton (UP);
    if (butState == PUSHED && desiredAltitude + 10 <= 100)
    {
        desiredAltitude -= 10;
    }

    butState = checkButton (DOWN);
    if (butState == PUSHED && desiredAltitude - 10 >= 0)
    {
        desiredAltitude -= 10;
    }
}

//*****************************************************************************
//
// Checks for yaw input - ie. LEFT and RIGHT buttons.
//
//*****************************************************************************
void checkForYawInput ()
{
    uint8_t butState = checkButton (RIGHT);
    if (butState == PUSHED)
    {
        if (desiredYaw + 15 <= 360)
        {
            desiredYaw += 15;
        }
        else
        {
            desiredYaw = 15;
        }
    }

    butState = checkButton (LEFT);
    if (butState == PUSHED)
    {
        if (desiredYaw - 15 >= 0)
        {
            desiredYaw -= 15;
        }
        else
        {
            desiredYaw = 345;
        }
    }
}

//*****************************************************************************
//
// Checks for mode input - ie. SELECT button.
//
//*****************************************************************************
int checkForModeInput (void)
{
    updateButtons();
    uint8_t butState = checkButton(SELECT);
    if (selectPushes == 0)
    {
        butState = NO_CHANGE;
        selectPushes++;
    }
    return butState;
}
