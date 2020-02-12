---
header-includes:
# - \usepackage[version=3]{mhchem}
metadata:
  reportInfo:
    subject: 発光ダイオードとフォトトランジスタ実験
    reportNo: 11
  writer:
    class: E3
    no: 15
    group: 2
    chief:
    name: 小畠 一泰
  others:
    date: 2020. 01. 20
    weather: 曇り
    temp: 22.3
    wet: 53.5
  partners:
    collaborator1: 井上　　　　　隆治
    collaborator2: 木下　　　　　拓真
    collaborator3: 重見　　　　　達也
    collaborator4: DANDAR　TUGULDUR
---

# 目的

発光ダイオードとフォトトランジスタの実験を行うことで光デバイスの基礎を学ぶとともに, フォトカプラフォトインタラプタの使用方法を理解することを目的とする.

# 実験方法と結果の整理

## 使用器具

1. ディジタルオシロスコープ(RIGOL DS1074B)
1. 発振器(NF1915)
1. 光パワーメータ(サンワ, 12030201091)
1. 直流スイッチング電源($5 \unit{V}$, F-3)
1. 実験キット
1. 直流電流計 A: $30\unit{mA}, 3\unit{mA}$(YOKOGAWA, 23, 25)
1. スライド抵抗器 VR: $4800\unit{\ohm}$(YOKOGAWA)と$330\unit{\ohm}$(YAMABISHI)を直列接続
1. スイッチ SW

\clearpage

## 発行ダイオードの発光強度

図 11.1 の回路により, 順電流に対する赤外線放射強度を測定した.
光パワーメータは直読校正波長が 633$\unit{nm}$であるから, 赤外線のピーク波長が 940$\unit{nm}$の場合 0.72 倍して補正した.
特性を図 11.2 のように両対数グラフに描いた.

