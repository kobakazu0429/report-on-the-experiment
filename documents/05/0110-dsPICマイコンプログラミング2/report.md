---
header-includes:
# - \usepackage[version=3]{mhchem}
metadata:
  reportInfo:
    subject: dsPICマイコンプログラミング2
    reportNo: 10
  writer:
    class: E5
    no: 14
    group: 4
    chief:
    name: 小畠 一泰
  others:
    date: 2021. 06. 23
    weather: 腫れ
    temp: 24.5
    wet: 62
  partners:
    collaborator1:
    collaborator2:
    collaborator3:
    collaborator4:
---

# 目的

ディジタル信号処理開発ツールを用いてフィルタを設計し, dsPIC マイコンによる信号処理演習を行うことで, ディジタル信号処理について理解する.

# 実験機器

- マイコンボード
- PC

# 実習

## FIR フィルタによる LPF の作成

```{#lst:awesome-code .c .numberLines caption="FIRフィルタによるLPF コード(その1)"}
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
```

\clearpage

```{#lst:awesome-code .c .numberLines caption="FIRフィルタによるLPF コード(その2)"}
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
  while (!IFS0bits.ADIF);
  filterInData = (signed int)ADCBUF0;
  FIR(1, &filterOutData, &filterInData, &firFilter);
  OC2RS = (unsigned int)filterOutData >> 2;
  IFS0bits.ADIF = 0;
  IFS0bits.T3IF = 0;
}
```

\clearpage

```{#lst:awesome-code .c .numberLines caption="FIRフィルタによるLPF コード(その3)"}
int main(void) {
  init_adc();
  init_timer();
  FIRStructInit(&firFilter, 127, (fractional *)firCoeff, __builtin_psvpage(firCoeff), firDelay);
  FIRDelayInit(&firFilter);
  while (1);
}
```

<!-- prettier-ignore-start -->
\begin{figure}[htbp]
\begin{center}
\begin{tabular}{c}
%1
\begin{minipage}{0.5\hsize}
\begin{center}
\includegraphics[keepaspectratio]{./documents/05/0110-dsPICマイコンプログラミング2/images/fir-osi.PNG}
\hspace{1cm} オシロスコープ
\end{center}
\end{minipage}
%2
\begin{minipage}{0.5\hsize}
\begin{center}
\includegraphics[keepaspectratio]{./documents/05/0110-dsPICマイコンプログラミング2/images/fir-fft.PNG}
\hspace{1cm} FFTアナライザ
\end{center}
\end{minipage}
\end{tabular}

\vspace{5mm}

\begin{tabular}{c}
%3
\begin{minipage}{0.5\hsize}
\begin{center}
\includegraphics[keepaspectratio]{./documents/05/0110-dsPICマイコンプログラミング2/images/fir-net.PNG}
\hspace{1cm} ネットワーク解析
\end{center}
\end{minipage}
%4
\begin{minipage}{0.5\hsize}
\begin{center}
% -- no image, only space
\end{center}
\end{minipage}
\end{tabular}
\end{center}
\end{figure}
<!-- prettier-ignore-end -->

\clearpage

## IIR フィルタによる LPF の作成

