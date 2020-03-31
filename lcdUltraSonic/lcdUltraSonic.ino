// LCD setup
#include <LiquidCrystal.h>
LiquidCrystal lcd(53,51,49,47,45,43);

// SuperSonic setup
const int trigPin = 50;
const int echoPin = 52;
long duration;
long distance;

void setup(){
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.begin(16,2);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;

  lcd.print("Distance: ");
  lcd.setCursor(0, 1);
  lcd.print(distance);
  delay(3000);
  lcd.clear();
}
