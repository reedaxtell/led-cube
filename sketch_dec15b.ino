#include <FastLED.h>

#define NUM_LEDS 125
#define DATA_PIN 6

CRGB leds[NUM_LEDS];

uint32_t x, y, z;

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(100);
  x = random16();
  y = random16();
  z = random16();
}

void loop() {
  for (int i = 0; i < NUM_LEDS; i++) {
    uint8_t noise = inoise16(x + i*200, y, z) >> 8; 
    leds[i] = ColorFromPalette(HeatColors_p, noise);
  }

  z += 100; 
  FastLED.show();
}