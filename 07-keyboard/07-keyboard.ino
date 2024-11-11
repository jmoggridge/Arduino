int notes[] = {
  415.30,  // G 
  466.16,  // Bb
  659.25,  // E
  698.46,  // F 
  }; 

void setup() {
  Serial.begin(9600);
}

void loop() {
  // read voltage coming through resistor ladder (keyboard)
  int keyVal = analogRead(A0);
  Serial.println(keyVal);

  if (keyVal == 1023){
    tone(8, notes[0]);
  } 
  else if(keyVal >= 990 && keyVal <= 1010) {
    tone(8, notes[1]);
  }
  else if (keyVal  >= 505 && keyVal <= 515) {
    tone(8, notes[2]);
  }
  else if (keyVal >= 5 && keyVal <= 10) {
    tone(8, notes[3]);
  }
  else {
    noTone(8);
  }
}
