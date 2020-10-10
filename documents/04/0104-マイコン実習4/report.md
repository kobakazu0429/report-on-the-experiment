---
header-includes:
# - \usepackage{listings}
metadata:
  reportInfo:
    subject: マイコン実習(4):シリアル通信
    reportNo: 4
  writer:
    class: E4
    no: 14
    group: 2
    chief:
    name: 小畠 一泰
  others:
    date: 2020. 07. 02
    weather: 晴れ
    temp:
    wet:
  partners:
    collaborator1:
    collaborator2:
    collaborator3:
    collaborator4:
---

# 目的

組み込みマイコン dsPIC を用いてシリアル通信を行うことで, PC やセンサ等からのデータのやり取りに習熟することを目的とする.

# 実習

## PC と通信

実習キットは USB により PC と接続され, USB-シリアル変換 IC(FT232RL)によって UART 通信が PC と行えるようになっている.
また, マイコンの受信結果を確認するため, LCD ユニット(SC1602BS-B)が接続されている.

![PCとの通信回路](./documents/04/04-マイコン実習4/images/cir1.png){#fig:cir1 height=50mm}

\clearpage

### 課題 1

PC から 1 文字送信し, マイコンで受信して LCD にそれを表示するプログラムを作成せよ.

```{#lst:awesome-code .c .numberLines caption="課題1のソースコード全文"}
#include <p30F3013.h>
#include "c:\work\e4exp.h"

int main(void) {
    char x;
    U1MODE = 0x8400;
    U1BRG = 95;
    U1STA = 0x0400;
    init_LCD();
    while (1) {
        while (U1STAbits.URXDA != 1);
        x = U1RXREG;
        put_char(x);
        while (U1STAbits.UTXBF != 0);
        U1TXREG = x;
    }
}
```

### 課題 2

マイコンから文字列”Hello PC”を送信し, LCD と PC にそれぞれ表示するプログラムを作成せよ.

```{#lst:awesome-code .c .numberLines caption="課題2のソースコード全文"}
#include <p30F3013.h>
#include "c:\work\e4exp.h"

int main(void) {
  U1MODE = 0x8400;
  U1BRG = 95;
  U1STA = 0x0400;
  init_LCD();
  char* greet = "Hello PC";
  while(*greet != '\0') {
    U1TXREG = *greet;
    put_char(*greet);
    greet++;
  }
  while(1);
}
```

\clearpage

### 課題 3

マイコンから 10 個の数値を CSV に変換して送信し, PC の通信ソフトで受信した後, バッファの中身をファイルに保存後, それを Excel で開いて表示せよ.

[@fig:csv] にログのスクリーンショットを示す.

```{#lst:awesome-code .c .numberLines caption="課題3のソースコード全文"}
#include <p30F3013.h>
#include "c:\work\e4exp.h"

int main(void) {
  U1MODE = 0x8400;
  U1BRG = 95;
  U1STA = 0x0400;

  init_LCD();

  char data[] = {'0','1','2','3','4','5','6','7','8','9'};
  char split = ',';

  int i = 0;
  for(;i < 10; i++) {
    U1TXREG = data[i];
    put_char(data[i]);
    U1TXREG = split;
    put_char(split);
  }

  while(1);
}
```

![ログのスクリーンショット](./documents/04/04-マイコン実習4/images/csv.png){#fig:csv width=160mm}

\clearpage

## アドレス付き UART 通信

![2個の SN74LV8153 に7セクグメント LED を取り付けた回路](./documents/04/04-マイコン実習4/images/cir2.png){#fig:cir2 height=50mm}

[@fig:cir2] にあるように, シリアル-パラレル・インタフェースとしてテキサス・インスツルメンツ社の SN74LV8153 が 2 個並列に接続され, アドレス設定ピン(A0~A2, 2~4 番ピン)によりそれぞれアドレスが(000,001)に設定されている.
dsPIC からは UART 出力 U1TX(17 番ピン)が SN74LV8153 のシリアル・データ入力 D (5 番ピン)に, ディジタル I/O の RF6(16 番ピン)が SN74LV8153 のレジスタ・ステータスの初期化 RESET (7 番ピン)に接続されている.
CPU ボードからモジュール 3 には電源 VDD とグラウンド GND と上記 2 本が接続されているのみである. SN74LV8153 の出力(Y0~Y7)は 7 セグメント LED に $1 \unit{k \ohm}$ を通して接続されている.
伝送するシリアル・データのフォーマットを [@tbl:tbl1] に示す.
2 回の送信によりアドレスと 8 ビット分のデータ D0~D7 を送信する.
このインタフェース IC のデータ伝送速度は無調整/無設定で $2 \unit{kbps}〜24\unit{kbps}$ の任意のビットレートに対応している.

<!-- TODO: ↓ "_ -> *" -->

\begin{table}[htb]
\begin{center}
\caption{\label{tbl:tbl1}シリアル・データのフォーマット}
\begin{tabular}{|l|l|l|l|}
\hline
\multicolumn{2}{|l|}{第 1 フレーム} & \multicolumn{2}{l|}{第 2 フレーム} \\ \hline
\multicolumn{2}{|l|}{スタートビット} & \multicolumn{2}{l|}{スタートビット} \\ \hline
\multicolumn{2}{|l|}{1} & \multicolumn{2}{l|}{1} \\ \hline
A0 & \multirow{3}{*}{アドレス} & A0 & \multirow{3}{*}{アドレス} \\ \cline{1-1} \cline{3-3}
A1 & & A1 & \\ \cline{1-1} \cline{3-3}
A2 & & A2 & \\ \hline
D0 & \multirow{4}{*}{データ} & D0 & \multirow{4}{*}{データ} \\ \cline{1-1} \cline{3-3}
D1 & & D1 & \\ \cline{1-1} \cline{3-3}
D2 & & D2 & \\ \cline{1-1} \cline{3-3}
D3 & & D3 & \\ \hline
\multicolumn{2}{|l|}{ストップビット} & \multicolumn{2}{l|}{ストップビット} \\ \hline
\end{tabular}
\end{center}
\end{table}


\clearpage

### 課題 1

表 2 より, hdata[3]を hdata[16]に拡張せよ.
表 2 を埋めて, それを元に配列にデータを追加せよ.

```{#lst:awesome-code .c .numberLines caption="課題1のソースコード一部"}
unsigned char hdata[16]={ 0x77,0x41,0x3b,0x6b,0x4d,0x6e,
                          0x7e,0x43,0x7f,0x4f,0x5f,0x7c,
                          0x36,0x79,0x3e,0x1e };
```

### 課題 2

第 1 引数は表示する桁, 第 2 引数は表示する値(0 から 16)を受け取り, 16 進数 1 桁分を表示する関数を作成せよ.

```{#lst:awesome-code .c .numberLines caption="課題2のソースコード一部"}
void printNumberWithDigit(unsigned digit, unsigned number) {
  unsigned char adrs = digit == 1 ? 1 : 3;
  unsigned char x = hdata[number];
  while(U1STAbits.UTXBF!=0);
  U1TXREG=adrs+(x<<4);
  while(U1STAbits.UTXBF!=0);
  U1TXREG=adrs+((x>>4)<<4);
}
```

### 課題 3

#0 から 255 の値を受け取り, 2 桁の 16 進数のデータに分けて, 16 進数 2 桁を表示する関数を, 課題 5 の関数を利用して作成せよ.

```{#lst:awesome-code .c .numberLines caption="課題3のソースコード一部"}
void printNumber(unsigned number) {
  unsigned a = number % 16;
  unsigned b = number / 16;
  printNumberWithDigit(1, a);
  printNumberWithDigit(2, b);
}
```

\clearpage

### 課題 4

LED 表示器に 00 から FF までの 16 進をカウント・アップするプログラムを作成せよ.

```{#lst:awesome-code .c .numberLines caption="課題4のソースコード全文(前半)"}
#include <p30F3013.h>
#include "c:\work\e4exp.h"

unsigned char hdata[16]={ 0x77,0x41,0x3b,0x6b,0x4d,0x6e,
                          0x7e,0x43,0x7f,0x4f,0x5f,0x7c,
                          0x36,0x79,0x3e,0x1e };

void wait(unsigned x) {
  unsigned i, j;
  for (i = 0; i < x; i = i + 1) {
    for (j = 0; j < 60000; j = j + 1){
      asm("nop");
    }
  }
}

void printNumberWithDigit(unsigned digit, unsigned number) {
  unsigned char adrs = digit == 1 ? 1 : 3;
  unsigned char x = hdata[number];
  while(U1STAbits.UTXBF!=0);
  U1TXREG=adrs+(x<<4);
  while(U1STAbits.UTXBF!=0);
  U1TXREG=adrs+((x>>4)<<4);
}

void printNumber(unsigned number) {
  unsigned a = number % 16;
  unsigned b = number / 16;
  printNumberWithDigit(1, a);
  printNumberWithDigit(2, b);
}
```

\clearpage

```{#lst:awesome-code .c .numberLines startFrom="32" caption="課題7のソースコード全文(後半)"}
void main(void) {
  _TRISF6 = 0;       // RF6ポートを出力設定
  U1BRG = 95;
  U1MODE = 0x8000;
  U1STA = 0x0400;

  _RF6 = 0;          // SN74LV8153をリセット
  wait(10);
  _RF6 = 1;          // SN74LV8153 release reset

  while(1) {
    int i = 0;
    for(;i < 256; i++){
      printNum(i);
      wait(60);
    }
  }
}
```

# 検討課題

1. サンプル 1 は `U1MODE = 0x8400;`, サンプル 2 は `U1MODE = 0x8000;` となっている. その理由を説明せよ.

   UART モードレジスタより 15 ビット目は UART の有効化ビットであり, 10 ビット目が入出力選択ビットの役割を果たしていることが分かる.
   ALTIO = 1 のときは U1ATX と U1ARX が, ALTIO = 0 のときは U1TX と U1RX が使われる.
   本実験キットでは PC との通信に USB を介しており, [@fig:cir1], [@fig:cir2] にそれぞれあるように USB-シリアル変換 IC(FT232RL)によって UART 通信が PC と行えるようになっている.
   サンプル 1 では PC にシリアル通信で文字情報を送るため ALTIO が 1 となっているが, サンプル 2 では PC と通信しないため ALTIO が 0 になっている.

2) マイコンのシリアル通信には UART の他に I2C や SPI がある. これについて調べよ.

- I2C(Inter-Integrated Circuit)

  - 主に同じ基板内などのように近距離で直結したデバイスと, 100kbps または 400kbps の速度でシリアル通信を行う
  - マスタ／スレーブ間を, SCL と SDA という２本の線でパーティーライン状に接続する
  - 個々のスレーブがアドレスを持ちデータ中にアドレスが含まれている
  - 1 バイト転送毎に受信側から ACK 信号の返送をして, 互いに確認を取りながらデータ転送を行っている

- SPI(Serial Peripheral Interface)
  - シリアル EEPROM や D/A コンバータなどの周辺 IC を専用のシリアルインタフェースで接続し, 高速の同期式通信を可能とする
  - 2 つの SPI のモジュール(マスタ/スレーブ)が互いに 3 本または 4 本(SS 信号を使う場合)の線で接続する
  - マスタが出力するクロック信号(SCK)を基準にして, 互いに向かい合わせて接続した SDI と SDO で, 同時に 1 ビット毎のデータの送受信を行う
  - SS ピンの HIGH/LOW を切り替えることで通信するスレーブを指定する

# 参考文献

- 山口晶大: PIC マイコン・スタートアップ, CQ 出版社(2009)
- マイコンボードに関する情報 http://www.marutsu.co.jp/shohin_40258/(2011.9.30 現在)
- 電子工作の実験室 http://www.picfun.com/f1/f05.html(2022.07.04 現在)
- 電子工作の実験室 http://www.picfun.com/f1/f06.html(2022.07.04 現在)
