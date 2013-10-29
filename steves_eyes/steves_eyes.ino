/*
  StevePIREyes
  Uses a basic PIR sensor to control LED eyes for Steve the skeleton
 
  @author: Tim Butler
  @gitrepo: https://github.com/timbutler/steveduino
 */
 
// Variables
// -----------------------

int pirInputPin = 3;
int ledOutputPin = 9;
int pirState = LOW;
int startDelay = 3 * 1000;
int retriggerDelay = 20 * 1000;

// Allow time for the PIR to calibrate at startup
void startupDelay() {
  delay (startDelay);
}


void ledStartup() {
  analogWrite(ledOutputPin, 0);         
  delay(100);
  analogWrite(ledOutputPin, 100);         
  delay(100);
  analogWrite(ledOutputPin, 0);         
  delay(100);
  analogWrite(ledOutputPin, 100);         
  delay(100);
  analogWrite(ledOutputPin, 0);         
  delay(100);
  analogWrite(ledOutputPin, 100);         
  delay(100);
  analogWrite(ledOutputPin, 0);         
}


void ledFadeIn() {
  for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) { 
    analogWrite(ledOutputPin, fadeValue);         
    delay(5);
  }
}


void ledFadeOut() {
  for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=5) { 
      analogWrite(ledOutputPin, fadeValue);         
    delay(1);                            
  }  
}

void ledFadeInOut() {
  ledFadeIn();
  ledFadeOut();
}

void freakyEyes() {
  ledFadeInOut();
  ledFadeInOut();
  ledFadeInOut();
  ledFadeIn();
  analogWrite(ledOutputPin, 255);
  //delay(5 * 1000);
}

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
  pinMode(pirInputPin, INPUT);
  pinMode(ledOutputPin, OUTPUT);
  ledStartup();
  Serial.println("Steves Eyes 0.1");
  Serial.println("=============================");
  Serial.print("PIR startup delay...............");
  startupDelay();
  Serial.println("done!");
}

void loop() {
  if(digitalRead(pirInputPin) == LOW){ 
       analogWrite(ledOutputPin, 0); 
  }
  else {
    analogWrite(ledOutputPin, 255);
    freakyEyes();
    delay(2000);
  }
  delay(500);        // delay in between reads for stability
}
