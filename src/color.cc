//
// Created by ctech on 26/06/18.
//

#include <Arduino.h>

#include "color.hh"

Color::Color(uint8_t r, uint8_t g, uint8_t b) : r(r), g(g), b(b) {

}

Color::Color(uint8_t *rgb) : Color(rgb[0], rgb[1], rgb[2]) {

}

Color::Color(const Color &other) : Color(other.r, other.g, other.b) {

}

Color::Color()  {
#if defined(ORDERED_COLORS)
    static int color_index = -1;
        if (color_index >= 0 && unsigned(color_index) >= (sizeof(colors) / sizeof(colors[0])) - 1) {
            color_index = -1;
        }
        color_index++;
        const uint8_t *color = colors[color_index];
        r = color[0];
        g = color[1];
        b = color[2];
#elif defined(UNORDERED_COLORS)
#ifdef OPTION_NO_DOUBLE_COLORS
    auto index = static_cast<int>(random(sizeof(colors) / sizeof(colors[0])));
    while (index == last_index) {
        index = static_cast<int>(random(sizeof(colors) / sizeof(colors[0])));
    }
    last_index = index;
    const uint8_t *color = colors[index];
    r = color[0];
    g = color[1];
    b = color[2];
#else
    const uint8_t *color = colors[random(sizeof(colors) / sizeof(colors[0]))];
        r = color[0];
        g = color[1];
        b = color[2];
#endif
#elif defined(RANDOM_COLORS)
    *color[0] = random(0, 256);
        *color[1] = random(0, 256);
        *color[2] = random(0, 256);
#endif
}

uint8_t &Color::operator[](uint8_t c) {
    switch (c) {
        case 0:
            return r;
        case 1:
            return g;
        case 2:
            return b;
        default:
            return (*this)[random(0, 3)]; //lol idk
    }
}

bool Color::operator==(const Color &other) {
    return r == other.r && g == other.g && b == other.b;
}

void Color::scale(double scale) {
    r = (uint8_t)(double(r) * scale);
    g = (uint8_t)(double(g) * scale);
    b = (uint8_t)(double(b) * scale);
}

void Color::operator*=(double scale) {
    this->scale(scale);
}

Color operator*(const Color &color, double scale) {
    Color nColor = Color(color);
    nColor.scale(scale);
    return nColor;
}


