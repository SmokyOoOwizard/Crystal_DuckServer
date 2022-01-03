//
// Created by smoky on 1/3/2022.
//

#ifndef CRYSTAL_DUCKSERVER_SOCKETUTILS_H
#define CRYSTAL_DUCKSERVER_SOCKETUTILS_H

#include "NetworkBase.h"


bool SetSocketBlockingMode(socket_t socket, bool blocking) {
    if (socket < 0) return false;

#ifdef _WIN32
    u_long mode = blocking ? 0 : 1;
    return ioctlsocket(socket, FIONBIO, &mode) == 0;
#else
    uint32_t flags = fcntl(socket, F_GETFL, 0);
    if (flags == -1) return false;
    flags = blocking ? (flags & ~O_NONBLOCK) : (flags | O_NONBLOCK);
    return fcntl(socket, F_SETFL, flags) == 0
#endif
}

#endif //CRYSTAL_DUCKSERVER_SOCKETUTILS_H
