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
    TcpNetwork(std::string host, int port);

    ~TcpNetwork() override;

    void ProcessingData() override;

private:
#ifdef _WIN32
    SOCKET socket_ptr = -1;
    WSAData w_data;
#else
    uint32_t socket_ptr;
#endif
};


#endif //CRYSTAL_DUCKSERVER_TCPNETWORK_H
