---
header-includes:
# - \usepackage[version=3]{mhchem}
metadata:
  reportInfo:
    subject: ワンチップマイコン基礎実験II
    reportNo: 1
  writer:
    class: E4
    no: 14
    group:
    chief:
    name: 小畠 一泰
  others:
    date: 2020. 12. 23
    weather: 晴れ
    temp: 24.0
    wet: 65.5
  partners:
    collaborator1:
    collaborator2:
    collaborator3:
    collaborator4:
---

# 目的

PIC16F84A を例に「プログラムカウンタの利用」と「割り込み処理」について理解し, 7 セグメント LED の使用方法に習熟することを, また後半では, サウンダを駆動することを目的とする.

# 課題

下記ソースコードを共通部分とし, すべてのソースコードは下記を含むものとする.

```{#lst:awesome-code .c .numberLines caption="共通部分"}
  list p=16F84A
  #include <p16F84A.inc>
  __CONFIG _CP_OFF & _WDT_OFF & _PWRTE_ON & _HS_OSC

  ORG 0x000

  bsf STATUS, RP0 ;バンク0→1に切り替え
  clrf TRISB      ;TRISBをすべて0、全ビット出力設定に
  bcf STATUS, RP0 ;バンク1→0に切り替え

  clrf PORTB      ;すべて消灯
```

また下記を標準タイマーとし, 明示しない限りこれらも含み使用できるものとする.

```{#lst:awesome-code .c .numberLines caption="タイマー"}
  COUNTER1 EQU 0x0C  ;作業用変数の設定
  COUNTER2 EQU 0x0D  ;汎用ファイルレジスタ0Chから

  WAIT clrf COUNTER1 ;変数1をクリア

WAIT1
  clrf COUNTER2      ;変数2をクリア
  call WAIT2         ;さらにサブルーチンへ
  decfsz COUNTER1, 1 ;変数から1を引く
  goto WAIT1         ;結果が0でなければ実行
  return             ;結果が0ならばスキップしこの行を実行

WAIT2
  decfsz COUNTER2, 1 ;サブルーチンのサブルーチン
  goto WAIT2
  return
```

```{#lst:awesome-code .asm .numberLines caption="[課題1] 表1を完成させ, List6 の欠落している部分を補いプログラムを完成させよ"}
movlw B'00011111'   ;下位5ビットを1に
movwf TRISA         ;TRISAに代入、RA0からRA4が入力設定に
movlw B'00000000'   ;Wレジスタにすべて0に
movwf TRISB         ;TRISBをすべて0、出力設定に
bcf STATUS, RP0     ;バンク1→0に切り替え

clrw                ;Wレジスタをクリア

MAIN
  bcf STATUS,C      ;Cフラグクリア
  movf PORTA, 0     ;入力データをWレジスタに転送
  call SS_Data  ;7セグLED点灯データ取得ルーチンに
  movwf PORTB       ;データ表示
  goto MAIN

;7セグLED点灯データ取得ルーチン
SS_Data
  addwf PCL,1       ;W+PCL(プログラムカウンタの下位)→PCL
  retlw B'00111111' ;W =  0→左の点灯データをWレジスタが持って帰る
  retlw B'00000110' ;W =  1→左の点灯データをWレジスタが持って帰る
  retlw B'01011011' ;W =  2
  retlw B'01001111' ;W =  3
  retlw B'01100110' ;W =  4
  retlw B'01101101' ;W =  5
  retlw B'01111101' ;W =  6
  retlw B'00000111' ;W =  7
  retlw B'01111111' ;W =  8
  retlw B'01101111' ;W =  9
  retlw B'01110111' ;W = 10→"A"のデータを持って帰る
  retlw B'01111100' ;W = 11→"b"のデータを持って帰る
  retlw B'01011000' ;W = 12→"c"のデータを持って帰る
  retlw B'01011110' ;W = 13→"d"のデータを持って帰る
  retlw B'01111001' ;W = 14→"E"のデータを持って帰る
  retlw B'01110001' ;W = 15→"F"のデータを持って帰る

  END
```

```{#lst:awesome-code .asm .numberLines caption="[課題2] 各自が自由に割り込み処理を確認するプログラムを作成せよ"}
;割り込みサブルーチンのみ抜粋(他はList 7と同じ)
SUB
  nop

  movlw 0x01
  andwf PORTB,1 ;PORTBのRB0以外をクリア
  call WAIT
  movlw 0x08    ;RB3のみ1
  addwf PORTB,1 ;Wを加算してPORTBに上書き、RB4のみ1
  call WAIT

  movlw 0x01
  andwf PORTB,1
  call WAIT
  movlw 0x04    ;RB2のみ1
  addwf PORTB,1
  call WAIT;

  nop
  return
```

