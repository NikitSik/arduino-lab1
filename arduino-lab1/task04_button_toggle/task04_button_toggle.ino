// Задание 4: переключение светодиода по нажатию кнопки
const int LED = 13;
const int BTN = 2;

bool ledState = false;
bool lastBtn = HIGH;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BTN, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  bool btn = digitalRead(BTN);

  if (btn != lastBtn) {                  // состояние кнопки изменилось
    delay(30);                           // защита от дребезга
    btn = digitalRead(BTN);              // читаем заново

    if (lastBtn == HIGH && btn == LOW) { // нажатие
      ledState = !ledState;
      digitalWrite(LED, ledState);
      if (ledState) Serial.println("Светодиод горит");
      else          Serial.println("Светодиод не горит");
    }
    lastBtn = btn;
  }
}
