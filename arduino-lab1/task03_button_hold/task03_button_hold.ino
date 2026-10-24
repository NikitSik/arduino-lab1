// Задание 3: светодиод горит, пока кнопка зажата
const int LED = 13;
const int BTN = 2;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BTN, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(BTN) == LOW) {
    digitalWrite(LED, HIGH);
    Serial.println("Кнопка нажата");
  } else {
    digitalWrite(LED, LOW);
    Serial.println("Кнопка не нажата");
  }
  delay(100);
}
