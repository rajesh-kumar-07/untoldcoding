#pragma once
#include "crow.h"
#include "../db/database.hpp"
#include "../models/application.hpp"
#include "nlohmann/json.hpp"

void register_application_routes(crow::SimpleApp& app) {
    CROW_ROUTE(app, "/apply").methods("POST"_method)
    ([](const crow::request& req) {
        auto json = nlohmann::json::parse(req.body);

        Application appData {
            json["name"],
            json["email"],
            json["university"],
            json["certificateId"]
        };

        Database::getInstance().saveApplication(appData);
        return crow::response(200, "Application submitted");
    });
}