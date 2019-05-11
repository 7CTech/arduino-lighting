//
// Created by jason on 11/04/19.
//

#include "spectrum_wave.hh"

SpectrumWave::SpectrumWave(Region &region, const Color &base, uint32_t loopTime) : Effect(region), active(base), loopTime(loopTime) {

}

void SpectrumWave::init() {

}

uint32_t SpectrumWave::loop() {
    for (uint16_t i = 0; i < region.size; i++) {
        region.set(i, active);
        active.cyclePercent(1.0/region.size);
    }
    return loopTime/region.size;
}
