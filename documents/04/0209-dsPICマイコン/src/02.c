void put_char(char x) {
  PORTB = x;
  dataout();
  PORTB = x << 4;
  dataout();
  delayms(15);
}
