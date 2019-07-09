---
header-includes:
# - \usepackage[version=3]{mhchem}
metadata:
  reportInfo:
    subject: ディジタル論理回路演習I:入出力編
    reportNo: 10
  writer:
    class: E3
    no: 15
    group: 6
    chief:
    name: 小畠 一泰
  others:
    date: 2019. 07. 09
    weather: 晴れ
    temp: 25.5
    wet: 48
  partners:
    collaborator1: 大橋 りさ
    collaborator2: 二重谷 光輝
    collaborator3: 森 和也
    collaborator4: DANDAR TUGULDUR
---

# 目的

論理回路の入出力について, 回路シミュレータ TINA を使用して演習を行うことで, 論理回路の基礎とシミュレータの操作方法を習得する.

# 課題

## プルアップ抵抗を用いた入力回路

![プルアップ抵抗を用いた入力回路](./documents/10-ディジタル論理回路演習I:入出力編/images/10.9.bmp){#fig:10.9 height=50mm}

| SW1 | SW2 | L1  |
| :-: | :-: | :-: |
| OFF | OFF |  0  |
| ON  | OFF |  1  |
| OFF | ON  |  1  |
| ON  | ON  |  1  |

: 真理値表

\clearpage

## プルダウン抵抗を用いた入力回路

![プルダウン抵抗を用いた入力回路](./documents/10-ディジタル論理回路演習I:入出力編/images/10.10.bmp){#fig:10.10 height=50mm}

| SW1 | SW2 | L1  |
| :-: | :-: | :-: |
| OFF | OFF |  1  |
| ON  | OFF |  1  |
| OFF | ON  |  1  |
| ON  | ON  |  0  |

: 真理値表

\clearpage

## High-Low スイッチ入力回路

![High-Low スイッチ入力回路](./documents/10-ディジタル論理回路演習I:入出力編/images/10.11.bmp){#fig:10.11 height=50mm}

| SW1 | SW2 | L1  |
| :-: | :-: | :-: |
| OFF | OFF |  1  |
| ON  | OFF |  1  |
| OFF | ON  |  1  |
| ON  | ON  |  0  |

: 真理値表

\clearpage

## ソースロード出力

![ソースロード出力](./documents/10-ディジタル論理回路演習I:入出力編/images/10.12.bmp){#fig:10.12 height=50mm}

| SW1 | SW2 | L1  |
| :-: | :-: | :-: |
| OFF | OFF |  1  |
| ON  | OFF |  1  |
| OFF | ON  |  1  |
| ON  | ON  |  0  |

: 真理値表

\clearpage

## シンクロード出力

![シンクロード出力](./documents/10-ディジタル論理回路演習I:入出力編/images/10.13.bmp){#fig:10.13 height=50mm}

| SW1 | SW2 | L1  |
| :-: | :-: | :-: |
| OFF | OFF |  0  |
| ON  | OFF |  0  |
| OFF | ON  |  0  |
| ON  | ON  |  1  |

: 真理値表

\clearpage

## オープンコレクタ型

![オープンコレクタ型](./documents/10-ディジタル論理回路演習I:入出力編/images/10.14.bmp){#fig:10.14 height=50mm}

| SW1 | SW2 | L1  |
| :-: | :-: | :-: |
| OFF | OFF |  1  |
| ON  | OFF |  1  |
| OFF | ON  |  1  |
| ON  | ON  |  0  |

: 真理値表

\clearpage

## [@fig:10.9] を NOR ゲートに置き換えた回路

![[@fig:10.9] をNORゲートに置き換えた回路](./documents/10-ディジタル論理回路演習I:入出力編/images/nor-10.9.bmp){#fig:nor-10.9 height=50mm}

| SW1 | SW2 | L1  |
| :-: | :-: | :-: |
| OFF | OFF |  0  |
| ON  | OFF |  1  |
| OFF | ON  |  1  |
| ON  | ON  |  1  |

: 真理値表

\clearpage

## [@fig:10.10] を NOR ゲートに置き換えた回路

![[@fig:10.10] をNORゲートに置き換えた回路](./documents/10-ディジタル論理回路演習I:入出力編/images/nor-10.10.bmp){#fig:nor-10.10 height=50mm}

| SW1 | SW2 | L1  |
| :-: | :-: | :-: |
| OFF | OFF |  1  |
| ON  | OFF |  0  |
| OFF | ON  |  0  |
| ON  | ON  |  0  |

: 真理値表

\clearpage

## [@fig:10.11] を NOR ゲートに置き換えた回路

![[@fig:10.11] をNORゲートに置き換えた回路](./documents/10-ディジタル論理回路演習I:入出力編/images/nor-10.11.bmp){#fig:nor-10.11 height=50mm}

| SW1 | SW2 | L1  |
| :-: | :-: | :-: |
| OFF | OFF |  1  |
| ON  | OFF |  0  |
| OFF | ON  |  0  |
| ON  | ON  |  0  |

: 真理値表

\clearpage

## [@fig:10.12] を NOR ゲートに置き換えた回路

![[@fig:10.12] をNORゲートに置き換えた回路](./documents/10-ディジタル論理回路演習I:入出力編/images/nor-10.12.bmp){#fig:nor-10.12 height=50mm}

| SW1 | SW2 | L1  |
| :-: | :-: | :-: |
| OFF | OFF |  1  |
| ON  | OFF |  0  |
| OFF | ON  |  0  |
| ON  | ON  |  0  |

: 真理値表

\clearpage

## [@fig:10.13] を NOR ゲートに置き換えた回路

![[@fig:10.13] をNORゲートに置き換えた回路](./documents/10-ディジタル論理回路演習I:入出力編/images/nor-10.13.bmp){#fig:nor-10.13 height=50mm}

| SW1 | SW2 | L1  |
| :-: | :-: | :-: |
| OFF | OFF |  0  |
| ON  | OFF |  1  |
| OFF | ON  |  1  |
| ON  | ON  |  1  |

: 真理値表

\clearpage

## 7 セグメント LED 回路

![7セグメント配置](./documents/10-ディジタル論理回路演習I:入出力編/images/digit.png){#fig:digit height=50mm}

![7 セグメント LED 回路](./documents/10-ディジタル論理回路演習I:入出力編/images/10.15.bmp){#fig:10.15 height=50mm}

\clearpage

|  a  |  b  |  c  |  d  |  e  |  f  |  g  | DP  | 数字 |
| :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :--: |
|  0  |  0  |  0  |  0  |  0  |  0  |  1  |  1  |  0   |
|  1  |  0  |  0  |  1  |  1  |  1  |  1  |  1  |  1   |
|  0  |  0  |  1  |  0  |  0  |  1  |  0  |  1  |  2   |
|  0  |  0  |  0  |  0  |  1  |  1  |  0  |  1  |  3   |
|  1  |  0  |  0  |  1  |  1  |  0  |  0  |  1  |  4   |
|  0  |  1  |  0  |  0  |  1  |  0  |  0  |  1  |  5   |
|  0  |  1  |  0  |  0  |  0  |  0  |  0  |  1  |  6   |
|  0  |  0  |  0  |  1  |  1  |  0  |  1  |  1  |  7   |
|  0  |  0  |  0  |  0  |  0  |  0  |  0  |  1  |  8   |
|  0  |  0  |  0  |  0  |  1  |  0  |  0  |  1  |  9   |
|  0  |  0  |  0  |  1  |  0  |  0  |  0  |  1  |  A   |
|  1  |  1  |  0  |  0  |  0  |  0  |  0  |  1  |  b   |
|  0  |  1  |  1  |  0  |  0  |  0  |  1  |  1  |  C   |
|  1  |  0  |  0  |  0  |  0  |  1  |  0  |  1  |  d   |
|  0  |  1  |  1  |  0  |  0  |  0  |  0  |  1  |  E   |
|  0  |  1  |  1  |  1  |  0  |  0  |  0  |  1  |  F   |

: スイッチパターン

\clearpage

## デコーダ IC を用いた回路

![デコーダ IC を用いた回路](./documents/10-ディジタル論理回路演習I:入出力編/images/10.16.bmp){#fig:10.16 height=50mm}

|  A  |  B  |  C  |  D  | 数字 |
| :-: | :-: | :-: | :-: | :--: |
|  0  |  0  |  0  |  0  |  0   |
|  1  |  0  |  0  |  0  |  1   |
|  0  |  1  |  0  |  0  |  2   |
|  1  |  1  |  0  |  0  |  3   |
|  0  |  0  |  1  |  0  |  4   |
|  1  |  0  |  1  |  0  |  5   |
|  0  |  1  |  1  |  0  |  6   |
|  1  |  1  |  1  |  0  |  7   |
|  0  |  0  |  0  |  1  |  8   |
|  1  |  0  |  0  |  1  |  9   |

: スイッチパターン

\clearpage

## HEX 表示器

![HEX 表示器](./documents/10-ディジタル論理回路演習I:入出力編/images/10.19.bmp){#fig:10.19 height=50mm}

|  0  |  1  |  2  |  3  | 表示 |
| :-: | :-: | :-: | :-: | :--: |
|  0  |  0  |  0  |  0  |  0   |
|  1  |  0  |  0  |  0  |  1   |
|  0  |  1  |  0  |  0  |  2   |
|  1  |  1  |  0  |  0  |  3   |
|  0  |  0  |  1  |  0  |  4   |
|  1  |  0  |  1  |  0  |  5   |
|  0  |  1  |  1  |  0  |  6   |
|  1  |  1  |  1  |  0  |  7   |
|  0  |  0  |  0  |  1  |  8   |
|  1  |  0  |  0  |  1  |  9   |
|  0  |  1  |  0  |  1  |  A   |
|  0  |  0  |  1  |  1  |  C   |
|  1  |  0  |  0  |  1  |  d   |
|  0  |  1  |  1  |  1  |  E   |
|  1  |  1  |  1  |  1  |  F   |
|  1  |  1  |  0  |  1  |  b   |

: スイッチパターン

\clearpage

## デコーダ 7442

![デコーダ 7442](./documents/10-ディジタル論理回路演習I:入出力編/images/10.20.bmp){#fig:10.20 height=50mm}

|  A  |  B  |  C  |  D  |    結果    |
| :-: | :-: | :-: | :-: | :--------: |
|  0  |  0  |  0  |  0  | 0 のみ消灯 |
|  1  |  0  |  0  |  0  | 1 のみ消灯 |
|  0  |  1  |  0  |  0  | 2 のみ消灯 |
|  1  |  1  |  0  |  0  | 3 のみ消灯 |
|  0  |  0  |  1  |  0  | 4 のみ消灯 |
|  1  |  0  |  1  |  0  | 5 のみ消灯 |
|  0  |  1  |  1  |  0  | 6 のみ消灯 |
|  1  |  1  |  1  |  0  | 7 のみ消灯 |
|  0  |  0  |  0  |  1  | 8 のみ消灯 |
|  1  |  0  |  0  |  1  | 9 のみ消灯 |

: スイッチパターン

\clearpage

# 研究

7 セグメント LED にはアノードコモンとカソードコモンがある.
その理由を説明せよ.

一般的な LED はアノードとカソードの 2 端子からなる.
7 セグメント LED では 7 セグメント+DP 部分で $(7 + 1) \times 2 = 16$ となる.
しかしアノードコモン(カソードコモン)にするとコモン端子 + 制御端子の 8 ピンとなるので, ピン数が少なくて済み, 効率よく使用できるようになる.
