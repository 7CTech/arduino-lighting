//
// Created by ctech on 26/06/18.
//

#pragma once

#include <Arduino.h>

class Waiter {
public:
    explicit Waiter(double ms) : ms(ms) { }

    bool hasWaited() {
        return ms - (double(start)/1000) <= 0;
    }

private:
    double ms;
    uint32_t start = micros();
};
