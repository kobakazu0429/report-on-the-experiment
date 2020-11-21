void locate(char x, char y) {
  RS_pin = 0;
  delayms(15);

  // row
  PORTB = y == 0 ? 0b10000000 : 0b11000000;
  dataout();

  // col
  PORTB = x << 4;
  dataout();
}
