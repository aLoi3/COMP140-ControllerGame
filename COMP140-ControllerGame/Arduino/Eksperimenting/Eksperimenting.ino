// Basic demo for accelerometer readings from Adafruit LIS3DH

#include <Wire.h>
#include <SPI.h>
//#include <FastLED.h>

#include <Adafruit_LIS3DH.h>
#include <Adafruit_Sensor.h>

// Used for software SPI
#define LIS3DH_CLK 13
#define LIS3DH_MISO 12
#define LIS3DH_MOSI 11
// Used for hardware & software SPI
#define LIS3DH_CS 10
#define LED_PIN 8
#define NUM_LEDS 45

//CRGB leds[NUM_LEDS];

int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 7;

int value1 = 0;
int value2 = 0;
int value3 = 0;
int value4 = 0;

int findEstimatedMin (long value);
int findEstimatedMax (long value);

int inByte;
int expectedX;
int expectedY;

// software SPI
//Adafruit_LIS3DH lis = Adafruit_LIS3DH(LIS3DH_CS, LIS3DH_MOSI, LIS3DH_MISO, LIS3DH_CLK);
// hardware SPI
Adafruit_LIS3DH lis = Adafruit_LIS3DH(LIS3DH_CS);
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

  //FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);

  Serial.begin(115200);
  Serial.println("LIS3DH test!");

  if (! lis.begin(0x19)) {   // change this to 0x19 for alternative i2c address
    Serial.println("Couldnt start");
    while (1);
  }
  Serial.println("LIS3DH found!");

  lis.setRange(LIS3DH_RANGE_4_G);   // 2, 4, 8 or 16 G!

  Serial.print("Range = "); Serial.print(2 << lis.getRange());
  Serial.println("G");
  
  randomSeed(A0);
  expectedX = random(-1000, 1000);  // change  to the range of (-5000, 5001)
  expectedY = random(-1000, 1000);  // change  to the range of (-5000, 5001)

  Serial.println (expectedX);
  Serial.println (expectedY);
}

void loop() {
  lis.read();      // get X Y and Z data at once
  Serial.println(lis.x);
  if (lis.x > expectedX - 200 && lis.x < expectedX + 200 && lis.y > expectedY - 200 && lis.y < expectedY + 200) {
    Serial.println("S");
    Serial.write("S");

    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);

    delay(1000);

    expectedX = random(-500, 500);  // change  to the range of (-5000, 5001)
    expectedY = random(-500, 500);  // change  to the range of (-5000, 5001)
    
  }
  else
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
  }

  if (Serial.available() > 0) {

    inByte = Serial.read();

    if (inByte == 'A') {
      Serial.println("values read from the accelerometer");
    }
  }
  delay(100);
}

int findEstimatedMax (int value)
{
  value += 200;
  return value;
}

int findEstimatedMin (int value)
{
  value -= 200;
  return value;
}

