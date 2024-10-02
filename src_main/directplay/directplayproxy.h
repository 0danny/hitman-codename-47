#pragma once

#include "common.h"
#include "zstdlib/zdynamicloader.h"
#include "directplay.h"

class DirectPlayProxy : public ZDynamicLoader
{
public:
    DirectPlay *m_directPlay;

    virtual ~DirectPlayProxy();

    // Overrides
    void Unknown2();
    void Unknown3();
};
