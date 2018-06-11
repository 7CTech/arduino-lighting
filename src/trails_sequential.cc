//
// Created by ctech on 10/06/18.
//

#include <Adafruit_NeoPixel.h>
#include <time.h>
#include "trails_sequential.hh"
#include "macros.hh"
#include "trails_common.hh"

//region user
#define TRAIL_COUNT 1
#define TRAIL_LENGTH 5
#define LOOP_TIME 15000

#define UNORDERED_COLORS
#define OPTION_NO_DOUBLE_COLORS
//#define ORDERED_COLORS

#if defined(UNORDERED_COLORS) && defined(ORDERED_COLORS)
static_assert(false, "ORDERED AND UNORDERED");
#endif

const uint8_t colors[][3] = {
    { 128, 0, 0 },
    { 128, 0, 128 },
    { 0, 0, 128 }
};
//endregion

#define GAP (NUM_PIXELS / TRAIL_COUNT)
static_assert(TRAIL_COUNT * TRAIL_LENGTH < NUM_PIXELS, "TRAILS WILL COLLIDE");

void move_one_pos(Adafruit_NeoPixel &pixels, trail_t &trail);
const uint8_t *get_new_color();

trail_t _trails[TRAIL_COUNT];
trail_t temp;
boolean has_temp = false;

int color_index = -1;

void trails_sequential_setup(Adafruit_NeoPixel &pixels) {
    for (int i = 0; i < TRAIL_COUNT; i++) {
        _trails[i] = trail_t { -i * GAP, TRAIL_LENGTH, NUM_PIXELS, get_new_color() };
    }
    srand(time(nullptr));
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

const uint8_t *get_new_color() {
#ifdef OPTION_NO_DOUBLE_COLORS
    static int last_index = -1;
#endif
#if defined(ORDERED_COLORS)
    if (color_index >= (sizeof(colors) / sizeof(colors[0])) - 1) {
        color_index = -1;
    }
    color_index++;
    return colors[color_index];
#elif defined(UNORDERED_COLORS)
#ifdef OPTION_NO_DOUBLE_COLORS
    int index = rand() % (sizeof(colors) / sizeof(colors[0])) + 0;
    while (index == last_index) {
        index = rand() % (sizeof(colors) / sizeof(colors[0])) + 0;
    }
    last_index = index;
    return colors[index];
#else
    return colors[rand() % (sizeof(colors) / sizeof(colors[0])) + 0];
#endif

#endif
}