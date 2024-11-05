const int sensorPin = A0;
const float baselineTemp = 20.0;


void setup() {
  Serial.begin(9600);
  for (int pinNum = 2; pinNum <5; pinNum++){
    pinMode(pinNum, OUTPUT);
    digitalWrite(pinNum, LOW);
  }
}

void loop() {
  // get temp sensor reading
  int sensorVal = analogRead(sensorPin);
  // Serial.print("\nSensor: ");
  // Serial.print(sensorVal);

  // convert ADC to voltage
  float volts = (sensorVal / 1024.0) * 5.0;
  // Serial.print("; Voltage (v): ");
  // Serial.print(volts);

  float temperature = (volts - 0.5) * 100;
  // Serial.print("; Temperature (˚C): ");
  Serial.print(temperature);

  if (temperature < baselineTemp + 2){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temperature >= baselineTemp + 2 && temperature < baselineTemp + 4){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temperature >= baselineTemp + 4 && temperature < baselineTemp + 6){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  } else {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);

  }

  delay(1000);
}
