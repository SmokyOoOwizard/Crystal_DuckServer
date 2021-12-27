//
// Created by smoky on 12/27/2021.
//

#include <iostream>
#include "TcpNetwork.h"

TcpNetwork::TcpNetwork(std::string host, int port) {

#ifdef _WIN32
    WSAStartup(MAKEWORD(2, 2), &w_data);

    SOCKADDR_IN address;
    address.sin_addr.S_un.S_addr = INADDR_ANY;
    address.sin_port = htons(port);
    address.sin_family = AF_INET;
    socket_ptr = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_ptr == SOCKET_ERROR) {
        perror("socket failed");
    }

    if (bind(socket_ptr, (struct sockaddr *) &address, sizeof(address)) == SOCKET_ERROR) {
        perror("socket failed");
    }

    if (listen(socket_ptr, 10) == SOCKET_ERROR) {
        perror("socket failed");
    }
#else
    struct sockaddr_in server;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(port);
    server.sin_family = AF_INET;
    socket_ptr = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_ptr == -1) {
        perror("socket failed");
    }

    if (bind(socket_ptr, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("socket failed");
    }

    if (listen(socket_ptr, 10) < 0) {
        perror("socket failed");
    }
#endif

}

TcpNetwork::~TcpNetwork() {
#ifdef _WIN32
    closesocket(socket_ptr);
#else
    close(socket_ptr);
#endif
}

void TcpNetwork::ProcessingData() {

}

