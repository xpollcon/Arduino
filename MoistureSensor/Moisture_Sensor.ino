int sensoreInputPin = 0;
int redPin = 8;
int yellowPin = 9;
int greenPin = 10;

void setup() {
  Serial.begin(9600);  
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  digitalWrite(redPin, HIGH);
  digitalWrite(yellowPin, HIGH);
  digitalWrite(greenPin, HIGH);
  delay(1000);
  
}

void loop() {
    int sensoreValue = analogRead(sensoreInputPin);
    Serial.println(sensoreValue);
    if (sensoreValue > 600){
        digitalWrite(redPin, HIGH);
        digitalWrite(yellowPin, LOW);
        digitalWrite(greenPin, LOW);
    }else if(sensoreValue > 400 && sensoreValue < 600){
        digitalWrite(redPin, LOW);
        digitalWrite(yellowPin, HIGH);
        digitalWrite(greenPin, LOW);      
    }else if (sensoreValue <= 400){
        digitalWrite(redPin, LOW);
        digitalWrite(yellowPin, LOW);
        digitalWrite(greenPin, HIGH);   
    }  
    delay(20000jnni);
}

//boolean cycleCheck(unsigned long *lastMillis, unsigned int cycle) 
//{
// unsigned long currentMillis = millis();
// if(currentMillis - *lastMillis >= cycle)
// {
//   *lastMillis = currentMillis;
//   return true;
// }
// else
//   return false;
//}
 
