//
// Created by jason on 24/08/18.
//

#include "wave.hh"

Wave::Wave(Region &region, int16_t loopTime) : Effect(region), loopTime(loopTime) {

}

void Wave::init() {

}

uint64_t Wave::loop() {
    return 0;
}
