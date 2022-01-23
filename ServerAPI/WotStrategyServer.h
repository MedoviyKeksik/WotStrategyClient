//
// Created by slonik on 1/22/22.
//

#ifndef WOT_STRATEGY_WOTSTRATEGYSERVER_H
#define WOT_STRATEGY_WOTSTRATEGYSERVER_H

#include <vector>
#include <boost/json.hpp>
#include "TcpConnection.h"
#include "Models/LoginRequestModel.h"
#include "Models/LoginResponseModel.h"

class WotStrategyServer : public TcpConnection {
public:
    enum class Action {
        LOGIN = 1,
        LOGOUT = 2,
        MAP = 3,
        GAME_STATE = 4,
        GAME_ACTIONS = 5,
        TURN = 6,
        CHAT = 100,
        MOVE = 101,
        SHOOT = 102
    };

    enum class Result {
        OKEY = 0,
        BAD_COMMAND = 1,
        ACCESS_DENIED = 2,
        INAPPROPRIATE_GAME_STATE = 3,
        TIMEOUT = 4,
        INTERNAL_SERVER_ERROR = 500
    };

    WotStrategyServer(std::string host, std::string service);

    ServerModels::LoginResponseModel Login(ServerModels::LoginRequestModel &request);

    void SendAction(Action action, std::string data);
    void RecvResult();
private:
    std::vector<char> buffer;
    boost::json::stream_parser streamParser;
};

#endif //WOT_STRATEGY_WOTSTRATEGYSERVER_H
