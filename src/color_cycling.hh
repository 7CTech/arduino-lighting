//
// Created by ctech on 27/06/18.
//

#pragma once

#include "color.hh"

class ColorCycling : public Color {
public:
    ColorCycling(const Color &base);

    void cycle(); //moves this color forward by one increment. Call this repeatedly to actually cycle
protected:
    void cycle(uint8_t increment);
private:
    uint8_t decColor;
    uint8_t incColor;
    int16_t iColorIndex;
    friend class SpectrumCycle;
};
