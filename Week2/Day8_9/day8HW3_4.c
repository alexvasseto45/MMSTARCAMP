#include <stddef.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

typedef struct Point {
    double x;
    double y;
    double z;
} Point;


// int cmpInt(const void* p1,const void* p2){
//     if(p1==p2){
//         return 0;
//     }
//     return *(int*)p1 > *(int*)p2 ? 1:-1;
// }

int cmpUint64_t(const void* p1,const void* p2){
    if(p1==p2){
        return 0;
    }
    return *(uint64_t*)p1 > *(uint64_t*)p2 ? 1:-1;
}

// int cmpBits1(const void* p1, const void* p2){
//     int counter1 = 0,cointer2 = 0;
//     for()
// }


typedef struct Human {
    double weight_kg;
    uint16_t height_cm;
} Human;

int cmpBMI(const void* p1, const void* p2){
    if (p1==p2){
        return 0;
    }
    const Human human1,human2;
    p1 = &human1;
    p2 = &human2;
    return human1.weight_kg/human1.height_cm*human1.height_cm - human2.weight_kg/human2.height_cm*human2.height_cm ? -1:1;
}

int cmpPoints(const void* p1, const void* p2){
    if(p1==p2){
        return 0;
    }
    const Point point1;
    const Point point2;
    p1 = &point1;
    p2 = &point2;
    return sqrt(point1.x * point1.y * point1.z) - sqrt(point2.x*point2.y*point2.z) ? 1:-1;  
}


void* findMax(void* arr,size_t n,size_t elem_s, int (*cmp)(const void*,const void*)){
    uint64_t *max =(uint64_t*)arr;
    int result = 0;
    for (size_t i = 0;i<n;i++){
        result = cmp(&((uint64_t*)arr)[i], max);
        if(result==1){
            max = &((uint64_t*)arr)[i];
        }
    }
    return max;
}

int main(){
    uint64_t arr[] = {1,2,81,3,5,11,12,13,2,100,22};
    Point pointarr[] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };
    Human humanarr[]={
    {80,190},
    {90,180},
    {81,198}        
    };
    uint64_t* max = (uint64_t*)findMax(arr, sizeof(arr)/sizeof(uint64_t), sizeof(uint64_t), cmpUint64_t);
    Point* maxPoint = (Point*)findMax(pointarr, sizeof(pointarr)/sizeof(Point), sizeof(Point), cmpPoints);
    Human* maxHuman = (Human*)findMax(arr, sizeof(humanarr)/sizeof(Human), sizeof(Human), cmpBMI);
    printf("%lu",*max);
    printf("Max point: (%f, %f, %f)\n", maxPoint->x, maxPoint->y, maxPoint->z);
    return 0;
}