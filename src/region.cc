//
// Created by ctech on 24/06/18.
//

#include <Adafruit_NeoPixel.h>

#include "color.hh"
#include "region.hh"

Region::Region(Adafruit_NeoPixel &pixels, uint16_t minIndex, uint16_t maxIndex) :
        minIndex(minIndex), maxIndex(maxIndex), pixels(pixels), effectSem(pt_sem{}), base(Color(0, 0, 0)) {
    PT_SEM_INIT(&effectSem, 1);
}

void Region::set(const uint16_t regionIndex, const uint8_t r, const uint8_t g, const uint8_t b) {
    if (minIndex + regionIndex > maxIndex) {
        //todo: wrapping?
        //region locks to a range, exceeding this is a no-go
        return;
    }

    pixels.setPixelColor(minIndex + regionIndex, r, g, b);
}

void Region::set(const uint16_t regionIndex, const Color &color) {
    set(regionIndex, color.r, color.g, color.b);
}

void Region::set(uint16_t regionIndex, const Color &color, double scale) {
    set(regionIndex, static_cast<uint8_t>(scale * color.r), static_cast<uint8_t>(scale * color.g),
        static_cast<uint8_t>(scale * color.b));
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


