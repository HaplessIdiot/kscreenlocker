#pragma once

#include "sessionbackend.h"

class NullBackend : public SessionBackend {
public:
    NullBackend() = default;
    ~NullBackend() override = default;

    bool isActive() override {
        return true;   // Always active; no session tracking
    }

    bool inhibit() override {
        return true;   // No-op
    }

    void uninhibit() override {
        // No-op
    }

    bool switchVT(int) override {
        return false;  // Null backend cannot switch VTs
    }

    void processEvents() override {
        // Nothing to dispatch
    }
};
