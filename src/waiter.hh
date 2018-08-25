//
// Created by ctech on 26/06/18.
//

#pragma once

#include <Arduino.h>

class Waiter {
public:
    explicit Waiter(uint64_t ms) : ms(ms) { }

    bool hasWaited() {
        return ms + start <= millis();
    }

private:
    uint64_t ms;
    uint64_t start = millis();
};