#include<stdio.h>
#include<stdint.h>
int main(void){
    uint32_t GPIO_ODR =0;
    GPIO_ODR |=(1<<5);
    printf("GPIO register= 0x%X\n", GPIO_ODR);
    return 0;
}
