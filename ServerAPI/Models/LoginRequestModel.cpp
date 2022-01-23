//
// Created by slonik on 1/23/22.
//

#include "LoginRequestModel.h"

namespace ServerModels {

    void tag_invoke(const boost::json::value_from_tag&, boost::json::value& jv, LoginRequestModel const &c) {
        jv = {
                {"name", c.name },
                {"password", c.password},
                {"game", c.game},
                {"num_turns", c.num_turns},
                {"num_players", c.num_players},
                {"is_observer", c.is_observer}
        };
    }
}