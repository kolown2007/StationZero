#include <Adafruit_NeoPixel.h>

#define SOUND_SENSOR_PIN 34  // Pin connected to the sound sensor
#define POTENTIOMETER_PIN 35  // Pin connected to the potentiometer
#define PIN        6  // Pin connected to the NeoPixel ring
#define NUMPIXELS 12  // Number of LEDs in the NeoPixel ring

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();  // Initialize the NeoPixel library
  pinMode(SOUND_SENSOR_PIN, INPUT);  // Initialize the sound sensor pin as an input
  pinMode(POTENTIOMETER_PIN, INPUT);  // Initialize the potentiometer pin as an input
}

void loop() {
  int soundValue = analogRead(SOUND_SENSOR_PIN);  // Read the value from the sound sensor
  int sensitivity = analogRead(POTENTIOMETER_PIN);  // Read the value from the potentiometer

  for(int i=0; i<NUMPIXELS; i++) {  // For each pixel...
    if (soundValue > sensitivity) {  // If the sound value is greater than the sensitivity...
      pixels.setPixelColor(i, pixels.Color(0, 150, 0));  // Set the pixel color to green
    } else {
      pixels.setPixelColor(i, pixels.Color(0, 0, 0));  // Otherwise, turn off the pixel
    }
    pixels.show();  // Update the ring with the new color
  }

  delay(50);  // Wait for 50 milliseconds
}