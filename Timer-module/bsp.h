#ifndef __BSP_H_
#define __BSP_H_

#define SYS_CLOCK_HZ 16000000U

#define COUNT_FLAG (1<<16) //SYStick Control register count flag 1-when systick timer reaches zero;0-when we read contol flag.

#define FLAG_NONE 0x00
#define FLAG_TOGGLE 0x01


#define TICKS_HALF_SECOND SYS_CLOCK_HZ/2
#define LED_RED (1<<1)
#define LED_BLUE (1<<2)
#define LED_GREEN (1<<3)

extern unsigned int jiffies;
extern  void SysTick_Handler();
//void SysTick_Handler1();
void LedInit(void);
void SysTickInit(void);
void delay(int);
void TimerInit(void);
#endif //__BSP_H_