//
// Created by ctech on 26/06/18.
//
#include <Arduino.h>

#include "effect.hh"


Effect::Effect(Region &region) : region(region), w(Waiter(0)) {
    delay = 1;
}

#ifdef __CLION_IDE__
#pragma clang diagnostic push
#pragma ide diagnostic ignored "missing_default_case"
#endif
const PT_THREAD(Effect::run(struct pt *proto)) {
    PT_BEGIN(proto);
    while (delay > 0) {
        PT_YIELD_UNTIL(proto, region.claim(this));
        PT_YIELD_UNTIL(proto, w.hasWaited());
        delay = loop();
        w = Waiter(delay);
    }
    //region.free(this);
    PT_END(proto);

}
#ifdef __CLION_IDE__
#pragma clang diagnostic pop
#endif

const void Effect::kill() {
    region.free(this);
}
