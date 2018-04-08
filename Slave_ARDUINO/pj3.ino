#include <Wire.h>
#define trigPin1 13
#define echoPin1 12

#define trigPin2 3
#define echoPin2 2
#define led 9
#define led2 6
#define led3 5
int c,ldr=A2,light;
int x;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
   pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(ldr, INPUT);

  Wire.begin(9);
  // Attach a function to trigger when something is received.
  Wire.onReceive(receiveEvent);
}

void receiveEvent(int bytes) {
  x = Wire.read();    // read 
}

void loop() {

  if( x==1) //fog
  
  { analogWrite(led, 255);
     analogWrite(led3,255);
     digitalWrite(led2, HIGH);
}
else
  {
  light=analogRead(ldr);
  if (light<960)
  {long duration1, distance1;
  long duration2, distance2;
  digitalWrite(trigPin1, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin1, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = (duration1/2) / 29.1;




  digitalWrite(trigPin2, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin2, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = (duration2/2) / 29.1;






if (distance1 >= 100 && distance2 >= 100  )



{ Serial.println("out1");
  analogWrite(led, 5);
     analogWrite(led3,5);
     digitalWrite(led2, LOW);
     

}








  
  
  
  
   else{
    
    while(distance1 <= 100 || distance2 <= 100 ){
    analogWrite(led, distance1);
     analogWrite(led3, distance2);
    Serial.print(distance1);
    Serial.println(" cm1");
    Serial.print(distance2);
    Serial.println(" cm2");

    digitalWrite(trigPin1, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin1, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = (duration1/2) / 29.1;

   digitalWrite(trigPin2, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin2, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = (duration2/2) / 29.1;


    if(distance1 <= 10|| distance2<= 10)
    digitalWrite(led2, HIGH);
   

   
  }
    
   

   
   
    
    

  
  
  
  
  
  
 
  
 
  delay(1000);
  if(c==1){
  
  digitalWrite(led2, LOW);

  }

  
}
  }
  else
  {analogWrite(led, 0);
     analogWrite(led3,0);
     digitalWrite(led2, LOW);
  }
  }

 

digitalWrite(led2, LOW);

}
