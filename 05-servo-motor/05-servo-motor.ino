#include <Servo.h>

Servo myServo;

// potentiometer connection, level, and mapped angle
int const potPin = A0;
int potVal;
int delayV;
bool isDelayIncreasing;
int angle;

void setup() {
  // servo is in digital #9
  myServo.attach(9);
  // setup logging
  Serial.begin(9600);
}

  // flip-flop the motor angle on each loop with varied delay
void loop() {
  // read potentiometer
  potVal = analogRead(potPin);
  // rescale input value
  delayV = map(potVal, 0, 1023, 100, 1000);
  
  // back & forth
  if (angle == 0){
    angle = 179;
  } else { 
    angle = 0;
  }
  myServo.write(angle);
  // interval depends on potentiometer
  delay(delayV);

  Serial.print("\n potVal: ");
  Serial.print(potVal);
  Serial.print(", angle:");
  Serial.print(angle);
  Serial.print(", delay:");
  Serial.print(delayV);
  };
