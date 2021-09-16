#include "lm4f120h5qr.h"
#define RED   (1U<<1)
#define BLUE  (1U<<2)
#define GREEN (1U<<3)
#define DATA GPIO_PORTF_DATA_R
int main(){ 
  {
    *((unsigned int *)0x400FE608U)=0x20u;
    *((unsigned int *)0x40025400U)=0x0Eu;
    *((unsigned int *)0x4002551CU)=0x0EU;
    *((unsigned int *)0x400253FCU)=0x02U;
    *((unsigned int *)0x400253FCU)=0x00U;

}
  return 0;
}
  

