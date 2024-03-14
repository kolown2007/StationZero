#include <Adafruit_NeoPixel.h>

#define PIN        6  // Pin connected to the NeoPixel ring
#define NUMPIXELS 16  // Number of LEDs in the NeoPixel ring

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();  // Initialize the NeoPixel library
}

void loop() {
  for(int i=0; i<NUMPIXELS; i++) {  // For each pixel...
    pixels.setPixelColor(i, pixels.Color(0, 150, 0));  // Set the pixel color to green
    pixels.show();  // Update the ring with the new color
    delay(50);  // Wait for 50 milliseconds
  }
}