#include "crow.h"
#include "routes/application_routes.hpp"
#include "routes/verification_routes.hpp"

int main() {
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([] {
        return "Internship API Running!";
    });

    register_application_routes(app);
    register_verification_routes(app);

    app.port(18080).multithreaded().run();
}