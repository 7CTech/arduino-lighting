//
// Created by ctech on 11/06/18.
//

#ifndef ARDUINO_LEDS_COMMON_HH
#define ARDUINO_LEDS_COMMON_HH

#include <Arduino.h>

//region user
#define UNORDERED_COLORS
#define OPTION_NO_DOUBLE_COLORS
//#define ORDERED_COLORS

const uint8_t colors[][3] = {
        { 128, 0, 0 },
        { 128, 0, 128 },
        { 0, 0, 128 }
};
//endregion


#if defined(UNORDERED_COLORS) && defined(ORDERED_COLORS)
static_assert(false, "ORDERED AND UNORDERED");
#endif

const uint8_t *get_new_color();


#endif //ARDUINO_LEDS_COMMON_HH
