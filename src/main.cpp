#include <Adafruit_NeoPixel.h>
#include <Arduino.h>
#include <pt.h>
#include <effects/spectrum_cycle.hh>

#include "effects/breathe.hh"
#include "region.hh"
#include "effects/trail_basic.hh"

#define NUM_PIXELS 60
#define PIN 6

#ifdef __CLION_IDE__
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#endif

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_PIXELS, PIN, NEO_GRB + NEO_KHZ800);
Region half = Region(pixels, 0, 29);
Region half2 = Region(pixels, 30, 60);
SpectrumCycle cycle = SpectrumCycle(half, {255, 0, 0});
SpectrumCycle cycle2 = SpectrumCycle(half, {0, 255, 0});

pt proto;

void setup() {
    Serial.begin(9600);
    pixels.begin();
    //clear
    for (uint16_t i = 0; i < NUM_PIXELS; i++) {
        pixels.setPixelColor(i, 0, 0, 0);
    }
    randomSeed(static_cast<unsigned long>(analogRead(0)));
    PT_INIT(&proto);
}
#ifdef __CLION_IDE__
#pragma clang diagnostic pop
#endif

#ifdef __CLION_IDE__
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#endif
void loop() {
    cycle.run(&proto);
    cycle2.run(&proto);
}
#ifdef __CLION_IDE__
#pragma clang diagnostic pop
#endif