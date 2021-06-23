#include <p30F3013.h>

#include "dsp.h"

fractional filterOutData;
fractional filterInData;

const fractional firCoeff[] __attribute__((space(auto_psv))) = {
    0,     -5,   -9,   -15,  -20,  -24,  -25,   -21,   -11,  1,   17,   30,
    37,    35,   22,   0,    -26,  -50,  -64,   -62,   -41,  -4,  39,   80,
    104,   102,  69,   11,   -60,  -125, -163,  -160,  -109, -18, 91,   191,
    250,   244,  166,  26,   -141, -294, -383,  -373,  -250, -34, 228,  467,
    609,   594,  397,  40,   -406, -831, -1105, -1109, -762, -44, 989,  2214,
    3458,  4528, 5251, 5507, 5251, 4528, 3458,  2214,  989,  -44, -762, -1109,
    -1105, -831, -406, 40,   397,  594,  609,   467,   228,  -34, -250, -373,
    -383,  -294, -141, 26,   166,  244,  250,   191,   91,   -18, -109, -160,
    -163,  -125, -60,  11,   69,   102,  104,   80,    39,   -4,  -41,  -62,
    -64,   -50,  -26,  0,    22,   35,   37,    30,    17,   1,   -11,  -21,
    -25,   -24,  -20,  -15,  -9,   -5,   0};

fractional __attribute__((space(ymemory), aligned(256))) firDelay[127];

FIRStruct firFilter;

void init_adc() {
  TRISBbits.TRISB3 = 1;  // RB1 as input
  ADPCFG = 0xFFF7;
  ADCHS = 0x0003;
  ADCON1 = 0x0044;
  ADCSSL = 0;
  ADCON2 = 0x0000;
  ADCON3 = 0x0113;
  ADCON1bits.ADON = 1;  // ADC on
}

void init_timer() {
  INTCON1bits.NSTDIS = 0;
  INTCON2bits.ALTIVT = 1;  // 代替ベクタを使用
  TMR3 = 0x0000;           // clear counter register
  PR3 = 1024 - 1;          // set period register
  IFS0 = 0x0000;           // clear all interrupt
  T3CON = 0x8000;          // start TIMER3 on
  IPC1 = 0x5000;
  IPC2 = 0x3000;
  IEC0 = 0x0880;

  TRISBbits.TRISB9 = 0;  // OC2 pin as output
  OC2CON = 0x0006;       // PWM mode
  TMR2 = 0x0000;         // clear counter register
  PR2 = 1024 - 1;        // set period register
  T2CON = 0x8000;        // start TIMER2 on
  OC2RS = 0;
}

int Resultdata, Msec = 0, flag = 0;

void _ISR _AltT3Interrupt(void) {
  while (!IFS0bits.ADIF)
    ;
  filterInData = (signed int)ADCBUF0;

  FIR(1, &filterOutData, &filterInData, &firFilter);

  OC2RS = (unsigned int)filterOutData >> 2;
  IFS0bits.ADIF = 0;
  IFS0bits.T3IF = 0;
}

int main(void) {
  init_adc();
  init_timer();

  FIRStructInit(&firFilter, 127, (fractional *)firCoeff,
                __builtin_psvpage(firCoeff), firDelay);
  FIRDelayInit(&firFilter);

  while (1)
    ;
}
