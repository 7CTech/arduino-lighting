//
// Created by ctech on 23/06/18.
//

#pragma once

#include <Arduino.h>
#include <alloca.h>
#include <Adafruit_NeoPixel.h>

#include "trail_basic.hh"

class TrailsSequential : public Effect {
public:
    explicit TrailsSequential(Region &region, uint16_t trailLength, uint16_t trailCount, uint16_t loopTime);

    void init() override;
    int16_t loop() override;

private:
    const uint16_t trailLength;
    const uint16_t trailCount;
    const uint16_t trailGap;
    const uint16_t loopTime;
    TrailBasic *trails = (TrailBasic *)alloca(trailCount * sizeof(TrailBasic)); //note to future idiotic self: don't try change this.
};
