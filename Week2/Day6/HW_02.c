#include <stdint.h>
#include <stdio.h>
#define TINT 0100;
#define TCHAR 01100001;
#define TDOUBLE 1100;
#define TFLOAT 100;
#define TUINT8_T 10000000;
#define TUINT16_T 1000000000000000;

void printValue(const void* valuePtr, uint8_t flag){
    //if (flag == 0000100){
    //    int a = *valuePtr;
     //   printf("Value: %d",*valuePtr);
    //}
    printf("Value: %p",valuePtr);
}
int main(){
    int ptr = 23;
    printValue(&ptr, TINT);
}