#include "main.h"


void sys_clock(void)
{
    SysCtlClockSet(SYSCTL_SYSDIV_2 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN);
}

void gpio_init(void)
{


}


void hc05_init(void)
{
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGC2_GPIOE;

    SYSCTL_RCGCUART_R |=







}


int main(void)
{
    sys_clock();

    gpio_init();

    hc05_init();

    while(1);

}
