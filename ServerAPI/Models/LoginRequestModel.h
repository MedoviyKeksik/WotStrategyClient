//
// Created by slonik on 1/23/22.
//

#ifndef WOT_STRATEGY_LOGINREQUESTMODEL_H
#define WOT_STRATEGY_LOGINREQUESTMODEL_H

#include <string>
#include <boost/json.hpp>

namespace ServerModels {

    struct LoginRequestModel {
        std::string name;
        std::string password;
        std::string game;
        int num_turns;
        int num_players;
        bool is_observer;
    };

    void tag_invoke(const boost::json::value_from_tag&, boost::json::value& jv, LoginRequestModel const &c);
}


#endif //WOT_STRATEGY_LOGINREQUESTMODEL_H
