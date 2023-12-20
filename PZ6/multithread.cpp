#include <thread>
#include <iostream>

int main() {
     static int i =0;
     std::thread([](){ 
          while(true){ 
               ++i;
               std::this_thread::sleep_for( std::chrono::milliseconds(1000));
          }
     }).detach();

     std::thread([](){ 
          while(true){
               std::this_thread::sleep_for(std::chrono::milliseconds(1000));
               std::cout << "i: " << i << "\n";
          }
     }).join();

     return 0;
}