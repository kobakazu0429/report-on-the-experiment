#include <math.h>
#include <p30F3013.h>

#define PI 3.141592

unsigned count = 0;
unsigned s[50];

void _ISR _AltT2Interrupt(void) {  // TIMER2 interrupt handler
  OC2RS = s[count++];              // set data to OC2RS register
  if (count >= 50) {
    count = 0;
  }
  IFS0bits.T2IF = 0;  // clear interrupt
}

int main(void) {
  unsigned i;
  TRISBbits.TRISB9 = 0;    // OC2 pin as output
  INTCON2bits.ALTIVT = 1;  // use Alternate Interrupt Vector
  OC2CON = 0x0006;         // PWM mode
  TMR2 = 0x0000;           // clear counter register
  PR2 = 590 - 1;           // set period register (50kHz)
  IFS0 = 0x0000;           // clear all interrupt

  for (i = 0; i < 50; i++) {  // set sin wave data
    s[i] = (unsigned){(PR2) * (1.0 + sin(PI * i * 3 / 25)) / 2};
  }

  OC2RS = 0;
  T2CON = 0x8000;  // start TIMER2 on
  IEC0 = 0x0040;   // enable TIMER2 interrupt

  while (1)
    ;
}
