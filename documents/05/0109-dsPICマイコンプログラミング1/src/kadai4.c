#include <p30F3013.h>

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
  INTCON2bits.ALTIVT = 1;  // 代替ベクタを使用
  TMR3 = 0x0000;           // clear counter register
  PR3 = 1024 - 1;          // set period register
  IFS0 = 0x0000;           // clear all interrupt
  T3CON = 0x8000;          // start TIMER3 on
  INTCON1bits.NSTDIS = 0;
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
  Resultdata = ADCBUF0;
  OC2RS = Resultdata >> 2;
  IFS0bits.ADIF = 0;
  IFS0bits.T3IF = 0;  // タイマ３割り込みフラグクリア
}

int main(void) {
  init_adc();
  init_timer();

  while (1)
    ;
}
