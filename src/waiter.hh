//
// Created by ctech on 26/06/18.
//

#pragma once

#include <Arduino.h>

class Waiter {
public:
    explicit Waiter(int16_t ms) : ms(ms) { }

    bool hasWaited() {
        return ((unsigned long)(ms * 1000)) + start <= micros();
    }

private:
    int16_t ms;
    unsigned long start = micros();
};