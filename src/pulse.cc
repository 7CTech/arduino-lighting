#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "macros.hh"


//region user
#define TIME_OUT 100
#define TIME_OFF 0
#define STEPS 60

const uint8_t colors[][3] = {
        { 60, 0, 0 },
        { 0, 60, 0 },
        { 0, 0, 60 }
};

//endregion

void pulse_setup(Adafruit_NeoPixel &pixels) {

}

void pulse(Adafruit_NeoPixel &pixels) {
    static int step = 0;
    static int color_pos = 0;
    double percent = ((STEPS - double(step)) / STEPS);
    delay(TIME_OUT / STEPS);
    for (uint16_t i = 0; i < NUM_PIXELS; i++) {
        SET_COLOR(pixels, i, percent * colors[color_pos][0], percent * colors[color_pos][1], percent * colors[color_pos][2]);
    }
    pixels.show();
    if (step == STEPS) {
        step = -1;
        color_pos++;
        if (color_pos == sizeof(colors)/sizeof(colors[0])) color_pos = 0;
        delay(TIME_OFF);
    }
    step++;
}

