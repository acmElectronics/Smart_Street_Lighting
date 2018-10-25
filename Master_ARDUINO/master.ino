#include<dht.h>
#include<Wire.h>
int x ;
dht DHT;

#define DHT11_PIN 3
void setup() {

  
  Wire.begin();
  Serial.begin(9600); 
}
void loop() {
  Wire.beginTransmission(9);
  
  int chk = DHT.read11(DHT11_PIN);

Serial.println(" Humidity " );

Serial.println(DHT.humidity, 1);

Serial.println(" Temparature ");

Serial.println(DHT.temperature, 1);

delay(1000);


if(((DHT.humidity, 1) >60) && ((DHT.temperature, 1)<35)){ 
  x=1;   //FOG
}            
  Wire.write(x);              // sends x 
  Wire.endTransmission();    // stop transmitting
  
  
}
