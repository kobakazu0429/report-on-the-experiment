---
header-includes:
# - \usepackage[version=3]{mhchem}
metadata:
  reportInfo:
    subject: ワンチップマイコン基礎実験I
    reportNo: 1
  writer:
    class: E4
    no: 14
    group:
    chief:
    name: 小畠 一泰
  others:
    date: 2020. 12. 09
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

PIC16F84A についてプログラム方法と基本的な入出力制御の習得を目的とする.

# 課題

下記ソースコードを共通部分とし, すべてのソースコードは下記を含むものとする.

```{#lst:awesome-code .c .numberLines caption="共通部分"}
  list p=16F84A
  #include <p16F84A.inc>
  __CONFIG _CP_OFF & _WDT_OFF & _PWRTE_ON & _HS_OSC

  ORG 0x000

  bsf STATUS, RP0 ;バンク0→1に切り替え
  clrf TRISB      ;TRISBをすべて0, 全ビット出力設定に
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

```{#lst:awesome-code .asm .numberLines caption="[課題1] RB1 に接続された LED を点灯させるプログラムを作成せよ"}
  bsf PORTB, 1    ;0番目のLED点灯
  STP goto STP    ;無限ループ
```

```{#lst:awesome-code .asm .numberLines caption="[課題2] List3 の点滅周期を約1秒になるように調整したプログラムを作成せよ"}
TODO
```

```{#lst:awesome-code .asm .numberLines caption="[課題3] List3 の点滅を10回に規定して動作させるプログラムを作成せよ"}
TODO
```

```{#lst:awesome-code .asm .numberLines caption="[課題4] RB0 から RB7 まで順次点灯するように List4 を書き換えよ"}
MAIN
  movlw B'00000001' ;WレジスタにB'00000000'を代入
  movwf PORTB       ;PORTBに値を転送→0番目のLED点灯
  call WAIT         ;時間待ちサブルーチン呼び出し

  movlw B'00000011'
  movwf PORTB
  call WAIT

  movlw B'00000111'
  movwf PORTB
  call WAIT

  movlw B'00001111'
  movwf PORTB
  call WAIT

  movlw B'00011111'
  movwf PORTB
  call WAIT

  movlw B'00111111'
  movwf PORTB
  call WAIT

  movlw B'01111111'
  movwf PORTB
  call WAIT

  movlw B'11111111'
  movwf PORTB
  call WAIT

  goto MAIN         ;無限ループ
```

```{#lst:awesome-code .asm .numberLines caption="[課題5] 課題 4 をローテートを用いる方法に書き換えよ"}
MAIN
  movlw B'00000001' ;WレジスタにB'00000000'を代入
  movwf PORTB       ;PORTBに値を転送→0番目のLED点灯
  call WAIT         ;時間待ちサブルーチン呼び出し
  call SHIFT
  call SHIFT
  call SHIFT
  call SHIFT
  call SHIFT
  call SHIFT
  call SHIFT
  goto MAIN         ;無限ループ

SHIFT
  rlf PORTB         ;左に1つシフト
  addwf PORTB, 1    ;インクリメントしPORTBに値を転送
  call WAIT
  return
```

```{#lst:awesome-code .asm .numberLines caption="[課題6] LED を上位・下位半分ずつ交互に点滅するプログラムを作成せよ"}
;init
  movlw B'00001111' ;WレジスタにB'00000000'を代入
  movwf PORTB       ;PORTBに値を転送→0番目のLED点灯
  call WAIT         ;時間待ちサブルーチン呼び出し
  call WAIT
  call WAIT

MAIN
  swapf PORTB, 1    ;PORTBの上位ビットと下位ビットを交換
  call WAIT
  call WAIT
  call WAIT
  goto MAIN         ;無限ループ
```

```{#lst:awesome-code .asm .numberLines caption="[課題7] List5 をポート A の押されたスイッチに対応して, LED を消灯するように変更せよ"}

movlw B'00011111'   ;下位5ビットを1に
movwf TRISA         ;TRISAに代入, RA0からRA4が入力設定に
movlw B'00000000'   ;Wレジスタにすべて0に
movwf TRISB         ;TRISBをすべて0, 出力設定に
bcf STATUS, RP0     ;バンク1→0に切り替え

clrw                ;Wレジスタをクリア

MAIN
  bcf STATUS,C      ;Cフラグクリア
  movf PORTA, 0     ;入力データをWレジスタに転送
  comf  PORTA, 0    ;PORTAの値を反転させる
  movwf PORTB       ;ポートBに出力
  goto MAIN
```

```{#lst:awesome-code .asm .numberLines caption="[課題8] List5 を対応して点灯する LED を RB1 から RB5 となるように変更せよ"}

movlw B'00011111'   ;下位5ビットを1に
movwf TRISA         ;TRISAに代入, RA0からRA4が入力設定に
movlw B'00000000'   ;Wレジスタにすべて0に
movwf TRISB         ;TRISBをすべて0, 出力設定に
bcf STATUS, RP0     ;バンク1→0に切り替え

clrw                ;Wレジスタをクリア

MAIN
  bcf STATUS,C      ;Cフラグクリア
  movf PORTA, 0     ;入力データをWレジスタに転送
  rlf  PORTA, 0     ;左にシフト
  movwf PORTB       ;ポートBに出力
  goto MAIN
```

\clearpage

# 調査課題

1. 今回使用しているセラミック発振子とクリスタル発振子の長所, 短所を調べよ.

   - セラミック発振子
     - 発振周波数の安定性が高い(水晶振動子と LC もしくは CR 発振回路との中間に位置する)
     - 小型, 軽量(通常の水晶振動子の約 1/2 以下のサイズ)
     - 発振回路の無調整化, 低価格化が可能
       - セラミック発振子は CR, LC など電気的共振を応用したものと異なり, 機械的共振を利用
       - 外部回路や電源電圧の変動などの影響を受けにくい
       - 無調整で高安定な発振回路が得られる
   - クリスタル(水晶)発振子
     - 周波数誤差が少ない(セラミック発振子よりも安定している)
     - Q 値が大きい
     - 均一で安定した高品質材料を確保できる
     - 温度特性も良好で, 弾性率の温度変化と熱膨張率が相殺する関係にあるので, 温度変化に対して特性変動が小さい
     - ウエハーを切り出す方向次第で, さまざまな発振周波数を生み出せる
     - 発振させたときの内部損失が極めて小さい

1. マイコンの入力端子には, 多くの場合プルアップ抵抗もしくはプルダウン抵抗が付けられる.
   今回 RA0〜RA4 はプルダウン, MCLR はプルアップである.
   抵抗値の選択を行う場合留意する点について調べよ.

   ![MCLR](./documents/04/0201-ワンチップマイコン基礎実験I/images/mclr.png){#fig:mclr height=50mm}

   たとえば [@fig:mclr] のように MCLR を利用してリセットを作動させるためには次の条件を満たす必要がある.

   - 抵抗 R: 抵抗での電圧降下が大きくなり過ぎて, 論理の判定が出来なくなってしまわないように $40 \unit{k \ohm}$ 以下であること
   - ダイオード D: 電源が off になった時にリセットが早めにかかるように, 急速にコンデンサ C を放電させる必要があるため容量は大きすぎないこと
   - 抵抗 R1: MCLR 端子にコンデンサからの過電流が流れるのを防止するためのもので, $100 ～ 1 \unit{k \ohm}$ 程度とすること

   このようにプルダウン, プルアップ抵抗には電圧を安定化させるための役割があるが, 入力として使う場合には閾値を上回ったり, 逆に下回ってしまわないように適切な電圧値, 電流値を得る必要がある.
   したがってマイコンや IC のデータシートなどを読み抵抗値を決定しなければならない.

1. マイコンの出力端子では, 電流をプルダウン抵抗に出力するソース出力と電流をプルアップ抵抗などから吸い込むシンク出力の両方もしくはどちらか一方が可能となっている.
   PIC16F84A の端子内部の構造を調べ, 各端子を出力設定とした場合にどのような出力が可能か調べよ(トーテムポール型とオープンドレイン型について理解すること).

   - シンク(吸い込み)ロジック: NPN トランジスタ (主に国内での使用が多い)
   - ソース(吐き出し)ロジック: PNP トランジスタ (主に海外での使用が多い)

   ![トーテムポール型(https://www.slideshare.net/minorunatsutani/kdmsopen-drain より抜粋)](./documents/04/0201-ワンチップマイコン基礎実験I/images/tp.jpg){#fig:tp height=50mm}

   - トーテムポール型
     - VCC と GND 間に 2 つのトランジスターを組み合わせた出力回路
     - 出力にプルアップ抵抗をつけなくてもハイまたはローレベルが確定する
     - シンクとソースの両方が可能

   ![オープンドレイン型(https://www.slideshare.net/minorunatsutani/kdmsopen-drain より抜粋)](./documents/04/0201-ワンチップマイコン基礎実験I/images/od.png){#fig:od height=50mm}

   - オープンドレイン型
     - 出力はローの出力しかできない
     - 信号線をハイにするためにはプルアップ抵抗が必要
     - シンクのみ

   PIC16F84A ではデータシートを見ると RA, RB ピンは次の表のようになっている.

   | Pin Name | Buffer Type | Function                                     |
   | -------- | ----------- | -------------------------------------------- |
   | RA0      | TTL         |                                              |
   | RA1      | TTL         |                                              |
   | RA2      | TTL         |                                              |
   | RA3      | TTL         |                                              |
   | RA4      | ST          | Output is open drain type.                   |
   | RB0      | TTL         | Internal software programmable weak pull-up. |
   | RB1      | TTL         | Internal software programmable weak pull-up. |
   | RB2      | TTL         | Internal software programmable weak pull-up. |
   | RB3      | TTL         | Internal software programmable weak pull-up. |
   | RB4      | TTL         | Internal software programmable weak pull-up. |
   | RB5      | TTL         | Internal software programmable weak pull-up. |
   | RB6      | TTL         | Internal software programmable weak pull-up. |
   | RB7      | TTL         | Internal software programmable weak pull-up. |

   : I/O Pin's Buffer Types {#tbl:id}

   | Symbol   | Characteristic              |    Min |    Max | Units |
   | -------- | --------------------------- | -----: | -----: | :---: |
   | $V_{IL}$ | with TTL buffer             |    VSS |    0.8 |   V   |
   | $V_{IL}$ | with Schmitt Trigger buffer |    VSS | 0.2VDD |   V   |
   | $V_{IH}$ | with TTL buffer             |    2.0 |    VDD |   V   |
   | $V_{IH}$ | with Schmitt Trigger buffer | 0.8VDD |    VDD |   V   |

   : I/O Pin's Threshold {#tbl:id}

1. List3 の WAIT ルーチンにおいて, 変数をクリアしてから減算処理に入っている.
   この理由を説明せよ.
   1. クリアすることで B'00000000'となる.
   1. 減算をすると B'11111111'(D'255') となり, 最大値が得られる.
   1. 最大値を `COUNTER1`, `COUNTER2` で得られたので 255 × 255 の回数分得られる.

\clearpage

# 参考文献

- PIC 命令一覧表(https://www.mlab.im.dendai.ac.jp/~assist/PIC/appendix/instruction/)
- セラミック発振子(セラロック) | 村田製作所(https://www.murata.com/ja-jp/products/timingdevice/ceralock/basic/summary)
- 水晶振動子 | マルツオンライン(https://www.marutsu.co.jp/contents/shop/marutsu/mame/46.html)
- 第 2 回　水晶を発振器に使う 5 つの理由 - EE Times Japan(https://eetimes.jp/ee/articles/1011/24/news121.html)
- PIC16F84A Data Sheet(https://akizukidenshi.com/download/PIC16F84A.pdf)
- リセットの使い方 | 電子工作の実験室 (http://www.picfun.com/pic21.html)
- オープンコレクター出力型とトーテムポール出力型では何が違うのですか ? | 東芝デバイス＆ストレージ株式会社(https://toshiba.semicon-storage.com/jp/semiconductor/knowledge/faq/opto/opto-038.html)
- Kdms 勉強会(open drain)(https://www.slideshare.net/minorunatsutani/kdmsopen-drain)
- RA4 の罠 | PIC の罠(http://mhage.zombie.jp/PicTrap/RA4.html)
- TTL or ST? What is it? | PICBASIC Community Discussion (http://www.picbasic.co.uk/forum/showthread.php?t=8704)
- what is TTL input and Schmitt Trigger input? | microchip Forums(https://www.microchip.com/forums/m103724.aspx)
