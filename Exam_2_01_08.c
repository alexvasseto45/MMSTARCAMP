#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Car{
    char model[20];
    uint8_t maxspeed;
    double price;
}Car;

int compare_model_inc(const void* p1, const void* p2){
    return (strcmp(((Car*)p1)->model,(((Car*)p2))->model))*1000;
}

int compare_model_desc(const void* p1, const void* p2){
    return (strcmp(((Car*)p2)->model,(((Car*)p1))->model))*1000;
}

int compare_maxspeed_inc(const void* p1, const void* p2){
    return ((((Car*)p1))->maxspeed - (((Car*)p2))->maxspeed)*1000;
}

int compare_maxspeed_desc(const void* p1, const void* p2){
    return ((((Car*)p2))->maxspeed - (((Car*)p1))->maxspeed)*1000;
}

int compare_price_inc(const void* p1, const void* p2){
    return ((((Car*)p1))->price - (((Car*)p2))->price)*1000;
}

int compare_price_desc(const void* p1, const void* p2){
    return ((((Car*)p1))->price - (((Car*)p2))->price)*1000;
}

void print_arr(Car arr[],size_t n){
    for(size_t i =0; i<n;i++){
        printf("%s %u %lf",arr[i].model,arr[i].maxspeed, arr[i].price);
    }
    printf("\n");
}

int (*getComparator(int n))(const void*,const void*){
    switch (n) {
        case 1: 
        return compare_model_inc;
        break;
        case 2: 
        return compare_model_desc;
        break;
        case 3: 
        return compare_maxspeed_inc;
        break;
        case 4: 
        return compare_maxspeed_desc;
        break;
        case 5: 
        return compare_price_inc;
        break;
        case 6: 
        return compare_price_desc;
        break;
        default:
        return 0;
    }
}
int main(){
    Car *arr = malloc(10*sizeof(Car));
    int number;
    for(size_t i = 0;i<10;i++){
        scanf("%20s",arr[i].model);
        scanf("%hhu",&arr[i].maxspeed);
        scanf("%lf",&arr[i].price);
    }
    printf("Enter a number between 1 and 6: ");
    scanf("%d",&number);
    qsort(arr,10,sizeof(Car),getComparator(number));
    print_arr(arr, 10);
    return 0;
}