```{#lst:awesome-code .c .numberLines caption="IIRフィルタによるLPF コード(その1)"}
#include <p30F3013.h>
#include "dsp.h"

fractional filterOutData;
fractional filterInData;

const fractional iirCoeff[] __attribute__((space(auto_psv))) =
  {//              a0 , a1 , b1の符号反転, a2 , b2 の符号反転
  /* 1st buquad */ 409, 818,    29196    , 409, -14449,
  /* 2nd buquad */ 369, 738,    26325    , 369, -11417,
  /* 3rd buquad */ 343, 686,    24482    , 343, -9471,
  /* 4rd buquad */ 330, 661,    23589    , 330, -8527 };

fractional __attribute__((space(ymemory), aligned(8))) iirDelay1[4];
fractional __attribute__((space(ymemory), aligned(8))) iirDelay2[4];
IIRTransposedStruct iirFilter;

void init_adc() {
  TRISBbits.TRISB3 = 1;  // RB1 as input
  ADPCFG = 0xFFF7; ADCHS = 0x0003;
  ADCON1 = 0x0044; ADCSSL = 0;
  ADCON2 = 0x0000; ADCON3 = 0x0113;
  ADCON1bits.ADON = 1;  // ADC on
}
void init_timer() {
  INTCON2bits.ALTIVT = 1;  // 代替ベクタを使用
  TMR3 = 0x0000;           // clear counter register
  PR3 = 1024 - 1;          // set period register
  IFS0 = 0x0000;           // clear all interrupt
  T3CON = 0x8000;          // start TIMER3 on
  INTCON1bits.NSTDIS = 0;
  IPC1 = 0x5000; IPC2 = 0x3000; IEC0 = 0x0880;
  TRISBbits.TRISB9 = 0;  // OC2 pin as output
  OC2CON = 0x0006;       // PWM mode
  TMR2 = 0x0000;         // clear counter register
  PR2 = 1024 - 1;        // set period register
  T2CON = 0x8000;        // start TIMER2 on
  OC2RS = 0;
}
```

\clearpage

```{#lst:awesome-code .c .numberLines caption="IIRフィルタによるLPF コード(その2)"}
int Resultdata, Msec = 0, flag = 0;

void _ISR _AltT3Interrupt(void) {
  while (!IFS0bits.ADIF);
  filterInData = (signed int)ADCBUF0;

  IIRTransposed(1, &filterOutData, &filterInData, &iirFilter);

  OC2RS = (unsigned int)filterOutData >> 2;
  IFS0bits.ADIF = 0;
  IFS0bits.T3IF = 0;
}

#define iirNumSections 4

int main(void) {
  init_adc();
  init_timer();

  iirFilter.numSectionsLess1 = iirNumSections - 1;
  iirFilter.coeffsBase = (fractional *)iirCoeff;
  iirFilter.coeffsPage = __builtin_psvpage(iirCoeff);
  iirFilter.delayBase1 = iirDelay1;
  iirFilter.delayBase2 = iirDelay2;
  iirFilter.finalShift = 0;
  IIRTransposedInit(&iirFilter);

  while (1);
}
```

\clearpage

<!-- prettier-ignore-start -->
\begin{figure}[htbp]
\begin{center}
\begin{tabular}{c}
%1
\begin{minipage}{0.5\hsize}
\begin{center}
\includegraphics[keepaspectratio]{./documents/05/0110-dsPICマイコンプログラミング2/images/iir-osi.PNG}
\hspace{1cm} オシロスコープ
\end{center}
\end{minipage}
%2
\begin{minipage}{0.5\hsize}
\begin{center}
\includegraphics[keepaspectratio]{./documents/05/0110-dsPICマイコンプログラミング2/images/iir-fft.PNG}
\hspace{1cm} FFTアナライザ
\end{center}
\end{minipage}
\end{tabular}

\vspace{5mm}

\begin{tabular}{c}
%3
\begin{minipage}{0.5\hsize}
\begin{center}
\includegraphics[keepaspectratio]{./documents/05/0110-dsPICマイコンプログラミング2/images/iir-net.PNG}
\hspace{1cm} ネットワーク解析
\end{center}
\end{minipage}
%4
\begin{minipage}{0.5\hsize}
\begin{center}
% -- no image, only space
\end{center}
\end{minipage}
\end{tabular}
\end{center}
\end{figure}
<!-- prettier-ignore-end -->

# まとめ

Matlab などの GUI で信号処理を学習できるツールでは非常に手軽に学習することができるが, 実際にはこのような処理を自分で書く必要があることがわかり, 非常に勉強になった.

# 参考文献

- 16 ビット言語ツールライブラリ DS51456C_JP, Microchip Technology Inc. (2007)
- 岩田利王, dsPIC 基板で始めるディジタル信号処理, CQ 出版社(2009)
