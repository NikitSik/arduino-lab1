// Задание 8Б: скорость переключения D13 через регистры
void setup() {
  Serial.begin(9600);
  DDRB = 0b00100000;
}

void loop() {
  unsigned long times = micros();
  for (int i = 0; i < 100; i++) {
    PORTB |= (1 << 5);
    PORTB &= ~(1 << 5);
  }
  Serial.println(micros() - times);
  delay(1000);
}
