//
// Created by ctech on 20/06/18.
//

#pragma once

//forward decls
class Effect;
class Modifier;

#include <pt.h>
#include <pt-sem.h>
#include <modifiers/modifier.hh>
#include "region.hh"

/**
 * Class used to define any kind of effect.
 * There are 3 things that can/need/will be done in any effect
 * The constructor should take in all it's needed parameters and what not
 * Initialise should clear the effect, and prepare it for starting
 * Run should be looping code
 */
class Effect {
private:
    friend class Modifier;
public:
    explicit Effect(Region &region);
    /**
     * Used for first time internal initialisation. Only called once
     * This function is not proceeded by .show() - do not use it to set LEDs
     */
    virtual void init() = 0;
    /**
     * The main looper function. Called at 1000/delay(ms) frequency
     * @return the delay time in ms
     */
    virtual uint32_t loop() = 0;

    /**
     * Add a modifier to this effect
     * @param modifier the modifier to add
     * @return this
     */
    const Effect &addModifier(Modifier &modifier);

    /**
     * The main running code. This deals with waiting and locking, and calls the loop function as necessary
     * @param proto
     * @return
     */
    const PT_THREAD(run(struct pt *proto));

    /**
     * Stop this effect
     */
    const void kill();

protected:
    /**
     * The region this effect is operating on.
     */
    Region &region;

private:
    /**
     * Time keeping waiter
     */
    Waiter w;
    /**
     * Next delay
     */
    uint32_t delay;
};
