#pragma once
#include "crow.h"
#include "../db/database.hpp"
#include <string>

void register_verification_routes(crow::SimpleApp& app) {
    CROW_ROUTE(app, "/verify/<string>")
    ([](const std::string& certId) {
        bool exists = Database::getInstance().verifyCertificate(certId);
        return exists ? crow::response(200, "Valid Certificate")
                      : crow::response(404, "Certificate not found");
    });
}