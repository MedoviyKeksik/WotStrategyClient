#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include "ServerAPI/WotStrategyServer.h"

int main(int argc, char* argv[]) {
    WotStrategyServer server("wgforge-srv.wargaming.net", "443");
    ServerModels::LoginRequestModel request {
        "name",
        "password",
        "wasd",
        32,
        1,
        false
    };
    ServerModels::LoginResponseModel response = server.Login(request);
    std::cout << "IDX: " << response.idx << " Name: " << response.name << " Password: " << response.password << " IsObserver: " << response.is_observer<< '\n';
    std::cout.flush();
    return 0;
}