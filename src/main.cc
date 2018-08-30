#include <FastLED.h>
#include <Arduino.h>
#include <pt.h>

#include "region.hh"

#include "effects/effects.hh"
#include "base_region.hh"

/*
 * This code has about a 3ms control loop cycles. Trying to use smaller delays will have no effect.
 */

#define PIN 6

#ifdef __CLION_IDE__
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#endif

#define NUM_LEDS 60
CRGB data[NUM_LEDS];

BaseRegion base(data, NUM_LEDS);

bool evenSelector (uint16_t index) {
    return index % 2 == 0;
}

bool allSelector (uint16_t index) {
    return true;
};

Region even = base.newRegion(evenSelector);
Region odd = base.newRegion(allSelector);

//Region half = Region(data, 0, 29);
//Region half2 = Region(data, 30, 60);

//SpectrumCycle spectrum(half, Color(255, 0, 0), 1000, 400);
SpectrumCycle s(even, 1000, 0);//, Color(0, 128, 0), 50);
Fill fill(odd, Color(255, 0, 0), 1000, 500, true);
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
    s.init();
    fill.init();
    Serial.println(F("INIT"));
}
#ifdef __CLION_IDE__
#pragma clang diagnostic pop
#endif

#ifdef __CLION_IDE__
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#endif
void loop() {
    PT_SCHEDULE(s.run(&proto1));
    PT_SCHEDULE(fill.run(&proto2));
    FastLED.show();
}
#ifdef __CLION_IDE__
#pragma clang diagnostic pop
#endif