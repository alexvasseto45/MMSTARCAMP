#include <stdio.h>
#include <string.h>

int main(int argc, char*argv[]){
    int sum =0;
    for(int i = 1;i<argc;i++){
        int num;
        sscanf(argv[i],"%d" ,&num);
        sum +=num;
    }
    printf("%d",sum);
    return 0;
}