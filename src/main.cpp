#include <Adafruit_NeoPixel.h>
#include "macros.hh"
#include "modes.hh"

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_PIXELS, PIN, NEO_GRB + NEO_KHZ800);

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
void setup() {
    pixels.begin();

    // yes
    for (uint16_t i = 0; i < NUM_PIXELS; i++) {
        SET_COLOR(pixels, i, 0, 0, 0);
    }

    randomSeed(analogRead(0));

    pixels.show();

    //trails_sequential_setup(pixels);
}
#pragma clang diagnostic pop


#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
void loop() {
    breathe(pixels);
}
#pragma clang diagnostic pop