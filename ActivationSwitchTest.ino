void setup() {
  // Code to Test Activate Button:
  pinMode(7, INPUT);
  Serial.begin(9600);
  Serial.println("Push Button Test");

}

void loop() {
  // Code to Test Activate Button:
  int pushButtonValue = digitalRead(7);
  if (pushButtonValue == HIGH){
    Serial.println("Button is HIGH");
  }
  delay(10);
}
