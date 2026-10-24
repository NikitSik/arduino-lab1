// Задание 7А: светофор на задержках
const int GREEN = 8;
const int YELLOW = 7;
const int RED = 6;
const int N = 10;           // длительность зелёного и красного, с

void setup() {
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);
}

void loop() {
  // зелёный
  digitalWrite(GREEN, HIGH);
  delay((N - 3) * 1000UL);

  // зелёный мигает 3 секунды
  for (int i = 0; i < 3; i++) {
    digitalWrite(GREEN, LOW);
    delay(500);
    digitalWrite(GREEN, HIGH);
    delay(500);
  }
  digitalWrite(GREEN, LOW);

  // жёлтый 1 секунда
  digitalWrite(YELLOW, HIGH);
  delay(1000);
  digitalWrite(YELLOW, LOW);

  // красный
  digitalWrite(RED, HIGH);
  delay((N - 1) * 1000UL);

  // последняя секунда: красный + жёлтый
  digitalWrite(YELLOW, HIGH);
  delay(1000);
  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, LOW);
}
