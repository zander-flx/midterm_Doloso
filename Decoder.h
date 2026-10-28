const uint8_t DIGITS[10][7] = { //for common-cathode
    {1, 1, 1, 1, 1, 1, 0}, // 0
    {0, 1, 1, 0, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1}, // 2
    {1, 1, 1, 1, 0, 0, 1}, // 3
    {0, 1, 1, 0, 0, 1, 1}, // 4
    {1, 0, 1, 1, 0, 1, 1}, // 5
    {1, 0, 1, 1, 1, 1, 1}, // 6
    {1, 1, 1, 0, 0, 0, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 1, 0, 1, 1}  // 9
};

void displayDigit(int digit, const uint8_t pins[]) {
    for (int i = 0; i < 7; i++) {
        digitalWrite(pins[i], DIGITS[digit][i]);
    }
}

void decoder(int counter){
  int tens = counter / 10;
  int ones = counter % 10;

  displayDigit(tens, LED_2);
  displayDigit(ones, LED_1);
}