//
// Created by ctech on 10/06/18.
//
#include "spectrum_cycle.hh"
#include <global.hh>

SpectrumCycle::SpectrumCycle(Region &region, uint32_t loopTime) :
        Effect(region), active(base), loopTime(loopTime) {

}

void SpectrumCycle::init() {
    active = base; //copy

}

uint32_t SpectrumCycle::loop() {
    const double idealDelay = double(loopTime)/(255 * 3);
    //Serial.println(idealDelay);
    if (idealDelay < SLOWNESS) {
        active.cycle(SLOWNESS/idealDelay);
    } else {
        active.cycle();
    }

    for (uint16_t i = 0; i < region.size; i++) {
        region.set(i, active);
    }
    return (uint32_t) (idealDelay < SLOWNESS ? SLOWNESS : idealDelay);
}
