---
header-includes:
# - \usepackage[version=3]{mhchem}
metadata:
  reportInfo:
    subject: マイコン実習(3)
    reportNo: 12
  writer:
    class: E3
    no: 15
    group: 2
    chief:
    name: 小畠 一泰
  others:
    date: 2019. 10. 07
    weather: 曇り
    temp: 25.9
    wet: 60.5
  partners:
    collaborator1: 井上 隆治
    collaborator2: 木下 拓真
    collaborator3: 重見 達也
    collaborator4: DANDAR TUGULDUR
---

# 目的

前期の実習で用いた 16 ビットマイコン dsPIC30F3013 について, レジスタを直接 C 言語によりプログラミングする方法を習得することを目的とする.

# 実験器具

- 実験セット ④: (16 ビットマイコン dsPIC30F3013, PC)

\clearpage

# 課題

## 課題 1-1

サンプル 2 のリストを変更して, LED の点滅間隔を短くしたり長くしたりせよ.
ループの繰り返し回数を変えて試せ.

```{.c .numberLines}
#include <p30F3013.h>

void wait1() {
  unsigned i, j;
  for (i = 0; i < 64; i++) {
    for (j = 0; j < 65000; j++) {
      asm("nop");
    }
  }
}

void main() {
  TRISBbits.TRISB0 = 0;
  while (1) {
    PORTBbits.RB0 = ~PORTBbits.RB0;
    wait1();
  }
}
```

\clearpage

## 課題 1-2

奇数ビットと偶数ビットの LED を交互に点灯させるプログラムを作成せよ.

```{.c .numberLines}
#include <p30F3013.h>

void wait1() {
  unsigned i, j;
  for (i = 0; i < 64; i++) {
    for (j = 0; j < 65000; j++) {
      asm("nop");
    }
  }
}

void main() {
  TRISB = 0;
  LATB = 85;

  while (1) {
    LATB = ~LATB;
    wait1();
  }
}
```

\clearpage

## 課題 1-3

LED1 個を最下位から順に点灯していき, 最上位に達したらまた最下位から順に点灯するプログラムを作成せよ.

```{.c .numberLines}
#include <p30F3013.h>

void wait1() {
  unsigned i, j;
  for (i = 0; i < 64; i++) {
    for (j = 0; j < 65000; j++) {
      asm("nop");
    }
  }
}

void main() {
  TRISB = 0;
  int i = 0;

  while (1) {
    LATB = 1;
    wait1();
    for (i = 0; i < 7; i++) {
      LATB = LATB << 1;
      wait1();
    }
  }
}
```

\clearpage

## 課題 1-4

LED を最下位から順に点灯していき, 最上位に達したら, 最上位から順に最下位まで点灯し, これを交互に繰り返すプログラムを作成せよ.

```{.c .numberLines}
#include <p30F3013.h>

void wait1() {
  unsigned i, j;
  for (i = 0; i < 64; i++) {
    for (j = 0; j < 65000; j++) {
      asm("nop");
    }
  }
}

void main() {
  TRISB = 0;
  int i = 0;

  LATB = 1;
  while (1) {
    for (i = 0; i < 7; i++) {
      LATB = LATB << 1;
      wait1();
    }
    for (i = 0; i < 7; i++) {
      LATB = LATB >> 1;
      wait1();
    }
  }
}
```

\clearpage

## 課題 1-5

LED を真ん中 2 個から最下位と最上位に向かって順に点灯していき, 最上位と最下位に達したらまた真ん中から最上位と最下位に順に点灯を繰り返すプログラムを作成せよ.

```{.c .numberLines}
#include <p30F3013.h>

void wait1() {
  unsigned i, j;
  for (i = 0; i < 64; i++) {
    for (j = 0; j < 65000; j++) {
      asm("nop");
    }
  }
}

void main() {
  TRISB = 0;
  int i = 0;
  int PATTERN[4] = {24, 36, 66, 129};
  while (1) {
    for (i = 0; i < 4; i++) {
      LATB = PATTERN[i];
      wait1();
    }
  }
}
```

