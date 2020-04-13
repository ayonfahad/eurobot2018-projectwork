#include <Wire.h>
char incomingByte;

int i = 0;
int j = 0;
int k = 0;

// Motor A

int enA = 5;
int in1 = 12;
int in2 = 13;

// Motor B

int enB = 6;
int in3 = 7;
int in4 = 8;

const int trigPin = 3;
const int echoPin = 9;

long duration;
int distance;

int SensorRight = 10;
int SensorLeft = 4;
int SensorMiddle = 9;
int SensorLeftOutside = 2;
int SensorRightOutside = 11;
int SR;
int SL;
int SM;
int SRR;
int SLL;

void setup()

{
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication

  Wire.begin();
  
  // Set all the motor control pins to outputs

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(SensorRight, INPUT);
  pinMode(SensorLeft, INPUT);
  pinMode(SensorMiddle, INPUT);
  pinMode(SensorRightOutside, INPUT);
  pinMode(SensorLeftOutside, INPUT);

}

void forward()

{

  // This function will run the motors in both directions at a fixed speed

  // Turn on motor A

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  // Set speed to 200 out of possible range 0~255

  analogWrite(enA, 200);

  // Turn on motor B

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  // Set speed to 200 out of possible range 0~255

  analogWrite(enB, 200);
}

void right()
{

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 200);


  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 200);


}



void left()
{

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 200);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 200);

}

void pause() {

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);


  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);


}

void gap()
{

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 200);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 200);

  delay(700);


}

void leftmove() {

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, 200);
  analogWrite(enB, 200);
  delay(1800);

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  delay(1500);


}

void left1() {




  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, 200);
  analogWrite(enB, 200);

  delay(2100);

}



void right1()
{

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 200);


  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 200);

  delay(1900);

}



void backleft()
{

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 200);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 200);

  delay(260);

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  // analogWrite(enA, 200);


  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  //analogWrite(enB, 200);
  delay(1850);

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  //analogWrite(enA, 200);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(800);

  //analogWrite(enB, 200);

  // digitalWrite(in1, LOW);
  //digitalWrite(in2, LOW);
  //digitalWrite(in3, LOW);
  //digitalWrite(in4, LOW);
}



void backleft2()
{

  /*
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enA, 200);
    analogWrite(enB, 200);
    delay(850);
  */
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, 200);
  analogWrite(enB, 200);

  delay(2500);



  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  delay(10000);


}

void transmission () {
  Wire.beginTransmission(9);
  delay(2000);
  incomingByte = 'R';
  Wire.write (incomingByte);
  Wire.endTransmission();  
}

void distance_test () {
  // Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;

// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
}
  
void loop()

{  
  SR = digitalRead(SensorRight);
  SL = digitalRead(SensorLeft);
  SM = digitalRead(SensorMiddle);
  SRR = digitalRead(SensorRightOutside);
  SLL = digitalRead(SensorLeftOutside);

  //Serial.println(SR);
  //Serial.println(SL);
  //Serial.println(SM);
  //Serial.println(SRR);
  //Serial.println(SLL);

  if ((SL == LOW & SR == LOW & SLL == HIGH & SRR == HIGH & k == 0) || (SL == HIGH & SR == HIGH & SLL == HIGH & SRR == HIGH & k == 0))

    forward();

  if (SL == HIGH & SR == LOW & k == 0) 
    right();

  if (SL == LOW & SR == HIGH & k == 0)
    left();

  if (SL == LOW & SR == LOW & SLL == HIGH & SRR == LOW & i == 0)
  {
    right1();
    i++;
  }

  if (SL == LOW & SR == LOW & SLL == LOW & SRR == LOW & i == 1)
  {

    right1();

   /* digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    analogWrite(enA, 200);
    analogWrite(enB, 200);

    delay(500);
    // lforward();

    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    delay(200);*/
    
   i++;    
   
  }

  distance_test();
  
  if (distance < 35 & i==2)
    {


    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enA, 205);
    analogWrite(enB, 195);

    delay(2550);
    
   
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    analogWrite(enA, 0);
    analogWrite(enB, 0);
    delay(1000);

    transmission();
    k++;
    
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enA, 200);
    analogWrite(enB, 200);
    delay(1300);
    
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    analogWrite(enA, 0);
    analogWrite(enB, 0);

    

      
    }

  
}
