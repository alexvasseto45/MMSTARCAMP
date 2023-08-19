#include <stdio.h>
#include <stdarg.h>
#include <time.h>

int printf_time(const char *format, ...) {
    time_t myTime = time(NULL);
    struct tm *timeinfo = localtime(&myTime);
    char timeArr[20];
    strftime(timeArr,sizeof(timeArr), "[%d.%m.%Y - %H:%M:%S]", timeinfo);
    printf("%s ", timeArr);
    va_list args;
    va_start(args, format);
    int result = vprintf(format, args);
    va_end(args);
    return result;
}

int main() {
    printf_time("%d %d\n", 10, 20);
    return 0;
}