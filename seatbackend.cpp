#include "seatdbackend.h"
#include <libseat.h>

static void seatd_enable_seat(struct libseat *seat, void *data) {
    // KScreenLocker doesn't need to do anything here
}

static void seatd_disable_seat(struct libseat *seat, void *data) {
    // Session deactivated → lock screen should enforce itself
}

SeatdBackend::SeatdBackend() {
    struct libseat_seat_listener listener = {
        .enable_seat = seatd_enable_seat,
        .disable_seat = seatd_disable_seat,
    };

    m_seat = libseat_open_seat(&listener, this);
}

SeatdBackend::~SeatdBackend() {
    if (m_seat)
        libseat_close(m_seat);
}

bool SeatdBackend::isActive() {
    return libseat_seat_active(m_seat);
}

bool SeatdBackend::inhibit() {
    return true; // seatd has no inhibit API
}

void SeatdBackend::uninhibit() {
}

bool SeatdBackend::switchVT(int vt) {
    return libseat_switch_session(m_seat, vt) == 0;
}

void SeatdBackend::processEvents() {
    libseat_dispatch(m_seat, 0);
}
