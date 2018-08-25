//
// Created by ctech on 20/06/18.
//

#pragma once

#include <effect.hh>
#include <color.hh>

class Breathe : public Effect {
    public:
        explicit Breathe(Region &region, uint8_t steps = 60, uint16_t timeIn = 250, uint16_t timeOut = 250, uint16_t timeOff = 100);
        void init() override;
        uint64_t loop() override;
    private:
        uint8_t steps;
        uint16_t timeIn;
        uint16_t timeOut;
        uint16_t timeOff;

        int16_t step;
        Color color;
        bool fadingIn;
};
