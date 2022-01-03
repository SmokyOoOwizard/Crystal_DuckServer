//
// Created by smoky on 12/28/2021.
//

#ifndef CRYSTAL_DUCKSERVER_NETWORKCONNECTIONBASE_H
#define CRYSTAL_DUCKSERVER_NETWORKCONNECTIONBASE_H


class NetworkConnectionBase {
public:
    virtual ~NetworkConnectionBase() = default;

    virtual void Disconnect() = 0;
};


#endif //CRYSTAL_DUCKSERVER_NETWORKCONNECTIONBASE_H
