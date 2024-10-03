// numerator for scaling down output voltage
const int outputScalar = 10;

// digital pin outputs
const int blueLEDPin = 9;
const int greenLEDPin = 10;
const int redLEDPin = 11;

// analog pin inputs
const int greenSensorPin =A0;
const int redSensorPin = A1;
const int blueSensorPin = A2;

// init values for inputs and output
int greenValue =0;
int redValue = 0;
int blueValue = 0;
int greenSensorValue =0;
int redSensorValue = 0;
int blueSensorValue = 0;


void setup() {
  // logging
  Serial.begin(9600);
  // set digital pins as outputs
  pinMode(greenLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
}

void loop() {
  // read the values from the three phototransistors
  greenSensorValue = analogRead(greenSensorPin);
  delay(5);
  redSensorValue = analogRead(redSensorPin);
  delay(5);
  blueSensorValue = analogRead(blueSensorPin);

  // set output values based on analog input vals
  greenValue = greenSensorValue / outputScalar;
  redValue = redSensorValue / outputScalar;
  blueValue = blueSensorValue / outputScalar;

  analogWrite(greenLEDPin, greenValue);
  analogWrite(redLEDPin, redValue);
  analogWrite(blueLEDPin, blueValue);

  // logging
  Serial.print("\nRaw Sensor Values \t red: ");
  Serial.print(redSensorValue);
  Serial.print("\t green: ");
  Serial.print(greenSensorValue);
  Serial.print("\t blue: ");
  Serial.print(blueSensorValue);
  Serial.print("\nMapped sensor Values \t red: ");
  Serial.print(redValue);
  Serial.print("\t green: ");
  Serial.print(greenValue);
  Serial.print("\t blue: ");
  Serial.print(blueValue);
}
