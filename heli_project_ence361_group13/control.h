/**********************************************************
 *
 * control.h - Module for setting the duty cycles for the
 * PWM signals for the main and tail rotors of the
 * helicopter.  Duty cycles calculated using PID control.
 * Keeps track of the status of the helicopter (landed,
 * landing, taking-off, flying).
 *
 * Authors: Annabelle Ritchie, Karan Naidu, Emily Tideswell
 * Group 13, Thursday PM lab
 **********************************************************/
#ifndef CONTROL_H_
#define CONTROL_H_

int desiredAltitude;
int desiredYaw;

/*********************************************************
 * Used in flyingFSM to keep track of the state of the
 * helicopter.
 *********************************************************/

enum status currentStatus[6];

/*********************************************************
 * initialiseTimer
 * Initialises the timer that in the PID controller
 *********************************************************/
void initializeTimer (void);

/*********************************************************
 * integralControlUpdate
 * Returns the integral part of the PID controller output
 * for altitude if altitude parameter is true.  Otherwise
 * returns the integral part of the controller output for
 * yaw.
 *********************************************************/
double integralControlUpdate (double error, double delta_t, int altitude);

/*********************************************************
 * derivativeControlUpdate
 * Returns the derivative part of the PID controller
 * output for altitude if altitude parameter is true.
 * Otherwise returns the derivative part of the controller
 * output for yaw.
 *********************************************************/
double derivativeControlUpdate (double error, double delta_t, int altitude);

/*********************************************************
 * controlAltitude
 * Sets the duty cycle for the main PWM which controls the
 * altitude of the helicopter.  Duty cycle is calculated
 * using PID control.  Also transmits the duty cycle using
 * UART.
 *********************************************************/
void controlAltitude (void);

/*********************************************************
 * getYawError
 * Returns the difference between the desired yaw and
 * actual yaw.  Returned value is negative if the
 * helicopter has to turn CCW to reach the desired yaw,
 * and positive if it has to turn CW.
 *********************************************************/
int getYawError (int desired, int yaw);

/*********************************************************
 * controlYaw
 * Sets the duty cycle for the tail PWM which controls the
 * yaw of the helicopter.  Duty cycle is calculated
 * using PID control.  Also transmits the duty cycle using
 * UART.
 *********************************************************/
void controlYaw (void);

/*********************************************************
 * flyingFSM
 * Keeps track of the state of the helicopter.  Possible
 * states are landing, landed, taking-off, flying.
 *********************************************************/
void flyingFSM (int modeButton);

/*********************************************************
 * sortie
 * Rotates the helicopter to the reference yaw before
 * taking off.
 *********************************************************/
void sortie (void)

#endif /* CONTROL_H_ */
