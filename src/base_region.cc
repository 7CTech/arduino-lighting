//
// Created by jason on 28/08/18.
//

#include <Arduino.h>

#include "base_region.hh"
#include "region.hh"

BaseRegion::BaseRegion(CRGB *data, uint16_t size) : data(data), size(size) {
    claimed = (bool *)malloc(sizeof(bool) * size);
    for (uint16_t i = 0; i < size; i++) {
        claimed[i] = false;
    }
}

Region BaseRegion::newRegion(Selector selector) {
    uint16_t count = 0;
    for (uint16_t i = 0; i < size; i++) {
        //Serial.println(i);
        if (!claimed[i] && selector(i)) {
            count++;
        }
    }
    auto *passData = (CRGBContainer *)malloc(sizeof(CRGBContainer *) * count); //doing two for loops is probably faster than loads of reallocs
    Serial.println("done 1");
    uint16_t index = 0;
    for (uint16_t i = 0; i < size; i++) {
        if (!claimed[i] && selector(i)) {
            claimed[i] = true;
            passData[index].index = i;
            passData[index].led = &data[i];
            index++;
        }
    }
    return Region(passData, count);
}

void BaseRegion::deleteRegion(Region &region) {
    for (uint16_t i = 0; i < region.size; i++) {
        claimed[region.indices[i].index] = false;
    }

    region.~Region();
}
