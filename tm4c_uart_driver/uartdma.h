/*
 * uartdma.h
 *
 *  Created on: 11 Jun 2024
 *      Author: Kanbocum
 */

#ifndef UARTDMA_H_
#define UARTDMA_H_

#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_sysctl.h"
#include "inc/hw_types.h"
#include "inc/hw_uart.h"
#include "driverlib/debug.h"
#include "driverlib/interrupt.h"
#include "driverlib/uart.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "inc/hw_gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"
#include "inc/hw_types.h"
#include "driverlib/fpu.h"
#include "inc/tm4c123gh6pm.h"
#include "inc/hw_timer.h"                   // Defines and macros used when accessing the timer
#include "driverlib/timer.h"                // Defines and macros for Timer API of driverLib
#include "driverlib/pin_map.h"              // Mapping of peripherals to pins for all parts


#define UART_BUF_SIZE 256

uint32_t uart_tx_data = 1;
volatile uint32_t vola_receive_data;
volatile uint32_t receive_data[UART_BUF_SIZE];
volatile uint32_t receive_data_last;

uint32_t g_sysclock;


/* U2Tx U2Rx
/* PA0 PA1 PA2 PA3 GPIO config output APB clock bus */


void gpio_init();
void uart_dma_init();
uint16_t uart_calculate_br(uint32_t uart_clk, uint32_t uart_baud_rate);
void uart_set_br(uint32_t uart_clk, uint32_t uart_baud_rate);
void uart_dma_transmit();
uint32_t uart_dma_receive(uint32_t base_uart);




#endif /* UARTDMA_H_ */
