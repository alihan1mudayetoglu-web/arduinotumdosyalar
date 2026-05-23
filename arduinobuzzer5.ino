int buzzerPin = 11;
int led1 = 8;
int led2 = 9;
int led3 = 10;

// Nota frekansları
#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_G3  196
#define NOTE_A3  220
#define NOTE_B3  247

// Melodi (slow vibe)
int melody[] = {
  NOTE_G3, NOTE_A3, NOTE_C4, NOTE_A3,
  NOTE_G3, NOTE_E4, NOTE_D4, NOTE_C4,
  NOTE_G3, NOTE_A3, NOTE_C4, NOTE_B3,
  NOTE_A3, NOTE_G3
};

// Süreler (ultra slowed hissi)
int durations[] = {
  800, 800, 1200, 800,
  800, 1200, 1000, 1500,
  800, 800, 1200, 800,
  1000, 1500
};

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {

  for (int i = 0; i < 14; i++) {

    // LED animasyonu
    digitalWrite(led1, i % 3 == 0);
    digitalWrite(led2, i % 3 == 1);
    digitalWrite(led3, i % 3 == 2);

    // Nota çal
    tone(buzzerPin, melody[i], durations[i]);

    delay(durations[i]);

    noTone(buzzerPin);
    delay(100);
  }

  // Kısa duraklama (loop tekrar etmeden önce)
  delay(2000);
}
