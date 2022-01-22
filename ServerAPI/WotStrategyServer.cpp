//
// Created by slonik on 1/22/22.
//

#include <iostream>
#include "WotStrategyServer.h"
#include <boost/endian.hpp>

void WotStrategyServer::SendAction(WotStrategyServer::Action action, std::string data) {
    size_t szData = data.size();
    if (buffer.size() < szData + 8) buffer.resize(szData + 8);
    std::memcpy(&buffer[0], &action, sizeof(action));
    std::memcpy(&buffer[4], &szData, sizeof(szData));
    std::memcpy(&buffer[8], &data[0], szData);
    Send(boost::asio::const_buffer(&buffer[0], szData + 8));
}

void WotStrategyServer::RecvResult() {
    Recieve(boost::asio::mutable_buffer(&buffer[0], 8));
    int *szData = (int *)(&buffer[4]);
    Recieve(boost::asio::mutable_buffer(&buffer[8], *szData));
    std::cout.write((char *)&buffer[8], *szData);
}

WotStrategyServer::WotStrategyServer(std::string host, std::string service) : TcpConnection(host, service) {
}
