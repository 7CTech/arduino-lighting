//
// Created by ctech on 10/06/18.
//

#include "breathe.hh"
#include "macros.hh"
#include "common.hh"

//region user
#define TIME_IN 250
#define TIME_OUT 250
#define TIME_OFF 100
#define STEPS 60
//endregion

void breathe_setup(Adafruit_NeoPixel &pixels) {

}

void breathe(Adafruit_NeoPixel &pixels) {
    static bool forward = true;
    static int step = 0;
    static const uint8_t *color = get_new_color();

    double percent;
    if (forward) {
        percent = (double(step) / STEPS);
        delay(TIME_IN / STEPS);
    }
    else {
        percent = ((STEPS - double(step)) / STEPS);
        delay(TIME_OUT / STEPS);
    }
    for (uint16_t i = 0; i < NUM_PIXELS; i++) {
        SET_COLOR(pixels, i, percent * color[0], percent * color[1], percent * color[2]);
    }
    pixels.show();

    if (step == STEPS) {
        step = -1;
        forward = !forward;
        if (forward) {
            color = get_new_color();
            delay(TIME_OFF);
        }
    }
    step++;
}