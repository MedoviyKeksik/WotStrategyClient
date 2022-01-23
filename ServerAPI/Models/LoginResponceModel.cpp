//
// Created by slonik on 1/23/22.
//

#include "LoginResponseModel.h"

LoginResponseModel tag_invoke(const boost::json::value_to_tag<LoginResponseModel>&, boost::json::value const& jv) {
    boost::json::object const& obj =  jv.as_object();
    return {
            boost::json::value_to<int>(obj.at("idx")),
            boost::json::value_to<std::string>(obj.at("name")),
            boost::json::value_to<std::string>(obj.at("password")),
            boost::json::value_to<bool>(obj.at("is_observer"))
    };
}