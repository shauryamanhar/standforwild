#include <SoftwareSerial.h>

//LDR
int sensorPin_ldr = A0; 
int sensorValue = 0; // variable to store the value coming from the sensor
int led = 3;
int sensor_pin = A2;

//AIR_QUALITY
int airquality = 0;
int output_value ;

//FLAME
int flamePin = 11;
int Flame = HIGH;

//ULTRASONIC
#include <Wire.h>  // Comes with Arduino IDE
#define echoPin 10 // Echo Pin
#define trigPin 9 // Trigger Pin
long duration, distance; // Duration used to calculate distance
int sensorCounter = 0;   // counter for the number of button presses
int lastsensorDistance = 0;
int setCounter = 20;
int incomingByte;

void setup() 
{
Serial.begin(9600);
pinMode(led, OUTPUT);
pinMode(flamePin, INPUT);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
delay(2000);
}

void loop() 
{
//LDR
sensorValue = analogRead(sensorPin_ldr);
if (sensorValue < 100)
{
digitalWrite(led,HIGH);
delay(1000);
}
digitalWrite(led,LOW);
delay(sensorValue);

//Temp
const int tmp = A2;
const int p = 8;

//MOISTURE
output_value= analogRead(sensor_pin);
int sensorValue = analogRead(A1);
output_value = map(output_value,550,0,0,100);
Serial.print(output_value);
Serial.print(" , ");


//AIR QUALITY
//Serial.print("Air Quality = ");
Serial.print(sensorValue);
//Serial.print(" , ");
//Serial.println();
if(sensorValue<=500)
{
//Serial.println("Fresh Air");
}
else

{
//Serial.println("Poor Air");
}

Serial.print(" , ");


//Tenp
 int Temp = analogRead(tmp);
  float volts = (Temp / 965.0) * 5;
  float c = ( .5 - volts) * 55;
  float f = (c * 9 / 5 + 32);

  Serial.print(c);
 Serial.print(" , "); 




//FLAME
Flame = digitalRead(flamePin);
if (Flame== LOW)
{
 Serial.print("1");
//   Serial.println("Fire!!! Turn on the Water Sprinklers and send a Relief team! ");
}
else
{
  Serial.print("0");
  // Serial.println("No Fire! No worries!");
}
Serial.print(" , ");
if (Serial.available() > 0) 
{        
  incomingByte = Serial.read();        
  if (incomingByte == 'R') 
  {            
  //Serial.println("Reset");
  sensorCounter = 20;
  }
} 

digitalWrite(trigPin, LOW); 
delayMicroseconds(2); 
digitalWrite(trigPin, HIGH);
delayMicroseconds(10); 
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = duration/58.2;
if (distance <= 20 && lastsensorDistance >= 40)
{
sensorCounter++;
//Serial.print("Haphazard Movement in Jungle ; Count= ");

Serial.print(sensorCounter);

//Serial.print("Distance Measure: ");
//Serial.println(distance);
}
   
else 
{
 Serial.print("0 ");  
}
lastsensorDistance = distance;
delay(500); 
Serial.println();
delay(1000);
}
