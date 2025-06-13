#pragma once
#include "../models/application.hpp"
#include <unordered_map>
#include <string>

class Database {
private:
    std::unordered_map<std::string, Application> storage;

public:
    void saveApplication(const Application& app) {
        storage[app.certificateId] = app;
    }

    bool verifyCertificate(const std::string& certId) {
        return storage.find(certId) != storage.end();
    }

    static Database& getInstance() {
        static Database instance;
        return instance;
    }
};