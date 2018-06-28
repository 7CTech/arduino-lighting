//
// Created by ctech on 20/06/18.
//

#pragma once

#include <Adafruit_NeoPixel.h>
#include <pt.h>
#include <pt-sem.h>

#include "region.hh"

/**
 * Class used to define any kind of effect.
 * There are 3 things that can/need/will be done in any effect
 * The constructor should take in all it's needed parameters and what not
 * Initialise should clear the effect, and prepare it for starting
 * Run should be looping code
 */
class Effect {
public:
    explicit Effect(Region &region);
    virtual void init() = 0;
    virtual int16_t loop() = 0;

    const int run(struct pt *proto);
    const void kill();

protected:
    Region &region;

private:
    Waiter w;
};