//
// Created by ctech on 20/06/18.
//

#pragma once

#include <Arduino.h>

//#define UNORDERED_COLORS
//#define OPTION_NO_DOUBLE_COLORS
#define ORDERED_COLORS
//#define RANDOM_COLORS

#if defined(UNORDERED_COLORS) + defined(ORDERED_COLORS) + defined(RANDOM_COLORS) > 1
#error "MULTIPLE COLOR MODES ENABLED"
#elif defined(UNORDERED_COLORS) + defined(ORDERED_COLORS) + defined(RANDOM_COLORS) < 1
#error "NO COLOR MODE ENABLED"
#endif

// put user defined colors here
const uint8_t colors[][3] = {
        { 128, 0, 0 },
        { 128, 0, 128 },
        { 0, 0, 128 }
};

class Color {
public:
    explicit Color(uint8_t r, uint8_t g, uint8_t b);
    explicit Color(uint8_t rgb[3]);
    Color(const Color &other);
    explicit Color();


    uint8_t r;
    uint8_t g;
    uint8_t b;

    uint8_t &operator[] (uint8_t c);
    bool operator== (const Color &other);

    void operator*= (double scale);

protected:
    void scale(double scale);
private:
#ifdef OPTION_NO_DOUBLE_COLORS
private:
    int last_index = -1;
#endif
    friend Color operator* (const Color &color, double scale);
};
Color operator* (const Color &color, double scale);
