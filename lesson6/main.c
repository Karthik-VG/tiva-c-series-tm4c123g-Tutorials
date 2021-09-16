#include "lm4f120h5qr.h"
#define LED_RED (1U<<1)
#define LED_BLUE (1U<<2)
#define LED_GREEN (1U<<3)

int main()
{
  SYSCTL_RCGCGPIO_R |=0x20U;
  GPIO_PORTF_DIR_R |=0x0EU;
  GPIO_PORTF_DEN_R |=0x0EU;
  ;
  while(1){
    
    
     GPIO_PORTF_DATA_R=GPIO_PORTF_DATA_R | LED_BLUE;
    int volatile counter=0;
    while(counter<100000){
      ++counter;
    }
    GPIO_PORTF_DATA_R=GPIO_PORTF_DATA_R & ~LED_BLUE;
    counter=0;
    while(counter<500000){
      ++counter;
    }
  }
  return 0;
}