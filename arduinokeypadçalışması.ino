#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27,16,2);

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {2, 3, 4, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 7, 8, 9}; //connect to the column pinouts of the keypad

//Create an object of keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

String girilenSifre = "";
String dogruSifre = "1905";
int yanlisSayisi = 0;
const int maxYanlis = 3;
bool kilitlendi = false;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Sifreyi Giriniz:");
}

void loop() {
  if(kilitlendi) {
    return;
  }
  char tus = keypad.getKey();
  if (tus == '#') {
    if (girilenSifre == dogruSifre) {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Doğru Sifre!");
      yanlisSayisi = 0;
    }
    else {
      yanlisSayisi = yanlisSayisi + 1;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Yanlis Sifre!");

      if(yanlisSayisi >= maxYanlis){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Sistem Kilitlendi!");
        kilitlendi = true;
      }
      
    }
    girilenSifre = "";
    delay(2000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Sifreyi Giriniz: ");
  }
  else {
    girilenSifre += tus;
    lcd.setCursor(0,1);
    lcd.print("       ");
    lcd.setCursor(0,1);
    lcd.print(girilenSifre);
  }
}
