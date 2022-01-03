//
// Created by smoky on 12/27/2021.
//

#ifndef CRYSTAL_DUCKSERVER_NETWORKBASE_H
#define CRYSTAL_DUCKSERVER_NETWORKBASE_H

#include "NetworkConnectionBase.h"
#include <vector>
#include <memory>

#ifdef _WIN32

#include <WinSock2.h>

typedef SOCKET socket_t;
#else
#include <fcntl.h>
typedef int socket_t;
#endif

class NetworkBase {
public:
    virtual ~NetworkBase() = default;

    virtual int AcceptIncomingConnections(std::vector<std::shared_ptr<NetworkConnectionBase>> &Connections,
                                          uint32_t maxAcceptedConnections) = 0;
};


#endif //CRYSTAL_DUCKSERVER_NETWORKBASE_H
