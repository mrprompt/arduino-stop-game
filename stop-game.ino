/**
 * Jogo do STOP
 *
 * STOP é um jogo onde, após a letra sorteada, todos os participantes devem
 * preencher as colunas (ex.: Nome, Localidade, Objeto, Carro, etc) e o primeiro
 * a terminar, grita "STOP", parando o jogo para a contagem.
 *
 * A regra de contagem é: repetidos valem 5, senão, 10 pontos. Ao final de todas
 * as rodadas, soma-se o total de pontos de cada um e ganha quem obtiver mais
 * pontos, claro.
 *
 * @author Thiago Paes
 **/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

char ultimaletra;
int pin = 11;
int led = 13;
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
  pinMode(led, OUTPUT);
}

void loop() {
  val = digitalRead(pin);

  // o push button vem por padrão 1
  if (val == 0) {
    // utilizando um contador, pq a leitura é muito rápida
    contador++;

    // com o contador ativado - cerca de 2s - sorteio apenas uma vez.
    if (contador >= 250) {
      sorteia();

      contador = 0;
    }
  }

  // joga na tela Amarelo
  lcd.setCursor(8, 0);
  lcd.print(rodada);

  lcd.setCursor(7, 1);
  lcd.print(ultimaletra);
}

// sorteio de letras, utilizando a própria tabela ASCII e tratando repetição
void sorteia() {
  duplicado = true;

  while (duplicado == true) {
    digitalWrite(led, HIGH);

    ultimaletra = char(random(65, 90));
    duplicado = false;

    for (int i = 0; i < sizeof(letras); i++) {
      if (letras[i] == ultimaletra) {
        duplicado = true;
      }
    }
  }

  digitalWrite(led, LOW);

  letras[rodada] = ultimaletra;

  rodada++;
}


