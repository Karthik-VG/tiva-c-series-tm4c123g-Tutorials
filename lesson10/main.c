#include "lm4f120h5qr.h"

#define LED_RED   (1U << 1)
#define LED_BLUE  (1U << 2)
#define LED_GREEN (1U << 3)


int main() {
    SYSCTL_RCGCGPIO_R |= 0x20u;  /* enable clock for GPIOF */
    GPIO_PORTF_DIR_R |= 0x0E;
    GPIO_PORTF_DEN_R |= 0x0E;
    GPIO_PORTF_DATA_R |= LED_BLUE;   
     while (1) {
       int volatile co=0;  
        GPIO_PORTF_DATA_R |= LED_GREEN;
      while(co<1000000){
       
`       ++co;
      }
      GPIO_PORTF_DATA_R  &= ~LED_GREEN ;
            co=0;
      while(co<1000000){
        
        ++co;
      }
    }
    return 0;
}
