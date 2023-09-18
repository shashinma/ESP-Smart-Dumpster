#include <Arduino.h>

//#define D3 0
//#define D4 2

const int pingPin = D3;
int inPin = D4;

long microsecondsToCentimeters(long microseconds)
{
    return microseconds / 29 / 2;
}

void setup()
{
    Serial.begin(115200);
}

void loop()
{
    long duration, cm;
    pinMode(pingPin, OUTPUT);

    digitalWrite(pingPin, LOW);
    delayMicroseconds(2);
    digitalWrite(pingPin, HIGH);
    delayMicroseconds(5);
    digitalWrite(pingPin, LOW);
    pinMode(inPin, INPUT);
    duration = pulseIn(inPin, HIGH);
    cm = microsecondsToCentimeters(duration);

    Serial.print(cm);
    Serial.print("cm");
    Serial.println();
    delay(100);
}