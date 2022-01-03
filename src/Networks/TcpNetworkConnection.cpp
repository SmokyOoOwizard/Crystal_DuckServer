//
// Created by smoky on 12/28/2021.
//

#include "TcpNetworkConnection.h"

#ifdef _WIN32

#include <WinSock2.h>

#else

#include <sys/socket.h>

#endif

TcpNetworkConnection::TcpNetworkConnection(socket_t socket) : connectionSocket(socket) {

}

TcpNetworkConnection::~TcpNetworkConnection() {
    Disconnect();
}

void TcpNetworkConnection::Disconnect() {
#ifdef _WIN32
    shutdown(connectionSocket, 2);
    closesocket(connectionSocket);
#else
    shutdown(socket, SHUT_RDWR);
    close(socket);
#endif
}
