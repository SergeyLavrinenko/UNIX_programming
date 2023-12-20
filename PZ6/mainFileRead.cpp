#include <iostream>
#include <fstream>
#include <string>    
 
int main()
{
    std::string line;

    int a;
 
    std::ifstream in("hello.txt");
    if (in.is_open())
    {
        while (std::getline(in, line))
        {
            std::cout << line << std::endl;
        }
    }
    in.close();

    a = 1 / 0;
}