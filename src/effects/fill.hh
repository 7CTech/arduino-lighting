//
// Created by jason on 26/08/18.
//

#pragma once

#include <Arduino.h>
#include <effect.hh>

class Fill : public Effect {
public:
    explicit Fill(Region &region, Color color, uint32_t fadeInTime, bool fadeBack);
    void init() override;
    uint32_t loop() override;
private:
    const Color color;
    const uint32_t fadeInTime;
    const bool fadeBack;
    uint16_t head;
};


