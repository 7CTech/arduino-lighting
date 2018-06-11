//
// Created by ctech on 10/06/18.
//

#include "breathe.hh"
#include "macros.hh"

//region user
#define TIME_IN 250
#define TIME_OUT 250
#define TIME_OFF 100
#define STEPS 60

const uint8_t colors[][3] = {
        { 60, 0, 0 },
        { 60, 0, 60 },
        { 0, 0, 60 }
};
//endregion

void breathe_setup(Adafruit_NeoPixel &pixels) {

}

int color_pos = 0;
bool direction = true;
int step = 0;

void breathe(Adafruit_NeoPixel &pixels) {
    double percent;
    if (direction) {
        percent = (double(step) / STEPS);
        delay(TIME_IN / STEPS);
    }
    else {
        percent = ((STEPS - double(step)) / STEPS);
        delay(TIME_OUT / STEPS);
    }
    for (uint16_t i = 0; i < NUM_PIXELS; i++) {
        SET_COLOR(pixels, i, percent * colors[color_pos][0], percent * colors[color_pos][1], percent * colors[color_pos][2]);
    }
    pixels.show();

    if (step / STEPS == 1) {
        step = -1;
        direction = !direction;
        if (direction) {
            color_pos++;
            if (color_pos == sizeof(colors) / sizeof(colors[0])) color_pos = 0;
            delay(TIME_OFF);
        }
    }
    step++;
}