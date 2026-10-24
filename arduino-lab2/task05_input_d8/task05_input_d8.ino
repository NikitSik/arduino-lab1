// Задание 5: все выводы порта B на чтение, считывается PB0 (D8)
void setup() {
  Serial.begin(9600);
  DDRB = 0b00000000;   // все выводы порта в режиме чтения
}

void loop() {
  Serial.println(((PINB >> 0) & 1), BIN);   // состояние PB0 (D8)
  delay(1000);
}
