# Лабораторная работа. Работа с портами и битовые операции (Arduino UNO, ATmega328)

Скетчи к отчёту.

| Папка | Задание |
|---|---|
| `task01_led_registers` | 1. Включение светодиода D13 через регистры DDRB и PORTB |
| `task02a_set_bit` | 2А. Установка бита (PORTB \|= (1 << 5)) |
| `task02b_clear_bit` | 2Б. Сброс бита (PORTB &= ~(1 << 5)) |
| `task03_read_port` | 3. Чтение порта B целиком (PINB) |
| `task04_read_one_pin` | 4. Чтение одного вывода порта |
| `task05_input_d8` | 5. Вывод D8 в режиме входа |
| `task06_input_pullup` | 6. Вход D8 с подтягивающим резистором, кнопка на GND |
| `task07a_blink_standard` | 7А. Blink: digitalWrite / delay |
| `task07b_blink_registers` | 7Б. Blink: регистры / delay |
| `task07c_blink_delay_ms` | 7В. Blink: регистры / _delay_ms |
| `task08a_speed_write_standard` | 8А. Скорость переключения D13: digitalWrite |
| `task08b_speed_write_registers` | 8Б. Скорость переключения D13: регистры |
| `task09a_speed_read_standard` | 9А. Скорость чтения D13: digitalRead |
| `task09b_speed_read_registers` | 9Б. Скорость чтения PB5: PINB |
| `task10_bit_operations` | 10. Битовые операции и макросы bitRead, bitSet и др. |

Скорость монитора порта: 9600 бод.
