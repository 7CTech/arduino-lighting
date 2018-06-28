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

    //this needs to be post test, going any larger will cause us to wrap, so a greater than test has no effect
    if (iColorIndex == 255) {
        decColor = uint8_t(decColor == 2 ? 0 : decColor + 1);
        incColor = uint8_t(decColor == 2 ? 0 : decColor + 1);
        iColorIndex = 0;
    }
    ++iColorIndex;
}


