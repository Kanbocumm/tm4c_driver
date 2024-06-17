#include <stdio.h>
#include <stdint.h>
#include "uartdma.h"

void sys_clock(void)
{
    SysCtlClockSet(SYSCTL_SYSDIV_2_5 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);
}
/* PD6, PD7 for UART config pins */
void gpio_init()
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

    //IOIntRegister(GPIO_PORTA_BASE, PortAIntHandler);

    GPIOPadConfigSet(GPIO_PORTA_BASE , GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4, GPIO_STRENGTH_4MA, GPIO_PIN_TYPE_STD);

    GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE,(GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4));

    GPIOIntTypeSet(GPIO_PORTA_BASE, GPIO_PIN_2 | GPIO_PIN_4, GPIO_RISING_EDGE);

    GPIOIntTypeSet(GPIO_PORTA_BASE, GPIO_PIN_3, GPIO_HIGH_LEVEL);

    GPIOIntEnable(GPIO_PORTA_BASE, GPIO_PIN_2 | GPIO_PIN_4 | GPIO_PIN_3);

}

void gpio_write(uint32_t port_base, uint32_t pin_num, uint8_t pin_state)
{
    GPIOPinWrite(port_base, pin_num, pin_state);

}

void uart_dma_init()
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);

    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOD))
    {
    }

    GPIOPinTypeUART(GPIO_PORTD_BASE, GPIO_PIN_6 | GPIO_PIN_7);

    GPIOPinConfigure(GPIO_PD6_U2RX);
    GPIOPinConfigure(GPIO_PD7_U2TX);

    UARTDisable(UART2_BASE);


    /* Configure the UART2 peripheral */
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART2);

    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_UART2))
    {

    }


    UARTConfigSetExpClk(UART2_BASE, SysCtlClockGet(), 9600, (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));

    UARTFIFOEnable(UART2_BASE);

}

uint16_t uart_calculate_br(uint32_t uart_clk, uint32_t uart_baud_rate)
{

}

void uart_set_br(uint32_t uart_clk, uint32_t uart_baud_rate)
{

}

void uart_dma_transmit(uint32_t base_uart)
{
    UARTCharPutNonBlocking(base_uart, uart_tx_data);

}

uint32_t uart_dma_receive(uint32_t base_uart)
{
    vola_receive_data =  UARTCharGetNonBlocking(base_uart);


   static uint32_t index = 0;

      if (index < UART_BUF_SIZE) {
          receive_data[index++] = vola_receive_data;
      } else {
          // Handle buffer overflow if necessary
      }

      return vola_receive_data;
}

int main(void)
{
    sys_clock();
    uart_dma_init();
    //gpio_init();

    while(1)
        {
        receive_data_last = uart_dma_receive(UART2_BASE);

        }

	return 0;
}
