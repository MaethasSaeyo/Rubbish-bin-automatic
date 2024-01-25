
#include <Servo.h>

Servo myservo;

int pos = 0; 
const int pingPin = 13;
int inPin = 12;
void setup() {
Serial.begin(9600);
myservo.attach(9);
myservo.write(90);  
}
void loop()
{
long duration, cm;
pinMode(pingPin, OUTPUT);
digitalWrite(pingPin, LOW);
delayMicroseconds(2);
digitalWrite(pingPin, HIGH);
delayMicroseconds(5);
digitalWrite(pingPin, LOW);
pinMode(inPin, INPUT);
duration = pulseIn(inPin, HIGH);
cm = microsecondsToCentimeters(duration);
Serial.print(cm);
Serial.print("cm");
Serial.println();
delay(100);


if(cm <= 15){
    
    Serial.println("Servo Start");
    for (pos = 0; pos <= 170; pos++) { // goes++ from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
                           // waits 15 ms for the servo to reach the position
  }
  delay(5000); 
  for (pos = 17 0; pos >= 90; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
}


}




long microsecondsToCentimeters(long microseconds)
{
// The speed of sound is 340 m/s or 29 microseconds per centimeter.
// The ping travels out and back, so to find the distance of the
// object we take half of the distance travelled.
return microseconds / 29 / 2;
}
