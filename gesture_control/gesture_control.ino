
// Define the HC-SR04 pins
const int rgtrig = 13;
const int rgtecho = 12;
const int lftrig = 6;
const int lftecho = 5;

// Define the led pins
const int led2 = 11;
const int led = 10;

// No delay timer variable
unsigned long previousMillis = 0;

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
  for (int i; i = 10; i++) {
    digitalWrite(led, HIGH);
    digitalWrite(led, HIGH);
    delay(250);
    digitalWrite(led, LOW);
    digitalWrite(led, LOW);
  }
}

// triggered by sweeping hand l - r
//void lefttoright() {
//unsigned long currentMillis = millis();
//
//if (currentMillis - previousMillis >= interval) {
//  previousMillis = currentMillis;
//}
//}

void rightsensor() {
long duration, distance;
  digitalWrite(rgtrig, LOW);
  delayMicroseconds(2);
  digitalWrite(rgtrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(rgtrig, LOW);
  duration = pulseIn(rgtecho, HIGH);
  Serial.println(duration);
  distance = (duration/2) / 29.1;

  if (distance < 10) {
  digitalWrite(led, HIGH);
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
  Serial.println(duration2);
  distance2 = (duration2/2) / 29.1;
  if (distance2 < 10) {
  digitalWrite(led2, HIGH);
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
