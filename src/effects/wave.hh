//
// Created by jason on 24/08/18.
//

#pragma once

#include <effect.hh>

class Wave : public Effect {
public:
    explicit Wave(Region &region, int16_t loopTime);
    void init() override;
    int16_t loop() override;
private:
    const int16_t loopTime;
};