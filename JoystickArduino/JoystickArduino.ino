#define BTN_A 2
#define BTN_B 3
#define BTN_C 4
#define BTN_D 5
#define BTN_E 6
#define BTN_F 7

void setup() {
  Serial.begin(9600);
  pinMode(BTN_A, INPUT_PULLUP);
  pinMode(BTN_B, INPUT_PULLUP);
  pinMode(BTN_C, INPUT_PULLUP);
  pinMode(BTN_D, INPUT_PULLUP);
  pinMode(BTN_E, INPUT_PULLUP);
  pinMode(BTN_F, INPUT_PULLUP);
  Serial.println("Joystick çalışmaya başladı. Butonları Test Et!");
}

void loop() {
  if(digitalRead(BTN_A) == LOW) {
    Serial.println("A butonuna basıldı!");
    delay(250);
  }
  if(digitalRead(BTN_B) == LOW) {
    Serial.println("B butonuna basıldı!");
    delay(250);
  }
  if(digitalRead(BTN_C) == LOW) {
    Serial.println("C butonuna basıldı!");
    delay(250);
  }
  if(digitalRead(BTN_D) == LOW) {
    Serial.println("D butonuna basıldı!");
    delay(250);
  }
  if(digitalRead(BTN_E) == LOW) {
    Serial.println("E butonuna basıldı!");
    delay(250);
  }
  if(digitalRead(BTN_F) == LOW) {
    Serial.println("F butonuna basıldı!");
    delay(250);
  }}
