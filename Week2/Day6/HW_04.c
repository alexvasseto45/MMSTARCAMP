#include <stddef.h>
#include <stdio.h>
#include <stdint.h>

int isEven(int a){
    if(a%2 == 0){
        return 1;
    }
    return 0;
}
int isPositive(int a){
    if(a > 0){
        return 1;
    }
    return 0;
}

int isPrime(int a)
{
    int bool = 1;
    for (int i = 2; i <= a / 2; i++) {
        if (a % i == 0) {
            bool = 0;
            break;
        }
    }
    return bool;
}

int addOne(int a){
    return a+1;
}

int my_sqrt(int a){
    return a*a;
}

int bitCount(int a){
    int counter = 0;
    uint8_t b = a;
    for(size_t i=0;i<8;i++){
        counter += !!(b & (1ULL << i));
    }
    return counter;
}

void filter_and_map(const int arr[],size_t n, int (*filter_f)(int), int (*map_f)(int), int dest[], size_t* dest_cnt){
    int temp_num;
    *dest_cnt = 0;
    for (size_t i = 0;i<n;i++){
        if(filter_f(arr[i])==1){
            temp_num = arr[i];
            dest[*dest_cnt] = map_f(temp_num);
            (*dest_cnt)++;
        }
    }
    printf("new size: %lu\n", *dest_cnt);
    for(size_t i =0; i<*dest_cnt;i++){
        printf("%d ",dest[i]);
    }
    printf("\n");
}

int main(){
    int arr[8] = {1,2,3,4,-1,-2,11,-100};
    int dest[10];
    size_t new_size;
    filter_and_map(arr, 8, isPositive, addOne, dest, &new_size);
    filter_and_map(arr, 8, isEven, addOne, dest, &new_size);
    filter_and_map(arr, 8, isPrime, my_sqrt, dest, &new_size);
    filter_and_map(arr, 8, isPositive, bitCount, dest, &new_size);
    return 0;
}