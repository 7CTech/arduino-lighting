//
// Created by ctech on 21/06/18.
//

#include "trail_basic.hh"

TrailBasic::TrailBasic(Region &region, uint16_t length, Color color, bool forward, uint16_t loopTime) :
        Effect(region), head(0), length(length), color(color), forward(forward), loopTime(loopTime) {

}

const void TrailBasic::move() {
    if (head < 0) return; //nothing to do, either we are dead or queued
    for (int i = length; i >= 0; i--) {
        double percent = double(length - i) / length;
        int16_t expectedIndex;
        if (forward) expectedIndex = head - i;
        else expectedIndex = head + i;
        if (expectedIndex < 0 || unsigned(expectedIndex) > region.maxIndex || unsigned(expectedIndex) < region.minIndex) continue;
        region.set(unsigned(expectedIndex), color, percent);
    }
}

void TrailBasic::init() {
    head = 0;
}

int16_t TrailBasic::loop() {
    move();
    if (head - length >= region.maxIndex) return 0;
    return loopTime / region.size;
}
