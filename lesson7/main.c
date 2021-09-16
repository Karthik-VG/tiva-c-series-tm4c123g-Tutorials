#define GPIOFBASE (*((unsigned int*)0x400FE608U))
int main(){ 

/* General-Purpose Input/Output Run Mode Clock Gating control
To make GPIO F block on  */
     GPIOFBASE= 0x20U;
    
    *((unsigned int*)0x40025400U) = 0x0EU;
    
    *((unsigned int*)0x4002551CU) = 0x0EU;
    
    
    
    while(1){
      
      volatile int counter=0;
      *((unsigned int*)0x400253FCU) = 0x04U;
      while(counter<1000000){
      *((unsigned int*)0x400253FCU) = 0x02U;
    
      ++counter;
      }
      counter=0;
      *((unsigned int*)0x400253FCU) = 0x00U;
      while(counter<1000000){
    
    ++counter;
      }
      
    }
    
}
