#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "macros.hh"
#include "common.hh"


//region user
#define TIME_OUT 100
#define TIME_OFF 0
#define STEPS 60
//endregion

void pulse_setup(Adafruit_NeoPixel &pixels) {

}

void pulse(Adafruit_NeoPixel &pixels) {
    static int step = 0;
    static const uint8_t *color = get_new_color();
    double percent = ((STEPS - double(step)) / STEPS);
    delay(TIME_OUT / STEPS);
    for (uint16_t i = 0; i < NUM_PIXELS; i++) {
        SET_COLOR(pixels, i, percent * color[0], percent * color[1], percent * color[2]);
    }
    pixels.show();
    if (step == STEPS) {
        step = -1;
        color = get_new_color();
        delay(TIME_OFF);
    }
    step++;
}

