#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include "ServerAPI/WotStrategyServer.h"

int main(int argc, char* argv[]) {
    WotStrategyServer server("wgforge-srv.wargaming.net", "443");
    LoginRequestModel request {
        "name",
        "password",
        "wasd1",
        32,
        1,
        false
    };
    LoginResponseModel response = server.Login(request);
    if (server.GetLastResult() == WotStrategyServer::Result::OKEY) {
        server.Logout();
        std::cout << "IDX: " << response.idx << " Name: " << response.name << " Password: " << response.password
                  << " IsObserver: " << response.is_observer << '\n';
    }
    return 0;
}