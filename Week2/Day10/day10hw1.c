#include <stdio.h>
#include <stdint.h>

int check_bit(uint16_t mask,int bit){
     return mask & (1<<bit)? 1:0;
    }

void swapBytes(uint16_t* word){
    for(int i = 0; i<8;i++){
        int bitInFirstByte = check_bit(*word, i);
        int bitInSecondByte = check_bit(*word, i+8);
        if(bitInFirstByte != bitInSecondByte){
            if(bitInFirstByte == 1){
                *word &= ~(1ULL << i);
            }
            else{
                *word |= (1ULL << i);
            }
            if(bitInSecondByte == 1){
                *word &= ~(1ULL << (i+8));
            }
            else{
                *word |= (1ULL << (i+8));
            }
        }
    }
    printf("%u",*word);
}

int main(){
    uint16_t a = 3;
    uint16_t* p =&a;
    swapBytes(p);
}