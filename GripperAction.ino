#include <Servo.h>

Servo actuator;
int pos = 1415;

#define ACTIVATION_SWITCH 7
#define LIMIT_SWITCH 8

bool button1Pressed = false;

void setup() {
  actuator.attach(9);
  actuator.writeMicroseconds(pos);
  delay(10000);

  pinMode(ACTIVATION_SWITCH, INPUT);
  pinMode(LIMIT_SWITCH, INPUT);

  Serial.begin(9600);
  Serial.println("Program is starting");
  Serial.println("Initial pos is: ");
  Serial.println(pos);
}

void loop() {
  if (digitalRead(ACTIVATION_SWITCH) == HIGH) {
    Serial.println("ACTIVATION_SWITCH is Pressed");
    button1Pressed = true;
    int pos1 = 0;
    int pos2 = 0;

    while (button1Pressed){
      for (pos1 = pos; pos1 >= 1300; pos1 -= 1) {
        if (digitalRead(ACTIVATION_SWITCH) == HIGH){
          actuator.writeMicroseconds(pos1);
          delay(25);
        }
        else{
          Serial.println("Button released and toggled the value");
          button1Pressed = false;
          break;
        }
      }
      int current_pos = pos1;
      Serial.println("Current pos is: ");
      Serial.println(pos1);
      for(pos2 = current_pos; pos2 <= 1590; pos2 +=1){
        actuator.writeMicroseconds(pos2);
        delay(25);
        
        if(digitalRead(LIMIT_SWITCH) == LOW){
          Serial.println("LIMIT_SWITCH is Pressed");
          break;
        }
      }
      Serial.println("Final pos is: ");
      Serial.println(pos2);
      Serial.println("Motor STOPPED");
    }
  }
}
