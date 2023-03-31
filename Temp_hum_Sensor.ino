#include <DHT.h>


DHT dht(26, DHT11);

void setup(){
  dht.begin();
  delay(2000);

  Serial.begin(115200);
}

void loop(){
  float temp = dht.readTemperature();
  float humidity = dht.readHumidity();

  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print(" C ");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println("% ");

  delay(2000);
}



//Pintouts
// Sensor vcc to 3.3v
// Sensor GND to GND
// Sensor Data to D26