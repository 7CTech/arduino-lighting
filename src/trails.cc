//
// Created by ctech on 10/06/18.
//

#include <Adafruit_NeoPixel.h>
#include "trails.hh"
#include "macros.hh"

//region user
#define TRAIL_COUNT 10
#define TRAIL_LENGTH 5
#define LOOP_TIME 4000

//#define UNORDERED_COLORS
#define ORDERED_COLORS

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

typedef struct trail {
    int head;
    const uint8_t *color;
} trail_t;

void move_one_pos(Adafruit_NeoPixel &pixels, trail_t &trail);
const uint8_t *get_new_color();

trail_t _trails[TRAIL_COUNT + 1];
trail_t temp;
boolean have_temp = false;

int color_index = -1;

void trails_setup(Adafruit_NeoPixel &pixels) {
    for (int i = 0; i < TRAIL_COUNT; i++) {
        _trails[i] = trail_t { -i * GAP, get_new_color() };
    }
}

void trails(Adafruit_NeoPixel &pixels) {
    for (int i = 0; i < TRAIL_COUNT; i++) {
        move_one_pos(pixels, _trails[i]);
        if (_trails[i].head == NUM_PIXELS) {
            temp = trail_t { 0, get_new_color() };
            have_temp = true;
        }
        if (_trails[i].head - TRAIL_LENGTH == NUM_PIXELS) { //drop us
            _trails[i] = temp;
            have_temp = false;
        }
        _trails[i].head++;
    }
    if (have_temp) {
        move_one_pos(pixels, temp);
        temp.head++;
    }
    pixels.show();
    delay(LOOP_TIME / NUM_PIXELS);
}

/**
 * Move a trail forward by 1 index. Does not apply configuration
 * @param pixels Neopixels object
 * @param head the (new) head
 */
void move_one_pos(Adafruit_NeoPixel &pixels, trail_t &trail) {
    if (trail.head < 0) return;
    for (int i = TRAIL_LENGTH; i >= 0; i--) {
        double percent = double(TRAIL_LENGTH - i) / TRAIL_LENGTH;
        int expected_index = trail.head - i;
        if (expected_index >= NUM_PIXELS) continue;
        SET_COLOR(pixels, unsigned(expected_index), percent * trail.color[0], percent * trail.color[1], percent * trail.color[2]);
    }
}

const uint8_t *get_new_color() {
#if defined(ORDERED_COLORS)
    if (color_index >= (sizeof(colors) / sizeof(colors[0])) - 1) {
        color_index = -1;
    }
    color_index++;
    return colors[color_index];
#elif defined(UNORDERED_COLORS)
#endif
}