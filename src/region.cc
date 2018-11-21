//
// Created by ctech on 24/06/18.
//

#include <alloca.h>
#include <FastLED.h>

#include "color.hh"
#include "region.hh"

Region::Region(CRGBContainer *indices, uint16_t size) :
        size(size), indices(indices), base(Color(0, 0, 0)) {
    owner = nullptr;
}

void Region::set(const uint16_t regionIndex, const uint8_t r, const uint8_t g, const uint8_t b) {
    Serial.println(regionIndex);
    Serial.println(size);
    this->operator[](regionIndex)->setRGB(r, g, b);
}

void Region::set(const uint16_t regionIndex, const Color &color) {
    set(regionIndex, color.r, color.g, color.b);
}

void Region::setBase(const uint8_t r, const uint8_t g, const uint8_t b) {
    for (uint16_t i = 0; i < size; i++) {
        set(i, r, g, b);
    }
    base = Color(r, g, b); //we hold a new object
}

void Region::setBase(const Color &color) {
    setBase(color.r, color.g, color.b);
}

/**
 * Immeadiately sets the region to it's base color. If an effect is still active there will probably be a conflict of some sort
 */
void Region::clear() {
    for (uint16_t i = 0; i < size; i++) {
        set(i, base);
    }
}

bool Region::claim(void *me) {
    if (owner == me) return true;
    if (owner == nullptr) {
        owner = me;
        return true;
    }
    return false;
}

bool Region::free(void *me) {
    if (owner == me) {
        owner = nullptr;
        return true;
    }
    return false;
}

Region::~Region() {
    free(indices);
}

CRGB *Region::operator[](uint16_t n) {
    if (n < 0 || n >= size) return nullptr;
    CRGB *led = indices[n].led;
    return led;
}


