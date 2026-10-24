// Задание 9Б: скорость чтения PB5 через регистр PINB
void setup() {
  Serial.begin(9600);
  DDRB = 0b00111111;
  PORTB |= (1 << 5);
}

void loop() {
  unsigned long times = micros();
  int x = 0;
  for (int i = 0; i < 1000; i++) {
    if (((PINB >> 5) & 1) == 1) {
      x++;
    }
  }
  Serial.println(micros() - times);   // затраченное время, мкс
  Serial.println(x);                  // количество измерений
  delay(1000);
}
