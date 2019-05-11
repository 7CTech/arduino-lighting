//
// Created by jason on 11/04/19.
//

#pragma once


#include <effect.hh>
#include "color_cycling.hh"

class SpectrumWave : public Effect {
public:
    explicit SpectrumWave(Region &region, const Color &base, uint32_t loopTime);
    void init() override;
    uint32_t loop() override;

private:
    ColorCycling active;
    uint32_t loopTime;
};


