//
// Created by jason on 21/12/18.
//

#include <Arduino.h>
#include "christmas.hh"
#include <effect.hh>

Christmas::Christmas(Christmas::Builder &builder) :
        Effect(*builder.region), steps(builder.steps), minTimeIn(builder.minTimeIn), maxTimeIn(builder.maxTimeIn),
        minTimeOut(builder.minTimeOut), maxTimeOut(builder.maxTimeOut), minTimeOn(builder.minTimeOn), maxTimeOn(builder.maxTimeOn),
        minTimeOff(builder.minTimeOff), maxTimeOff(builder.maxTimeOff), minCountOn(builder.minCountOn), maxCountOn(builder.maxCountOn), bias(builder.bias) {
    step = -1;
    fadingIn = false;
}

void Christmas::init() {
    active = (uint8_t)random(minCountOn, maxCountOn);
    memset(indicies, 0, maxCountOn * sizeof(Holder));
    for (uint8_t i = 0; i < active; i++) {

    }
    step = 0;
    fadingIn = true;
    timeIn = (uint16_t)random(minTimeIn, maxTimeIn);
    timeOut = (uint16_t)random(minTimeOut, maxTimeOut);
    createHolders(indicies, active, 0, region.size);
}

uint32_t Christmas::loop() {
    double percent;
    uint32_t totalDelay = 0;
    if (fadingIn) {
        percent = (double(step) / steps);
    } else {
        percent = ((steps - double(step)) / steps);
    }

    for (uint16_t i = 0; i < active; i++) {
        region.set(indicies[i].index, indicies[i].green ? green * percent : red * percent);
    }

    if (step == steps) {
        step = -1;
        fadingIn = !fadingIn;
        if (fadingIn) {
            totalDelay += random(minTimeOff, maxTimeOff);
            timeIn = (uint16_t)random(minTimeIn, maxTimeIn);
            timeOut = (uint16_t)random(minTimeOut, maxTimeOut);
            memset(indicies, 0, active * sizeof(Holder));
            active = (uint8_t)random(minCountOn, maxCountOn);
            createHolders(indicies, active, 0, region.size);
        } else {
            totalDelay += random(minTimeOn, maxTimeOn);
        }
    }
    if (fadingIn) {
        totalDelay += timeIn / steps;
    } else {
        totalDelay += timeOut / steps;
    }
    step++;
    Serial.println(totalDelay);
    return totalDelay;
}

Christmas::Builder::Builder(Region &region) : region(&region) {

}

Christmas::Builder *Christmas::Builder::setRegion(Region &region) {
    this->region = &region;
    return this;
}

Region &Christmas::Builder::getRegion() {
    return *region;
}

Christmas::Builder *Christmas::Builder::setSteps(uint8_t steps) {
    this->steps = steps;
    return this;
}

uint8_t Christmas::Builder::getSteps() {
    return steps;
}

Christmas::Builder *Christmas::Builder::setMinTimeIn(uint16_t minTimeIn) {
    this->minTimeIn = minTimeIn;
    return this;
}

uint16_t Christmas::Builder::getMinTimeIn() {
    return minTimeIn;
}

Christmas::Builder *Christmas::Builder::setMaxTimeIn(uint16_t maxTimeIn) {
    this->maxTimeIn = maxTimeIn;
    return this;
}

uint16_t Christmas::Builder::getMaxTimeIn() {
    return maxTimeIn;
}

Christmas::Builder *Christmas::Builder::setMinTimeOut(uint16_t minTimeOut) {
    this->minTimeOut = minTimeOut;
    return this;
}

uint16_t Christmas::Builder::getMinTimeOut() {
    return minTimeOut;
}

Christmas::Builder *Christmas::Builder::setMaxTimeOut(uint16_t maxTimeOut) {
    this->maxTimeOut = maxTimeOut;
    return this;
}

uint16_t Christmas::Builder::getMaxTimeOut() {
    return maxTimeOut;
}

Christmas::Builder *Christmas::Builder::setMinTimeOn(uint16_t minTimeOn) {
    this->minTimeOn = minTimeOn;
    return this;
}

uint16_t Christmas::Builder::getMinTimeOn() {
    return minTimeOn;
}

Christmas::Builder *Christmas::Builder::setMaxTimeOn(uint16_t maxTimeOn) {
    this->maxTimeOn = maxTimeOn;
    return this;
}

uint16_t Christmas::Builder::getMaxTimeOn() {
    return maxTimeOn;
}


Christmas::Builder *Christmas::Builder::setMinTimeOff(uint16_t minTimeOff) {
    this->minTimeOff = minTimeOff;
    return this;
}

uint16_t Christmas::Builder::getMinTimeOff() {
    return minTimeOff;
}


Christmas::Builder *Christmas::Builder::setMaxTimeOff(uint16_t maxTimeOff) {
    this->maxTimeOff = maxTimeOff;
    return this;
}

uint16_t Christmas::Builder::getMaxTimeOff() {
    return maxTimeOff;
}

Christmas::Builder *Christmas::Builder::setMinCountOn(uint8_t minCountOn) {
    this->minCountOn = minCountOn;
    return this;
}

uint8_t Christmas::Builder::getMinCountOn() {
    return minCountOn;
}

Christmas::Builder *Christmas::Builder::setMaxCountOn(uint8_t maxCountOn) {
    this->maxCountOn = maxCountOn;
    return this;
}

uint8_t Christmas::Builder::getMaxCountOn() {
    return maxCountOn;
}

Christmas::Builder *Christmas::Builder::setGreenBias(double bias) {
    this->bias = bias;
    return this;
}

double Christmas::Builder::getGreenBias() {
    return bias;
}

bool Christmas::holdersContainIndex(Holder *arr, size_t size, uint8_t index) {
    for (uint16_t i = 0; i < size; i++) {
        if (arr[i].index == index) return true;
    }
    return false;
}

void Christmas::createHolders(Holder *arr, uint8_t active, uint8_t min, uint8_t max) {
    for (uint8_t i = 0; i < active; i++) {
        auto index = (uint8_t)random(min, max);
        while (holdersContainIndex(arr, i, index)) {
            index = (uint8_t)random(min, max);
        }
        arr[i].index = index;
        arr[i].green = (static_cast <float> (random()) / static_cast <float> (RANDOM_MAX)) <= bias;
    }
}
