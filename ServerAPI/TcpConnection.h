//
// Created by slonik on 1/21/22.
//

#ifndef WOT_STRATEGY_TCPCONNECTION_H
#define WOT_STRATEGY_TCPCONNECTION_H

#include <boost/asio.hpp>
#include <boost/utility.hpp>
#include <boost/array.hpp>

class TcpConnection {
public:
    TcpConnection(std::string host, std::string service);
    std::size_t Send(boost::asio::const_buffer buffer);
    std::size_t Recieve(boost::asio::mutable_buffer buffer);
    ~TcpConnection();
private:
    boost::system::error_code error;
    boost::asio::io_service ioService;
    boost::asio::ip::tcp::socket socket;
};

#endif //WOT_STRATEGY_TCPCONNECTION_H
