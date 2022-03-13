#define RLOAD 22.0
// Calibration resistance at atmospheric CO2 level
#define RZERO 879.13 
#include "MQ135.h" 
MQ135 gasSensor = MQ135(A0);
int sensorValue1;
int digitalValue1;
int sensorValue2;
int digitalValue2;

void setup()
{
    Serial.begin(9600); // sets the serial port to 9600
    pinMode( 6, INPUT);
    pinMode( 9, INPUT);
}

void loop()
{
    digitalValue1 = digitalRead(6);
    digitalValue2 = digitalRead(9); 
    sensorValue1 = analogRead(A0);
    sensorValue2 = analogRead(A2);
    /*Serial.println(digitalValue1, DEC);
    Serial.println(digitalValue2, DEC);
    Serial.println(sensorValue1, DEC);
    Serial.println(sensorValue2, DEC);*/
    if(sensorValue1>150&&sensorValue2>150)
    {
        Serial.println(sensorValue1, DEC);
        Serial.println(sensorValue2, DEC);
        float ppm = gasSensor.getPPM(); 
        Serial.print ("ppm: "); 
        Serial.println (ppm);
        Serial.println("Hazardous");
    }
    delay(1000); // wait 100ms for next reading
}