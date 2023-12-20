#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

int main(int argc, char *argv[])
{
    std::string buf;

    std::getline(std::cin, buf);

    std::string start = "nm -an ";
    buf = start + buf;

    buf.append(" | grep asan | grep sanitizer");
    std::cout << buf;
    system(buf.c_str());

    return 0;
}