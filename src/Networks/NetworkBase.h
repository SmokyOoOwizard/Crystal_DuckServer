//
// Created by smoky on 12/27/2021.
//

#ifndef CRYSTAL_DUCKSERVER_NETWORKBASE_H
#define CRYSTAL_DUCKSERVER_NETWORKBASE_H


class NetworkBase {
public:
    virtual ~NetworkBase() = default;
    virtual void ProcessingData() = 0;
};


#endif //CRYSTAL_DUCKSERVER_NETWORKBASE_H
