#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int pos = 1500;    // variable to store the servo position

void setup() {
  myservo.attach(9);// attaches the servo on pin 9 to the servo object
  myservo.writeMicroseconds(pos);
  Serial.begin(9600);
  Serial.println(pos);
  delay(10000);        
}

void loop() {
  int pos1 = 0;
  for (pos1 = pos; pos1 <= 1700; pos1 += 1) { // goes from 1000 to 2000
    // in steps of 1 degree
    myservo.writeMicroseconds(pos1);              // tell servo to go to position in variable 'pos'
    delay(25);                      // waits 25ms for the servo to reach the position
  }
  int pos2 = 0;
  Serial.println(pos1);
  for (pos2 = pos1; pos2 >= 1300; pos2 -= 1) { // goes from 2000 to 1000
    myservo.writeMicroseconds(pos2);              // tell servo to go to position in variable 'pos'
    delay(25);                       // waits 25ms for the servo to reach the position
  }
  int pos3 = 0;
  Serial.println(pos2);
  for (pos3 = pos2; pos3 <= 1500; pos3 += 1) { // goes from 1000 to 2000
    // in steps of 1 degree
    myservo.writeMicroseconds(pos3);              // tell servo to go to position in variable 'pos'
    delay(25);                      // waits 25ms for the servo to reach the position
  }  
  Serial.println(pos3);
  if (myservo.attached()){
  myservo.detach();
  }
}

