// Задание 7В: мигание D13 через регистры порта, задержка _delay_ms()
#include <util/delay.h>

void setup() {
  DDRB = 0b00100000;
}

void loop() {
  PORTB |= (1 << 5);
  _delay_ms(1000);
  PORTB &= ~(1 << 5);
  _delay_ms(1000);
}
