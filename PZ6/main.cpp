
#include <stdio.h>
#include <iostream>
#include <unistd.h>

int main(int argc, char const* argv[])
{
    while(1){
        std::cout << "Hello ";
        __asm__ __volatile__("int1");
        std::cout << "World! \n";
    }
}