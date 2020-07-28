/**********************************************************
 *
 * pwmGen.h - Module for generating PWM signals for the
 * main and tail rotors of the helicopter.
 *
 * Authors: Annabelle Ritchie, Karan Naidu, Emily Tideswell
 * Group 13, Thursday PM lab
 * Contributions:  P.J. Bones   UCECE -- provided base code
 **********************************************************/

#ifndef PWMGEN_H_
#define PWMGEN_H_

/*********************************************************
 * initialisePWM
 * M0PWM7 (J4-05, PC5) is used for the main rotor motor
 *********************************************************/
void initialisePWM (void);

/*********************************************************
 * initialisePWMTail
 * M1PWM5 (J3-10, PF1) is used for the tail rotor motor
 *********************************************************/
void initialisePWMTail (void);

/********************************************************
 * setPWM
 * Function to set the freq, duty cycle of M0PWM7
 ********************************************************/
void setPWM (uint32_t u32Freq, uint32_t u32Duty);

/********************************************************
 * setPWMTail
 * Function to set the freq, duty cycle of M1PWM5
 ********************************************************/
void setPWMTail (uint32_t u32Freq, uint32_t u32Duty);

/********************************************************
 * initPWM
 * Initialises PWMs for both the main and tail rotors.
 ********************************************************/
void initPWM (void);

#endif /* PWMGEN_H_ */
