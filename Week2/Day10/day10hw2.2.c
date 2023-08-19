#include <stdio.h>
#include <stdint.h>

typedef struct float_comp{
    unsigned int mantissa:23;
    unsigned int exponent:8;
    unsigned int sign:1;
}float_comp;

typedef union F{
    float f;
    float_comp c;
}F;

int main(){
    F f1;
    f1.f = 123.456;
    printf("%u, %u, %u",f1.c.sign,f1.c.exponent,f1.c.mantissa);
    return 0;
}