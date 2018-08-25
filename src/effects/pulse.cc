//
// Created by ctech on 21/06/18.
//

#include "pulse.hh"

Pulse::Pulse(Region &region, uint8_t steps, uint16_t timeOut, uint16_t timeOff) :
        Effect(region), steps(steps), timeOut(timeOut), timeOff(timeOff), step(-1), color(nullptr) {
}

void Pulse::init() {
    step = 0;
    color = Color();
}

uint64_t Pulse::loop() {
    double percent = ((steps - double(step)) / steps);
    uint64_t totalDelay = 0;

    for (uint16_t i = 0; i < region.size; i++) {
        region.set(i, color * percent);
    }

    if (step == steps) {
        step = -1;
        color = Color();
        totalDelay += timeOff;
    }

    totalDelay += timeOut / steps;
    step++;

    return totalDelay;
}
