---
header-includes:
# - \usepackage[version=3]{mhchem}
metadata:
  reportInfo:
    subject: トランジスタ実験
    reportNo: 7
  writer:
    class: E3
    no: 15
    group: 6
    chief:
    name: 小畠 一泰
  others:
    date: 2019. 04. 22
    weather: 晴れ
    temp: 22.3
    wet: 56
  partners:
    collaborator1: 大橋 りさ
    collaborator2: 二重谷 光輝
    collaborator3: 森 和也
    collaborator4: DANDAR TUGULDUR
---

# 目的

接合トランジスタの特性実験や, 増幅回路・スイッチング回路実験を行うことで, 接合トランジスタの使い方を理解することを目的とする.

# 理論

## トランジスタ

トランジスタ(transistor) は接合トランジスタと電界効果トランジスタに分けられ, 今回は接合トランジスタについて実験を行う.
npn トランジスタは[@fig:transistor-structure](a)のように n 形半導体が p 形半導体を挟む構造をしていて, それぞれの領域をコレクタ (C: collector), ベース(B: base), エミッタ(E: emitter)という.
ベース電極にわずかな電流( ベース電流)を流し込むと, コレクタに $h_{FE}$ (電流増幅率) 倍の大きな電流(コレクタ電流)が流れる.
エミッタにはベース電流とコレクタ電流を合わせた電流が流れる.
今回の実験には用いないが, 接合トランジスタには(b)の pnp トランジスタがある.