\clearpage

## 課題 2-1

サンプル 4 の wait1()関数を次のように変更して, LED の点滅間隔を調整できるようにせよ.

```{.c .numberLines}
#include <p30F3013.h>

void wait2(unsigned x) {
  unsigned i, j;
  for (i = 0; i < x; i++) {
    for (j = 0; j < 65000; j++) {
      asm("nop");
    }
  }
}

void main() {
  TRISB = 0;
  while (1) {
    PORTB = 0x0000;
    wait2(32);
    PORTB = 0x0001;
    wait2(64);
  }
}
```

\clearpage

## 課題 2-2

LED が 0 から 9 まで順位点灯するプログラムを作成せよ.

```{.c .numberLines}
#include <p30F3013.h>

void wait2(unsigned x) {
  unsigned i, j;
  for (i = 0; i < x; i++) {
    for (j = 0; j < 65000; j++) {
      asm("nop");
    }
  }
}

void main() {
  TRISB = 0;
  int i = 0;
  while (1) {
    for (i = 0; i < 10; i++) {
      PORTB = i;
      wait2(32);
    }
  }
}
```

\clearpage

## 課題 2-3

タクトスイッチが押されたら LED が 0 から 1 に変化するプログラムを作成せよ.

```{.c .numberLines}

#include <p30F3013.h>

void wait2(unsigned x) {
  unsigned i, j;
  for (i = 0; i < x; i++) {
    for (j = 0; j < 65000; j++) {
      asm("nop");
    }
  }
}

void main() {
  TRISB = 0;
  TRISBbits.TRISB8 = 1;

  LATB = 0;
  while (1) {
    if (PORTBbits.RB8 == 0) LATB = 1;
    else LATB = 0;
  }
}
```

\clearpage

## 課題 2-4

タクトスイッチを押すたびに表示が 1 増す(9 の次は 0)プログラムを作成せよ.

```{.c .numberLines}
#include <p30F3013.h>

void wait2(unsigned x) {
  unsigned i, j;
  for (i = 0; i < x; i++) {
    for (j = 0; j < 65000; j++) {
      asm("nop");
    }
  }
}

void main() {
  TRISB = 0;
  TRISBbits.TRISB8 = 1;

  LATB = 0;
  while (1) {
    if (PORTBbits.RB8 == 0) {
      if (LATB < 9) LATB += 1;
      else LATB = 0;
      wait2(16);
    }
  }
}
```

\clearpage

## 課題 2-5

0 ~ 9 を順に(早く)表示し, タクトスイッチを押したら表示が停止する電子ルーレットを作成せよ.

```{.c .numberLines}
#include <p30F3013.h>

void wait2(unsigned x) {
  unsigned i, j;
  for (i = 0; i < x; i++) {
    for (j = 0; j < 65000; j++) {
      asm("nop");
    }
  }
}

void main() {
  TRISB = 0;
  TRISBbits.TRISB8 = 1;
  LATB = 0;
  int i = 0;
  while (1) {
    for (i = 0; i < 10; i++) {
      PORTB = i;
      if (PORTBbits.RB8 == 0) while (1) ;
      wait2(8);
    }
  }
}
```

# 検討課題

前期の実習では put_num(12)のように, 制御レジスタを意識することなく, 目的に応じて関数を呼びだす方法でプログラミングを行った.
今回の課題を, 前期同様に関数呼び出しで行うには, どのような関数を用意し, 課題プログラムをどのように記述すればよいか, モジュール 2 の課題 2 について作成せよ.

```{.c .numberLines}
#include <p30F3013.h>
void wait2(unsigned x) {
  unsigned i, j;
  for (i = 0; i < x; i++) {
    for (j = 0; j < 65000; j++) {
      asm("nop");
    }
  }
}

void displayNumber(int num) {
  PORTB = num;
}

void main() {
  TRISB = 0;
  int i = 0;
  while (1) {
    for (i = 0; i < 10; i++) {
      displayNumber(i);
      wait2(32);
    }
  }
}
```
