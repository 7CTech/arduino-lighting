//
// Created by jason on 11/04/19.
//

#pragma once


#include <effect.hh>
#include "color_cycling.hh"

class SpectrumStatic : public Effect {
public:
    explicit SpectrumStatic(Region &region, const Color &base, uint32_t delay);
    void init() override;
    uint32_t loop() override;

private:
    ColorCycling active;
    uint32_t delay;
    boolean first = true;
};


