//
// Created by smoky on 1/3/2022.
//

#ifndef CRYSTAL_DUCKSERVER_CONDUCTORCONNECTIONS_H
#define CRYSTAL_DUCKSERVER_CONDUCTORCONNECTIONS_H

#include "DevUtils.h"
#include <memory>
#include "Networks/NetworkConnectionBase.h"

typedef void WorkTrack;

class ConductorConnections {
public:
    STUB(void, AddConnections, std::shared_ptr<NetworkConnectionBase> *pConnections, uint32_t count);

    STUB_WITH_TYPE(std::shared_ptr<WorkTrack>, std::shared_ptr<WorkTrack>(), MakeWorkTrack)

    STUB(void, RemoveWorkTrack, std::shared_ptr<WorkTrack> workTrack)

    STUB(void, CloseAllConnections);

    STUB(void, Reset)
};


#endif //CRYSTAL_DUCKSERVER_CONDUCTORCONNECTIONS_H
