#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "macros.hh"


//region user
// number of times to decrement
#define STEPS 60

#define TIME_OUT 100
#define TIME_OFF 0

const uint8_t colors[][3] = {
        { 60, 0, 0 },
        { 0, 60, 0 },
        { 0, 0, 60 }
};

//endregion


#define GET_DECREMENT(pos) (double(pos) / (STEPS))

#define GET_COLOR(pos, max) ((max) - ((max) * GET_DECREMENT(pos)))
#define GET_COLORS(pixels, pos, color) COLOR(pixels, GET_COLOR(pos, (color)[0]), GET_COLOR(pos, (color)[1]), GET_COLOR(pos, (color)[2]))

void pulse_setup(Adafruit_NeoPixel &pixels) {

}

void pulse(Adafruit_NeoPixel &pixels) {
    static int decrement_pos = 0;
    static int color_index = 0;
    for (uint16_t i = 0; i < NUM_PIXELS; i++) {
        pixels.setPixelColor(i, GET_COLORS(pixels, decrement_pos, colors[color_index]));
    }
    pixels.show();
    if (decrement_pos == STEPS) {
        decrement_pos = -1;
        color_index++;
        if (color_index == sizeof(colors)/sizeof(colors[0])) {
            color_index = 0;
        }
        delay(TIME_OFF);
    } else {
        delay(TIME_OUT / STEPS);
    }

    decrement_pos++;
}

