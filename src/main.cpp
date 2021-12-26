#include <iostream>
#include "ApplicationInfo.h"

int main() {
    setlocale(LC_ALL, "en_US.utf8");

    ApplicationInfo info;
    info.PrintInfo(std::cout);

    return 0;
}