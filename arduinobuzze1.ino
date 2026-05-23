int buzzerPin = 11;
int led1 = 8;
int led2 = 9;
int led3 = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzerPin, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  tone(buzzerPin, 1000, 1000); // 1 kHz tone
  delay(1000);
}
