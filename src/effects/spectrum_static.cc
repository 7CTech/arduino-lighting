//
// Created by jason on 11/04/19.
//

#include "spectrum_static.hh"

SpectrumStatic::SpectrumStatic(Region &region, const Color &base, uint32_t delay) : Effect(region), active(base), delay(delay) {

}

void SpectrumStatic::init() {

}

uint32_t SpectrumStatic::loop() {
    if (first) {
        for (uint16_t i = 0; i < region.size; i++) {
            region.set(i, active);
            active.cyclePercent(1.0/region.size);
        }
        first = false;
    }
    return delay;
}
