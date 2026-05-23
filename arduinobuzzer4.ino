int buzzerPin = 11;
int led1 = 8;
int led2 = 9;
int led3 = 10;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {

  digitalWrite(led1, HIGH);
  tone(buzzerPin, 1000);
  delay(500);
  digitalWrite(led1, LOW);
  noTone(buzzerPin);
  delay(200);

  digitalWrite(led2, HIGH);
  tone(buzzerPin, 1500);
  delay(500);
  digitalWrite(led2, LOW);
  noTone(buzzerPin);
  delay(200);

  digitalWrite(led3, HIGH);
  tone(buzzerPin, 2000);
  delay(500);
  digitalWrite(led3, LOW);
  noTone(buzzerPin);
  delay(200);
}
