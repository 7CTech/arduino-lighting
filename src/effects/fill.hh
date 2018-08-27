//
// Created by jason on 26/08/18.
//

#pragma once

#include <Arduino.h>
#include <effect.hh>

class Fill : public Effect {
public:
    explicit Fill(Region &region, Color color, uint32_t inTime, uint32_t outTime, bool fade);
    void init() override;
    uint32_t loop() override;
private:
    const Color color;
    const uint32_t inTime;
    const uint32_t outTime;
    const bool fade;
    bool direction = true; //true for forward, false for backwards
    uint16_t head;
};


