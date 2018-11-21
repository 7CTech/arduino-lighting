//
// Created by ctech on 10/06/18.
//
#include "spectrum_cycle.hh"
#include <global.hh>

#undef FADE

SpectrumCycle::SpectrumCycle(Region &region, uint32_t loopTime, uint32_t fadeTime) :
        Effect(region), active(base), loopTime(loopTime), fadeTime(fadeTime), curFade(-1), fadingIn(false) {

}

void SpectrumCycle::init() {
    active = base; //copy
    curFade = 1;
    fadingIn = false;
}

uint32_t SpectrumCycle::loop() {
    const double idealDelay = double(loopTime)/(255 * 3);
    //Serial.println(idealDelay);
    if (idealDelay < SLOWNESS) {
        active.cycle(SLOWNESS/idealDelay);
    } else {
        active.cycle();
    }
    Serial.print(F("r: "));
    Serial.print(active.r);
    Serial.print(F("; g: "));
    Serial.print(active.g);
    Serial.print(F("; b: "));
    Serial.print(active.b);
    Serial.println(F(";"));
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
    //Serial.println(region.size);

    for (uint16_t i = 0; i < region.size; i++) {
#ifdef FADE
        region.set(i, active * curFade);
#else
        //Serial.println(i);
        region.set(i, active);
#endif
    }
    return (uint32_t) (idealDelay < SLOWNESS ? SLOWNESS : idealDelay);
}
