//
// Created by smoky on 12/26/2021.
//

#ifndef CRYSTAL_DUCKSERVER_BUTLER_H
#define CRYSTAL_DUCKSERVER_BUTLER_H


#include <memory>
#include <vector>
#include <thread>
#include "ApplicationSettings.h"
#include "ConductorConnections.h"
#include "Networks/NetworkBase.h"

class Butler {
public:
    void Setup(std::shared_ptr<ApplicationSettings> Settings);

    void Start();

    void Stop();

    ~Butler();

private:
    std::atomic<bool> working = false;

    std::thread handlerThread;

    std::shared_ptr<ApplicationSettings> settings;

    std::vector<std::unique_ptr<NetworkBase>> networks;

    ConductorConnections conductor;

    void threadNetworkAcceptClientsJobFunction();

    void createNetworks();
};


#endif //CRYSTAL_DUCKSERVER_BUTLER_H
