//
// Created by ctech on 26/06/18.
//

#include "effect.hh"


Effect::Effect(Region &region) : region(region), w(Waiter(0)) {

}

#ifdef __CLION_IDE__
#pragma clang diagnostic push
#pragma ide diagnostic ignored "missing_default_case"
#endif
const int Effect::run(struct pt *proto) {
    PT_BEGIN(proto);
    PT_SEM_WAIT(proto, &region.effectSem);
    int16_t delay;
    while ((delay = loop()) > 0) {
        w = Waiter(unsigned(delay));
        PT_WAIT_UNTIL(proto, w.hasWaited());
    }
    PT_SEM_SIGNAL(proto, &region.effectSem);
    PT_END(proto);
}
#ifdef __CLION_IDE__
#pragma clang diagnostic pop
#endif

const void Effect::kill() {

}
