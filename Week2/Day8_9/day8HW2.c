#include <stddef.h>
#include <stdio.h>

int cmpInt(const void* p1,const void* p2){
    if(p1==p2){
        return 0;
    }
    return *(int*)p1 > *(int*)p2 ? 1:-1;
}

void* findMax(void* arr,size_t n,size_t elem_s, int (*cmp)(const void*,const void*)){
    int *max =(int*)arr;
    int result = 0;
    for (size_t i = 0;i<n;i++){
        result = cmp(&((int*)arr)[i], max);
        //result = cmp(&arr[i*elem_s],max);
        if(result==1){
            max = &((int*)arr)[i];
        }
    }
    return max;
}

int main(){
    int arr[] = {1,2,-1,3,5,11,12,13,2,100,22};
    int* max = findMax(arr, sizeof(arr)/sizeof(int), sizeof(int), cmpInt);
    printf("%d",*max);
    return 0;
}