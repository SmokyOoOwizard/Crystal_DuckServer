//
// Created by smoky on 12/26/2021.
//

#include "ApplicationInfo.h"

#include <sstream>
#include <iomanip>

void ApplicationInfo::PrintInfo(std::ostream &output) const {
    output << "                                             \n"
              "                                             \n"
              "                    ██████████               \n"
              "              ░░  ██░░░░░░░░░░██             " "\tCrystal Duck Server " << ToString(Condition) << " v" << MakeVersion() << "\n"
              "                ██░░░░░░░░░░░░░░██           " "\tCreated by Crystal Team\n"
              "                ██░░░░░░░░████░░██████████   " "\tBuild from "<< MakeDate() << "\n"
              "    ██          ██░░░░░░░░████░░██▒▒▒▒▒▒██   " "\tBuild #" << BuildNumber << "\n"
              "  ██░░██        ██░░░░░░░░░░░░░░██▒▒▒▒▒▒██   \n"
              "  ██░░░░██      ██░░░░░░░░░░░░░░████████     \n"
              "██░░░░░░░░██      ██░░░░░░░░░░░░██           \n"
              "██░░░░░░░░████████████░░░░░░░░██             \n"
              "██░░░░░░░░██░░░░░░░░░░░░░░░░░░░░██           \n"
              "██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██         \n"
              "██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██         \n"
              "██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██         \n"
              "██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██         \n"
              "██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██         \n"
              "██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██           \n"
              "  ██░░░░░░░░░░░░░░░░░░░░░░░░░░██             \n"
              "    ██████░░░░░░░░░░░░░░░░████               \n"
              "          ████████████████                   \n"
              "                                             \n"
              "                                             " << std::endl;
}

std::string ApplicationInfo::MakeVersion() const {
    return std::to_string((Version >> 8) & 0xFF) + "." + std::to_string(Version & 0xFF);
}

std::string ApplicationInfo::MakeDate() const {
    std::time_t temp = BuildTime;
    std::tm* t = std::gmtime(&temp);
    std::stringstream ss;
    ss << std::put_time(t, "%p %I:%M:%S | %d.%m.%Y");
    return ss.str();
}
