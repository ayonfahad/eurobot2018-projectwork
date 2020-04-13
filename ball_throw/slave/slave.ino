#include <Wire.h>

int enA = 3;          //PWM pin
int in1 = 4;
int in2 = 5;

int enB = 6;          //PWM pin
int in3 = 7;
int in4 = 8;

int x=0;

void setup() {

  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  Wire.begin (9);
  Wire.onReceive(receiveEvent);  
}
void receiveEvent(int bytes) {
  x = Wire.read();
}
void loop() {

  if (x=='R') {

    delay(700);

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 220); //200 

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 220); //200
/*
  delay(15000);
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);

  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);
  x=0;

  */
  }

}
