int redLed    = 8;
int orangeLed = 9;
int greenLed  = 10;
int blueLed   = 11;

void setup(){
  Serial.begin(9600);

  pinMode(redLed, OUTPUT);
  pinMode(orangeLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
}

void loop (){
  if (Serial.available()) {

    //read serial as a character
    char ser = Serial.read();

    //NOTE because the serial is read as "char" and not "int", the read value must be compared to character numbers
    //hence the quotes around the numbers in the case statement
    switch (ser) {
      case '0':
        turnOffAll();
        break;
      case '1':
        turnOnAll();
        break;
      case '2':
        triggerPin(redLed);
        break;
      case '3':
        triggerPin(greenLed);
        break;
      case '4':
        triggerPin(blueLed);
        break;
      case '5':
        triggerPin(orangeLed);
        break;
    }
  }
}

void triggerPin(int pin){
  turnOffAll();
  digitalWrite(pin, HIGH);
}

void turnOffAll(){
   digitalWrite(redLed, LOW);
   digitalWrite(greenLed, LOW);
   digitalWrite(orangeLed, LOW);
   digitalWrite(blueLed, LOW);
}

void turnOnAll(){
   digitalWrite(redLed, HIGH);
   digitalWrite(greenLed, HIGH);
   digitalWrite(orangeLed, HIGH);
   digitalWrite(blueLed, HIGH);
}
