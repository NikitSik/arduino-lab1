// Задание 10: плавная смена цвета потенциометром (модель HSV)
const int R_PIN = 9;
const int G_PIN = 10;
const int B_PIN = 11;
const int POT = A0;

// H: 0..360, S, V: 0..1
void hsvToRgb(float h, float s, float v, int &r, int &g, int &b) {
  float lo = v * (1.0 - s);                 // V(1 - S)
  int sector = ((int)(h / 60.0)) % 6;
  float t = (h - 60.0 * floor(h / 60.0)) / 60.0;
  float up = lo + (v - lo) * t;             // растёт
  float down = v - (v - lo) * t;            // убывает
  float R, G, B;
  switch (sector) {
    case 0: R = v;    G = up;   B = lo;   break;
    case 1: R = down; G = v;    B = lo;   break;
    case 2: R = lo;   G = v;    B = up;   break;
    case 3: R = lo;   G = down; B = v;    break;
    case 4: R = up;   G = lo;   B = v;    break;
    default: R = v;   G = lo;   B = down; break;
  }
  r = (int)(R * 255);
  g = (int)(G * 255);
  b = (int)(B * 255);
}

void setup() {
  pinMode(R_PIN, OUTPUT);
  pinMode(G_PIN, OUTPUT);
  pinMode(B_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int pot = analogRead(POT);
  float h = pot * 360.0 / 1023.0;
  int r, g, b;
  hsvToRgb(h, 1.0, 1.0, r, g, b);
  analogWrite(R_PIN, r);
  analogWrite(G_PIN, g);
  analogWrite(B_PIN, b);

  Serial.print("H = "); Serial.print(h);
  Serial.print("  RGB = ");
  Serial.print(r); Serial.print(", ");
  Serial.print(g); Serial.print(", ");
  Serial.println(b);
  delay(30);
}
