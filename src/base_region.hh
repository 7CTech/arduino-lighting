//
// Created by jason on 28/08/18.
//

#pragma once

#include <FastLED.h>
#include "region.hh"


class BaseRegion {
public:
    explicit BaseRegion(CRGB *data, uint16_t size);
    typedef bool(&Selector)(int index);
    Region newRegion(Selector &selector);
    void deleteRegion(Region &region);

private:
    CRGB *data;
    bool *claimed;
    const uint16_t size;
};


