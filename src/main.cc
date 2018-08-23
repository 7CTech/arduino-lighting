//#include <Adafruit_NeoPixel.h>
#include <WS2812.h>
#include <Arduino.h>
#include <pt.h>
#include <effects/spectrum_cycle.hh>
#include <effects/static_color.hh>
#include <effects/trails_sequential.hh>

#include "effects/breathe.hh"
#include "region.hh"
#include "effects/trail_basic.hh"


#define NUM_PIXELS 60
#define PIN 6

#ifdef __CLION_IDE__
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#endif

WS2812 leds(NUM_PIXELS);
//Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_PIXELS, PIN, NEO_GRB + NEO_KHZ800);
Region full(leds, 0, 60);
Region half = Region(leds, 0, 29);
Region half2 = Region(leds, 30, 60);

SpectrumCycle purple(half, Color(255, 0, 0), 1);
Breathe green(half2, 50, 49, 50, 0);//, Color(0, 128, 0), 50);

pt proto1, proto2;

/*
 * Note to future sleep deprived self
 * cRGB takes values in order g, r b
 */

void setup() {
    Serial.begin(2000000);
    leds.setOutput(PIN);
    leds.setColorOrderGRB();
    //pixels.begin();
    //clear
    for (uint16_t i = 0; i < NUM_PIXELS; i++) {
        leds.set_crgb_at(i, { 0, 0, 0 });
        //leds.setPixelColor(i, 0, 0, 0);
    }
    leds.sync();
    randomSeed(static_cast<unsigned long>(analogRead(0)));
    PT_INIT(&proto1);
    PT_INIT(&proto2);
    purple.init();
    green.init();
}
#ifdef __CLION_IDE__
#pragma clang diagnostic pop
#endif

#ifdef __CLION_IDE__
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#endif
void loop() {
    PT_SCHEDULE(purple.run(&proto1));
    PT_SCHEDULE(green.run(&proto2));
    //PT_SCHEDULE(breathe2.run(&proto2));
    leds.sync();
}
#ifdef __CLION_IDE__
#pragma clang diagnostic pop
#endif