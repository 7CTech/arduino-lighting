//
// Created by jason on 21/12/18.
//

#pragma once


#include <effect.hh>


class Christmas : public Effect {
    public:
        class Builder {
            public:
                explicit Builder(Region &region);

                Builder *setRegion(Region &region);
                Region &getRegion();

                Builder *setSteps(uint8_t steps);
                uint8_t getSteps();

                Builder *setMinTimeIn(uint16_t minTimeIn);
                uint16_t getMinTimeIn();

                Builder *setMaxTimeIn(uint16_t maxTimeIn);
                uint16_t getMaxTimeIn();

                Builder *setMinTimeOut(uint16_t minTimeOut);
                uint16_t getMinTimeOut();

                Builder *setMaxTimeOut(uint16_t maxTimeOut);
                uint16_t getMaxTimeOut();

                Builder *setMinTimeOn(uint16_t minTimeOn);
                uint16_t getMinTimeOn();

                Builder *setMaxTimeOn(uint16_t maxTimeOn);
                uint16_t getMaxTimeOn();

                Builder *setMinTimeOff(uint16_t minTimeOff);
                uint16_t getMinTimeOff();

                Builder *setMaxTimeOff(uint16_t maxTimeOff);
                uint16_t getMaxTimeOff();

                Builder *setMinCountOn(uint8_t minCountOn);
                uint8_t getMinCountOn();

                Builder *setMaxCountOn(uint8_t maxCountOn);
                uint8_t getMaxCountOn();

                Builder *setGreenBias(double bias);
                double getGreenBias();
            private:
                Region *region;
                uint8_t steps;
                uint16_t minTimeIn;
                uint16_t maxTimeIn;
                uint16_t minTimeOut;
                uint16_t maxTimeOut;
                uint16_t minTimeOn;
                uint16_t maxTimeOn;
                uint16_t minTimeOff;
                uint16_t maxTimeOff;
                uint8_t minCountOn;
                uint8_t maxCountOn;
                double bias = 0.5;

                friend class Christmas;

        };

        explicit Christmas(Builder &builder);
        void init() override;
        uint32_t loop() override;
    private:
        uint8_t steps;
        uint16_t minTimeIn;
        uint16_t maxTimeIn;
        uint16_t minTimeOut;
        uint16_t maxTimeOut;
        uint16_t minTimeOn;
        uint16_t maxTimeOn;
        uint16_t minTimeOff;
        uint16_t maxTimeOff;
        uint8_t minCountOn;
        uint8_t maxCountOn;

        uint16_t timeIn;
        uint16_t timeOut;

        const Color green = Color(11, 142, 11);
        const Color red = Color(255, 26, 26);

        class Holder {
            public:
                explicit Holder(uint8_t index, bool green) : index(index), green(green) {

                }
                uint8_t index;
                bool green;
        };

        Holder *indicies = (Holder *)malloc(maxCountOn * sizeof(Holder));
        uint8_t active;
        bool holdersContainIndex(Holder *arr, size_t size, uint8_t index);
        void createHolders(Holder *arr, uint8_t active, uint8_t min, uint8_t max);

        bool fadingIn;
        int16_t step;
        double bias;
};


