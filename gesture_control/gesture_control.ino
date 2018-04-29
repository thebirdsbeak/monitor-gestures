/* (c) Craig McIntyre
 * www.thebirdsbeak.com
 * Licensed under GPL 3 
 */


// Define the HC-SR04 pins
const int rgtrig = 13;
const int rgtecho = 12;
const int lftrig = 6;
const int lftecho = 5;

// Define the led pins
const int led2 = 10;
const int led = 11;

// Define the ledstate trackers
int leftstate = LOW;
int rightstate = LOW;

// Define delay timer variable
unsigned long lefttimer;
unsigned long righttimer;

void setup() {
  Serial.begin (9600);
  pinMode(rgtrig, OUTPUT);
  pinMode(rgtecho, INPUT);
  pinMode(lftrig, OUTPUT);
  pinMode(lftecho, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
}

// Flashes the lights
void flash() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(led, HIGH);
    digitalWrite(led2, HIGH);
    delay(250);
    digitalWrite(led, LOW);
    digitalWrite(led2, LOW);
    delay(250);
  }
}

void righttriggred() {
  if (leftstate == HIGH) {
    unsigned long current = millis();
    unsigned long elapsed = current - lefttimer;
    if (elapsed < 500) {
      flash();
      Serial.println("A");
    }
  rightstate = LOW;
  leftstate = LOW;
  }
}

void lefttriggered() {
  if (rightstate == HIGH) {
    unsigned long current = millis();
    unsigned long elapsed = current - righttimer;
    if (elapsed < 500) {
      flash();
      Serial.println("B");
    }
  rightstate = LOW;
  leftstate = LOW;
  }
}


void rightsensor() {
  long duration, distance;
  digitalWrite(rgtrig, LOW);
  delayMicroseconds(2);
  digitalWrite(rgtrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(rgtrig, LOW);
  duration = pulseIn(rgtecho, HIGH);
  distance = (duration/2) / 29.1;
  if (distance < 20) {
    digitalWrite(led, HIGH);
    rightstate = HIGH;
    righttimer = millis();
    righttriggred();
  }
  
  else {
    digitalWrite(led, LOW);
  }
}

void leftsensor() {
  long duration2, distance2;
  digitalWrite(lftrig, LOW);
  delayMicroseconds(2);
  digitalWrite(lftrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(lftrig, LOW);
  duration2 = pulseIn(lftecho, HIGH);
  distance2 = (duration2/2) / 29.1;

  if (distance2 < 20) {
    digitalWrite(led2, HIGH);
    leftstate = HIGH;
    lefttimer = millis();
    lefttriggered();
  }
  
  else {
    digitalWrite(led2, LOW);
  }
}

void loop() {

  rightsensor();
  leftsensor();
  delay(100);

  
} 
