#include "bsp.h"
#include "tm4c_cmsis.h"

extern uint8_t flag;
unsigned int jiffies=0;
int main()
{
  LedInit();/*Init PORTF LED */
  //SysTickInit(); /*Init the SysTick timer*/
  TimerInit();
  //GPIOF->DATA_Bits[LED_RED] = LED_RED;
  while (1)
  {
    //Polling method
    /*if((TIMER0->RIS & (1<<0)) == 0x00000001)
    {
      TIMER0->ICR = (1<<0);
      GPIOF->DATA_Bits[LED_BLUE] ^= LED_BLUE;
      
    }*/
    
    //Interrupt method
    if(flag==FLAG_TOGGLE)
    {
      flag = FLAG_NONE;
      GPIOF->DATA_Bits[LED_BLUE] ^= LED_BLUE;
    }
   /* GPIOF->DATA_Bits[LED_BLUE] ^= LED_BLUE;
    delay(500000);*/
  }
  return 0;
}
