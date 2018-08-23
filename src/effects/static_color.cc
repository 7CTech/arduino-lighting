//
// Created by ctech on 28/06/18.
//

#include "static_color.hh"

StaticColor::StaticColor(Region &region, Color color, uint16_t delay) : Effect(region), color(color), delay(delay) {

}

void StaticColor::init() {

}

int16_t StaticColor::loop() {
    for (uint16_t i = 0; i < region.size; i++) {
        region.set(i, color);
    }
    return delay;
}
