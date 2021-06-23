#include <p30F3013.h>

#include "c:\work\lcd.h"

void init_adc() {
  TRISBbits.TRISB1 = 1;  // RB1 as input
  ADPCFG = 0xFFFD;
  ADCHS = 0x0001;
  ADCON1 = 0x0044;
  ADCSSL = 0;
  ADCON2 = 0x0000;
  ADCON3 = 0x0113;
  ADCON1bits.ADON = 1;  // ADC on
}

int Resultdata, Msec = 0, flag = 0;

void _ISR _AltT3Interrupt(void) {
  ++Msec;
  if (Msec >= 1000) {
    Msec = 0;
    flag = 1;
  }
  while (!IFS0bits.ADIF)
    ;
  Resultdata = ADCBUF0;
  IFS0bits.ADIF = 0;
  IFS0bits.T3IF = 0;  // タイマ３割り込みフラグクリア
}

void init_timer() {
  INTCON1bits.NSTDIS = 0;
  INTCON2bits.ALTIVT = 1;  // 代替ベクタを使用
  TMR3 = 0x0000;           // clear counter register
  PR3 = 29480 - 1;         // set period register (1kHz)
  IFS0 = 0x0000;           // clear all interrupt
  T3CON = 0x8000;          // start TIMER3 on
  IPC1 = 0x5000;
  IPC2 = 0x3000;
  IEC0 = 0x0880;
}

int main() {
  init_LCD();
  init_timer();
  init_adc();

  while (1) {
    if (flag == 1) {
      clr_LCD();
      put_num(Resultdata);
      flag = 0;
    }
  }
}
