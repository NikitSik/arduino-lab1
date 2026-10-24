// Задание 7Б: мигание D13 через регистры порта, задержка delay()
void setup() {
  DDRB = 0b00100000;
}

void loop() {
  PORTB |= (1 << 5);
  delay(1000);
  PORTB &= ~(1 << 5);
  delay(1000);
}
