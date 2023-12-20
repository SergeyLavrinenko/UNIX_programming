#include <pistache/endpoint.h>
#include <pistache/http.h>
#include <cstdint>
#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>
 

using namespace Pistache;

class systemInfo{
    std::string temp;
    std::string free_mem;

    public:

    std::string get_temp(){                                      
        std::ifstream ifile("/sys/class/thermal/thermal_zone0/temp");
        ifile >> temp;                                        
        ifile.close();
        return temp.substr(0,2);
    }

    std::string get_free_mem(){
        std::ifstream ifile("/proc/meminfo");
        for(int i = 0; i < 5; i++){
            ifile >> free_mem;  // Получаем свободную оперативную память
        }
                                                                                 
        ifile.close();
        return free_mem;
    }


};

systemInfo info;

struct HelloHandler : public Http::Handler {
  HTTP_PROTOTYPE(HelloHandler)
  void onRequest(const Http::Request&, Http::ResponseWriter writer) override {
    
    std::string temp = info.get_temp();
    std::string free_mem = info.get_free_mem();

    writer.headers().add<Http::Header::ContentType>(MIME(Application, Json));
    writer.send(Http::Code::Ok, "[{\"name\": \"temp\", \"value\": " + temp 
                                    + ", \"units\": \"°C\"}, {\"name\": \"free_memory\", \"value\": " 
                                    + free_mem + ", \"units\": \"Kb\"}" + "]");
  }
};

int main() {
    

std::cout << "start "<< '\n';

  Http::listenAndServe<HelloHandler>(Pistache::Address("*:9086"));
}


