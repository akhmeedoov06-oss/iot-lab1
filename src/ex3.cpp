#include "Arduino.h"

#define LIGHT_SENSOR_PIN 33

/****************************************************/
void setup(void)
{
    Serial.begin(115200);
    pinMode(LIGHT_SENSOR_PIN, INPUT);
}

/****************************************************/
void loop(void)
{
    int raw = analogRead(LIGHT_SENSOR_PIN);
    Serial.print("raw=");
    Serial.println(raw);
    delay(500);
}