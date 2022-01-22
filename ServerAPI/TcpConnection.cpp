//
// Created by slonik on 1/21/22.
//

#include <iostream>
#include "TcpConnection.h"

TcpConnection::TcpConnection(std::string host, std::string service) : ioService(), socket(ioService) {
    using boost::asio::ip::tcp;
    tcp::resolver resolver(ioService);
    auto results = resolver.resolve(host, service);
    boost::asio::connect(socket, results, error);
}

void TcpConnection::Send(boost::asio::const_buffer buffer) {
    std::size_t total = socket.send(buffer, 0, error);
}

void TcpConnection::Recieve(boost::asio::mutable_buffer buffer) {
    std::size_t total = socket.receive(buffer, 0, error);
}

TcpConnection::~TcpConnection() {
}


