//
// Created by ctech on 24/06/18.
//

#pragma once

#include <WS2812.h>
#include <pt-sem.h>

#include "color.hh"
#include "waiter.hh"

class Region {
public:
    const uint16_t minIndex;
    const uint16_t maxIndex;
    const uint16_t size = maxIndex - minIndex + 1;

    explicit Region(WS2812 &leds, uint16_t minIndex, uint16_t maxIndex);

    void set(uint16_t regionIndex, uint8_t r, uint8_t g, uint8_t b);
    void set(uint16_t regionIndex, const Color &color);
    void set(uint16_t regionIndex, const Color &color, double scale);

    void setBase(uint8_t r, uint8_t g, uint8_t b);
    void setBase(const Color &color);

    void clear();

private:
    WS2812 &leds;
    Color base;
    void *owner;
    friend class Effect;
    bool claim(void *me);
    bool free(void *me);
};
