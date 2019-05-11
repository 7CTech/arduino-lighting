//
// Created by jason on 11/05/19.
//

#include "modifier.hh"

const void Modifier::setParentEffect(Effect &effect) {
    this->parent = &effect;
}

void Modifier::clear() {
}


const void Modifier::modifyImpl(Effect &effect, MutableRegionState &regionState) {
    if (parent != &effect) return;
    modify(regionState);
}

