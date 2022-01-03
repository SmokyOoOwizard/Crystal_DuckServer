//
// Created by smoky on 12/26/2021.
//

#ifndef CRYSTAL_DUCKSERVER_APPLICATIONINFO_H
#define CRYSTAL_DUCKSERVER_APPLICATIONINFO_H

#include <iostream>
#include <string>
#include "ApplicationInfoDefines.h.out"

class ApplicationInfo {
public:
    const uint32_t BuildTime = BUILD_TIME;
    const uint32_t BuildNumber = 0;
    const uint16_t Version = 1;
    const enum ApplicationCondition {
        Dev, Alpha, Beta
    } Condition = BUILD_CONDITION;


    void PrintInfo(std::ostream &output) const;

    std::string MakeVersion() const;

    std::string MakeDate() const;

};

inline const std::string ToString(ApplicationInfo::ApplicationCondition v) {
    switch (v) {
        case ApplicationInfo::ApplicationCondition::Dev:
            return "Dev";
        case ApplicationInfo::ApplicationCondition::Alpha:
            return "Alpha";
        case ApplicationInfo::ApplicationCondition::Beta:
            return "Beta";
        default:
            return "Unknown Application Condition";
    }
}

#endif //CRYSTAL_DUCKSERVER_APPLICATIONINFO_H
