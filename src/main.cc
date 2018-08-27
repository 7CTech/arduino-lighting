#include <FastLED.h>
#include <Arduino.h>
#include <pt.h>

#include "region.hh"

#include "effects/effects.hh"

/*
 * This code has about rms control loop cycles. Trying to use smaller delays will have no effect.
 */

#define NUM_PIXELS 60
#define PIN 6

#ifdef __CLION_IDE__
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#endif

#define NUM_LEDS 60
CRGB data[NUM_LEDS];

Region full(data, 0, 60);
Region half = Region(data, 0, 29);
Region half2 = Region(data, 30, 60);

//SpectrumCycle spectrum(half, Color(255, 0, 0), 1000, 400);
Fill trails(full, Color(128, 0, 0), 3000, 3000, true);//, Color(0, 128, 0), 50);
//StaticColor staticC(half, Color(255, 0, 0), 50);
//StaticColor staticC2(half2, Color(128, 0, 0), 50);
pt proto1, proto2;

/*
 * Note to future sleep deprived self
 * cRGB takes values in order g, r b
 */

void setup() {

    Serial.begin(2000000);
    FastLED.addLeds<NEOPIXEL, PIN>(data, NUM_LEDS);
    //clear
    for (auto &i : data) {
        i.setRGB(0, 0 , 0);
    }
    FastLED.show();
    randomSeed(static_cast<unsigned long>(analogRead(0)));
    PT_INIT(&proto1);
    PT_INIT(&proto2);
    trails.init();
}
#ifdef __CLION_IDE__
#pragma clang diagnostic pop
#endif

#ifdef __CLION_IDE__
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#endif
void loop() {
    PT_SCHEDULE(trails.run(&proto1));
    //PT_SCHEDULE(staticC2.run(&proto2));
    FastLED.show();
}
#ifdef __CLION_IDE__
#pragma clang diagnostic pop
#endif