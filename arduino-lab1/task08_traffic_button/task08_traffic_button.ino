// Задание 8: светофор по кнопке
const int GREEN = 8;
const int YELLOW = 7;
const int RED = 6;
const int BTN = 2;
const int N = 10;

void setup() {
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(BTN, INPUT_PULLUP);
}

void loop() {
  digitalWrite(GREEN, HIGH);                 // ожидание нажатия
  while (digitalRead(BTN) == HIGH) { }

  delay(5000);                               // 5 секунд до переключения

  for (int i = 0; i < 3; i++) {              // зелёный мигает
    digitalWrite(GREEN, LOW);  delay(500);
    digitalWrite(GREEN, HIGH); delay(500);
  }
  digitalWrite(GREEN, LOW);

  digitalWrite(YELLOW, HIGH); delay(1000);   // жёлтый
  digitalWrite(YELLOW, LOW);

  digitalWrite(RED, HIGH);                   // красный
  delay((N - 1) * 1000UL);
  digitalWrite(YELLOW, HIGH); delay(1000);   // красный + жёлтый
  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, LOW);
}
