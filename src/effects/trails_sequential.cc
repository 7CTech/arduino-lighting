//
// Created by ctech on 23/06/18.
//

#include "trails_sequential.hh"

TrailsSequential::TrailsSequential(Region &region, uint16_t trailLength, uint16_t trailCount, uint16_t loopTime) :
        Effect(region), trailLength(trailLength), trailCount(trailCount), trailGap(trailCount / region.size), loopTime(loopTime) {
    memset(trails, 0, trailCount * sizeof(TrailBasic)); //clear area
}

void TrailsSequential::init() {
    memset(trails, 0, trailCount * sizeof(TrailBasic)); //clear all trails
}

int16_t TrailsSequential::loop() {
    for (uint16_t i = 0; i < trailCount; i++) {
        if (trails + (i * sizeof(TrailBasic)) == nullptr) { // new trail
            if (i == 0 || trails[i - 1].head - trailLength == trailGap) {
                const TrailBasic temp = TrailBasic(region, trailLength, Color(), true, loopTime);
                memcpy(trails + (i * sizeof(TrailBasic)), &temp, sizeof(TrailBasic));
            }
        }
        if (trails[i].loop() == 0) {
            const TrailBasic temp = TrailBasic(region, trailLength, Color(), true, loopTime);
            memcpy(trails + (i * sizeof(TrailBasic)), &temp, sizeof(TrailBasic));
        }
    }

    return loopTime / region.size;
}
