#pragma once

#include <Arduino_GFX_Library.h>

#include "rm67162.h"

class RM67162 {
    public:
        RM67162(void);

        void init();
        void setBrightness(uint8_t brightness);
        void setRotation(uint_fast8_t rotation);
        void setColorDepth(uint16_t depth);

        void startWrite();
        void endWrite();
        void setAddrWindow(int32_t x, int32_t y, int32_t w, int32_t h);
        void writePixels(const uint16_t* data, int32_t len, bool swap);
        void writePixels(const uint32_t* data, int32_t len, bool swap);
        void writePixels(int16_t x, int16_t y, uint8_t *data, int16_t w, int16_t h);
        void writePixels(int16_t x, int16_t y, uint16_t *data, int16_t w, int16_t h);
};
