//
// Created by ctech on 10/06/18.
//

#include <Adafruit_NeoPixel.h>
#include <time.h>
#include "trails_sequential.hh"
#include "macros.hh"
#include "trails_common.hh"
#include "common.hh"

//region user
#define TRAIL_COUNT 6
#define TRAIL_LENGTH 5
#define LOOP_TIME 4000
//endregion

#define GAP (NUM_PIXELS / TRAIL_COUNT)
static_assert(TRAIL_COUNT * TRAIL_LENGTH < NUM_PIXELS, "TRAILS WILL COLLIDE");

trail_t _trails[TRAIL_COUNT];
trail_t temp;
boolean has_temp = false;

int color_index = -1;

void trails_sequential_setup(Adafruit_NeoPixel &pixels) {
    for (int i = 0; i < TRAIL_COUNT; i++) {
        _trails[i] = trail_t { -i * GAP, TRAIL_LENGTH, NUM_PIXELS, get_new_color() };
    }
}

void trails_sequential(Adafruit_NeoPixel &pixels) {
    for (int i = 0; i < TRAIL_COUNT; i++) {
        move_one_pos(pixels, _trails[i]);
        if (_trails[i].head == NUM_PIXELS) {
            temp = trail_t { 0, TRAIL_LENGTH, NUM_PIXELS, get_new_color() };
            has_temp = true;
        }
        if (_trails[i].head - TRAIL_LENGTH == NUM_PIXELS) { //drop us
            _trails[i] = temp;
            move_one_pos(pixels, temp);
            temp.head++; //move the temp
            has_temp = false;
        }
        _trails[i].head++;
    }
    if (has_temp) {
        move_one_pos(pixels, temp);
        temp.head++;
    }
    pixels.show();
    delay(LOOP_TIME / NUM_PIXELS);
}