/**
 * Jogo do STOP
 *
 *  @author Thiago Paes
 **/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

char ultimaletra;
int pin = 11;
int val = 1;
int rodada = 0;
int letras[26];
int contador = 0;
boolean duplicado;

void setup() {
  lcd.begin();
  lcd.clear();
  lcd.setBacklight(HIGH);

  lcd.setCursor(0, 0);
  lcd.print("RODADA:    DE 26");
  lcd.setCursor(0, 1);
  lcd.print("LETRA:");

  pinMode(pin, INPUT_PULLUP);
}

void loop() {
  val = digitalRead(pin);
  
  if (val == 0) {
    contador++;

    if (contador >= 250) {
      sorteia();

      contador = 0;
    }
  }

  lcd.setCursor(8, 0);
  lcd.print(rodada);

  lcd.setCursor(7, 1);
  lcd.print(ultimaletra);
}

void sorteia() {
  duplicado = true;

  while (duplicado == true) {
    ultimaletra = char(random(65, 90));
  
    duplicado = false;

    for (int i = 0; i < sizeof(letras); i++) {
      if (letras[i] == ultimaletra) {
        duplicado = true;
      }
    }
  }

  letras[rodada] = ultimaletra;

  rodada++;
}


