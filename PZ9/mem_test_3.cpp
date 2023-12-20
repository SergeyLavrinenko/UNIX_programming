#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Переполнение буфера
int main(int argc, const char *argv[]) {
    char *buf = (char*) malloc(strlen("Hello world!"));
    strcpy(buf, "Hello world!");
    printf("string is: %s\n", buf);
    free(buf);
    return 0;
}