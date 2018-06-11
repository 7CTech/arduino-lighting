//
// Created by ctech on 11/06/18.
//

#include "common.hh"

const uint8_t *get_new_color() {
#ifdef OPTION_NO_DOUBLE_COLORS
    static int last_index = -1;
#endif
#if defined(ORDERED_COLORS)
    if (color_index >= (sizeof(colors) / sizeof(colors[0])) - 1) {
        color_index = -1;
    }
    color_index++;
    return colors[color_index];
#elif defined(UNORDERED_COLORS)
#ifdef OPTION_NO_DOUBLE_COLORS
    int index = random(sizeof(colors) / sizeof(colors[0]));
    while (index == last_index) {
        index = random(sizeof(colors) / sizeof(colors[0]));
    }
    last_index = index;
    return colors[index];
#else
    return colors[random(sizeof(colors) / sizeof(colors[0]))];
#endif

#endif
}