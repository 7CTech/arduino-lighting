//
// Created by jason on 11/04/19.
//

#pragma once


#include <effect.hh>

class SpectrumStatic : public Effect {
public:
    explicit SpectrumStatic(Region &region, Color base, uint32_t delay);
    void init() override;
    uint32_t loop() override;

private:
    Color base;
    uint32_t delay;
};


