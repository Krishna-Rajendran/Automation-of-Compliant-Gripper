#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int pos = 1000;    // variable to store the servo position

void setup() {
  myservo.attach(9);// attaches the servo on pin 9 to the servo object
  myservo.writeMicroseconds(pos);
  delay(10000);        
}

void loop() {
  for (pos = 1000; pos <= 2000; pos += 1) { // goes from 1000 to 2000
    // in steps of 1 degree
    myservo.writeMicroseconds(pos);              // tell servo to go to position in variable 'pos'
    delay(25);                       // waits 25ms for the servo to reach the position
  }
  for (pos = 2000; pos >= 1000; pos -= 1) { // goes from 2000 to 1000
    myservo.writeMicroseconds(pos);              // tell servo to go to position in variable 'pos'
    delay(25);                       // waits 25ms for the servo to reach the position
  }
  if (myservo.attached()){
  myservo.detach();
  }
}
