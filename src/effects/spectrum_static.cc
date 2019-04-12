//
// Created by jason on 11/04/19.
//

#include "spectrum_static.hh"

SpectrumStatic::SpectrumStatic(Region &region, Color base, uint32_t delay) : Effect(region), base(base), delay(delay) {

}

void SpectrumStatic::init() {

}

uint32_t SpectrumStatic::loop() {
    for (uint16_t i = 0; i < region.size; i++) {
        region.set(i, base * i/region.size);
    }
    return delay;
}
