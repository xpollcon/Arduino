/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
 
 int delayInt=500;
 int sensorPin = 3;
 int buzzPin = 9;

void setup() {                
  // initialize the digital pin as an output.
  // Pin 13 has an LED connected on most Arduino boards:
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

  pinMode(buzzPin,OUTPUT);

  Serial.begin(9600);  
}

void loop() {
  digitalWrite(4, HIGH);
  delay(delayInt);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  delay(delayInt);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  delay(delayInt);
  digitalWrite(6, LOW );

  digitalWrite(buzzPin, HIGH);
  delay(1);
  digitalWrite(buzzPin, LOW);

   int reading = analogRead(sensorPin);

   float voltage = reading * 5;
   voltage /= 1024.0; 

   Serial.print(voltage); Serial.println(" volts");
   float temperatureC = (voltage - 0.5) * 100 ;
   Serial.print(temperatureC); Serial.println(" degrees C");

   delay(1000);
}
