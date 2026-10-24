// Задание 10: битовые операции и макросы работы с битами

// вывод байта в двоичном виде с ведущими нулями
void printBin8(byte v) {
  for (int i = 7; i >= 0; i--) {
    Serial.print(bitRead(v, i));
  }
  Serial.println();
}

void setup() {
  Serial.begin(9600);
  byte myByte, myBits;

  Serial.println("--- AND ---");
  myByte = 0b11001100;
  myBits = myByte & 0b10000111;        // маска
  printBin8(myBits);                   // 10000100
  myByte &= 0b10000000;                // берём старший бит
  printBin8(myByte);                   // 10000000

  Serial.println("--- OR ---");
  myByte = 0b11001100;
  myBits = myByte | 0b00000001;         // ставим бит 0
  printBin8(myBits);                   // 11001101
  myBits = myBits | bit(1);            // ставим бит 1
  printBin8(myBits);                   // 11001111
  myByte = 0b11001100;
  myByte |= 16;                        // включаем бит 4
  printBin8(myByte);                   // 11011100

  Serial.println("--- NOT ---");
  myByte = 0b11001100;
  myByte = ~myByte;                    // инвертируем
  printBin8(myByte);                   // 00110011

  Serial.println("--- XOR ---");
  myByte = 0b11001100;
  myByte ^= 0b10000000;                // инвертируем 7-й бит
  printBin8(myByte);                   // 01001100

  Serial.println("--- SHIFT ---");
  myByte = 0b00011100;
  myByte = myByte << 3;                // сдвиг влево на 3
  printBin8(myByte);                   // 11100000
  myByte >>= 5;
  printBin8(myByte);                   // 00000111
  myByte >>= 2;
  printBin8(myByte);                   // 00000001 (остальные биты потеряны)

  Serial.println("--- MACROS ---");
  myByte = 0b11001100;
  Serial.println(bitRead(myByte, 2));  // 1
  bitSet(myByte, 0);
  printBin8(myByte);                   // 11001101
  bitClear(myByte, 7);
  printBin8(myByte);                   // 01001101
  bitWrite(myByte, 1, 1);
  printBin8(myByte);                   // 01001111
  Serial.println(bit(4));              // 16
  Serial.println(_BV(7));              // 128

  // bit_is_set / bit_is_clear применяются к регистрам
  DDRB  = 0b00100000;
  PORTB = 0b00100000;                  // PB5 = HIGH (светодиод D13 горит)
  Serial.println(bit_is_set(PORTB, 5) ? 1 : 0);    // 1
  Serial.println(bit_is_clear(PORTB, 5) ? 1 : 0);  // 0
}

void loop() {}
