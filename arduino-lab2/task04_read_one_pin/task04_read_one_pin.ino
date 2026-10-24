// Задание 4: чтение одного вывода порта (PB5)
void setup() {
  Serial.begin(9600);
  DDRB  = 0b00111111;
  PORTB = 0b00111011;
}

void loop() {
  Serial.println(((PINB >> 5) & 1), BIN);   // состояние PB5
  delay(1000);
}