![測定回路](./documents/11-発光ダイオードとフォトトランジスタ実験/images/1108.jpeg){#fig:1108 width=80mm}

| 電流$\unit{mA}$ | 電力$\unit{\micro W}$ | $\lambda$ |
| --------------: | --------------------: | --------: |
|            0.70 |                  3.17 |     2.282 |
|            1.00 |                  5.83 |     4.198 |
|            1.40 |                  9.45 |     6.804 |
|            2.00 |                 15.09 |    10.865 |
|            3.00 |                 25.40 |    18.288 |
|            5.00 |                 46.80 |    33.696 |
|            8.00 |                 79.10 |    56.952 |
|           10.00 |                102.90 |    74.088 |
|           15.00 |                155.50 |   111.960 |
|           18.00 |                189.10 |   136.152 |

\clearpage

![順電流と赤外線放射強度](./documents/11-発光ダイオードとフォトトランジスタ実験/images/1109-graph.png){#fig:1109-graph width=120mm}

## フォトトランジスタの光電流特性

![測定回路](./documents/11-発光ダイオードとフォトトランジスタ実験/images/1110.jpeg){#fig:1110 width=90mm}

\clearpage

![入射強度と光電流](./documents/11-発光ダイオードとフォトトランジスタ実験/images/1111-graph.png){#fig:1111-graph width=120mm}

| $I \unit{\micro A}$ | $E \unit{mW}$ |
| ------------------: | ------------: |
|               2.282 |         0.019 |
|               4.198 |         0.024 |
|               6.804 |         0.042 |
|              10.865 |         0.078 |
|              18.288 |         0.120 |
|              33.696 |         0.230 |
|              56.952 |         0.400 |
|              74.088 |         0.515 |
|             111.960 |         0.800 |
|             136.152 |         0.965 |

\clearpage

## フォトカプラ実験

[@fig:1112] の回路を組み, $t_r, t_f$ をオシロスコープで観測した.
入力波形は矩形波 $5\unit{V}$($0 〜 +5\unit{V}$, オフセットに注意)とした.

![フォトカプラ実験回路](./documents/11-発光ダイオードとフォトトランジスタ実験/images/1112.jpeg){#fig:1112 width=100mm}

\clearpage

1. TLN103A と TPS603A の組み合わせについて, $1\unit{kHz}, 10\unit{kHz}$ で実験を行った.

   $RD = 200 \unit{\ohm}, RL = 1 \unit{k \ohm}$

   ![$1\unit{kHz} - t_r$](./documents/11-発光ダイオードとフォトトランジスタ実験/images/01-1ktr.png){#fig:01-1ktr width=100mm}

   ![$1\unit{kHz} - t_f$](./documents/11-発光ダイオードとフォトトランジスタ実験/images/01-1ktf.png){#fig:01-1ktf width=100mm}

   ![$10\unit{kHz} - t_r$](./documents/11-発光ダイオードとフォトトランジスタ実験/images/01-10ktr.png){#fig:01-10ktr width=100mm}

   ![$10\unit{kHz} - t_f$](./documents/11-発光ダイオードとフォトトランジスタ実験/images/01-10ktf.png){#fig:01-10ktf width=100mm}

   \clearpage

1. フォトカプラ PC817 について, $1\unit{kHz}, 10\unit{kHz}$ で実験を行った.

   $RD = 3.5 \unit{k \ohm}, RL = 1 \unit{k \ohm}$

   ![$1\unit{kHz} - t_r$](./documents/11-発光ダイオードとフォトトランジスタ実験/images/02-1ktr.png){#fig:02-1ktr width=100mm}

   ![$1\unit{kHz} - t_f$](./documents/11-発光ダイオードとフォトトランジスタ実験/images/02-1ktf.png){#fig:02-1ktf width=100mm}

   ![$10\unit{kHz} - t_r$](./documents/11-発光ダイオードとフォトトランジスタ実験/images/02-10ktr.png){#fig:02-10ktr width=100mm}

   ![$10\unit{kHz} - t_f$](./documents/11-発光ダイオードとフォトトランジスタ実験/images/02-10ktf.png){#fig:02-10ktf width=100mm}

   \clearpage

1. フォトインタラプタ TLP908LB について, $100\unit{Hz}, 1\unit{kHz}$ で実験を行った.

   $RD = 381 \unit{\ohm}, RL = 10 \unit{k \ohm}$

   ![$100\unit{Hz} - t_r$](./documents/11-発光ダイオードとフォトトランジスタ実験/images/03-100tr.png){#fig:03-100tr width=100mm}

   ![$100\unit{Hz} - t_f$](./documents/11-発光ダイオードとフォトトランジスタ実験/images/03-100tf.png){#fig:03-100tf width=100mm}

   ![$1\unit{kHz} - t_r$](./documents/11-発光ダイオードとフォトトランジスタ実験/images/03-1ktr.png){#fig:03-1ktr width=100mm}

   ![$1\unit{kHz} - t_f$](./documents/11-発光ダイオードとフォトトランジスタ実験/images/03-1ktf.png){#fig:03-1ktf width=100mm}

   \clearpage

1. フォトインタラプタ PS4005 について, $100\unit{Hz}, 1\unit{kHz}$ で実験を行った.

   $RD = 1.8 ｋ \unit{\ohm}, RL = 1 \unit{k \ohm}$

   ![$100\unit{Hz} - t_r$](./documents/11-発光ダイオードとフォトトランジスタ実験/images/04-100tr.png){#fig:04-100tr width=100mm}

   ![$100\unit{Hz} - t_f$](./documents/11-発光ダイオードとフォトトランジスタ実験/images/04-100tf.png){#fig:04-100tf width=100mm}

   ![$1\unit{kHz} - t_r$](./documents/11-発光ダイオードとフォトトランジスタ実験/images/04-1ktr.png){#fig:04-1ktr width=100mm}

   ![$1\unit{kHz} - t_f$](./documents/11-発光ダイオードとフォトトランジスタ実験/images/04-1ktf.png){#fig:04-1ktf width=100mm}

   \clearpage

\clearpage

# 検討課題

1. フォトカプラを使用する場合の注意点を列挙せよ.

   - コレクタ遮断電流は, 動作周囲温度が $25 \unit{\celsius}$ 上昇するごとにおよそ１桁大きくなるため, 動作周囲温度に注意する必要がある.
   - 小さな電流はノイズや回路部品のリーク電流として発生しやすく, 特に高温で増えて, フォトカプラの誤動作の原因となるため注意する必要がある.

2. フォトインタラプタを使用する用途を TLP908 と PS4005 の場合について考えよ.

   - TLP908 は反射型フォトインタラプタ（フォトリフレクタ）の一種で, 発光素子と受光素子を同一面に配置, 検出物体の反射光によって物体の存在（有無）・位置を検知できる.
   - PS4005 は透過型フォトセンサの一種で, 発光素子と受光素子を 1 つのパッケージに対向して並べ, その間を検出物体が光をさえぎることにより, 検出機能を持っている.
     その間を検出物が通過するとき光を遮ることにより物体の有無を検出する光スイッチで, 機械式スイッチと異なり, 接点を持たない無接点スイッチ（非接触型光スイッチ）のため接点の摩耗はなく高い信頼性がある.

# 参考文献

1. 管博, 田中誠ほか: 増補改訂版図説電子デバイス, 産業図書(2011)
1. フォトカプラの「ON と OFF」|ルネサス エレクトロニクス: https://www.renesas.com/jp/ja/products/optoelectronics/technology/on-off.html
1. フォトインタラプタとは？ | フォトインタラプタとは？ | エレクトロニクス豆知識 | ローム株式会社 - ROHM Semiconductor: https://www.rohm.co.jp/electronics-basics/photointerrupters/pi_what1
