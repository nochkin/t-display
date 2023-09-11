#include <Arduino.h>

#include <Arduino_GFX_Library.h>

#include "rm67162.h"
#include "t-amoled.h"

Arduino_DataBus *bus = new Arduino_ESP32QSPI(TFT_CS, TFT_SCK, TFT_QSPI_D0, TFT_QSPI_D1, TFT_QSPI_D2, TFT_QSPI_D3);
Arduino_GFX *gfx = new Arduino_RM67162(bus, TFT_RES, 0 /* rotation */);

RM67162::RM67162(void) {
}

void RM67162::init() {
    // rm67162_init();
    gfx->begin();
    gfx->fillScreen(BLACK);
}

void RM67162::setRotation(uint_fast8_t rotation) {
    // lcd_setRotation(rotation);
    gfx->setRotation(rotation);
}

void RM67162::setBrightness(uint8_t brightness) {
}

void RM67162::startWrite() {
}

void RM67162::endWrite() {
}

void RM67162::setAddrWindow(int32_t x, int32_t y, int32_t w, int32_t h) {
    // lcd_address_set(x, y, w, h);
}

void RM67162::writePixels(const uint16_t* data, int32_t len, bool swap) {
    // lcd_PushColors((uint16_t*)data, len);
}

void RM67162::writePixels(const uint32_t* data, int32_t len, bool swap) {
    // lcd_PushColors((uint16_t*)data, len);
}

void RM67162::writePixels(int16_t x, int16_t y, uint8_t *data, int16_t w, int16_t h) {
    // gfx->draw24bitRGBBitmap(x, y, data, w, h);
}

void RM67162::writePixels(int16_t x, int16_t y, uint16_t *data, int16_t w, int16_t h) {
    gfx->draw16bitRGBBitmap(x, y, data, w, h);
}
