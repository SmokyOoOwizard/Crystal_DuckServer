//
// Created by smoky on 12/27/2021.
//

#include "ApplicationSettings.h"

bool ApplicationSettings::ContainsKey(std::string key) {
    return rawSettings.contains(key);
}

bool ApplicationSettings::GetValue(std::string key, std::string &value) {
    auto rawValue = rawSettings.find(key);
    if (rawValue != rawSettings.end()) {
        value = rawValue->second;
        return true;
    }
    return false;
}

bool ApplicationSettings::ParseSettings(std::istream& stream, ApplicationSettings &settings) {
    settings.rawSettings.clear();

    try {
        std::string tmp;
        std::string key;
        std::string value;
        do {
            std::getline(stream, tmp, '=');
            key = tmp;
            std::getline(stream, tmp, '\n');
            value = tmp;

            settings.rawSettings.insert_or_assign(key, value);
        }
        while (!stream.eof());
    }
    catch (std::exception& ex){
        perror(ex.what());
        return false;
    }
    return true;
}
