//
// Created by ctech on 20/06/18.
//

#include <Adafruit_NeoPixel.h>
#include <alloca.h>

#include "breathe.hh"
#include "color.hh"

Breathe::Breathe(Region &region, uint8_t steps, uint16_t timeIn, uint16_t timeOut, uint16_t timeOff) :
        Effect(region), steps(steps), timeIn(timeIn), timeOut(timeOut), timeOff(timeOff) {
    if (steps > timeIn || steps > timeOut) {
        timeIn > timeOut ? (*this).steps = static_cast<uint8_t>(timeOut) : (*this).steps = static_cast<uint8_t>(timeIn);
    }
    step = -1;
    fadingIn = false;

}

void Breathe::init() {

    step = 0;
    color = Color();
    fadingIn = true;
}

int16_t Breathe::loop() {
    double percent;
    int16_t totalDelay = 0;
    if (fadingIn) {
        percent = (double(step) / steps);
    } else {
        percent = ((steps - double(step)) / steps);
    }
    for (uint16_t i = 0; i < region.size; i++) {
        region.set(i, color, percent);
    }

    if (step == steps) {
        step = -1;
        fadingIn = !fadingIn;
        if (fadingIn) {
            color = Color();
            totalDelay += timeOff;
        }
    }
    if (fadingIn) {
        totalDelay += timeIn / steps;
    } else {
        totalDelay += timeOut / steps;
    }
    step++;
    return totalDelay;
}
