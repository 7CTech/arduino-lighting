//
// Created by ctech on 10/06/18.
//

#pragma once

#include <color.hh>
#include <color_cycling.hh>
#include <effect.hh>

class SpectrumCycle : public Effect {
public:
    explicit SpectrumCycle(Region &region, uint32_t loopTime = 1000, uint32_t fadeTime = 0);
    void init() override;
    uint32_t loop() override;
private:
    const Color base = Color(255, 0 , 0);
    ColorCycling active;
    const uint32_t loopTime;
    const uint32_t fadeTime;
    double curFade;
    bool fadingIn;
};