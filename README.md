# Stop

Jogo do Stop com Arduino

[![Jogo do Stop com Arduino](http://img.youtube.com/vi/qSSaKfrhp48/0.jpg)](https://www.youtube.com/watch?v=qSSaKfrhp48 "Jogo do Stop com Arduino")


### Componentes

- Arduino UNO
- LCD 16x2
- I2C
- Push Button

### Funcionalidades

- Sorteio de letras aleatórias para o jogo
- Controle de repetição de letras
- Contador de rodadas

### Instruções de Montagem

- Conecte o push button no conector 11 do Arduino e ao GND.
- Conecte o adaptador I2C nas portas analógicas do Arduino:
    - GND -> GND
    - VCC -> 5V
    - SDA -> AN4
    - SCL -> AN5

### Uso

- Pressione o push button por alguns instantes até que alguma letra seja
  sorteada e apareça na tela
- Com a letra sorteada, solte imediatamente o push button, para não atrapalhar a
  contagem de rodadas
- Divirta-se

### Licença 
MIT
