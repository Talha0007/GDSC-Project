// install library ESP32Servo by Kevin...
#include <ESP32Servo.h>

Servo myServo;
int servoPin = 14;

void setup() {
  
  myServo.attach(servoPin);
  // myServo.write(100);

  Serial.begin(115200);
}

void loop() {
  if(Serial.available()){
    int angle = Serial.parseInt();
    myServo.write(angle);
  }
  // myServo.write(angle);
  delay(2000);

}


//pinout details
// servo red to 3.3v
// servo brown to gnd
// servo orange to 19