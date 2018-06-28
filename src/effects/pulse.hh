//
// Created by ctech on 21/06/18.
//

#pragma once

#include "color.hh"
#include "effect.hh"

class Pulse : Effect {
    public:
        explicit Pulse(Region &region, uint8_t steps = 60, uint16_t timeOut = 100, uint16_t timeOff = 0);
        void init() override;
        int16_t loop() override;
    private:
        uint8_t steps;
        uint16_t timeOut;
        uint16_t timeOff;

        int16_t step;
        Color color;
};
