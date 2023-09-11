#include <Arduino.h>

#include <lvgl.h>

#ifdef LV_USE_DEMO_WIDGETS
#include "demos/lv_demos.h"
#include "demos/music/lv_demo_music.h"
#endif

#ifdef LV_USE_DEMO_BENCHMARK
#include "demos/benchmark/lv_demo_benchmark.h"
#endif

#if defined(ARDUINO_LILYGO_T_DISPLAY_S3)
#include "t-amoled.h"
static RM67162 tft;
#elif defined(ARDUINO_ESP32_DEV)
#include "t-display.h"
static LGFX_ST7789_SPI tft;
#endif

#include "gui.h"

lv_disp_drv_t _disp_drv;
lv_disp_draw_buf_t _disp_buf;

#define BUF_SIZE LV_HOR_RES_MAX * 30
lv_color_t _buf[BUF_SIZE];
lv_color_t _buf2[BUF_SIZE];

static void disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
    uint32_t w = ( area->x2 - area->x1 + 1 );
    uint32_t h = ( area->y2 - area->y1 + 1 );

    tft.startWrite();
    tft.setAddrWindow(area->x1, area->y1, w, h);
    // tft.writePixels(&color_p->full, w*h, true);
    tft.writePixels(area->x1, area->y1, (uint16_t *)&color_p->full, w, h);
    tft.endWrite();

    lv_disp_flush_ready(disp);
}

void setup() {
    Serial.begin(115200);
    Serial.println("start");

    tft.init();
    tft.setBrightness(32);
    tft.setRotation(1);
#if defined(ARDUINO_LILYGO_T_DISPLAY_S3)
#elif defined(ARDUINO_ESP32_DEV)
    tft.setColorDepth(lgfx::v1::rgb565_2Byte);
    // tft.setColorDepth(LV_COLOR_DEPTH);
#endif

    lv_init();
    lv_disp_draw_buf_init(&_disp_buf, _buf, _buf2, BUF_SIZE);

    lv_disp_drv_init(&_disp_drv);
    _disp_drv.hor_res = LV_HOR_RES_MAX;
    _disp_drv.ver_res = LV_VER_RES_MAX;
    _disp_drv.flush_cb = disp_flush;
    _disp_drv.draw_buf = &_disp_buf;
    lv_disp_drv_register(&_disp_drv);

    // lv_demo_benchmark();
    lv_demo_widgets();
    // lv_demo_music();
}

void loop() {
    lv_task_handler();
    delay(1);
}
