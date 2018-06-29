//
// Created by ctech on 26/06/18.
//

#pragma once

#include <Arduino.h>

class Waiter {
public:
    explicit Waiter(uint32_t ms) : ms(ms) { }

    bool hasWaited() {
        return (ms * 1000) + start <= micros();
    }

private:
    uint32_t ms;
    uint32_t start = micros();
};
