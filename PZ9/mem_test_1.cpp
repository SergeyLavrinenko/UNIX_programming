#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Утечка памяти
int main(int argc, char *argv[])
{
    char *buf = (char*) malloc(100);
    strcpy(buf, "Hello world!");
    printf("string is: %s\n", buf);
    return 0;
}