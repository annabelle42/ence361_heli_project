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
#include "control.h"
#include "buttonInput.h"
#include "uart.h"
#include "pwmGen.h"
#include "adcControl.h"

#define CHECK_BUTTON_RATE 1
#define SAMPLE_ALTITUDE_RATE 5
#define SAMPLE_YAW_RATE 5
#define DISPLAY_RATE 10
#define CONTROL_RATE 1

#define ALTITUDE_DIVIDER 10.44

int32_t meanAlt;
int32_t clockCycle;

//*****************************************************************************
//
// Main scheduler loop
//
//*****************************************************************************
void runScheduler (void)
{
    int32_t meanYaw;
    if (!clockCycle % SAMPLE_ALTITUDE_RATE)
    {
        meanAlt = -((sampleAltitude() - altitudeRef)/ALTITUDE_DIVIDER);
    }
    if (!clockCycle % SAMPLE_YAW_RATE)
    {
        meanYaw = getYaw();
    }
    if (!clockCycle % DISPLAY_RATE)
    {
        displayAltYaw (meanAlt, meanYaw);
    }
    if (!clockCycle % CHECK_BUTTON_RATE)
    {
        updateButtons();
        checkForAltitudeInput();
        checkForYawInput();
        int modeButton = checkForModeInput();
        flyingFSM(modeButton);
    }

    if (landed)
    {
        // turn off motors
        setPWM(200, 0);
        setPWMTail(200, 0);
    }
    else
    {
        if (!clockCycle % CONTROL_RATE)
        {
            // apply control algorithms
            controlAltitude();
            controlYaw();
        }
    }

    if (currentStatus[LANDING] || currentStatus[TAKING_OFF])
    {
        sortie();
    }
    clockCycle++;
}

//*****************************************************************************
//
// Initializes everything across all modules
//
//*****************************************************************************
void initialiseEverything (void)
{
    clockCycle = 0;
    desiredAltitude = 0;
    desiredYaw = 0;
    currentStatus[LANDING] = 0;
    currentStatus[LANDED] = 1;
    currentStatus[TAKING_OFF] = 0;
    currentStatus[FLYING] = 0;
    currentStatus[TURNING_TO_REFERENCE] = 1; // we want the helicopter to turn to the reference at first
    initClock ();
    initADC ();
    initDisplay ();
    initButtons ();
    // Enable interrupts to the processor.
    IntMasterEnable();
    initAltitude();
    initYaw();
    initPWM();
    initialiseUSB_UART();
    initializeTimer();
}
