//
// Created by smoky on 12/27/2021.
//

#include <iostream>
#include "TcpNetwork.h"
#include "TcpNetworkConnection.h"
#include "SocketUtils.h"

TcpNetwork::TcpNetwork(std::string host, uint32_t port, uint32_t maxIncomingConnectionsQueue) {

#ifdef _WIN32
    WSAStartup(MAKEWORD(2, 2), &w_data);

    SOCKADDR_IN address;
    address.sin_addr.S_un.S_addr = INADDR_ANY;
    address.sin_port = htons(port);
    address.sin_family = AF_INET;
    socket_ptr = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_ptr == INVALID_SOCKET) {
        // TODO write description of the error
        perror("socket failed");
    }

    if (bind(socket_ptr, (struct sockaddr *) &address, sizeof(address)) == SOCKET_ERROR) {
        // TODO write description of the error
        perror("socket bind");
    }

    if (listen(socket_ptr, maxIncomingConnectionsQueue) == SOCKET_ERROR) {
        // TODO write description of the error
        perror("socket listen");
    }
#else
    struct sockaddr_in address;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    address.sin_family = AF_INET;
    socket_ptr = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_ptr == -1) {
        // TODO write description of the error
        perror("socket failed");
    }

    if (bind(socket_ptr, (struct sockaddr *) &address, sizeof(address)) < 0) {
        // TODO write description of the error
        perror("socket bind");
    }

    if (listen(socket_ptr, maxIncomingConnectionsQueue) < 0) {
        // TODO write description of the error
        perror("socket listen");
    }
#endif

    if (!SetSocketBlockingMode(socket_ptr, false)) {
        // TODO write description of the error
        perror("socket blocking mode failed");
    }

}

TcpNetwork::~TcpNetwork() {
#ifdef _WIN32
    shutdown(socket_ptr, 2);
    closesocket(socket_ptr);
#else
    shutdown(socket_ptr, SHUT_RDWR);
    close(socket_ptr);
#endif
}

int TcpNetwork::AcceptIncomingConnections(std::vector<std::shared_ptr<NetworkConnectionBase>> &Connections,
                                          uint32_t maxAcceptedConnections) {
    uint32_t acceptedConnections = 0;
    do {
#ifdef _WIN32
        socket_t client_socket;
        SOCKADDR_IN client_addr;
        int addrlen = sizeof(client_addr);

        client_socket = accept(socket_ptr, (struct sockaddr *) &client_addr, &addrlen);
        if (client_socket == INVALID_SOCKET) {
            shutdown(client_socket, 0);
            closesocket(client_socket);
            return acceptedConnections;
        }
#else
        socket_t client_socket;
        struct sockaddr_in client_addr;
        int addrlen = sizeof(struct sockaddr_in);

        client_socket = accept(socket_ptr, (struct sockaddr *) &client_addr, (socklen_t * ) & addrlen);
        if (client_socket < 0) {
            shutdown(client_socket, 0);
            close(client_socket);
            return acceptedConnections;
        }
#endif

        ++acceptedConnections;

        std::shared_ptr<TcpNetworkConnection> connection(new TcpNetworkConnection(client_socket));
        Connections.push_back(connection);

        if (maxAcceptedConnections != 0 && acceptedConnections == maxAcceptedConnections) {
            return acceptedConnections;
        }
    } while (true);
}

