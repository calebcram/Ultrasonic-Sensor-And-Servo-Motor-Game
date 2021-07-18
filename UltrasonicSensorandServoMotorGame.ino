#include <Servo.h>
Servo myServo;
int trigPin = 11;    // Trigger
int echoPin = 12;    // Echo
long duration, cm, inches;
int const potPin = A0;
int angle;
 
void setup() {
  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  //Show what pin the servo is attached to
  myServo.attach(9);
}
 
void loop() {
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // Convert the time into a distance
  cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  inches = (duration/2) / 74;   // Divide by 74 or multiply by 0.0135
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  //Servo Motor code
  potVal = analogRead(potPin);
  //map the angle variable to the cm values measured by the ultrasonic sensor
  angle = map(cm, 0, 35, 0, 179);
  Serial.print(", angle: ");
  Serial.println(angle);

  myServo.write(angle);
  //delay(15);
  
  delay(250);
}
