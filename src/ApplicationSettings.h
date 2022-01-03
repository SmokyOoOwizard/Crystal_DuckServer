//
// Created by smoky on 12/27/2021.
//

#ifndef CRYSTAL_DUCKSERVER_APPLICATIONSETTINGS_H
#define CRYSTAL_DUCKSERVER_APPLICATIONSETTINGS_H


#include <string>
#include <unordered_map>
#include <fstream>

// TODO Make application settings more flexible and smart. Change format on json
class ApplicationSettings {
public:
    bool ContainsKey(std::string key);

    bool GetValue(std::string key, std::string &value);

    static bool ParseSettings(std::istream &stream, ApplicationSettings &settings);

private:
    std::unordered_map<std::string, std::string> rawSettings;
};


#endif //CRYSTAL_DUCKSERVER_APPLICATIONSETTINGS_H
