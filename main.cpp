#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include "ServerAPI/WotStrategyServer.h"

int main(int argc, char* argv[]) {
    WotStrategyServer strategy("wgforge-srv.wargaming.net", "443");
    strategy.SendAction(WotStrategyServer::Action::LOGIN, R"({"name":"17"})");
    strategy.RecvResult();
    return 0;
}