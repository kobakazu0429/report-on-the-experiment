---
header-includes:
# - \usepackage[version=3]{mhchem}
metadata:
  reportInfo:
    subject: dsPICマイコンプログラミング1
    reportNo: 9
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

dsPIC を用いて, A/D 変換, タイマ機能と割り込み, PWM 出力の演習を行う.

# 実験機器

- マイコンボード
- PC

# 課題

## 課題 1

```{#lst:awesome-code .c .numberLines caption="課題 1 コード"}
#include <p30F3013.h>
#include "c:\work\lcd.h"
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
unsigned int get_ADC() {
  ADCON1bits.SAMP = 1;  // sampling start
  delayms(100);
  ADCON1bits.SAMP = 0;  // converting start
  while (!ADCON1bits.DONE);
  return ADCBUF0;  // ADC value
}
int main() {
  init_LCD();
  init_ADC();
  while (1) { clr_LCD();
    put_num(get_ADC());
    delayms(500);
  }
}
```

\clearpage

## 課題 2

```{#lst:awesome-code .c .numberLines caption="課題 2 コード(その1)"}
#include <p30F3013.h>
#include "c:\work\lcd.h"

int Resultdata, Msec = 0, flag = 0;

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

void _ISR _AltT3Interrupt(void) {
  ++Msec;
  if (Msec >= 1000) {
    Msec = 0;
    flag = 1;
  }
  while (!IFS0bits.ADIF);
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
```

```{#lst:awesome-code .c .numberLines caption="課題 2 コード(その2)"}
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
```

## 課題 3

```{#lst:awesome-code .c .numberLines caption="課題 3 コード(3kHz) 変更部分のみ抜粋"}
PR2 = 197 - 1; // set period register (3kHz)
```

```{#lst:awesome-code .c .numberLines caption="課題 3 コード(5kHz) 変更部分のみ抜粋"}
PR2 = 118 - 1; // set period register (5kHz)
```

<!-- prettier-ignore-start -->
\begin{figure}[htbp]
\begin{center}
\begin{tabular}{c}
%1
\begin{minipage}{0.5\hsize}
\begin{center}
\includegraphics[keepaspectratio]{./documents/05/0109-dsPICマイコンプログラミング1/images/3k-osi.PNG}
\hspace{1cm} 3kHz オシロスコープ
\end{center}
\end{minipage}
%2
\begin{minipage}{0.5\hsize}
\begin{center}
\includegraphics[keepaspectratio]{./documents/05/0109-dsPICマイコンプログラミング1/images/3k-fft.PNG}
\hspace{1cm} 3kHz FFTアナライザ
\end{center}
\end{minipage}
\end{tabular}
\end{center}
\end{figure}
<!-- prettier-ignore-end -->

\clearpage

<!-- prettier-ignore-start -->
\begin{figure}[htbp]
\begin{center}
\begin{tabular}{c}
%1
\begin{minipage}{0.5\hsize}
\begin{center}
\includegraphics[keepaspectratio]{./documents/05/0109-dsPICマイコンプログラミング1/images/5k-osi.PNG}
\hspace{1cm} 5kHz オシロスコープ
\end{center}
\end{minipage}
%2
\begin{minipage}{0.5\hsize}
\begin{center}
\includegraphics[keepaspectratio]{./documents/05/0109-dsPICマイコンプログラミング1/images/5k-fft.PNG}
\hspace{1cm} 5kHz FFTアナライザ
\end{center}
\end{minipage}
\end{tabular}
\end{center}
\end{figure}
<!-- prettier-ignore-end -->

## 課題 4

```{#lst:awesome-code .c .numberLines caption="課題 4 コード(その1)"}
#include <p30F3013.h>
int Resultdata, Msec = 0, flag = 0;
void _ISR _AltT3Interrupt(void) {
  while (!IFS0bits.ADIF);
  Resultdata = ADCBUF0;
  OC2RS = Resultdata >> 2;
  IFS0bits.ADIF = 0; IFS0bits.T3IF = 0;  // 割り込みフラグクリア
}
void init_timer() {
  INTCON1bits.NSTDIS = 0;
  INTCON2bits.ALTIVT = 1;  // 代替ベクタを使用
  TMR3 = 0x0000;           // clear counter register
  PR3 = 1024 - 1;          // set period register
  IFS0 = 0x0000;           // clear all interrupt
  T3CON = 0x8000;          // start TIMER3 on
  IPC1 = 0x5000; IPC2 = 0x3000; IEC0 = 0x0880;
  TRISBbits.TRISB9 = 0;  // OC2 pin as output
  OC2CON = 0x0006;       // PWM mode
  TMR2 = 0x0000;         // clear counter register
  PR2 = 1024 - 1;        // set period register
  T2CON = 0x8000;        // start TIMER2 on
  OC2RS = 0;
}
```

```{#lst:awesome-code .c .numberLines caption="課題 4 コード(その2)"}
void init_adc() {
  TRISBbits.TRISB3 = 1;  // RB1 as input
  ADPCFG = 0xFFF7; ADCHS = 0x0003;
  ADCON1 = 0x0044; ADCSSL = 0;
  ADCON2 = 0x0000; ADCON3 = 0x0113;
  ADCON1bits.ADON = 1;  // ADC on
}
int main(void) {
  init_adc(); init_timer(); while (1);
}
```

<!-- prettier-ignore-start -->
\begin{figure}[htbp]
\begin{center}
\begin{tabular}{c}
%1
\begin{minipage}{0.5\hsize}
\begin{center}
\includegraphics[keepaspectratio]{./documents/05/0109-dsPICマイコンプログラミング1/images/kadai4-sin1k.PNG}
\hspace{1cm} 1kHz オシロスコープ
\end{center}
\end{minipage}
%2
\begin{minipage}{0.5\hsize}
\begin{center}
\includegraphics[keepaspectratio]{./documents/05/0109-dsPICマイコンプログラミング1/images/kadai4-net-sin1k.PNG}
\hspace{1cm} 1kHz ネットワーク解析
\end{center}
\end{minipage}
\end{tabular}

\vspace{5mm}

\begin{tabular}{c}
%3
\begin{minipage}{0.5\hsize}
\begin{center}
\includegraphics[keepaspectratio]{./documents/05/0109-dsPICマイコンプログラミング1/images/kadai4-sin3k.PNG}
\hspace{1cm} 3kHz オシロスコープ
\end{center}
\end{minipage}
%4
\begin{minipage}{0.5\hsize}
\begin{center}
\includegraphics[keepaspectratio]{./documents/05/0109-dsPICマイコンプログラミング1/images/kadai4-net-sin3k.PNG}
\hspace{1cm} 3kHz ネットワーク解析
\end{center}
\end{minipage}
\end{tabular}
\end{center}
\end{figure}
<!-- prettier-ignore-end -->

\clearpage

# まとめ

A/D 変換やタイマ機能を用いて課題を達成できて成長できたと感じた.
また今回は SoftOscillo2 を用いた簡易的な計測だったため, 一部滑らかでないところもあったがきちんと計測できてよかった.

# 参考文献

- dsPIC30F ファミリーリファレンスマニュアル(DS70065B_JP), 第 6 章割り込み, 第 12 章タイマー, 第 14 章出力比較モジュール, 第 18 章 12 ビット A/D コンバータ, Microchip Technology Inc. (2006).
- 小野寺康幸, 落合幸喜, トランジスタ技術 2007 年 9 月号, pp.101-135(2007)
