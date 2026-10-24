// Задание 8А: скорость переключения D13 стандартными функциями
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  unsigned long times = micros();
  for (int i = 0; i < 100; i++) {
    digitalWrite(13, HIGH);
    digitalWrite(13, LOW);
  }
  Serial.println(micros() - times);
  delay(1000);
}
