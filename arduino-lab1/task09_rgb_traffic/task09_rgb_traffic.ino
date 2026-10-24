// Задание 9: светофор на RGB-светодиоде (общий катод)
const int R_PIN = 9;
const int G_PIN = 10;
const int B_PIN = 11;
const int N = 10;

void setColor(int r, int g, int b) {
  analogWrite(R_PIN, r);
  analogWrite(G_PIN, g);
  analogWrite(B_PIN, b);
}

void setup() {
  pinMode(R_PIN, OUTPUT);
  pinMode(G_PIN, OUTPUT);
  pinMode(B_PIN, OUTPUT);
}

void loop() {
  setColor(0, 255, 0);                  // зелёный
  delay((N - 3) * 1000UL);

  for (int i = 0; i < 3; i++) {         // мигание зелёного
    setColor(0, 0, 0);   delay(500);
    setColor(0, 255, 0); delay(500);
  }

  setColor(255, 120, 0);                // жёлтый = красный + зелёный
  delay(1000);

  setColor(255, 0, 0);                  // красный
  delay((N - 1) * 1000UL);

  setColor(255, 40, 0);                 // оранжевый вместо "красный + жёлтый"
  delay(1000);
}
