//
// Created by jason on 11/05/19.
//

#pragma once


#include "modifier.hh"

class Fade : public Modifier {
    explicit Fade(uint32_t fadeTime);

public:
    void modify(MutableRegionState &regionState) override;
    void clear();

private:
    const uint32_t fadeTime;
    double curFade;
    bool fadingIn;
};


