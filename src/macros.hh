//
// Created by ctech on 10/06/18.
//

#ifndef ARDUINO_LEDS_MACROS_HH
#define ARDUINO_LEDS_MACROS_HH

//region user constants
#define NUM_PIXELS 60
#define PIN 6
//endregion

#define COLOR(pixels, r, g, b) pixels.Color(r, g, b)
#define SET_COLOR(pixels, i, r, g, b) pixels.setPixelColor(i, COLOR(pixels, r, g, b))

#endif //ARDUINO_LEDS_MACROS_HH
