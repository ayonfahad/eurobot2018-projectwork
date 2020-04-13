

int i = 0;
int j = 0;
int k = 0;




// defines pins numbers
const int trigPin = 3;
const int echoPin = 9;

// defines variables
long duration;
int distance;


// Motor A

int enA = 5;
int in1 = 12;
int in2 = 13;

// Motor B

int enB = 6;
int in3 = 7;
int in4 = 8;


int SensorRight = 10;  
int SensorLeft = 4; 
int SensorMiddle =9;
int SensorLeftOutside = 2;
int SensorRightOutside = 11;  
int SR;
int SL;
//int SM;
int SRR;
int SLL;

void setup()

{

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

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
   //distance_test();
  Serial.begin(9600);

}

//==========================================================
void forward()

{

  // This function will run the motors in both directions at a fixed speed

  // Turn on motor A

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  // Set speed to 215 out of possible range 0~255

  analogWrite(enA, 215);

  // Turn on motor B

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  // Set speed to 215 out of possible range 0~255

  analogWrite(enB, 215);
}



void right()
{
 
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 215);

    
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 215);


}

void left()
{
 
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 215);  
  
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 215);

}

void stop(){

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  
 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);

  
  }



void backward() 
{
  
  stop();
  delay(1000);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 215);
  
 
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 215);
  
  
  delay(2150);
  
  }

//************************************************************
void right90()
{
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 215);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 215);

  delay(700);
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  //analogWrite(enA, 215);

    
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
 // analogWrite(enB, 215);
  delay(1450);


  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  //analogWrite(enA, 215);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
 // analogWrite(enB, 215);

 delay(400); 
 
  }

void left90()
{
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 215);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 215);

  delay(700);
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  //analogWrite(enA, 215);
    
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
 // analogWrite(enB, 215);
  delay(1450);

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  //analogWrite(enA, 215);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
 // analogWrite(enB, 215);

 delay(400); 
 
  }
 
void left_push()
{
  
 digitalWrite(in1, HIGH);
 digitalWrite(in2, LOW);
 analogWrite(enA, 215);
   
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 215); 

  delay(700);

   digitalWrite(in1, LOW);
 digitalWrite(in2, HIGH);
 //analogWrite(enA, 215);
  
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
 // analogWrite(enB, 215); 

  delay(1200);
  
digitalWrite(in1, HIGH);
 digitalWrite(in2, LOW);
// analogWrite(enA, 215);
  
   digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
 // analogWrite(enB, 215);   
  delay(1150);
    
  }

void backward_right()
{
  
 digitalWrite(in1, LOW);
 digitalWrite(in2, HIGH);
 analogWrite(enA, 215);
  
 
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 215); 
  delay(1150);

   digitalWrite(in1, LOW);
 digitalWrite(in2, HIGH);  
 
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  delay(1200);

   digitalWrite(in1, LOW);
 digitalWrite(in2, LOW);
 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  delay (3000);

  digitalWrite(in1, HIGH);
 digitalWrite(in2, LOW);
  
   digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  
  delay(2000);
   
  }

void left_go()
{
  
 digitalWrite(in1, HIGH);
 digitalWrite(in2, LOW);
 analogWrite(enA, 215);
  
 
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 215); 

  delay(700);
  
 digitalWrite(in1, LOW);
 digitalWrite(in2, HIGH);
 //analogWrite(enA, 215);
  
 
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
 // analogWrite(enB, 215); 

  delay(1250);


 digitalWrite(in1, LOW);
 digitalWrite(in2, LOW);
 //analogWrite(enA, 215);
  
 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  delay(4000);

  digitalWrite(in1, HIGH);
 digitalWrite(in2, LOW);
// analogWrite(enA, 215);
   
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
 // analogWrite(enB, 215);   
  delay(700);
  
  
  }
  


void whitegap()
{
  
 digitalWrite(in1, HIGH);
 digitalWrite(in2, LOW);
 analogWrite(enA, 215);
  
 
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 215); 
  delay(1500);    
  
  }

void distance_test() {
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
//==========================================================  

void loop()

{
  SR= digitalRead(SensorRight);
  SL= digitalRead(SensorLeft);

  SRR= digitalRead(SensorRightOutside);
  SLL= digitalRead(SensorLeftOutside);




  //Serial.println(SR);
 // Serial.println( SL);

// Serial.println(SRR);
  //Serial.println(SLL);

distance_test();

if (SL == HIGH && SR == HIGH && SLL == LOW && SRR == LOW)
{
  forward();
}

 if (SL == LOW && SR == HIGH)
  right();

  if (SL == HIGH && SR == LOW)
  left();

if (SL == HIGH && SR == HIGH && SLL == LOW && SRR == HIGH && i == 0)
    {
    i++;
    whitegap();
    }      
    
 if (SL == HIGH && SR == HIGH && SLL == HIGH && SRR == LOW && i == 1)
  {
  left_push();
  i++;
  }
    
 if (i==2)
  {
  backward_right();
  i++;
  j++;
  }

  if (SL == HIGH && SR == HIGH && SLL == HIGH && SRR == LOW && j == 1)
  {
  left_go();
  j++;
  }
    
  if (SL == HIGH && SR == HIGH && SLL == HIGH && SRR == HIGH && j == 2)
  {
  whitegap();
  j++;
  }
  
  if (SL == HIGH && SR == HIGH && SLL == LOW && SRR == HIGH && j==3)
  {
  right90();
  j++;
  }

if (SL == HIGH && SR == HIGH && SLL == HIGH && SRR == LOW && j==4)

{
  
  left90();
  j++;
 
}
  if (distance<6 && j==5){
    
    
    
  

 digitalWrite(in1, LOW);
 digitalWrite(in2, LOW);
 analogWrite(enA, 0);
  
 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);    

   delay(5000);



 digitalWrite(in1, LOW);
 digitalWrite(in2, HIGH);
 analogWrite(enA, 215);
  
 
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 215); 

  delay(350);


   digitalWrite(in1, LOW);
 digitalWrite(in2, HIGH);
 analogWrite(enA, 215);
  
 
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 215);


  delay(5000);


  
   digitalWrite(in1, LOW);
 digitalWrite(in2, LOW);
 analogWrite(enA, 0);
  
 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);
  


  
  
  
    }
  

  

 }
  
