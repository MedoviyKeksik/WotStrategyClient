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

std::size_t TcpConnection::Send(boost::asio::const_buffer buffer) {
    return socket.send(buffer, 0, error);
}

std::size_t TcpConnection::Recieve(boost::asio::mutable_buffer buffer) {
    return socket.receive(buffer, 0, error);
}

TcpConnection::~TcpConnection() {
    socket.cancel();
    socket.close();
}


