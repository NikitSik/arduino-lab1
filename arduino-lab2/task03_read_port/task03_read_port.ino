// Задание 3: чтение состояния порта B целиком
void setup() {
  Serial.begin(9600);
  DDRB  = 0b00111111;   // PB0...PB5 как выходы (D8...D13)
  PORTB = 0b00111011;   // PB0, PB1, PB3...PB5 = HIGH, PB2 = LOW
}

void loop() {
  Serial.println(PINB, BIN);   // чтение порта и вывод в монитор порта
  delay(1000);
}
