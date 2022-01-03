//
// Created by smoky on 12/27/2021.
//

#ifndef CRYSTAL_DUCKSERVER_TCPNETWORK_H
#define CRYSTAL_DUCKSERVER_TCPNETWORK_H

#include "NetworkBase.h"
#include <string>

#ifdef _WIN32 // Windows NT

#include <WinSock2.h>

#else

#include <sys/socket.h>

#endif

class TcpNetwork : public NetworkBase {
public:
    TcpNetwork(std::string host, uint32_t port, uint32_t maxIncomingConnectionsQueue);

    ~TcpNetwork() override;

    int AcceptIncomingConnections(std::vector<std::shared_ptr<NetworkConnectionBase>> &Connections,
                                  uint32_t maxAcceptedConnections) override;

private:
    socket_t socket_ptr;
#ifdef _WIN32
    WSAData w_data;
#endif
};


#endif //CRYSTAL_DUCKSERVER_TCPNETWORK_H
