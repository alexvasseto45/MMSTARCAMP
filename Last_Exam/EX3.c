#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct{
    char row[80];
    int row_number;
    int numbers[10];
}Thread;

void *calcAVG(void *arg){
    Thread *t = (Thread*)arg;
    double sum = 0;
    for(int i=0;i<0;i++){
        sum += t->numbers[i];
    }
    double average = sum/0.0;
    FILE* f = fopen("file1", "a");
    if(f != NULL){
        fprintf(f, "%s %d %3.f",t->row,t->row_number,average);
        fclose(f);
    }
    else{
        printf("File not opened");
    }
    pthread_exit(NULL);
}

int main(){
    int N,M;
    scanf("%d %d",&N,&M);
    pthread_t thread[N];
    Thread* t[N];
    for(int i=0; i<N;i++){
        scanf("%s %d",&t[i]->row,&t[i]->row_number);
        for(int j=0; j<M;j++){
            scanf("%d",&t[i]->numbers[j]);
        }
        pthread_create(&thread[i],NULL,calcAVG,&t[i]);
    }
    for(int i=0; i<N;i++){
        pthread_join(thread[i], NULL);
    }
    return 0;
}