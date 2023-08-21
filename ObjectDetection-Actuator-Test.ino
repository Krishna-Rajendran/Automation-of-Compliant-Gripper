#include <Servo.h>

Servo actuator;
int pos = 1500;

#define OBJECT_DETECTION_SWITCH 8

bool button1Pressed = false;

void setup() {
  actuator.attach(9);
  actuator.writeMicroseconds(pos);
  delay(10000);

  pinMode(OBJECT_DETECTION_SWITCH, INPUT);

  Serial.begin(9600);
  Serial.println("Program is starting");
  Serial.println("Initial pos is: ");
  Serial.println(pos);
}

void loop() {
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
    
    if(digitalRead(OBJECT_DETECTION_SWITCH) == LOW){
      Serial.println("OBJECT_DETECTION_SWITCH is Pressed");
      break;
    }    
  }

  Serial.println("Final pos is: ");
  Serial.println(pos2);
  
  if (actuator.attached()){
    actuator.detach();
  }
  Serial.println("Motor STOPPED");
}
