#include "bsp.h"
//#include "tm4c_cmsis.h"
#include "TM4C123GH6PM.h"
#include "stdint.h"

uint8_t flag;

void LedInit(void)
{

SYSCTL->RCGC2 |= (1<<5); /* Clock Gating for PORTF*/
GPIOF->DIR = LED_RED | LED_BLUE | LED_GREEN; /* Select selected gpio direction as output */
GPIOF->DEN = LED_RED | LED_BLUE | LED_GREEN; /*  Enabled Digital ouput */
}
void SysTickInit(void)
{
  SysTick->LOAD    = TICKS_HALF_SECOND -1; /*Load TICKS for Half second */
  SysTick->VAL     = 0U; /*Load current value to zero*/
  SysTick->CTRL    = (1U<<2) | (0U<<1) | 1U; /* BIT0 - Enable systick timer, BIT1 - Interrupt mode, BIT2 - System clock 16MHZ*/
}

void TimerInit(void)
{
  
  SYSCTL->RCGCTIMER |= (1<<0);
  /*The GPTM is configured for One-Shot and Periodic modes by the following sequence:
1. Ensure the timer is disabled (the TnEN bit in the GPTMCTL register is cleared) before making
any changes.*/
  
  TIMER0->CTL &= ~(1<<0);  // BIT0 to Enable TimerA
  
/*2. Write the GPTM Configuration Register (GPTMCFG) with a value of 0x0000.0000.*/
  
  TIMER0->CFG = 0x00000000;   // For a 16/32-bit timer, this value selects the 32-bit timer
    
/*3. Configure the TnMR field in the GPTM Timer n Mode Register (GPTMTnMR):
a. Write a value of 0x1 for One-Shot mode.
b. Write a value of 0x2 for Periodic mode.*/
  
  //TIMER0->TAMR = (TIMER0->TAMR & (~(0x3<<0))) | (0x1<<0); //one shot mode, once It raises RIS flag then it diable the timer. 
  TIMER0->TAMR = (TIMER0->TAMR & (~(0x3<<0))) | (0x2<<0);  //periodic mode
    
/*4. Optionally configure the TnSNAPS, TnWOT, TnMTE, and TnCDIR bits in the GPTMTnMR register
to select whether to capture the value of the free-running timer at time-out, use an external
trigger to start counting, configure an additional trigger or interrupt, and count up or down.*/
  
  TIMER0->TAMR &= ~(1<<4);
  
/*5. Load the start value into the GPTM Timer n Interval Load Register (GPTMTnILR)*/
  
  TIMER0->TAILR = 0x00F42400; //16,000,000
  
 
  /*PRE scalar value is loaded into GPTMTnV Register in upper 16 bit,this values gets decremented first before timervalue gets decremnted
     NOTE:In 16-bit mode, only the lower 16-bits of the GPTMTAV
    register can be written with a new value. Writes to the
    prescaler bits have no effect*/
  
  TIMER0->TAPR  = 0x000000ff; // Prescalar can be configure for 16/32 Timer0 runs in 16 bit timer mode
  
/*6. If interrupts are required, set the appropriate bits in the GPTM Interrupt Mask Register
(GPTMIMR).*/
  
  TIMER0->IMR |=  (1<<0);
 // NVIC->ISER |= (1<<19);
  NVIC_EnableIRQ(TIMER0A_IRQn);
  
/*7. Set the TnEN bit in the GPTMCTL register to enable the timer and start counting.*/
  TIMER0->CTL |= (1<<0) | (1<<1); //TnEN is Bit0 , TASTALL - To stall timer in debugger mode BIT1 , TASTALL is ignored if RTCEN bit (Bit4) is set 
  
/*8. Poll the GPTMRIS register or wait for the interrupt to be generated (if enabled). In both cases,
the status flags are cleared by writing a 1 to the appropriate bit of the GPTM Interrupt Clear
Register (GPTMICR).*/
  
  
  
/*If the TnMIE bit in the GPTMTnMR register is set, the RTCRIS bit in the GPTMRIS register is set,
and the timer continues counting. In One-Shot mode, the timer stops counting after the time-out
event. To re-enable the timer, repeat the sequence. A timer configured in Periodic mode reloads
the timer and continues counting after the time-out event.*/
    /* Systick interrupt in poling mode*/
}
void delay (int count)
{
  while(count>0)
  {
    count--;
  }
}

__stackless void assert_failed (char const *file, int line) {
  /* TBD: damage control */
  NVIC_SystemReset(); /* reset the system */
}


/*SysTick timer interrupt handler*/
/*void SysTick_Handler(void)
{
  GPIOF->DATA_Bits[LED_RED] ^= LED_RED; 
}*/
                                          
void Timer0A_IRQHandler()
{
  TIMER0->ICR = (1<<0);
  flag = FLAG_TOGGLE;
}
