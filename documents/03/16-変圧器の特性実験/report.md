---
header-includes:
# - \usepackage[version=3]{mhchem}
metadata:
  reportInfo:
    subject: 変圧器の特性実験
    reportNo: 16
  writer:
    class: E3
    no: 15
    group: 2
    chief:
    name: 小畠 一泰
  others:
    date: 2019. 11. 25
    weather: 曇り
    temp: 18
    wet: 70
  partners:
    collaborator1: 井上　　　　　隆治
    collaborator2: 木下　　　　　拓真
    collaborator3: 重見　　　　　達也
    collaborator4: DANDAR　TUGULDUR
---

# 目的

変圧器は, 交流による送電, 電力変換に欠かせない存在であると共に, 通信分野でも広く利用される.
単相変圧器について, その特性と利用法に関する実験実習を行い, それを理解することを目的とする.

# 使用器具

- SW: コンセント付きスイッチ
- AT: 摺動式単巻変圧器(スライダック $100\unit{V}/0-130\unit{V}$) 型番 B・9 - 187
- V, $V_1, V_2$: 交流電圧計($AC300\unit{V}, 100\unit{V}, 30\unit{V}$) 型番 41, 49, 50
- LCR: LCR メータ DER EE Electrical Instrument CO., Ltd 製 DE-5000 型
- 供試変圧器: (株)菅野電機研究所製 SP-2405 型($100\unit{V}/24,20,16,12\unit{V} (CT)・0.5\unit{A}$), (株)菅野電機研究所製 SP-121 型($100\unit{V}/12,10,8,6\unit{V} (CT)・1\unit{A}$)
- 整流回路 A 及び B
- オシロスコープ DS1BE112600264 BH37H21S00000106

# 実験方法

## 変圧器の極性および変圧比の測定

1. 供試変圧器に対して, [@fig:146] の測定回路結線を行う.
   V(1 次白端子)及び v(2 次黒端子)を短絡し, 交流電圧系は $V_1$ を U(1 次黒端子) - V 間, 電圧計 $V_2$ を u(2 次赤端子) - v 間, 電圧計 V を U- u 間に接続した.
1. $V_1$ を $50 〜 120\unit{V}$ の間を約 $10\unit{V}$ 毎に測定できるようにスライダックを調整し, 各電圧において $V_2$ を測定した.
   また $V_1 = 50, 100\unit{V}$ の 2 点については V も測定した.
1. 測定結果を [@tbl:24V;@tbl:22V;@tbl:20V;@tbl:12V] に記録し, 供試変圧器の極性を判定した.
1. 測定担当を交代し, 別の２次端子について(2), (3)を行った.
   ただし, 電圧計の V の測定は必要ない.
1. 1 次電圧を横軸に, 各端子の 2 次電圧を縦軸にグラフを描き, 特性線上の $V_1 = 100\unit{V}$ の値から変圧比を求めた.
1. 各端子での変圧比を [@tbl:16.2] にまとめた.

