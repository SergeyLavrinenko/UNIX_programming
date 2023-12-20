#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Использование после освобождения
int main(int argc,char *argv[]) {
    char *buf = (char*) malloc(100);
    strcpy(buf, "Hello world!");
    printf("string is: %s\n", buf);
    free(buf);
    printf("string is: %s\n", buf);
    return 0;
}