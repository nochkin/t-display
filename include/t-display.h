#define LGFX_USE_V1

#include <LovyanGFX.hpp>

class LGFX_ST7789_SPI : public lgfx::LGFX_Device
{
    lgfx::Panel_ST7789   _panel_instance;
    lgfx::Bus_SPI        _bus_instance;
    lgfx::Light_PWM     _light_instance;

public:
  LGFX_ST7789_SPI(void)
  {
    {
      auto cfg = _bus_instance.config();
      cfg.freq_write = 40000000;
      cfg.pin_dc = 16;
      cfg.pin_miso = -1;
      cfg.pin_mosi = 19;
      cfg.pin_sclk = 18;
      cfg.spi_3wire = true;
      // cfg.spi_mode = 0;
      // cfg.use_lock = false;
      cfg.spi_host = VSPI_HOST;
      cfg.dma_channel = 1;

      _bus_instance.config(cfg);
      _panel_instance.setBus(&_bus_instance);
    }

    {
      auto cfg = _light_instance.config();    

      cfg.pin_bl = 4;
      cfg.invert = false;
      cfg.freq   = 44100;
      cfg.pwm_channel = 7;

      _light_instance.config(cfg);
      _panel_instance.setLight(&_light_instance);  
    }

    { 
      auto cfg = _panel_instance.config();    

      cfg.pin_cs           =    5;
      cfg.pin_rst          =    23;
      cfg.pin_busy         =    -1;

      cfg.panel_width      =     LV_HOR_RES_MAX;
      cfg.panel_height     =     LV_VER_RES_MAX;
      cfg.offset_x         =     52;
      cfg.offset_y         =     40;
      cfg.offset_rotation  =     0;
      cfg.dummy_read_pixel =     8;
      cfg.dummy_read_bits  =     1;
      cfg.readable         =  false;
      cfg.invert           =  true;
      cfg.rgb_order        =  false;
      cfg.dlen_16bit       =  false;
      cfg.bus_shared       =  false;

      _panel_instance.config(cfg);
    }

    setPanel(&_panel_instance); 
  }
};