![極性および変圧比の測定回路](./documents/16-変圧器の特性実験/images/164.png){#fig:146 width=80mm}

| $V_1 \unit{V}$ | $V_2 \unit{V}$ | $V \unit{V}$ |
| -------------: | -------------: | -----------: |
|           50.0 |           14.0 |         36.0 |
|           60.0 |           16.5 |         43.1 |
|           70.0 |           19.5 |         51.0 |
|           80.0 |           22.1 |         57.9 |
|           90.0 |           25.0 |         64.8 |
|          100.0 |           28.0 |         72.1 |
|          110.0 |           30.5 |         79.0 |
|          120.0 |           33.1 |         86.5 |

: 変圧器の極性と変圧比$24\unit{V}$ {#tbl:24V}

\clearpage

| $V_1 \unit{V}$ | $V_2 \unit{V}$ | $V \unit{V}$ |
| -------------: | -------------: | -----------: |
|           50.0 |           12.5 |         37.5 |
|           60.0 |           15.0 |         44.8 |
|           70.0 |           17.5 |         52.0 |
|           80.0 |           20.0 |         59.5 |
|           90.0 |           23.0 |         67.0 |
|          100.0 |           25.5 |         74.2 |
|          110.0 |           28.0 |         82.0 |
|          120.0 |           30.5 |         89.5 |

: 変圧器の極性と変圧比$22\unit{V}$ {#tbl:22V}

| $V_1 \unit{V}$ | $V_2 \unit{V}$ | $V \unit{V}$ |
| -------------: | -------------: | -----------: |
|           50.0 |           12.0 |         38.1 |
|           60.0 |           14.0 |         46.0 |
|           70.0 |           16.0 |         53.8 |
|           80.0 |           18.3 |         61.7 |
|           90.0 |           21.0 |         68.0 |
|          100.0 |           23.0 |         76.4 |
|          110.0 |           25.5 |         84.2 |
|          120.0 |           27.9 |         92.1 |

: 変圧器の極性と変圧比$20\unit{V}$ {#tbl:20V}

\clearpage

| $V_1 \unit{V}$ | $V_2 \unit{V}$ | $V \unit{V}$ |
| -------------: | -------------: | -----------: |
|           50.0 |            5.0 |         43.5 |
|           60.0 |            8.0 |         51.9 |
|           70.0 |           10.0 |         60.0 |
|           80.0 |           11.0 |         68.2 |
|           90.0 |           12.0 |         77.6 |
|          100.0 |           13.0 |         86.0 |
|          110.0 |           15.0 |         94.8 |
|          120.0 |           16.0 |        103.0 |

: 変圧器の極性と変圧比$20\unit{V}$ {#tbl:12V}

| 定格電圧 $\unit{V}$ | $V_2 \unit{V}$ | 変圧比 |
| ------------------: | -------------: | -----: |
|                  24 |           28.0 |   3.57 |
|                  22 |           25.5 |   3.92 |
|                  20 |           23.0 |   4.35 |
|                  12 |           13.0 |   7.69 |

: 変圧比のまとめ {#tbl:16.2}

\clearpage

## 自己インダクタンス及び相互インダクタンスの測定と結合係数の算出

### 1 次コイルの自己インダクタンス測定

1. 1 次コイルの両端子に LCR メータを接続し, LCR ボタンにより測定モード $L_s$ に変更し, 測定周波数 $f=1\unit{kHz}$ の自己インダクタンス $L_1$ を測定した.
   FREQ ボタンを押して測定周波数を変え, $f=10k, 100k, 100, 120\unit{Hz}$の順に変化するのでこれを測定した.
   測定モードが変わってしまうと正確な測定が出来ないため, 測定モード $L_s$ かどうかをチェックしておくこと.
1. 測定結果を [@tbl:16.3] に記録した.

|      測定周波数 f $\unit{Hz}$      |     100 |     120 |      1k |    10k |  100k |
| :--------------------------------: | ------: | ------: | ------: | -----: | ----: |
| 自己インダクタンス $L_1 \unit{mH}$ | 2195.00 | 2141.00 | 1503.40 | 154.09 | 10.69 |

: 各周波数での 1 次コイル自己インダクタンス {#tbl:16.3}

### 2 次コイルの自己インダクタンス及び相互インダクタンス測定

1. FREQ ボタンを押していき, 測定周波数を $f=100\unit{Hz}$ として担当する 2 次側端子間(赤, 黄, 緑, 白 - 黒)の自己インダクタンス$L_2$を測定した.
1. 1 次コイルと 2 次コイルを [@fig:165] の 2 とおりに接続し, 測定周波数を変更せずにそれぞれのインダクタンス値を測定した.
   このとき, 大きい値を$L_1 + L_2 + 2M$ とし, 小さい値を$L_1+ L_2 - 2M$ とした.
1. 測定結果を [@tbl:16.4] に記録し, 相互インダクタンス及び結合係数の算出を行った, また, $\frac{L_1}{L_2}$比から巻数比 n の算出を行った.
   ($\frac{L_1}{L_2} \propto n^2)$
1. 次の担当と後退して (1)〜(3) を行い, [@tbl:16.4] を完成させた.

![相互インダクタンス測定回路(極力短<Y端子で配線)](./documents/16-変圧器の特性実験/images/165.png){#fig:165 width=80mm}

| 定格電圧 $\unit{V}$ | 変圧比 $\frac{V_1}{V_2}$ | $L_1 \unit{mH}$ | $L_2 \unit{mH}$ | \fracTable{$L_1+L_2$}{$+2M$} | \fracTable{$L_1+L_2$}{$-2M$} | M $\unit{mH}$ |     k |     n |
| ------------------: | -----------------------: | --------------: | --------------: | ---------------------------: | ---------------------------: | ------------: | ----: | ----: |
|                  24 |                     3.57 |         2195.00 |          192.25 |                      3452.00 |                      1199.50 |        563.13 | 0.867 | 3.379 |
|                  22 |                     3.92 |         2195.00 |          162.07 |                      3333.00 |                      1266.70 |        516.58 | 0.866 | 3.680 |
|                  20 |                     4.35 |         2195.00 |          134.10 |                      3211.00 |                      1339.20 |        467.95 | 0.863 | 4.046 |
|                  12 |                     7.69 |         2195.00 |           45.78 |                      2767.00 |                      1659.40 |        276.90 | 0.874 | 6.924 |

: 相互インダクタンスおよび結合係数($f=100\unit{Hz}$) {#tbl:16.4}

\clearpage

## CT 付変圧器の全波整流回路の測定

供試変圧器は複数の 2 次端子をもつマルチタップ変圧器であるが, 2 次側白端子は CT(Center Tap)となっている.
全巻数の中央に接続され CT 端子から 2 次側端子 u(赤)及び v(黒)の電位を見た時, 全 2 次電圧の半分の振幅で位相が逆の 2 つの正弦波形を示す.
これを使って全波整流の波形を観測した.

1. [@fig:a] のように測定回路の結線を行い, 整流回路基板 A または B を 2 次側(赤, 白, 黒)端子に挿入して接続した.
1. オシロスコープを整流基板出力端子に接続し, スライダックの調整ダイアルを 50V の位置に調整した後, 入力電圧及び出力電圧の波形を観測した.
   ただし, プローブの GND 端子は下図の GND に必ず 1 本のみ接続し, 基板 A では 3ch, 基板 B では 4ch を使って波形を表示させ, これを画像データとして取り込んだ.

![(a)CT付変圧器の整流波形測定回路](./documents/16-変圧器の特性実験/images/a.png){#fig:a width=80mm}

\clearpage

![(b)整流回路基板A](./documents/16-変圧器の特性実験/images/b.png){#fig:b width=80mm}

![(c)整流回路基板B](./documents/16-変圧器の特性実験/images/c.png){#fig:c width=80mm}

![基板A](./documents/16-変圧器の特性実験/images/NewFile0.png){#fig:NewFile0 width=80mm}

![基板B](./documents/16-変圧器の特性実験/images/NewFile1.png){#fig:NewFile1 width=80mm}

\clearpage

# 考察及び検討

1. 1 次電圧に変換した変圧器の等価回路について示し, 各要素(各抵抗値, インダクタンス)について説明せよ.

   ![簡易等価回路](./documents/16-変圧器の特性実験/images/簡易等価回路.png){width=80mm}

   ![一次換算等価回路](./documents/16-変圧器の特性実験/images/一次換算等価回路.png){width=80mm}

1. 2.2.1 の測定結果について考察せよ.
   また, 1.の内容とどう関わるかを説明せよ.

   [@tbl:16.3] より周波数を大きくするにつれて, 自己インダクタンスの値は小さくなることがわかった.
   これは周波数によって変圧比を変化させないためだと考えられる.

1. 総合的考察を行え.

   実験中に電圧計のレンジの設定ミスで期待される値と大きく異なったが, 再度確認し、設定し直すことで期待どおりの値を得ることができたのでよかった.

# 参考文献

1. 宇野幸一, 磯部直吉：改訂　交流回路, 東京電機大学出版
1. 電気学会：電気機器工学 Ⅰ(改訂版), (社)電気学会・(株)オーム社
1. I 変圧器の原理と等価回路(https://www.denkishoin.co.jp/products/file_download.php?id=105)

\clearpage
