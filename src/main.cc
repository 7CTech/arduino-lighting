#include <FastLED.h>
#include <Arduino.h>
#include <pt.h>
#include <effects/christmas.hh>
//#include <EEPROM.h>
#include <effects/spectrum_static.hh>
#include <effects/spectrum_wave.hh>

#include "region.hh"

#include "effects/effects.hh"
#include "base_region.hh"

/*
 * This code has about a 3ms control loop cycles. Trying to use smaller delays will have no effect.
 */

#define PIN 6

#ifdef __CLION_IDE__
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#endif

//int ledCount = 30;

const int numLeds = 60;//EEPROM.read(0);

CRGB *data = (CRGB *)malloc(sizeof(CRGB) * numLeds);

BaseRegion base(data, numLeds);

bool evenSelector (uint16_t index) {
    return index % 2 == 0;
}

bool allSelector (uint16_t index) {
    return true;
}

Region all = base.newRegion(allSelector);
pt readProto, proto1, proto2;
//StaticColor spectrum(all, Color(unsigned(255), unsigned(0), unsigned(0)), 50);
//SpectrumCycle spectrum(all);
SpectrumWave spectrum(all, Color(unsigned(255), unsigned(0), unsigned(0)), unsigned(1500));

bool readInternal(uint8_t **buffer, uint8_t *index) {
    if (int raw = Serial.read() == -1) {
        return false;
    } else {
        const uint8_t byte = (uint8_t)(raw);
        if ((*index) == 0 && byte != 0xfe) {
            return false;
        } else if ((*index) == 0) {
            *index = 1;
            (*buffer)[0] = 0xfe;
            return false;
        } else {
            (*buffer)[*index] = byte;
            if ((*index) == 3) {
                (*buffer) = (uint8_t *)realloc((*buffer), 4 + signed(byte));
            }
            (*index)++;
            return (*index) == signed((*buffer)[3]) + 4;
        }
    }
}

uint8_t *buffer;
uint8_t index = 0;
Waiter w(50);
bool ended = false;


void executeCommand(uint8_t *buf) {

}

const PT_THREAD(readThread(struct pt *proto)) {
    PT_BEGIN(proto)
        while (!ended) {
            PT_YIELD_UNTIL(proto, readInternal(&buffer, &index));
            PT_YIELD_UNTIL(proto, w.hasWaited());
            executeCommand(buffer);
            memset(buffer, 0, index + 1);
            w = Waiter(50);
        }
    PT_END(proto)
}

/*
 * Note to future sleep deprived self
 * cRGB takes values in order g, r b
 */

void setup() {
    Serial.begin(38400);
    FastLED.addLeds<NEOPIXEL, PIN>(data, numLeds);
    //clear
    for (int i = 0; i < numLeds; i++) {
        data[i].setRGB(0, 0 , 0);
    }

    buffer = (uint8_t *)malloc(5);

    FastLED.show();
    randomSeed(static_cast<unsigned long>(analogRead(0)));
    PT_INIT(&readProto)
    PT_INIT(&proto1)
    PT_INIT(&proto2)
    spectrum.init();
}
#ifdef __CLION_IDE__
#pragma clang diagnostic pop
#endif

#ifdef __CLION_IDE__
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#endif
void loop() {
    //PT_SCHEDULE(readThread(&readProto));
    PT_SCHEDULE(spectrum.run(&proto1));
    //PT_SCHEDULE(fill.run(&proto2));
    FastLED.show();
}
#ifdef __CLION_IDE__
#pragma clang diagnostic pop
#endif