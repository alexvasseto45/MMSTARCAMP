#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>

typedef struct{
    const char* filename;
    int sum;
}Thread ;

int sumNumbers(uint64_t number){
    int sum =0;
    while (number> 0) {
        sum += number%10;
        number/=10;
    }
    return sum;
}

void* threadFunc(void* arg){
    Thread* t = (Thread*)arg;
    uint64_t number;
    FILE* f = fopen(t->filename,"r");
    if(!f){
        perror("file not opened");
        pthread_exit(NULL);
    }
    while (fread(&number, sizeof(uint64_t), 1, f)==1) {
        t->sum +=sumNumbers(number);
    }
    fclose(f);
    pthread_exit(NULL);
}

int main(int argc, char* argv[]){
    if(argc<2){
        fprintf(stderr, "Not enough arg\n");
        return -1;
    }
    int sum = 0;
    pthread_t thread[argc-1];
    Thread t[argc-1];
    for(int i =1; i<argc;i++){
        t[i-1].filename=argv[1];
        t[i-1].sum=0;
        pthread_create(&thread[i-1], NULL, threadFunc, &t[i-1]);
    }
    for(int i=0;i<argc-1;i++){
        pthread_join(thread[i],NULL);
        sum +=t[i].sum;
    }
    printf("%d",sum);
    return 0;
}