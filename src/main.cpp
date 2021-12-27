#include <iostream>
#include "ApplicationInfo.h"
#include "Butler.h"

int main() {
    setlocale(LC_ALL, "en_US.utf8");

    ApplicationInfo info;
    info.PrintInfo(std::cout);

    std::shared_ptr<ApplicationSettings> settings(new ApplicationSettings());

    std::ifstream file("Settings.ini");
    if (!file) {
        std::cout << "Failed to read settings file" << std::endl;
    } else {
        ApplicationSettings::ParseSettings(file, *settings);
    }
    file.close();


    Butler *butler;
    try {
        butler = new Butler();
        butler->Setup(settings);
        butler->Start();

        while (true) {
            std::string userInput;
            std::getline(std::cin, userInput);
            if (userInput == "exit") {
                break;
            }
        }

        butler->Stop();
    }
    catch (std::exception &ex) {
        std::cout << ex.what();
    }
    delete butler;

    return 0;
}