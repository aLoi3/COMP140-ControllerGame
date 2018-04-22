// Basic demo for accelerometer readings from Adafruit LIS3DH

#include <Wire.h>
#include <SPI.h>
#include <FastLED.h>

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

byte randomNumX;
byte randomNumY

CRGB leds[NUM_LEDS];

int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 7;

int value1;
int value2;
int value3;
int value4;

int findEstimatedMin (long value);
int findEstimatedMax (long value);

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

  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);

  Serial.begin(9600);
  Serial.println("LIS3DH test!");
  
  if (! lis.begin(0x19)) {   // change this to 0x19 for alternative i2c address
    Serial.println("Couldnt start");
    while (1);
  }
  Serial.println("LIS3DH found!");
  
  lis.setRange(LIS3DH_RANGE_4_G);   // 2, 4, 8 or 16 G!
  
  Serial.print("Range = "); Serial.print(2 << lis.getRange());  
  Serial.println("G");
}

void loop() {
  lis.read();      // get X Y and Z data at once
  // Then print out the raw data
  Serial.print("X:  "); Serial.print(lis.x); 
  Serial.print("  \tY:  "); Serial.print(lis.y); 
  Serial.print("  \tZ:  "); Serial.print(lis.z); 

  /* Or....get a new sensor event, normalized */ 
  sensors_event_t event; 
  lis.getEvent(&event);
  
  /* Display the results (acceleration is measured in m/s^2) */
  Serial.print("\t\tX: "); Serial.print(event.acceleration.x);
  Serial.print(" \tY: "); Serial.print(event.acceleration.y); 
  Serial.print(" \tZ: "); Serial.print(event.acceleration.z); 
  Serial.println(" m/s^2 ");

  /*for (int i = 0; i < 45; i++)
  {
    leds[i] = CRGB (255, 0, 0);
    FastLED.show();
  }*/

  value1 = findEstimatedMin(int(randomNumX));
  value2 = findEstimatedMax(int(randomNumX));
  value3 = findEstimatedMin(int(randomNumY));
  value4 = findEstimatedMax(int(randomNumY));

  if (lis.x > value1 && lis.x < value2 && lis.y > value3 && lis.y < value4)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
  }
  /*else if (value1 > lis.x && value2 < lis.x && value3 > lis.y && value4 < lis.y)
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }
  else if (value1 > lis.x && value2 < lis.x && value3 > lis.y && value4 < lis.y)
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
  }
  else if (value1 > lis.x && value2 < lis.x && value3 > lis.y && value4 < lis.y)
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
  }*/
  else
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
  }
  Serial.println();

  /*ArduinoValues output;

  output.startMarker = 0xADDE;
  output.accelX = (int)(event.acceleration.x * 1000);
  output.accelY = (int)(event.acceleration.y * 1000);
  output.accelZ = (int)(event.acceleration.z * 1000);
  output.endMarker = 0x0DD0;

  Serial.write((char*)&output, sizeof (output));
 
  delay(200); 
}
*/
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

