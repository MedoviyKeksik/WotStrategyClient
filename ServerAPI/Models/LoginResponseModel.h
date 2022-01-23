//
// Created by slonik on 1/23/22.
//

#ifndef WOT_STRATEGY_LOGINRESPONSEMODEL_H
#define WOT_STRATEGY_LOGINRESPONSEMODEL_H

#include <string>
#include <boost/json.hpp>

struct LoginResponseModel {
    int idx;
    std::string name;
    std::string password;
    bool is_observer;
};

LoginResponseModel tag_invoke(const boost::json::value_to_tag<LoginResponseModel>&, boost::json::value const& jv);

#endif //WOT_STRATEGY_LOGINRESPONSEMODEL_H