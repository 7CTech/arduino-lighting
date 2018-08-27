//
// Created by jason on 26/08/18.
//

#include "fill.hh"
#include <effect.hh>

Fill::Fill(Region &region, Color color, uint32_t inTime, uint32_t outTime, bool fade) : Effect(region), color(color),
    inTime(inTime), outTime(outTime), fade(fade), head(0) {

}

void Fill::init() {
    head = 0;
}

uint32_t Fill::loop() {
    if (direction) {
        if (head >= region.size) {
            if (outTime != 0) {
                direction = false;
                return 1; //todo: add hold time?
            }
            else {
                region.clear();
                head = 0;
            }
        }
        for (uint16_t i = head; i >= 0 && i != 65535; i--) { //there is some really really weird bug here
            double percent = fade ? (double(region.size - (head - i)) / region.size) : 1;
            region.set(i, color * percent);
        }
        head++;
        return inTime/region.size;
    } else {
        if (head == 65534) { //le has no effect
            if (inTime != 0) {
                direction = true;
                head = 0;
                return outTime/region.size;
            } else {
                region.clear();
                head = region.size - 1;
            }
        }
        Serial.println(head);
        for (uint16_t i = head; i >= 0 && i < 65534; i--) { //there is some really really weird bug here
            //Serial.println(i);
            double percent = fade ? (double(region.size - (head - i)) / region.size) : 1;
            region.set(i, color * percent);
        }
        region.set(head + 1, 0, 0, 0);
        head--;
        return outTime/region.size;
    }
}
