//
// Created by jason on 12/05/19.
//

#include "ripple.hh"

Ripple::Ripple(Ripple::Builder &builder) : Effect(*builder.region), origin(builder.origin), timeToBounds(builder.timeToBounds), timeToExit(builder.timeToExit), timeOff(builder.timeOff), count(builder.count), direction(builder.direction), width(builder.width) {

}

void Ripple::init() {
    dist = 0;
}

uint32_t Ripple::loop() {

}


Ripple::Builder::Builder(Region &region) : region(&region) {

}

Ripple::Builder *Ripple::Builder::setRegion(Region &region) {
    this->region = &region;
    return this;
}

Region &Ripple::Builder::getRegion() {
    return *region;
}

Ripple::Builder *Ripple::Builder::setOrigin(uint16_t origin) {
    this->origin = origin;
    return this;
}

uint16_t Ripple::Builder::getOrigin() {
    return origin;
}

Ripple::Builder *Ripple::Builder::setTimeToBounds(uint32_t timeToBounds) {
    this->timeToBounds = timeToBounds;
    return this;
}

uint32_t Ripple::Builder::getTimeToBounds() {
    return timeToBounds;
}

Ripple::Builder *Ripple::Builder::setTimeToExit(uint32_t timeToExit) {
    this->timeToExit = timeToExit;
    return this;
}

uint32_t Ripple::Builder::getTimeToExit() {
    return timeToExit;
}

Ripple::Builder *Ripple::Builder::setTimeOff(uint32_t timeOff) {
    this->timeOff = timeOff;
    return this;
}

uint32_t Ripple::Builder::getTimeOff() {
    return timeOff;
}

Ripple::Builder *Ripple::Builder::setCount(uint16_t count) {
    this->count = count;
    return this;
}

uint16_t Ripple::Builder::getCount() {
    return count;
}

Ripple::Builder *Ripple::Builder::setDirection(int8_t direction) {
    this->direction = direction;
    return this;
}

int8_t Ripple::Builder::getDirection() {
    return direction;
}

Ripple::Builder *Ripple::Builder::setWidth(uint8_t width) {
    this->width = width;
    return this;
}

uint8_t Ripple::Builder::getWidth() {
    return width;
}

