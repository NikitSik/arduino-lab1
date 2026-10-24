// Задание 5: яркость светодиода регулируется потенциометром
const int LED = 9;     // вывод с ШИМ
const int POT = A0;

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int pot = analogRead(POT);
  int brightness = map(pot, 0, 1023, 0, 255);
  analogWrite(LED, brightness);
  Serial.println(pot);
  delay(50);
}
