int switchState = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {

  if (switchState == 2){

  }
  // put your main code here, to run repeatedly:\=
  switchState = digitalRead(2);
  if (switchState == LOW){
    // button not pressed
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(3, LOW);
    delay(250);
    digitalWrite(3, HIGH);
    delay(250);
  } else {
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);    
    delay(250);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);    
    delay(250);
  
    //
  }
}