![トランジスタの構造と回路記号](./documents/07-トランジスタ実験/images/transistor-structure.png){#fig:transistor-structure width=80mm}

\clearpage

## 増幅回路の設計

[@fig:emitter-amplification-circuit]は npn トランジスタを使ったエミッタ接地増幅回路で[@fig:output-characteristic]はベース電流
$I_B$ をパラメータとして, コレクタ-エミッタ間電圧$V_{CE}$とコレクタ電流$I_C$の関係を表す出力特性図である.

![トランジスタの構造と回路記号](./documents/07-トランジスタ実験/images/emitter-amplification-circuit.png){#fig:emitter-amplification-circuit width=80mm}

![出力特性図](./documents/07-トランジスタ実験/images/output-characteristic.jpeg){#fig:output-characteristic width=80mm}

この出力特性図の上で, $h_{FE}$を 200, コレクタ負荷抵抗 $R_C$を$2.2 k \Omega$, 負荷抵抗 $R_L$を$1 k \Omega$として設計してみる.
$I_C$が 0 のときに$R_C$による電圧降下が発生しないために, $V_{CC}$に等しく, 今回 $V_{CC}=6V$として, A 点が決まる.
一方, $V_{CE}$が 0 のとき, $I_C=\frac{V_{CC}}{R_C}$であるから$\frac{6V}{2.2k\Omega} = 2.7mA$になり B 点が決まり, A-B 間を結ぶと直流負荷線が引ける.
交流負荷抵抗は$R_C$と$R_L$を並列に接続したものと考えることができ, 計算すると$678\Omega$になる.
したがって, 交流負荷抵抗による$V_{CE}=0$のときの$I_C$は 8.7mA となって C 点が決まる.
A-C 間を結ぶと交流負荷縁が引ける.
交流信号は交流負荷線上を動くが, トランジスタの中を流れる電流は直流負荷線上を動くので, 交流負荷線を直流負荷線と交わるように平行移動する.
この交わったところが増幅器の動作点 P となる.
動作点は, 動作点の両側で交流負荷線の長さがほぼ同じになるように選ぶ必要がある.
[@fig:output-characteristic]の出力特性図上では動作点が$I_B=0.01mA$ のときにバランスが取れており, バイアス抵抗$R_B$は$V_{BE}=0.6V$として,

$$R_B=\frac{V_{CC}-V_{BE}}{I_B}$${#eq:R_B}

で求めることができ, $R_B=\frac{6-0.6}{0.01mA} = 540k\Omega$と計算できる.
もしうまく動作点が決まらない時は, $R_C$の値を選び直す.

## スイッチング回路

[@fig:low-side-switching](a)のように, $I_B=0$のとき$I_C=0$であるから, トランジスタはスイッチが開いている時と同じ状態になっている.
またこのときのコレクタ電位は次の式で表される.

$$V_C=V_{CC}$${#eq:switching_equal}

一方, (b)のように$I_B$に十分な電流が流れると, $I_C$は負荷抵抗によって制限される電流が流れ, スイッチ閉と同じ状態になっている.
このときのコレクタ電位$V_C=0$である.
このようにトランジスタはスイッチとして用いることができ, [@fig:low-side-switching]の回路は負荷に対してグラウンド側に接続されるスイッチで ON/OFF するローサイド・スイッチとなっている.
グラウンド側を ON/OFF できないときは, [@fig:high-side-switching]のように pnp トランジスタを用いてハイサイド・スイッチとし, 負荷を$V_{CC}$側から ON/OFF する.

\clearpage

![ローサイド・スイッチング回路](./documents/07-トランジスタ実験/images/low-side-switching.png){#fig:low-side-switching width=80mm}

![ハイサイド・スイッチング回路](./documents/07-トランジスタ実験/images/high-side-switching.png){#fig:high-side-switching width=80mm}

\clearpage

# 実験方法と結果の整理

## 使用器具

1. ディジタルオシロスコープ(RIGOL DS1064B) (SERIAL NO. DS1BE112600264)
1. 発振器 (No. 27D329483 C)
1. 直流電源 (F-4)
1. Analog Discovery
1. 実験キット

## 接合トランジスタの出力特性

### 測定回路

[@fig:output-characteristic] の出力特性は, ベース電流 $I_B$ をパラメータとし, コレクターエミッタ電圧 $V_{CE}$ を変化させて, コレクタ電流 $I_C$ を測定することによって得られた.
この測定を Digilent 社の Analog Discovery を用いて行った.
[@fig:circuit-output-characteristic] の回路はトランジスタの出力特性やスイッチング特性を Analog Discovery で測定するための回路である.
Q4 は測定対象のトランジスタで, それ以外のトランジスタや OP アンプは Q4 のベース電流を設定するためのものであった.

![Analog Discoveryを用いた出力特性測定回路](./documents/07-トランジスタ実験/images/circuit-output-characteristic.png){#fig:circuit-output-characteristic width=80mm}

Q2 と Q3 はカレントミラー回路で, Q2 のコレクタに流れる電流と全く同じ値の電流が Q3 のコレクタに流れて Q4 のベース電流になった.したがって Q2 のコレクタ電流を調整することが, Q4 のベース電流を調節することになった.
Q2 のコレクタ電流 $I_{C1}$ は, $R_2$ の電位降下 $I_{C1}R_2$ として OP アンプの反転入力端子に導かれた.
これと $E_1$ の電位が等しくなるように OP アンプが Q1 のベース電流を調整するので,
$$I_{C1}R_2 = E_1$$
が成り立ち, Q4 のベース電流 $I_B$ は $I_{C1}$ と等しいことから,
$$I_B = \frac{E_1}{R_2}$$
で与えられた.
Q4 のベース電流 $I_B$ をパラメータ $10, 20, ... , 100 \micro A$ として設定するには, Analog Discovery の任意波形発生器(AWG1)の出力電圧を 0.1, 0.2, ..., 1V になるように設定すればよい.
コレクターエミッタ電圧 $V_CE$ を変化させるためには, Analog Discovery の任意波形発生器(AWG2)の出力電圧を $0 〜 5V$ の三角波になるように設定する.
コレクタ電流 $I_C$ の値は $R_3$ の電位降下より,
$$I_C = \frac{V_2}{R_3}$$
で求めることができた.
また, コレクターエミッタ電圧 $V_CE$ は $V_1$ の測定結果より得られた.

### 実験方法

1. Analog Discovery と実験キットの出力特性測定回路を接続する.
1. [@fig:AWG] の AWG 画面で, File メニューから Open Project を選択し「E3Tr」フォルダ内の「PRF.dwfawg」ファイルを開いた.
   これにより AWG1 から $0.1 〜 1V$ の電圧が 1ms ずつ, AWG2 から $0 〜 5V$ の三角波が 2ms の周期で供給する準備が整った.

   ![AWG画面](./documents/07-トランジスタ実験/images/AWG.png){#fig:AWG width=80mm}

1. [@fig:Oscilloscope] の Oscilloscope 画面で, File メニューの Open を選択し,「E3Tr」フォルダ内の「PRF.dwfawg」ファイルを開いた.
   これにより, CH1 に $V_{CE}$ が, CH2 に $I_{C}R_{3}$ がそれぞれ読み込まれ, X-Y 表示により出力特性が表示された.

   ![Oscilloscope画面](./documents/07-トランジスタ実験/images/Oscilloscope.png){#fig:Oscilloscope width=80mm}

1. Source を Main XY#(C1:C2)に選択し, タブを Image にして Oscilloscope の画像を保存した.
1. 保存した画像を縦軸にコレクタ電流 $I_C$ の換算値, 横軸に $V_CE$ の値, パラメータに $I_B$ の値を入れた.
1. $R_B$ の最適値 [@eq:R_B]を用いて算出し, 出力特性に負荷線を引き, [@fig:load-line]に示す.
   ただし, $V_{CC} = 5V, R_C = R_L = 680 \Omega$ とした.
   $R_B = \frac{5-0.6}{35 \micro A} = 125.7 k \Omega$

   ![負荷線](./documents/07-トランジスタ実験/images/load-line.png){#fig:load-line}

\clearpage

## スイッチング特性実験

### 測定回路

[@fig:circuit-output-characteristic]の回路で $E_2 = 5V$ 一定とし, $I_B$ を $1 〜 100\micro A$ まで変化させ, $I_C$ と $V_{CE}$ を測定することで, トランジスタのスイッチング特性が得られた.
したがって AWG2 を 5V 一定としたまま, AWG1 を 0.01, 0.02, ..., 1V になるように設定し, $I_C$ と $V_{CE}$ をそれぞれ測定した.

### 実験方法

1. スイッチング特性 1

   1. 測定回路をスイッチング特性 1 に交換し, トランジスタを挿入した.
      この回路は, CH1 に $R_2$ の電位降下, CH2 に $R_3$ の電位降下が読み込まれるので, $I_B$ と $I_C$ の関係を求めることができる.
   1. 結果が表示されたら Stop して, Export により画像を保存した.

   ![スイッチング特性 1](./documents/07-トランジスタ実験/images/switching01.png){#fig:switching01 width=80mm}

1. スイッチング特性 2

   1. 測定回路をスイッチング特性 2 に交換し, トランジスタを挿入した.
      この回路は, CH1 に $R_2$ の電位降下, CH2 に $V_{CE}$ の電位降下が読み込まれるので, $I_B$ と $V_{CE}$ の関係を求めることができる.
   1. 結果が表示されたら Stop して, Export により画像を保存した.

   ![スイッチング特性 2](./documents/07-トランジスタ実験/images/switching02.png){#fig:switching02 width=80mm}

## 接合トランジスタの増幅回路特性

![増幅特性測定回路](./documents/07-トランジスタ実験/images/amplification-characteristic-measurement-circuit.png){#fig:amplification-characteristic-measurement-circuit width=80mm}

1. [@fig:amplification-characteristic-measurement-circuit]の回路で $R_B$ は $68k\Omega$ とした.
   発振器(正弦波, 出力 1[kHz])を $V_{IN}$ に接続し, オシロスコープで観測しながら入力電圧 $V_{IN}$ が $20mV_{P-P}$ となるように調整した.
   $V_{CC}$ は 5V, $R_C$ と $R_L$ は $680\Omega$ と更して実験を行った.
   出力抵抗 $R_L$ の両端電圧を出力電圧としてオシロスコープで記録した.
   観測波形より電圧振幅および実効値で増幅度を求めた.
   同様に, 発振器の出力を増加させ, 出力波形および増幅度を記録し, 出力波形がゆがんでいく様子を観測した.

   結果を[@fig:01-68kohm-50mV]と[@tbl:amplification-characteristic-measurement-table1]に示す.
   また, $R_B = 68k\Omega$ では 30 mV で歪み始めた.

   ![$68k\Omega-50mV$](./documents/07-トランジスタ実験/images/01-68kohm-50mV.png){#fig:01-68kohm-50mV width=80mm}

   | $V_{IN} (mV_{P-P})$ | $V_{OUT} (V_{P-P})$ | 振幅度 | $V_{IN} (mV_{rms})$ | $V_{OUT} (V_{rms})$ | 振幅度 |
   | ------------------: | ------------------: | -----: | ------------------: | ------------------: | -----: |
   |                  20 |               0.984 |  49.20 |                 6.1 |               0.352 |  57.70 |
   |                  30 |               1.360 |  45.33 |                 9.3 |               0.512 |  55.05 |
   |                  40 |               1.760 |  44.00 |                12.5 |               0.658 |  52.64 |
   |                  50 |               2.080 |  41.60 |                15.5 |               0.790 |  50.97 |

   : 2SC1815 増幅回路特性($R_B = 68\Omega$) {#tbl:amplification-characteristic-measurement-table1}

   \clearpage

1. [@fig:amplification-characteristic-measurement-circuit] の回路で $R_B = 1M\Omega$ とした.
   (1) の実験と同様に出力波形および増幅度を記録した.

   結果を[@fig:02-1Mohm-50mV]と[@tbl:amplification-characteristic-measurement-table2]に示す.
   また, $R_B = 1M\Omega$ では 42 mV で歪み始めた.

   ![$1M\Omega-50mV$](./documents/07-トランジスタ実験/images/02-1Mohm-50mV.png){#fig:02-1Mohm-50mV width=80mm}

   | $V_{IN} (mV_{P-P})$ | $V_{OUT} (V_{P-P})$ | 振幅度 | $V_{IN} (mV_{rms})$ | $V_{OUT} (V_{rms})$ | 振幅度 |
   | ------------------: | ------------------: | -----: | ------------------: | ------------------: | -----: |
   |                  20 |               0.136 |   6.80 |                6.81 |               0.042 |   6.14 |
   |                  30 |               0.188 |   6.27 |                10.2 |               0.061 |   6.00 |
   |                  40 |               0.244 |   6.10 |                13.5 |               0.081 |   5.99 |
   |                  50 |               0.296 |   5.92 |                17.0 |               0.099 |   5.83 |

   : 2SC1815 増幅回路特性($R_B = 1M\Omega$) {#tbl:amplification-characteristic-measurement-table2}

   \clearpage

1. 3.2 節の実験で得られた出力特性および 2.2 節の「動作点は, 動作点の両側で交流負荷線の長さがほぼ同じになるように選ぶ必要がある.」ということを参考に, もっとも歪みの少ない動作点を算出した上, (1) の実験と同等に出力波形および増幅度を記録した.

   結果を[@fig:03-120kohm-50mV]と[@tbl:amplification-characteristic-measurement-table3]に示す.
   また, $R_B = 120k\Omega$ では 57 mV で歪み始めた.

   ![$120k\Omega-50mV$](./documents/07-トランジスタ実験/images/03-120kohm-50mV.png){#fig:03-120kohm-50mV width=80mm}

   | $V_{IN} (mV_{P-P})$ | $V_{OUT} (V_{P-P})$ | 振幅度 | $V_{IN} (mV_{rms})$ | $V_{OUT} (V_{rms})$ | 振幅度 |
   | ------------------: | ------------------: | -----: | ------------------: | ------------------: | -----: |
   |                  20 |               1.020 |  51.00 |                6.54 |               0.341 |  52.14 |
   |                  30 |               1.480 |  49.33 |                9.78 |               0.504 |  51.53 |
   |                  40 |               1.960 |  49.00 |                12.9 |               0.661 |  51.24 |
   |                  50 |               2.320 |  46.40 |                16.1 |               0.808 |  50.19 |

   : 2SC1815 増幅回路特性($R_B = 120k\Omega$) {#tbl:amplification-characteristic-measurement-table3}

\clearpage

# 考察及び検討

1. スイッチング特性のグラフはそれぞれどのような意味を表しているかを説明せよ.

   本実験で使ったトランジスタは 2SC1815O で , データシートより$h_{FE} = 70〜140$ ということが分かる.

   そのため, [@fig:switching01]では, $0 〜 0.4 V$間は $I_C = I_B \times 125$ の比例式が成り立っている.

   また, スイッチが OFF になるのは [@eq:switching_equal] より,
   \begin{eqnarray*}
   V_{CC}&=& V_C \\
     5 V &\fallingdotseq& 4.7V \\
   \end{eqnarray*}
   であるため, ほぼ電源電圧に等しくなった.
   その結果電流は増幅せず横ばいになったと考えられる.

1. 総合的考察を行え.

   トランジスタを用いることで人が制御しなくても, 回路的にスイッチの切り替えができることがわかった.
   また, 増幅回路を用いればセンサーなどで読み取った値を増幅して扱いやすくしたり, オシロスコープなどで見えるようにできることがわかった.
   しかし, ノイズが含まれていると同時に増幅されてしまうため, きちんと回路設計をする必要性を感じた.

# 参考文献 {-}

- 菅博, 田中誠ほか:増補改訂版-図説電子デバイス, 産業図書(2011)
- 丹波一夫:トランジスタのしくみと基本的な使い方, トランジスタ技術増刊 ECB No.1(1999 年夏号)
- 志田晟, ブレッドボードで実験しまくり! 腕上げまくり! オールマイティ・アナライザ Analog Discovery, トランジスタ技術, 2015 年 4 月号, p51-61

<!-- https://blogs.yahoo.co.jp/nobita_rx7/27341041.html -->
