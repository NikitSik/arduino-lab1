// Задание 11*: управление цветом RGB-светодиода энкодером
const int R_PIN = 9;
const int G_PIN = 10;
const int B_PIN = 11;
const int CLK = 2;
const int DT  = 3;
const int SW  = 4;

float hue = 0;          // 0..360
float val = 1.0;        // яркость 0..1
int lastClk;

void hsvToRgb(float h, float s, float v, int &r, int &g, int &b) {
  float lo = v * (1.0 - s);
  int sector = ((int)(h / 60.0)) % 6;
  float t = (h - 60.0 * floor(h / 60.0)) / 60.0;
  float up = lo + (v - lo) * t;
  float down = v - (v - lo) * t;
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

void showColor() {
  int r, g, b;
  hsvToRgb(hue, 1.0, val, r, g, b);
  analogWrite(R_PIN, r);
  analogWrite(G_PIN, g);
  analogWrite(B_PIN, b);
}

void setup() {
  pinMode(R_PIN, OUTPUT);
  pinMode(G_PIN, OUTPUT);
  pinMode(B_PIN, OUTPUT);
  pinMode(CLK, INPUT_PULLUP);
  pinMode(DT, INPUT_PULLUP);
  pinMode(SW, INPUT_PULLUP);
  Serial.begin(9600);
  lastClk = digitalRead(CLK);
  showColor();
}

void loop() {
  int clk = digitalRead(CLK);
  if (clk != lastClk && clk == LOW) {            // спад CLK
    int dir = (digitalRead(DT) != clk) ? 1 : -1; // направление вращения

    if (digitalRead(SW) == LOW) {                // кнопка зажата: яркость
      val += dir * 0.05;
      val = constrain(val, 0.0, 1.0);
    } else {                                     // иначе: оттенок
      hue += dir * 5;
      if (hue >= 360) hue -= 360;
      if (hue < 0)    hue += 360;
    }
    showColor();

    Serial.print("H = "); Serial.print(hue);
    Serial.print("  V = "); Serial.println(val);
  }
  lastClk = clk;
}
