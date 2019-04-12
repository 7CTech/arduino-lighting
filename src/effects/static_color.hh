//
// Created by ctech on 28/06/18.
//

#pragma once

#include <effect.hh>

class StaticColor : public Effect {
public:
    explicit StaticColor(Region &region, Color base, uint32_t delay);

    void init() override;
    uint32_t loop() override;

private:
    Color color;
    uint32_t delay;
};


