//
// Created by slonik on 1/22/22.
//

#include "WotStrategyServer.h"
#include <boost/endian.hpp>
#include <utility>
#include <iostream>

void WotStrategyServer::SendAction(WotStrategyServer::Action action, std::string data) {
    size_t szData = data.size();
    if (buffer.size() < szData + 8) buffer.resize(szData + 8);
    std::memcpy(&buffer[0], &action, sizeof(action));
    std::memcpy(&buffer[4], &szData, sizeof(szData));
    std::memcpy(&buffer[8], &data[0], szData);
    Send(boost::asio::const_buffer(&buffer[0], szData + 8));
}

boost::asio::mutable_buffer WotStrategyServer::RecvResult(WotStrategyServer::Result &result) {
    Recieve(boost::asio::mutable_buffer(&buffer[0], 8));
    result = *(Result *)(&buffer[0]);
    int szData = *(int *)(&buffer[4]);
    if (buffer.size() < szData + 8) buffer.resize(szData + 8);
    boost::asio::mutable_buffer resultBuffer(&buffer[8], szData);
    Recieve(resultBuffer);
    return resultBuffer;
}

WotStrategyServer::WotStrategyServer(std::string host, std::string service) :
    TcpConnection(std::move(host), std::move(service)) {
}

ServerModels::LoginResponseModel WotStrategyServer::Login(ServerModels::LoginRequestModel &request) {
    SendAction(Action::LOGIN, serialize(boost::json::value_from(request)));
    auto tmp = RecvResult(lastResult);
    if (lastResult != Result::OKEY) {
        std::cerr << "RequestResult: " << (int)lastResult << '\n';
        std::cerr.write((char *)tmp.data(), tmp.size()).put('\n');
        return ServerModels::LoginResponseModel();
    }
    streamParser.reset();
    streamParser.write((char *) tmp.data(), tmp.size());
    return boost::json::value_to<ServerModels::LoginResponseModel>(streamParser.release());
}

void WotStrategyServer::Logout() {
    SendAction(Action::LOGOUT, "");
}

WotStrategyServer::Result WotStrategyServer::GetLastResult() {
    return lastResult;
}

