//
// Created by ctech on 11/06/18.
//

#include "trails_common.hh"
#include "macros.hh"

//todo: directional code
void move_one_pos(Adafruit_NeoPixel &pixels, trail_t &trail) {
    if (trail.head < 0) return;
    for (int i = trail.length; i >= 0; i--) {
        double percent = double(trail.length - i) / trail.length;
        int expected_index = trail.head - i;
        if (expected_index >= trail.max_pos || expected_index < 0) continue;
        SET_COLOR(pixels, unsigned(expected_index), percent * trail.color[0], percent * trail.color[1], percent * trail.color[2]);
    }
}

