#ifndef COLOR_LED_HPP
#define COLOR_LED_HPP

#include <Adafruit_NeoPixel.h>

namespace c000 {

template <uint8_t PWR, uint8_t DATA> class ColorLed {
private:
  Adafruit_NeoPixel strip;

public:
  ColorLed() : strip(1, DATA) {}

  void begin() {
    pinMode(PWR, OUTPUT);
    digitalWrite(PWR, HIGH);
    strip.begin();
  }

  void showColor(uint8_t r, uint8_t g, uint8_t b) {
    strip.setPixelColor(0, strip.Color(r, g, b));
    strip.show();
  }
};

} // namespace c000

#endif