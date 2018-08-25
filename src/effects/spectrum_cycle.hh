//
// Created by ctech on 10/06/18.
//

#pragma once

#include <color.hh>
#include <color_cycling.hh>
#include <effect.hh>

class SpectrumCycle : public Effect {
public:
    explicit SpectrumCycle(Region &region, Color base, uint16_t loopTime = 1000, uint16_t fadeTime = 0);
    void init() override;
    uint64_t loop() override;
private:
    const Color base;
    ColorCycling active;
    const uint16_t loopTime;
    const uint16_t fadeTime;
    double curFade;
    bool fadingIn;
};