//
// Created by jason on 24/08/18.
//

#include "sequential_trails.hh"

SequentialTrails::SequentialTrails(Region &region, Color color, uint8_t length, uint8_t count, uint32_t loopTime, bool circular) :
        Effect(region), color(color), length(length), count(count), loopTime(loopTime), circular(circular), headDist(
        static_cast<const uint8_t>(region.size / count)) {
    if (headDist <= length) {
        headDist = static_cast<uint8_t>(length + 1);
    }
    memset(heads, 0, (count + 1) * sizeof(uint8_t)); //clear buffer
    first = true;
}

void SequentialTrails::init() {
    first = true;
}

uint32_t SequentialTrails::loop() {
    for (int i = 0; i <= count; i++) {
        if (!circular) { //circular means non-uniform distance to ensure smooth wrapping
            if (i == 0) { //accessing [-1] is a tad hard
                if (first) {
                    fadeBack(heads[0]);
                    heads[0] += 1;
                    if (int32_t(heads[0]) - length >= signed(region.size)) {
                        heads[0] = 0;
                        first = false;
                    }
                } else if (heads[count] - heads[0] >= headDist || heads[count] < heads[0]) {
                    fadeBack(heads[0]);
                    heads[0] += 1;
                    if (heads[0] - length >= signed(region.size)) {
                        heads[0] = 0;
                    }
                }
            } else if (heads[i - 1] - heads[i] > headDist || heads[i - 1] < heads[i]) {
                fadeBack(heads[i]);
                heads[i] += 1;
                if (heads[i] - length >= signed(region.size)) {
                    heads[i] = 0;
                }
            }
        }
    }
    return loopTime/region.size;
}

void SequentialTrails::fadeBack(uint8_t head) {
    for (int i = head; i >= 0 && i > head - length; i--) {
        double scale = double(i - head + length) / length;
        region.set(unsigned(i), color * scale);
    }
    const int16_t min = head - length;
    if (min >= 0) {
        region.set(unsigned(min), 0, 0, 0);
    }
}

SequentialTrails::~SequentialTrails() {
    free(heads);
}


