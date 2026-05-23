#include <Servo.h>
Servo servo;

const int pirPin = 8;
const int servoPin = 12;
const int buzzerPin = 6;

int aci = 40;
int yon = 1;

int onceki = LOW;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  servo.attach(servoPin);
  Serial.begin(9600);
  digitalWrite(buzzerPin, LOW);

}

void loop() {
  servo.write(aci);
  delay(60);

  int simdiki = digitalRead(pirPin);
  if(simdiki == HIGH || onceki == LOW){
    Serial.print("ALARM: ");
    Serial.print(aci);

    tone(buzzerPin, 1200);
    delay(200);
    noTone(buzzerPin);
    delay(100);
    tone(buzzerPin, 1200);
    delay(200);
    noTone(buzzerPin);
  }
  onceki = simdiki;
  aci += yon;
  if(aci >= 140){
    aci = 140;
    yon = -1;
  }
  if(aci<= 40){
    aci = 40;
    yon = 1;
  }
}
