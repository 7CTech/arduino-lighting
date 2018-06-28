//
// Created by ctech on 10/06/18.
//

#include <Adafruit_NeoPixel.h>

#include "spectrum_cycle.hh"
#include "color_cycling.hh"

SpectrumCycle::SpectrumCycle(Region &region, Color baseColor, uint16_t delay) :
        Effect(region), base(baseColor), active(baseColor), delay(delay) {

}

void SpectrumCycle::init() {
    active = base; //copy
}

int16_t SpectrumCycle::loop() {
    active.cycle();
    for (uint16_t i = 0; i < region.size; i++) {
        region.set(i, active);
    }
    return delay;
}
