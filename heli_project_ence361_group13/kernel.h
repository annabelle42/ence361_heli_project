#ifndef KERNEL_H_
#define KERNEL_H_

int32_t meanAlt;

//*****************************************************************************
//
// Main scheduler loop
//
//*****************************************************************************
void runScheduler (void);

//*****************************************************************************
//
// Initializes everything across all modules
//
//*****************************************************************************
void initialiseEverything (void);


#endif /* KERNEL_H_ */