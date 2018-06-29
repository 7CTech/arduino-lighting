#include <Adafruit_NeoPixel.h>
#include <Arduino.h>
#include <pt.h>
#include <effects/spectrum_cycle.hh>
#include <effects/static_color.hh>

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
SpectrumCycle cycle1 = SpectrumCycle(half, Color(255, 0, 0), 1);
Breathe breathe2 = Breathe(half2);

pt proto1, proto2;

void setup() {
    pixels.begin();
    Serial.begin(9600);
    //clear
    for (uint16_t i = 0; i < NUM_PIXELS; i++) {
        pixels.setPixelColor(i, 100, 100, 100);
    }
    pixels.show();
    randomSeed(static_cast<unsigned long>(analogRead(0)));
    PT_INIT(&proto1);
    PT_INIT(&proto2);
    Serial.println(F("Setup"));
}
#ifdef __CLION_IDE__
#pragma clang diagnostic pop
#endif

#ifdef __CLION_IDE__
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#endif
void loop() {
    PT_SCHEDULE(cycle1.run(&proto1));
    PT_SCHEDULE(breathe2.run(&proto2));
    pixels.show();
}
#ifdef __CLION_IDE__
#pragma clang diagnostic pop
#endif