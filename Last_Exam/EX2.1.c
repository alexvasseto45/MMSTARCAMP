#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdint.h>
#define BUF_SIZE 1000
int N=1100;

int main(int argc, char** argp){  
    if(argc != 3) {
        fprintf(stderr, "Argc invalid\n");
        exit(-1);
    }
    FILE* f1 = fopen(argp[1], "w");
    if(!f1) {
        perror("fopen error");
        exit(-1);
    }
    size_t N = atoi(argp[2]);
    size_t buf[BUF_SIZE];
    for(size_t i = 0; i < N; i++) {
        if(i % BUF_SIZE == 0 && i != 0) {
            fwrite(buf, sizeof(*buf), BUF_SIZE, f1);
        }
        buf[i%BUF_SIZE] = i;
    }

    
    fclose(f1);
    return 0;
}