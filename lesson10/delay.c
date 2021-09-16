#include "delay.h"

void delay(int iter);


void delay(int iter) {
    int volatile counter123;
    counter123 = 0;
    while (counter123 < iter) {  // delay loop
        ++counter123;
    }
}