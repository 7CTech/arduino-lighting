//
// Created by ctech on 10/06/18.
//
#include "spectrum_cycle.hh"

SpectrumCycle::SpectrumCycle(Region &region, Color baseColor, int16_t loopTime) :
        Effect(region), base(baseColor), active(baseColor), loopTime(loopTime) {

}

void SpectrumCycle::init() {
    active = base; //copy
}

int16_t SpectrumCycle::loop() {
    const double idealStep = (double)loopTime/(256^3);
    if (idealStep < 1) {
        for (int i = 0; i < idealStep; i++) {
            active.cycle();
        }
    }
    for (uint16_t i = 0; i < region.size; i++) {
        region.set(i, active);
    }
    return (int16_t) (idealStep < 1 ? 1 : idealStep);
}
