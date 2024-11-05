int sensorValue;       // holds input for phototransistor
int sensorLow = 1023;  // init low marker at highest possible val
int sensorHigh = 0;    // init hi marker at lowest possible val
const int ledPin = 13; // onboard led pin
int piezoPin = 8;      // digital pin for piezo output
int toneDuration = 15; // length of tone 

void setup() {
  // onboard LED (pin13) indicates calibration in progress
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  // millis returns how long the arduino has been running since last power-on or reset
  while (millis() < 5000){
    sensorValue = analogRead(A0);

    // set sensor reading limits for scaling the piezo's frequency 
    if (sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }
    if (sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
  }
  // turn of onboard LED to indicate calibration finished
  digitalWrite(ledPin, LOW);
}

void loop() {
  // get input from phototransistor
  sensorValue = analogRead(A0);

  // map (value, lowInput, highInput, lowOutput, highOutput)
  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 1000);

  tone(piezoPin, pitch, toneDuration);
}
