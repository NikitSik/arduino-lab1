// Задание 6: при зажатой кнопке яркость фиксируется
const int LED = 9;
const int POT = A0;
const int BTN = 2;

int lastBrightness = 0;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BTN, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(BTN) == LOW) {            // кнопка зажата
    analogWrite(LED, lastBrightness);       // яркость заморожена
    Serial.println("Изменение яркости невозможно!");
  } else {
    int pot = analogRead(POT);
    lastBrightness = map(pot, 0, 1023, 0, 255);
    analogWrite(LED, lastBrightness);
    Serial.println(pot);
  }
  delay(50);
}
