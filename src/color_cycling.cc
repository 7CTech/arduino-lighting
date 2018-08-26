//
// Created by ctech on 27/06/18.
//

#include "color_cycling.hh"

ColorCycling::ColorCycling(const Color &base) {
    r = base.r;
    g = base.g;
    b = base.b;

    decColor = 0;
    incColor = uint8_t(decColor == 2 ? 0 : decColor + 1);
    iColorIndex = 0;
}

void ColorCycling::cycle() {
    --(*this)[decColor];
    ++(*this)[incColor];

    ++iColorIndex;
    if (iColorIndex >= 255) {
        decColor = uint8_t(decColor == 2 ? 0 : decColor + 1);
        incColor = uint8_t(decColor == 2 ? 0 : decColor + 1);
        iColorIndex = 0;
    }
}

void ColorCycling::cycle(uint8_t increment) {
    if ((*this)[decColor] >= increment) {
        (*this)[decColor] -= increment;
        (*this)[incColor] += increment;
        iColorIndex += increment;
        if (iColorIndex > 255) {
            decColor = uint8_t(decColor == 2 ? 0 : decColor + 1);
            incColor = uint8_t(decColor == 2 ? 0 : decColor + 1);
            iColorIndex = 0;
        }
    } else {
        const uint8_t incrementPart = increment - (*this)[decColor];
        (*this)[decColor] -= (increment - incrementPart);
        (*this)[incColor] += (increment - incrementPart);
        decColor = uint8_t(decColor == 2 ? 0 : decColor + 1);
        incColor = uint8_t(decColor == 2 ? 0 : decColor + 1);
        iColorIndex = incrementPart;
        (*this)[decColor] -= (incrementPart);
        (*this)[incColor] += (incrementPart);
    }
}

void ColorCycling::scale(double scale) {
    
}


