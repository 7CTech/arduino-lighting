//
// Created by ctech on 11/06/18.
//

#ifndef ARDUINO_LEDS_TRAILS_COMMON_HH
#define ARDUINO_LEDS_TRAILS_COMMON_HH

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

typedef struct trail {
    int head;
    int length;
    int max_pos;
    const uint8_t *color;
} trail_t;

void move_one_pos(Adafruit_NeoPixel &pixels, trail_t &trail);


#endif //ARDUINO_LEDS_TRAILS_COMMON_HH
