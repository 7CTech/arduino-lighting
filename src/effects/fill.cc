//
// Created by jason on 26/08/18.
//

#include "fill.hh"
#include <effect.hh>

Fill::Fill(Region &region, Color color, uint32_t fadeInTime, bool fadeBack) : Effect(region), color(color), fadeInTime(fadeInTime),
        fadeBack(fadeBack), head(0) {

}

void Fill::init() {
    head = 0;
}

uint32_t Fill::loop() {
    if (head >= region.size) {
        region.clear();
        head = 0;
    }
    for (uint16_t i = head; i >= 0 && i != uint16_t(0) - 1; i--) { //there is some really really weird bug here
        Serial.println(i);
        region.set(i, color * (double(region.size - (head - i))/region.size));
    }
    //Serial.println(head);
    head++;
    return fadeInTime/region.size;
}
