#include <stddef.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define ID_LEN 4

struct Person{
    char name[100];
    char id[ID_LEN];
    uint16_t birthYear : 11;
    uint8_t birthMonth : 4;
    uint8_t birthDay : 5;
    uint8_t gender : 1;
};

int counter = 0;

void* initArray(size_t capacity){
    //struct Person p;
    struct Person* arr = malloc(capacity*sizeof(struct Person));
    return arr;
}

void generateRandomID(char *ID,int length){
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    srand(time(NULL));
    for(int i = 0;i<length;i++){
        ID[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    ID[length] = '\0';
}

int addPerson(char* name, unsigned short birthYear, unsigned char birthMonth,unsigned char birthDay, char gender){
    struct Person p;
    strcpy(p.name, name);
    generateRandomID(p.id, ID_LEN);
    strcpy(p.id, "abc");
    p.birthYear = birthYear;
    p.birthMonth = birthMonth;
    p.birthDay = birthDay;
    p.gender = gender;
    if(birthYear == p.birthYear&&birthMonth == p.birthMonth&&birthDay==p.birthDay&&gender == p.gender){
        counter++;
        return 0;
    }
    else {
        return 1;
    }
}

// int addPerson1(char* name, unsigned short birthYear, unsigned char birthMonth, unsigned char birthDay, char gender) {
//     struct Person p;
//     strcpy(p.name, name);
//     generateRandomID(p.id, ID_LEN);
//     p.birthYear = birthYear;
//     p.birthMonth = birthMonth;
//     p.birthDay = birthDay;
//     p.gender = gender;

//     if (!(birthYear == p.birthYear && birthMonth == p.birthMonth && birthDay == p.birthDay && gender == p.gender)) {
//         //p[counter] = p;
//         counter++;
//         return 0;  // Return success
//     } else {
//         return 1;  // Return failure
//     }
// }


int removePerson(char*id){
    struct Person p[counter];
    int index = -1;
    for(int i = 0; i<counter; i++){
        if(strcmp(p[i].id, id)==0){
            index = i;
            break;
        }
    }

    if (index != 1) {
        for(int i = index;i<counter;i++){
            p[i] = p[i+1];
        }
        return 1;
        counter --;
    }
    return -1;
}

// void readPerson(){

// }

int printPerson(struct Person* p,char *id){
    int index = -1;
    for(int i = 0; i<counter; i++){
        if(strcmp(p[i].id, id)==0){
            index = i;
        }
    }

    if(index != -1){
        printf("%s \n",p[index].id);
        printf("%s \n",p[index].name);
        printf("%u \n",p[index].birthYear);
        printf("%u \n",p[index].birthMonth);
        printf("%u \n",p[index].birthDay);
        switch (p[index].gender) {
            case 0:
            printf("Male");
            break;
            case 1:
            printf("Female");
            break;
        }
        //printf("%d \n",p[index].gender);
    }
    return 0;
}

int main(){
    struct Person* arr = (struct Person*)initArray(2);
    int a =addPerson("Alex", 2003, 4, 29, 1);
    addPerson("Angel", 2003, 1, 11, 0);
    printPerson(arr,arr[0].id);
    int b =removePerson(arr[1].id);
    printPerson(arr,arr[1].id);
    free(arr);
}