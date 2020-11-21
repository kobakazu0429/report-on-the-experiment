void clrLCD(void) {
  RS_pin = 0;

  delayms(15);
  PORTB = 0x0000;
  dataout();
  PORTB = 0x0010;
  dataout();
}
