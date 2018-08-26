//
// Created by jason on 24/08/18.
//

#pragma once

#include <alloca.h>
#include <effect.hh>

class SequentialTrails : public Effect {
public:
    explicit SequentialTrails(Region &region, Color color, uint8_t length, uint8_t count, uint32_t loopTime, bool circular = true);

    void init() override;
    uint32_t loop() override;

    ~SequentialTrails();
private:
    const Color color;
    const uint8_t length;
    const uint8_t count;
    const uint32_t loopTime;
    const bool circular;
    uint8_t headDist;
    uint8_t *heads = (uint8_t *)malloc((count + 1) * sizeof(uint8_t));
    bool first;

    void fadeBack(uint8_t head);
};


