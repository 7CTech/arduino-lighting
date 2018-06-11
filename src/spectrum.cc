//
// Created by ctech on 10/06/18.
//

#include <Adafruit_NeoPixel.h>
#include "spectrum.hh"
#include "macros.hh"

//region user
#define DELAY 1
//endregion

void spectrum_setup(Adafruit_NeoPixel &pixels) {

}

void spectrum(Adafruit_NeoPixel &pixels) {
    uint8_t rgb_color[] = { 255, 0, 0 };


    for (int dec_color = 0; dec_color < 3; dec_color += 1) {
        int inc_color = dec_color == 2 ? 0 : dec_color + 1;

        // cross-fade the two colours.
        for(int i = 0; i < 255; i += 1) {
            rgb_color[dec_color] -= 1;
            rgb_color[inc_color] += 1;

            for (uint16_t j = 0; j < NUM_PIXELS; j++) {
                SET_COLOR(pixels, j, rgb_color[0], rgb_color[1], rgb_color[2]);
            }
            pixels.show();

            delay(DELAY);

        }
    }
}