void setup() {
  // Code to Test Limit Switch:
  pinMode(8 , INPUT);
  Serial.begin(9600);
  Serial.println("Limit Switch Test");
}

void loop() {
  // Code to Test Limit Switch:
  int LimitSwitchValue = digitalRead(8);
  if(LimitSwitchValue == LOW){
    Serial.println("Internal Connection Activated");
  }
  delay(10);
}


