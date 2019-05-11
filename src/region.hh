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

    CRGB *operator[](uint16_t n);

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

class RegionState {
    explicit RegionState(Region &region) : size(region.size), region(region) {

    }

public:
    const uint16_t size;
protected:
    Region &region;
};

class MutableRegionState : RegionState {
public:
    const CRGB *get(uint16_t n) {
        return region[n];
    }
    const void set(uint16_t n, uint8_t r, uint8_t g, uint8_t b) {
        region.set(n, r, g, b);
    }
    const void set(uint16_t n, const CRGB &data) {
        region.set(n, data.r, data.g, data.b);
    }
    template <typename T>
    void all(const T &caller, const CRGB(*f)(const T &caller, const CRGB *)) {
        for (uint16_t i = 0; i < size; i++) {
            set(i, f(caller, get(i)));
        }
    }
};
