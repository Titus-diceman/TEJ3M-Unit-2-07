/*
 *	Creaated by Titus D
 *	Created on: March 2023
 */

#include <Servo.h>


const int TRIG_PIN = 4;
const int ECHO_PIN = 3;

Servo servo;
int angle = 10;

float duration, distance;

void setup() {
  servo.attach(2);
  servo.write(angle);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration*.0343)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);
  if (distance < 50) {
    Serial.print(distance);
    Serial.println(" cm");
    servo.write(100);
  }
  else if (distance > 50) {
    Serial.print(distance);
    Serial.println(" cm");
    servo.write(10); }
  else {
  Serial.println("The distance is more than 50cm");
  }
}
