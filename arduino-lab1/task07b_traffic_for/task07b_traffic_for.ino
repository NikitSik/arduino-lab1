// Задание 7Б: светофор на циклах for с выводом секунд в консоль
const int GREEN = 8;
const int YELLOW = 7;
const int RED = 6;
const int N = 10;

void setup() {
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // зелёный
  for (int s = N; s > 0; s--) {
    Serial.print("Зелёный, осталось секунд: ");
    Serial.println(s);
    if (s > 3) {
      digitalWrite(GREEN, HIGH);
      delay(1000);
    } else {                       // последние 3 секунды мигаем
      digitalWrite(GREEN, HIGH);
      delay(500);
      digitalWrite(GREEN, LOW);
      delay(500);
    }
  }
  digitalWrite(GREEN, LOW);

  // жёлтый
  digitalWrite(YELLOW, HIGH);
  delay(1000);
  digitalWrite(YELLOW, LOW);

  // красный
  digitalWrite(RED, HIGH);
  for (int s = N; s > 0; s--) {
    Serial.print("Красный, осталось секунд: ");
    Serial.println(s);
    if (s == 1) digitalWrite(YELLOW, HIGH);   // последняя секунда
    delay(1000);
  }
  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, LOW);
}
