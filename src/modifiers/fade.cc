//
// Created by jason on 11/05/19.
//

#include <global.hh>
#include "fade.hh"

void Fade::modify(MutableRegionState &regionState) {
    if (fadingIn) {
        curFade += (double(SLOWNESS)/fadeTime);
        if (curFade > 1) curFade = 1;
    } else {
        curFade -= (double(SLOWNESS)/fadeTime);
        if (curFade < 0) curFade = 0;
    }
    if (curFade <= 0 || curFade >= 1) {
        fadingIn = !fadingIn;
    }

    regionState.all<Fade>((*this), [](const Fade &fade, const CRGB *c) -> const CRGB {
        return {uint8_t(c->r * fade.curFade), uint8_t(c->g * fade.curFade), uint8_t(c->b * fade.curFade)};
    });
}

void Fade::clear() {
    curFade = 1;
    fadingIn = false;
}
