// Задание 9А: скорость чтения D13 стандартной функцией digitalRead()
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
}

void loop() {
  unsigned long times = micros();
  int x = 0;
  for (int i = 0; i < 1000; i++) {
    if (digitalRead(13) == 1) {
      x++;
    }
  }
  Serial.println(micros() - times);   // затраченное время, мкс
  Serial.println(x);                  // количество измерений
  delay(1000);
}
