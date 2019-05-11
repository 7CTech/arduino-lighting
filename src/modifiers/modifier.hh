//
// Created by jason on 11/05/19.
//

#pragma once

#include <region.hh>
#include <effect.hh>

class Modifier {
public:
    virtual void modify(MutableRegionState &region) = 0;
    void clear();

protected:
    const void setParentEffect(Effect &effect);

private:
    const void modifyImpl(Effect &effect, MutableRegionState &region);
    Effect *parent;
    friend class Effect;
};


