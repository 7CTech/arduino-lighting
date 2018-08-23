//
// Created by ctech on 21/06/18.
//

#pragma once

#include "../color.hh"
#include "../effect.hh"

/**
 * A singular trail, that will move the length of a region. This is an effect, but doesn't need to act as so. It can instaniated directly
 */
class TrailBasic : public Effect {
public:
    explicit TrailBasic(Region &region, uint16_t length, Color color, bool forward = true, uint16_t loopTime = 1500);

    void init() override;
    int16_t loop() override;
    const void move();
protected:
    int16_t head;
    uint16_t length;
    Color color;
    bool forward;
    uint16_t loopTime;

private:
    friend class TrailsSequential;
};
