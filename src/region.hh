//
// Created by ctech on 24/06/18.
//

#pragma once

#include <pt-sem.h>
#include <FastLED.h>

#include "color.hh"
#include "waiter.hh"

class Region {
public:
    const uint16_t minIndex;
    const uint16_t maxIndex;
    const uint16_t size = maxIndex - minIndex;

    explicit Region(CRGB *data, uint16_t minIndex, uint16_t maxIndex);

    void set(uint16_t regionIndex, uint8_t r, uint8_t g, uint8_t b);
    void set(uint16_t regionIndex, const Color &color);

    void setBase(uint8_t r, uint8_t g, uint8_t b);
    void setBase(const Color &color);

    void clear();
private:
    CRGB *data;
    Color base;
    void *owner;
    friend class Effect;
    bool claim(void *me);
    bool free(void *me);
};
