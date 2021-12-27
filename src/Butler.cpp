//
// Created by smoky on 12/26/2021.
//

#include "Butler.h"
#include "Networks/TcpNetwork.h"


void Butler::Setup(std::shared_ptr<ApplicationSettings> Settings) {
    settings = Settings;
}

void Butler::Start() {
    if (working) {
        return;
    }
    working = true;

    createNetworks();

    handlerThread = std::thread(&Butler::threadJobFunction, this);
}

void Butler::Stop() {
    working = false;

    handlerThread.join();

    networks.clear();
}


Butler::~Butler() {
    if (working) {
        Stop();
    }
}

void Butler::threadJobFunction() {

    while (working) {
        for (int i = 0; i < networks.size(); ++i) {
            networks[i]->ProcessingData();
        }

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void Butler::createNetworks() {
    std::string hostName;
    settings->GetValue("ip", hostName);
    std::string rawPort;
    settings->GetValue("port", rawPort);
    uint32_t port = std::atoi(rawPort.c_str());

    networks.push_back(static_cast<std::unique_ptr<NetworkBase>>(std::make_unique<TcpNetwork>(hostName, port)));
}

