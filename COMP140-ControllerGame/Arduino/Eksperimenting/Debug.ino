void serialDebug(){


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
  
  /*value1 = findEstimatedMin(int(randomNumX));
  value2 = findEstimatedMax(int(randomNumX));
  value3 = findEstimatedMin(int(randomNumY));
  value4 = findEstimatedMax(int(randomNumY));*/

  /*if (lis.x > value1 && lis.x < value2 && lis.y > value3 && lis.y < value4)
  {
    for (int i = 0; i < NUM_LEDS; i++)
    {
      leds[i] = CRGB (0, 255, 0);
      FastLED.show();
    }
  }
  else
  {
    for (int i = 0; i < NUM_LEDS; i++)
    {
      leds[i] = CRGB (255, 0, 0);
      FastLED.show();
    }
  }*/

  if (lis.x > value1 && lis.x < value2 && lis.y > value3 && lis.y < value4)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
  }
  else
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
  }
  Serial.println();
}

