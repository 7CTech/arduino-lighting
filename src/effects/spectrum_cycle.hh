//
// Created by ctech on 10/06/18.
//

#pragma once

#include "../color.hh"
#include "../color_cycling.hh"
#include "../effect.hh"

class SpectrumCycle : public Effect {
public:
    explicit SpectrumCycle(Region &region, Color base, int16_t delay = 1);
    void init() override;
    int16_t loop() override;
private:
    const Color base;
    ColorCycling active;
    const int16_t delay;
};