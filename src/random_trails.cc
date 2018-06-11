//
// Created by ctech on 11/06/18.
//

#include <time.h>
#include "random_trails.hh"

//region user
#define MAX_LENGTH 5
#define MIN_LENGTH 2
#define MAX_DIST 10
#define MIN_DIST 3
#define MAX_TRAILS 5
//speed in leds/sec
#define SPEED 5
//endregion

#define SPEED_ACTUAL (1000 / SPEED)

int indices[MAX_TRAILS][3];

void random_trails_setup(Adafruit_NeoPixel &pixels) {
    srand(time(nullptr));
}

void random_trails(Adafruit_NeoPixel &pixels) {

}

/**
 * true for forwards
 * @return
 */
boolean get_direction() {
    return static_cast<boolean>(rand() % 2 + 0);
}

int get_dist() {
    return rand() % (MAX_DIST + 1) + MIN_DIST;
}