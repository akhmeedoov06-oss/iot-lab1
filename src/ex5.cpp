#include "Arduino.h"

#define BUTTON_PIN 25
#define LIGHT_SENSOR_PIN 33
#define YELLOW_LED_PIN 12

bool lastButtonState = LOW;

/****************************************************/
void setup(void)
{
    Serial.begin(115200);
    pinMode(BUTTON_PIN, INPUT); // Active high
    pinMode(LIGHT_SENSOR_PIN, INPUT);
    pinMode(YELLOW_LED_PIN, OUTPUT);
}

/****************************************************/
void loop(void)
{
    bool buttonState = digitalRead(BUTTON_PIN);

    // Detect rising edge (button just pressed)
    if (buttonState == HIGH && lastButtonState == LOW)
    {
        int raw = analogRead(LIGHT_SENSOR_PIN);
        Serial.print("snapshot=");
        Serial.println(raw);

        digitalWrite(YELLOW_LED_PIN, HIGH);
        delay(100); // Flash acknowledge
        digitalWrite(YELLOW_LED_PIN, LOW);

        delay(50); // simple debounce
    }

    lastButtonState = buttonState;
}