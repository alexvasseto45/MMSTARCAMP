#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encode_char(int number){
    char arr[501];
    snprintf(arr, sizeof(char), "%d", number);
    char* parr = (char*)malloc((strlen(arr)+1)*sizeof(char));
    for (size_t i =0;i<strlen(arr); i++) {
        if(arr[i]%2==0){
            switch (arr[i]) {
                case 0: arr[i]='A';
                break;
                case 1: arr[i]='B';
                break;
                case 2: arr[i]='C';
                break;
                case 3: arr[i]='D';
                break;
                case 4: arr[i]='E';
                break;
                case 5: arr[i]='F';
                break;
                case 6: arr[i]='G';
                break;
                case 7: arr[i]='H';
                break;
                case 8: arr[i]='I';
                break;
                case 9: arr[i]='J';
                break;
            }
        }
        else {
             switch (arr[i]) {
                case 0: arr[i]='!';
                break;
                case 1: arr[i]='#';
                break;
                case 2: arr[i]='/';
                break;
                case 3: arr[i]='~';
                break;
                case 4: arr[i]='=';
                break;
                case 5: arr[i]='`';
                break;
                case 6: arr[i]='\\';
                break;
                case 7: arr[i]='>';
                break;
                case 8: arr[i]='.';
                break;
                case 9: arr[i]=',';
                break;
            }
        }
    }
    return parr;
}

int main(){
    int number;
    scanf("%d",&number);
    char *parr = encode_char(number);
    printf("%s",parr);
    free(parr);
    return 0;
}