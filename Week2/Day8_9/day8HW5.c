#include <stdio.h>
#include <stdint.h>

typedef struct MyTime {
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
}MyTime;

int isLeapYear(MyTime t){
    if(t.year%4 == 0){
        return 1;
    }
    return 0;
}

int totalDaysInYear(MyTime t){
    if(isLeapYear(t)==1){
        return 366;
    }
    return 365;
}
void printMonth(MyTime t){
    switch (t.month) {
        case 1:
        printf("January");
        break;
        case 2:
        printf("February");
        break;
        case 3:
        printf("March");
        break;
        case 4:
        printf("April");
        break;
        case 5:
        printf("May");
        break;
        case 6:
        printf("June");
        break;
        case 7:
        printf("July");
        break;
        case 8:
        printf("August");
        break;
        case 9:
        printf("September");
        break;
        case 10:
        printf("October");
        break;
        case 11:
        printf("November");
        break;
        case 12:
        printf("December");
        break;
    
    }
}

int main(){
    MyTime t;
    t.year = 2024;
    t.month = 8;
    t.day = 8;
    t.hour = 12;
    t.minute = 30;
    t.second = 45;
    if(isLeapYear(t)==1){
        printf("Leap year\n");
    }
    else {
        printf("Not a leap year\n");
    }
    printf("How many days: %d\n",totalDaysInYear(t));
    printMonth(t);
}