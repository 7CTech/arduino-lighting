//
// Created by ctech on 24/06/18.
//

#pragma once

#include <pt-sem.h>
#include <FastLED.h>

#include "color.hh"
#include "waiter.hh"

struct CRGBContainer {
    explicit CRGBContainer(CRGB *led, uint16_t index) : led(led), index(index) {

    }

    CRGB *led;
    uint16_t index;
};

class Region {
public:
    const uint16_t size;

    CRGB *operator[](uint16_t  n);

    void set(uint16_t regionIndex, uint8_t r, uint8_t g, uint8_t b);
    void set(uint16_t regionIndex, const Color &color);

    void setBase(uint8_t r, uint8_t g, uint8_t b);
    void setBase(const Color &color);

    void clear();
    ~Region();

protected:
    explicit Region(CRGBContainer *, uint16_t size);
    CRGBContainer *indices;
private:
    Color base;
    void *owner;
    friend class Effect;
    friend class BaseRegion;
    bool claim(void *me);
    bool free(void *me);
};
