#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);



const int trigPin = 9; 
const int echoPin = 10;
float duration, cm, inches;



void setup() {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.begin(16, 2);
  Serial.begin(9600); 

}



void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH, 25000); 
  cm = (duration / 2) / 29.1;
  
  Serial.print("Dang do duoc: ");
  Serial.println(cm);
  if (cm < 50) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Hello");
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Qua gioi han");
  }
  
  delay(200);
}