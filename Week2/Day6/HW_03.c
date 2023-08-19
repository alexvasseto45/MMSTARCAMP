#include <stddef.h>
#include <stdio.h>

int isPositive(int a){
    if(a > 0){
        return 1;
    }
    return 0;
}

int addOne(int a){
    return a+1;
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
}

int main(){
    int arr[8] = {1,2,3,4,-1,-2,11,-100};
    int dest[10];
    size_t new_size;
    filter_and_map(arr, 8, isPositive, addOne, dest, &new_size);
    return 0;
}