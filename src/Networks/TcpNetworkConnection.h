//
// Created by smoky on 12/28/2021.
//

#ifndef CRYSTAL_DUCKSERVER_TCPNETWORKCONNECTION_H
#define CRYSTAL_DUCKSERVER_TCPNETWORKCONNECTION_H

#include "NetworkBase.h"

class TcpNetworkConnection : public NetworkConnectionBase {
public:
    // TODO maybe automatic disconnect connection when root network was closed?
    TcpNetworkConnection(socket_t socket);

    ~TcpNetworkConnection() override;

    void Disconnect() override;

private:
    socket_t connectionSocket;
};


#endif //CRYSTAL_DUCKSERVER_TCPNETWORKCONNECTION_H
