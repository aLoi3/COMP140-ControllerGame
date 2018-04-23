// Basic demo for accelerometer readings from Adafruit LIS3DH

#include <Wire.h>
#include <SPI.h>
#include <FastLED.h>
#include <Adafruit_NeoPixel.h>

#include <Adafruit_LIS3DH.h>
#include <Adafruit_Sensor.h>

// Used for software SPI
#define LIS3DH_CLK 13
#define LIS3DH_MISO 12
#define LIS3DH_MOSI 11
// Used for hardware & software SPI
#define LIS3DH_CS 10

#define PIN 6
#define NUM_LEDS 12
#define BRIGHTNESS 50

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRBW + NEO_KHZ800);

int approximateRange = 200;

int expectedX;
int expectedY;

// software SPI
Adafruit_LIS3DH lis = Adafruit_LIS3DH(LIS3DH_CS, LIS3DH_MOSI, LIS3DH_MISO, LIS3DH_CLK);
// hardware SPI
//Adafruit_LIS3DH lis = Adafruit_LIS3DH(LIS3DH_CS);
// I2C
//Adafruit_LIS3DH lis = Adafruit_LIS3DH();

#if defined(ARDUINO_ARCH_SAMD)
// for Zero, output on USB Serial console, remove line below if using programming port to program the Zero!
#define Serial SerialUSB
#endif

void setup(void) {
#ifndef ESP8266
  while (!Serial);     // will pause Zero, Leonardo, etc until serial console opens
#endif


  Serial.begin(115200);
  Serial.println("LIS3DH test!");

  if (! lis.begin(0x19)) {   // change this to 0x19 for alternative i2c address
    Serial.println("Couldnt start");
    while (1);
  }
  Serial.println("LIS3DH found!");

 
  // End of trinket special code
  strip.setBrightness(BRIGHTNESS);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

  lis.setRange(LIS3DH_RANGE_4_G);   // 2, 4, 8 or 16 G!
  
  randomSeed(A0);
  expectedX = random(-6000, 6000);  // change  to the range of (-5000, 5001)
  //expectedY = random(-1000, 1000);  // change  to the range of (-5000, 5001)

  //Serial.println (expectedX);
  //Serial.println (expectedY);
}

void loop() {

  int mappedNumber = int(map(expectedX, -6000, 6000, 0, 11));
  strip.setPixelColor(mappedNumber, strip.Color(25,225,25) );
  
  lis.read();      // get X Y and Z data at once
  Serial.println(lis.x);
  if (lis.x > expectedX - approximateRange && lis.x < expectedX + approximateRange') {
    Serial.write("W");
    clearStrip();
   
    delay(500);

    expectedX = random(-6000, 6000);  // change  to the range of (-5000, 5001)
    expectedY = random(-6000, 6000);  // change  to the range of (-5000, 5001)
    
  }

  strip.show();
}

void clearStrip() {
  
    for(uint16_t i=0; i<strip.numPixels(); i++) {
        strip.setPixelColor(i, strip.Color(0,0,0,0 ) );
    }
      strip.show();
}
