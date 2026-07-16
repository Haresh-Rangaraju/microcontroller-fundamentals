#include<stdio.h>
#include<stdint.h>
int main(){
    uint8_t GPIO_REGISTER= 0x00;

    GPIO_REGISTER |=(1<<2);
    printf("After setting bit_2= %u\n", GPIO_REGISTER);

    GPIO_REGISTER &=~(1<<2);
    printf("After clearing bit_2= %u\n", GPIO_REGISTER);

    uint16_t ADC_REGISTER= 523;

    printf("ADC value= %u\n", ADC_REGISTER);

    return 0;
}
