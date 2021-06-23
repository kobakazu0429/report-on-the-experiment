#include <p30F3013.h>

#include "c:\work\lcd.h"

// initialization
void init_ADC() {
  TRISBbits.TRISB1 = 1;  // RB1 as input
  ADPCFG = 0xFFFD;
  ADCHS = 0x0001;
  ADCON1 = 0x0000;
  ADCSSL = 0;
  ADCON2 = 0x0000;
  ADCON3 = 0x0013;
  ADCON1bits.ADON = 1;  // ADC on
}

// manual A/D convert
unsigned int get_ADC() {
  ADCON1bits.SAMP = 1;  // sampling start
  delayms(100);
  ADCON1bits.SAMP = 0;  // converting start
  while (!ADCON1bits.DONE)
    ;
  return ADCBUF0;  // ADC value
}

int main() {
  init_LCD();
  init_ADC();

  unsigned int ADCvalue;

  while (1) {
    clr_LCD();
    ADCvalue = get_ADC();
    put_num(ADCvalue);
    delayms(500);
  }
}
