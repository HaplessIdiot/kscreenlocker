#pragma once

#include "sessionbackend.h"
#include <libseat.h>

class seatdBackend : public SessionBackend {
public:
    seatdBackend();
    ~SeatdBackend() override;

    bool isActive() override;
    bool inhibit() override;
    void uninhibit() override;
    bool switchVT(int vt) override;
    void processEvents() override;

private:
    struct libseat *m_seat = nullptr;
};
