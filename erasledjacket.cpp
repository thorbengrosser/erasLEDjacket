#include <Wire.h>
#include <Adafruit_ADS1X15.h>
#include <FastLED.h>
#include <SPI.h>

// Initialize the ADS1115 object
Adafruit_ADS1115 ads;

// LED strip configuration
#define LED_PIN     6
#define NUM_LEDS    60
CRGB leds[NUM_LEDS];

// Number of samples to average
#define NUM_SAMPLES 10

void setup(void) {
  Serial.begin(115200);
  Serial.println("Initializing ADS1115...");

  // Start the ADS1115
  ads.begin();
  // Set the gain to ±4.096V, making the readings more stable
  ads.setGain(GAIN_ONE);  // 1x gain ±4.096V 1 bit = 0.125mV

  // Initialize FastLED
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS);
}

void loop(void) {
  int16_t adc1, adc2, adc3;
  int32_t adc1_sum = 0, adc2_sum = 0, adc3_sum = 0;

  // Take multiple samples and average them
  for (int i = 0; i < NUM_SAMPLES; i++) {
    adc1_sum += ads.readADC_SingleEnded(1);
    adc2_sum += ads.readADC_SingleEnded(2);
    adc3_sum += ads.readADC_SingleEnded(3);
    delay(10);  // Short delay between samples
  }

  adc1 = adc1_sum / NUM_SAMPLES;
  adc2 = adc2_sum / NUM_SAMPLES;
  adc3 = adc3_sum / NUM_SAMPLES;

  // Print raw ADC values to Serial Monitor for plotting
  Serial.print("ADC1: "); Serial.print(adc1); Serial.print(", ");
  Serial.print("ADC2: "); Serial.print(adc2); Serial.print(", ");
  Serial.print("ADC3: "); Serial.println(adc3);

  // Map the adjusted ADC values to RGB values (0-255)
  int red = (adc1 >= 23500) ? 0 : map(adc1, 21000, 23500, 255, 0);   // Corrected to use ADC1 for red
  int green = (adc3 >= 23500) ? 0 : map(adc3, 10000, 23500, 255, 0); // Corrected to use ADC3 for green
  int blue = (adc2 >= 23500) ? 0 : map(adc2, 18000, 23500, 255, 0);  // Corrected to use ADC2 for blue

  // Constrain the values to ensure they stay within 0-255
  red = constrain(red, 0, 255);
  green = constrain(green, 0, 255);
  blue = constrain(blue, 0, 255);

  // Set the color of the LED strip
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(red, green, blue);
  }
  FastLED.show();

  delay(100);  // Shorter delay for more frequent updates
}

int myFunction(int x, int y) {
  return x + y;
}
