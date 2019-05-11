//
// Created by ctech on 27/06/18.
//

#pragma once

#include "color.hh"

class ColorCycling : public Color {
public:
    ColorCycling(const Color &base);

    void cycle(); //moves this color forward by one increment. Call this repeatedly to actually cycle
    void cycle(uint8_t increment); //alternate implementation - cycle multiple colors at once
    void cyclePercent(double percent); //alternate implementation - cycle a percentage

    const static int TOTAL_COLORS = 765;
protected:
    void scale(double scale); //todo
private:
    uint8_t decColor;
    uint8_t incColor;
    int16_t iColorIndex;
    friend class SpectrumCycle;
};
