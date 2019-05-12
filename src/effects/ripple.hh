//
// Created by jason on 12/05/19.
//

#pragma once


#include "../effect.hh"

#define DIRECTION_FORWARD 1
#define DIRECTION_BACKWARD -1
#define DIRECTION_BOTH 0
#define ORIGIN_MIDDLE -1

class Ripple : public Effect {
public:
    class Builder {
    public:
        explicit Builder(Region &region);

        Builder *setRegion(Region &region);
        Region &getRegion();

        Builder *setOrigin(uint16_t origin);
        uint16_t getOrigin();

        Builder *setTimeToBounds(uint32_t timeToBounds);
        uint32_t getTimeToBounds();

        Builder *setTimeToExit(uint32_t timeToExit);
        uint32_t getTimeToExit();

        Builder *setTimeOff(uint32_t timeOff);
        uint32_t getTimeOff();

        Builder *setCount(uint16_t count);
        uint16_t getCount();

        Builder *setDirection(int8_t direction);
        int8_t getDirection();

        Builder *setWidth(uint8_t width);
        uint8_t getWidth();


    private:
        Region *region;
        uint16_t origin;
        uint32_t timeToBounds;
        uint32_t timeToExit;
        uint32_t timeOff;
        uint16_t count;
        int8_t direction;
        uint8_t width;

        friend class Ripple;
    };

    explicit Ripple(Builder &builder);
    void init() override;
    uint32_t loop() override;
private:
    uint16_t origin;
    uint32_t timeToBounds;
    uint32_t timeToExit;
    uint32_t timeOff;
    uint16_t count;
    int8_t direction;
    uint8_t width;
    uint16_t dist = 0;
};


