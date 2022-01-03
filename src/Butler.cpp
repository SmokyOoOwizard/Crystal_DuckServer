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
    working.store(true, std::memory_order_seq_cst);

    // create networks
    createNetworks();

    // create threads working on clients requests

    // create threads(thread?) working on accept new clients
    handlerThread = std::thread(&Butler::threadNetworkAcceptClientsJobFunction, this);
}

void Butler::Stop() {
    working.store(false, std::memory_order_seq_cst);

    // stop all threads(thread?) working on accept new clients
    handlerThread.join();

    // close connections
    conductor.CloseAllConnections();
    conductor.Reset();
    //

    // stop all threads working on clients requests

    // close networks
    networks.clear();
}


Butler::~Butler() {
    if (working.load(std::memory_order_seq_cst)) {
        Stop();
    }
}

void Butler::threadNetworkAcceptClientsJobFunction() {

    while (working.load(std::memory_order_relaxed)) {

        std::vector<std::shared_ptr<NetworkConnectionBase>> acceptedConnections;
        for (int i = 0; i < networks.size(); ++i) {
            uint32_t accepted = networks[i]->AcceptIncomingConnections(acceptedConnections, 10);

            if (accepted > 0) {
                conductor.AddConnections(acceptedConnections.data(), accepted);
            }
        }

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void Butler::createNetworks() {
    // TODO cleanup this shit
    std::string hostName;
    settings->GetValue("ip", hostName);
    std::string rawPort;
    settings->GetValue("port", rawPort);
    uint32_t port = std::atoi(rawPort.c_str());

    networks.push_back(static_cast<std::unique_ptr<NetworkBase>>(std::make_unique<TcpNetwork>(hostName, port, 10)));
}

