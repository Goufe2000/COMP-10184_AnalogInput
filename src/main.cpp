// I Johannes Berbee 000788567 verifiy this is all my work
#include <Arduino.h>

void setup()
{
  // configure the USB serial monitor
  Serial.begin(115200);
}

void loop()
{
  int iVal;
  float aVal;
  float Temp;

  // read digitized value from the D1 Mini's A/D convertor
  iVal = analogRead(A0);

  // Analog Voltage
  aVal = iVal * (3.3 / 1023.0);

  // Temperature Equivelant
  Temp = aVal * (50.0 / 3.3);

  String TemperatureValue;

  if (Temp <= 10)
  {
    TemperatureValue = "Too Cold!";
  }

  else if (Temp < 15)
  {
    TemperatureValue = "Cool";
  }

  else if (Temp < 25)
  {
    TemperatureValue = "Perfect";
  }

  else if (Temp < 30)
  {
    TemperatureValue = "Warm";
  }

  else if (Temp < 35)
  {
    TemperatureValue = "Hot";
  }

  else if (Temp >= 35)
  {
    TemperatureValue = "Too Hot!";
  }
  Serial.println("Digitized Value of " + String(iVal) + " is equivalent to an temperature input of " + (Temp) + " deg. C, which is " + (TemperatureValue));
  // wait 0.5 seconds (500 ms)
  delay(500);
}