```{#lst:awesome-code .asm .numberLines caption="[課題3] 1kHz のパルス(0.5ms を ON, 0.5ms を OFF)を RA3 に出力するプログラム"}
  clrf TRISA  ;TRISAをすべて0, 全ビット出力設定に
  clrf PORTA

MAIN
  bsf PORTA, 3       ;RA3をON
  call WAIT          ;0.5ms待機

  bcf PORTA, 3       ;RA3をOFF
  call WAIT          ;0.5ms待機

  goto MAIN          ;無限ループ

WAIT
  movlw D'249'
  movwf COUNTER1     ;変数1をクリア

WAIT1
  nop
  nop
  decfsz COUNTER1, 1 ;変数から1を引く
  goto WAIT1         ;結果が0でなければ実行
  return             ;結果が0ならばスキップしこの行を実行
```

```{#lst:awesome-code .asm .numberLines caption="[課題4] メロディを作成せよ(その1)"}
  COUNTER1 EQU 0x0C;
  COUNTER2 EQU 0x0D;
  COUNTER3 EQU 0x0E;
  COUNTER4 EQU 0x0F;
  COUNTER5 EQU 0x10;
  COUNTER6 EQU 0x11;
  COUNTER7 EQU 0x12;
  COUNTER8 EQU 0x13;
  COUNTER9 EQU 0x14;

  ORG 0x000

  bsf STATUS, RP0
  clrf TRISA
  bcf STATUS, RP0
  clrf PORTA

MAIN
  call PLAY_C
  call PLAY_D
  call PLAY_E
  goto MAIN

;==== IF ====
PLAY_C
  clrf COUNTER7
  call PLAY_C_

PLAY_D
  clrf COUNTER8
  call PLAY_D_

PLAY_E
  clrf COUNTER9
  call PLAY_E_
```

```{#lst:awesome-code .asm .numberLines caption="[課題4] メロディを作成せよ(その2)"}
;==== private methods ====
PLAY_C_
  bsf PORTA, 3
  call WAIT1
  bcf PORTA, 3
  call WAIT1
  decfsz COUNTER7, 1
  goto PLAY_C_
  return

PLAY_D_
  bsf PORTA, 3
  call WAIT4
  bcf PORTA, 3
  call WAIT4
  decfsz COUNTER8, 1
  goto PLAY_D_
  return

PLAY_E_
  bsf PORTA, 3
  call WAIT7
  bcf PORTA, 3
  call WAIT7
  decfsz COUNTER9, 1
  goto PLAY_E_
  return

;==== timer ====
;==== timer - C ====
WAIT1
  movlw D'176'
  movwf COUNTER1

WAIT2
  movlw D'02'
  movwf COUNTER2
  call WAIT3
  decfsz COUNTER1, 1
  goto WAIT2
  return

WAIT3
  decfsz COUNTER2, 1
  goto WAIT3
  return
```

```{#lst:awesome-code .asm .numberLines caption="[課題4] メロディを作成せよ(その3)"}
;==== timer - D ====

WAIT4
  movlw D'160'
  movwf COUNTER3

WAIT5
  movlw D'02'
  movwf COUNTER4
  call WAIT6
  decfsz COUNTER3, 1
  goto WAIT5
  return

WAIT6
  decfsz COUNTER4, 1
  goto WAIT6
  return

;==== timer - E ====

WAIT7
  movlw D'144'
  movwf COUNTER5

WAIT8
  movlw D'02'
  movwf COUNTER6
  call WAIT9
  decfsz COUNTER5, 1
  goto WAIT8
  return

WAIT9
  decfsz COUNTER6, 1
  goto WAIT9
  return
```

\clearpage

# 調査課題

1. PIC16F84A の EEPROM(Electrically Erasable and Programmable Read Only Memory)はレジスタファイル空間に直接マッピングされていないので, 特殊機能レジスタを通じて間接的にアドレスしてリード/ライトします.
   この使い方(書き込み, 読み出し)の手順について調べ, プログラム例を示して説明せよ.
1. 7 セグメント LED を 2 桁表示させる方法について, 回路図を”bsch”などを用いて描き, 上位桁に 1, 下位桁に 2 を表示するプログラムを作成せよ.
1. 割り込み条件はいくつもあるが, PIC16F84A に許可されている割り込み条件のうち,「ポート RB0 からの外部割込み」「TMR0 カウンタオーバフロー内部割込み」, それぞれに対する特殊レジスタの設定について説明せよ.
1. W レジスタの復帰や出力ビットの書き換えにおいて, swapf 命令や addwf 命令を使う理由を述べよ.
1. 今まで実験で行った内容以外の PIC を使用した新しい動作の実験テーマや動作・内容を提案せよ.
   (例)押すボタン・回数を指定してロックをかける電子錠など

\clearpage

# 参考文献

- 特集電脳ガシェット’Pi’でラピッド・プログラミング, トランジスタ技術, 2016 年 6 月号 pp.56-128
- PIC 命令一覧表(https://www.mlab.im.dendai.ac.jp/~assist/PIC/appendix/instruction/)
- セラミック発振子(セラロック) | 村田製作所(https://www.murata.com/ja-jp/products/timingdevice/ceralock/basic/summary)
- 水晶振動子 | マルツオンライン(https://www.marutsu.co.jp/contents/shop/marutsu/mame/46.html)
- 第 2 回　水晶を発振器に使う 5 つの理由 - EE Times Japan(https://eetimes.jp/ee/articles/1011/24/news121.html)
