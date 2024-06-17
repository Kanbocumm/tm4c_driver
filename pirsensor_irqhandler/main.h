#ifndef MAIN_H_
#define MAIN_H_


#include <stdint.h>                     // Library of Standard Integer Types
#include <stdbool.h>                    // Library of Standard Boolean Types
#include "inc/tm4c123gh6pm.h"           // Definitions for interrupt and register assignments on Tiva C
#include "inc/hw_memmap.h"              // Macros defining the memory map of the Tiva C Series device
#include "inc/hw_types.h"               // Defines common types and macros
#include "driverlib/sysctl.h"           // Defines and macros for System Control API of DriverLib
#include "driverlib/interrupt.h"        // Defines and macros for NVIC Controller API of DriverLib
#include "driverlib/gpio.h"             // Defines and macros for GPIO API of DriverLib
#include "driverlib/timer.h"            // Defines and macros for Timer API of driverLib


void sys_clock(void);
void gpio_init(void);
void hc05_init(void);
void timer_IRQ_handler(void);
void timer_init(void);


#endif /* MAIN_H_ */
