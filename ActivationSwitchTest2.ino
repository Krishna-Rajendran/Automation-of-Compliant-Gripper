#include <Servo.h>

Servo actuator;
int pos = 1500;

#define ACTIVATION_SWITCH 7

bool button1Pressed = false;

void setup() {
  actuator.attach(9);
  actuator.writeMicroseconds(pos);
  delay(10000);

  pinMode(ACTIVATION_SWITCH, INPUT);

  Serial.begin(9600);
  Serial.println("Program is starting");
  Serial.println("Initial pos is: ");
  Serial.println(pos);
}

void loop() {
  if (digitalRead(ACTIVATION_SWITCH) == HIGH) {
    Serial.println("ACTIVATION_SWITCH is Pressed");
    int pos1 = 0;
    int pos2 = 0;

    for (pos1 = pos; pos1 >= 1300; pos1 -= 1) {
      actuator.writeMicroseconds(pos1);
      delay(25);
    }

    int current_pos = pos1;
    Serial.println("Current pos is: ");
    Serial.println(pos1);
      
    for(pos2 = current_pos; pos2 <= 1700; pos2 +=1){
      actuator.writeMicroseconds(pos2);
      delay(25);
    }

    Serial.println("Final pos is: ");
    Serial.println(pos2);
  }
}
