#include <SoftwareSerial.h>

int redLed=5;
int orangeLed=6;
int greenLed=7;

int speedChannel_M1 = 12;
int motorChannel_M1 = 5;
int brakeChannel_M1 = 9;

int speedChannel_M2 = 13;
int motorChannel_M2 = 6;
int brakeChannel_M2 = 8;

SoftwareSerial Genotronex(3,2); // RX, TX 
int BluetoothData;

void setup(){
  
  Genotronex.begin(9600); 
  Genotronex.println("Bluetooth On please press 1 or 0 blink LED ..");
  

  //LEDs
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(orangeLed, OUTPUT);

  //Motor Channels
  pinMode(speedChannel_M1, OUTPUT);
  pinMode(motorChannel_M1, OUTPUT);
  pinMode(brakeChannel_M1, OUTPUT);

  pinMode(speedChannel_M2, OUTPUT);
  pinMode(motorChannel_M2, OUTPUT);
  pinMode(brakeChannel_M2, OUTPUT);

}

void loop() {
   
   if (Genotronex.available()){
      BluetoothData=Genotronex.read();
      
      if (BluetoothData=='0'){
        turnOffAll();
      }
      
      if(BluetoothData=='1'){
        turnOnAll();
      }

      if(BluetoothData=='5'){
        Genotronex.println("Testing ...");
        digitalWrite(redLed,1);
        testLeds();
      }  
  }

delay(100);

}

void triggerPin(int pin){
  turnOffAll();
  digitalWrite(pin, HIGH);
  delay(250);
}

void turnOffAll(){
   Genotronex.println("Turninig off ...");
   digitalWrite(motorChannel_M1, LOW);
   digitalWrite(motorChannel_M2, LOW);
}

void turnOnAll(){
   Genotronex.println("Turninig on ...");
   digitalWrite(motorChannel_M1, HIGH);
   digitalWrite(motorChannel_M2, HIGH);

}
void stopMotor(){
  digitalWrite(5, LOW);
  triggerPin(redLed);
  delay(250);
  turnOffAll();
}

void testLeds(){
        digitalWrite(redLed,0);
        digitalWrite(greenLed,0);
        digitalWrite(orangeLed,0);

        delay(500);

        digitalWrite(redLed,1);
        digitalWrite(greenLed,1);
        digitalWrite(orangeLed,1);

        delay(500);

        digitalWrite(redLed,0);
        digitalWrite(greenLed,0);
        digitalWrite(orangeLed,0);
}




