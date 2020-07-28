/********************************************************
//
// uart.c - UART module for serial communication display
//
//
// Authors: Annabelle Ritchie, Karan Naidu, Emily Tideswell
// Group 13, Thursday PM lab
// Contributions:  P.J. Bones   UCECE -- provided base code
**********************************************************/

#ifndef UART_H_
#define UART_H_

//********************************************************
// initialiseUSB_UART - 8 bits, 1 stop bit, no parity
//********************************************************
void initialiseUSB_UART (void);

//**********************************************************************
// Transmit a string via UART0
//**********************************************************************
void UARTSend (char *pucBuffer);

//********************************************************
// Function to display a status message on the OLED
//********************************************************
void displayButtonState (char *butStr, char *stateStr,
    uint8_t numPushes, uint8_t charLine);



#endif /* UART_H_ */
