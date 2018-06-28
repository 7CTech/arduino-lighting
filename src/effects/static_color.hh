//
// Created by ctech on 28/06/18.
//

#pragma once

#include <effect.hh>

class StaticColor : public Effect {
public:
    explicit StaticColor(Region &region, Color color, uint16_t delay);

    void init() override;
    int16_t loop() override;

private:
    Color color;
    uint16_t delay;
};


