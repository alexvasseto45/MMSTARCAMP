#include <stdint.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<sys/mman.h>

int sumNumbers(uint64_t number){
    int sum =0;
    while (number> 0) {
        sum += number%10;
        number/=10;
    }
    return sum;
}

int main(int argc,char* argv[]){
    int totalsum = 0;
    if(argc<2){
        fprintf(stderr, "Not enough arg\n");
        return -1;
    }
    int sum=0;
    for (int i=1;i<argc;i++){
        pid_t pid = fork();
        if(pid == -1){
            perror("fork");
        }
        else if(pid == 0){
            uint64_t number;
            FILE* f = fopen(argv[1],"rb");
            if(!f) {
            perror("fopen error");
            exit(-1);
            }
            while (fread(&number, sizeof(uint64_t), 1, f)==1) {
                totalsum +=sumNumbers(number);
            }
            fclose(f);
        }
    }
    for(int i =1; i< argc;i++){
        wait(NULL);
    }
    printf("%d",totalsum);
}