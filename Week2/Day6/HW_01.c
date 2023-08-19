#include <stdio.h>

double korenTreti(double a){
    double b = 0;
    while(b*b*b-a>1 && b*b*b-a<1){
        b+=0.01;
    }
    return b;
}
int main(){
    printf("%lf",korenTreti(27));
}