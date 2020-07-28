//*****************************************************************************
//
// main.c - Main program for ENCE361 Helicopter Project
//
// Authors: Annabelle Ritchie, Karan Naidu, Emily Tideswell
// Group 13, Thursday PM lab
// Last modified:   1/6/19
//
//*****************************************************************************
// Based on the 'convert' series from 2016
//*****************************************************************************

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
#include "display.h"
#include "altitude.h"
#include "yaw.h"
#include "kernel.h"
#include "uart.h"
#include "pwmGen.h"

int main(void)
{
    initialiseEverything();
    while (1)
    {
        runScheduler();
    }
}
