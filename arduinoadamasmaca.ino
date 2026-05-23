#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {2, 3, 4, 5};
byte colPins[COLS] = {6, 7, 8, 9};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

char harfler[] = {'A','B','C','D','E','F','G','H','I'};

String gizliKelime = "GAF";

char gorunenKelime[4] = {'_','_','_','\0'};

int kalanHak = 6;

void setup() {
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Adam Asmaca!");
 
  delay(1500);

  guncelleEkran();
}

void loop() {

  char tus = keypad.getKey();

  if (tus) {

    Serial.print("Tus: ");
    Serial.println(tus);

    if (tus >= '1' && tus <= '9') {

      int index = tus - '1';

      if (index < sizeof(harfler)) {

        char tahmin = harfler[index];

        if (!harfZatenVarMi(tahmin)) {

          bool bulundu = false;

          for (int i = 0; i < gizliKelime.length(); i++) {

            if (gizliKelime[i] == tahmin) {

              gorunenKelime[i] = tahmin;
              bulundu = true;
            }
          }

          if (!bulundu) {
            kalanHak--;
          }

          guncelleEkran();

          if (kalanHak <= 0) {

            lcd.clear();

            lcd.setCursor(0, 0);
            lcd.print("Kaybettin :(");

            lcd.setCursor(0, 1);
            lcd.print(gizliKelime);

            delay(2000);

            oyunuSifirla();
          }

          else if (kelimeTamamMi()) {

            lcd.clear();

            lcd.setCursor(0, 0);
            lcd.print("Kazandin :)");

            lcd.setCursor(0, 1);
            lcd.print(gizliKelime);

            delay(2000);

            oyunuSifirla();
          }
        }
      }
    }

    if (tus == '#') {
      oyunuSifirla();
    }
  }
}

void guncelleEkran() {

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print(gorunenKelime);

  lcd.setCursor(0, 1);
  lcd.print("Hak: ");
  lcd.print(kalanHak);
}

bool harfZatenVarMi(char harf) {

  for (int i = 0; i < gizliKelime.length(); i++) {

    if (gorunenKelime[i] == harf) {
      return true;
    }
  }

  return false;
}

bool kelimeTamamMi() {

  for (int i = 0; i < gizliKelime.length(); i++) {

    if (gorunenKelime[i] == '_') {
      return false;
    }
  }

  return true;
}

void oyunuSifirla() {

  gizliKelime = "GAF";

  gorunenKelime[0] = '_';
  gorunenKelime[1] = '_';
  gorunenKelime[2] = '_';
  gorunenKelime[3] = '\0';

  kalanHak = 6;

  delay(1000);

  guncelleEkran();
}
