#include <stdio.h>
#include <stdint.h>
#include <string.h>

uint32_t checkBit(uint32_t mask, int bit){
    return mask & (1<<bit) ? 1:0;
}
typedef struct float_comp{
    unsigned int mantissa:23;
    unsigned int exponent:8;
    unsigned int sign:1;
}float_comp;

typedef union F{
    float f;
    float_comp c;
}F;

void printBits(float word){
    uint32_t number;
    memcpy(&number, &word, sizeof(float));
    printf("Sign: ");
    printf("%u",checkBit(number, (32-1)));
    printf(" Exponent: ");
    for(int i=31;i>23;i--){
        printf("%u",checkBit(number, (i-1)));
    }
    printf(" Mantissa: ");
    for(int i=23;i<24&&i>0;i--){
        printf("%u",checkBit(number, (i-1)));
    }

}

int main(){
    F f1;
    f1.f = -123.456;
    printBits(f1.f);
    printf("\n%u, %u, %u",f1.c.sign,f1.c.exponent,f1.c.mantissa);
}