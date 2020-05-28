---
header-includes:
# - \usepackage[version=3]{mhchem}
metadata:
  reportInfo:
    subject: 過度現象
    reportNo: 4
  writer:
    class: E3
    no: 15
    group: 6
    chief:
    name: 小畠 一泰
  others:
    date: 2019. 06. 24
    weather: 晴れ
    temp: 25.8
    wet: 55.9
  partners:
    collaborator1: 大橋　　　　　りさ
    collaborator2: 二重谷　　　　光輝
    collaborator3: 森　　　　　　和哉
    collaborator4: DANDAR　TUGULDUR
---

# 目的

過渡現象について回路シミュレーションと実験を行うことで, 過渡現象を理解することを目的とする.

# 理論

## RC 直列回路

![RC 直列回路](./documents/04-過度現象/images/4.1.jpeg){#fig:4.1 height=50mm}

[@fig:4.1] の直列回路において, $t = 0$ でスイッチ $S_1$ を閉じて直流電圧 E を加えるとき, 回路を流れる電流 i および電荷 q を求める.
この回路の方程式は次式となる.
$$Ri + \frac{1}{C} \int i dt = R \frac{dq}{dt} + \frac{1}{C} q = E$${#eq:4.1}
この式は定数係数線形微分方程式になっており, この式の一般解は定常解 $q_s$ と過度解 $q_t$ の和となる.
まず $E ＝ 0$ とした過渡解 $q_t$ を求める.

[@eq:4.1] より,
$$R \frac{dq_t}{dt} + \frac{1}{C} q_t = 0$${#eq:4.2}

変数分離するため式を変形して,
$$\frac{dq_t}{q_t} = - \frac{1}{RC} dt$${#eq:4.3}

両辺を積分する.
ここで $A_1$ は積分定数である.
$$\int \frac{dq_t}{q_t} = - \frac{1}{RC} \int dt + A_1$${#eq:4.5}
$$ \ln{q_t} = - \frac{1}{RC}t + A_1$${#eq:4.6}
$$ q_t = e^{- \frac{1}{RC}t + A_1} = e^{A_1} e^{- \frac{1}{RC}t} = A_2 e^{- \frac{1}{RC}t}$${#eq:4.6}

定常解 $q_s$ は十分長い時間経過した後コンデンサに蓄えられる電荷であるから, $q_s = CE$ である.

よって一般解 q は,
$$q = q_s + q_t = CE + A_2 e^{\frac{1}{RC}t}$${#eq:4.7}

ここで初期条件, $t = 0$ で $q = 0$ とするならば, $A_2 = -CE$ である.
したがって,
$$q = CE(1 - e^{\frac{1}{RC}t})$${#eq:4.8}
$$i = \frac{dq}{dt} = - (- \frac{1}{RC}) CE e^{\frac{1}{RC}t} = \frac{E}{R}  e^{\frac{1}{RC}t} = I e^{\frac{1}{RC}t}$${#eq:4.9}

また, 抵抗 R とコンデンサ C に生ずる電圧はそれぞれ,
$$ V_R = Ri = E e^{\frac{1}{RC}t}$$
$$ V_C = \frac{q}{C} = E(1 - e^{\frac{1}{RC}t})$${#eq:4.10}

電流の曲線に $t = 0$ で引いた接線が時間軸と交わる時刻を時定数 $\tau$ という.
[@eq:4.9] を $t = 0$ で微分すると,
$$ \frac{di}{dt} |_{t=0} = I (- \frac{1}{RC}e^{- \frac{1}{RC} 0}) = - \frac{I}{RC}$${#eq:4.11}

したがって, $t = 0$ のときの接線の傾きが $- \frac{I}{RC}$ であり, [@eq:4.9]から, $t = 0$ のときの電流は I となる.そのため, 時間軸の交点は RC となるので, $\tau = RC$ となる.
[@fig:4.2] にこれらの関係を図示する.

![RC 直列回路の充電電流と電荷](./documents/04-過度現象/images/4.2.jpeg){#fig:4.2 height=50mm}

次に [@fig:4.1] において電源 E で充電が完了し, スイッチ $S_1$ を開くと同時に $S_2$ を閉じて放電する場合を考える.回路の方程式は次式となる.
$$R \frac{dq}{dt} + \frac{1}{C} q = 0$$

定常解 $q_s$ は, 十分長い時間経過した後コンデンサに残された電荷が 0 として, $q_s = 0$ となる.
したがって一般解は,
$$q = q_s + q_t = A_3 e^{-\frac{1}{RC}t}$$

ここで, 初期条件, $t = 0$ のとき q = CE であるから, $A_3 = CE$ となって,
$$q = CE e^{- \frac{1}{RC} t}$$
$$i = \frac{dq}{dt} = CE(-\frac{1}{RC}) e^{- \frac{1}{RC} t} = -\frac{E}{R} e^{- \frac{1}{RC} t} = - I e^{- \frac{1}{RC} t}$$
となる.
[@fig:4.3] にこれらの関係を図示する.

![RC 直列回路の放電電流と電荷](./documents/04-過度現象/images/4.3.jpeg){#fig:4.3 height=50mm}

\clearpage

## RL 直列回路

![RL 直列回路](./documents/04-過度現象/images/4.4.jpeg){#fig:4.4 height=50mm}

[@fig:4.4] の RL 直列回路において, 時刻 t = 0 でスイッチ $S_1$ を閉じたとき流れる電流を求める.
この回路の方程式は次式となる.
$$L \frac{di}{dt} + Ri = E$$

まず, E = 0 とした過度解 $i_t$ を求める.
$$L \frac{di_t}{dt} + R i_t = 0$$

式を変形して両辺を積分する.
ここで, $A_4$ は積分定数である.
$$\int \frac{di_t}{i_t} = - \frac{R}{L} \int dt + A_4$${#eq:4.1}
$$\ln i_t = - \frac{R}{L} t + A_4$$
$$i_t = e^{- \frac{R}{L} t+ A_4} = e^{A_4} e^{- \frac{R}{L} t} = A_5 e^{- \frac{R}{L} t}$$

定常解 $i_S$ は, 十分長い時間経過した後コイルに流れる電流であるから $i_S = \frac{E}{R}$, よって一般解 i は,
$$i = i_S + i_t = \frac{E}{R} +A_5 e^{- \frac{R}{L} t}$$

ここで, 初期条件, t = 0 で i = 0 を用いて, $A_5 = - \frac{E}{R}$ であるから,
$$i = \frac{E}{R} (1 - e^{- \frac{R}{L} t} ) = I (1 - e^{- \frac{R}{L} t})$$

抵抗 R とインダクタンス L の端子電圧はそれぞれ,
$$V_R = Ri = E(1 - e^{- \frac{R}{L} t})$$
$$V_L = L \frac{di}{dt} = L(-\frac{E}{R})(-\frac{R}{L}) e^{- \frac{R}{L} t} = E e^{- \frac{R}{L} t}$$

次に, [@fig:4.4] おいて十分長い時間経過した後, スイッチ $S_1$ を開くと同時に $S_2$ を閉じた場合を考える.
回路の方程式は次式となる.
$$L \frac{di}{dt} + Ri = 0$$

定常解 $i_S$ は, 十分長い時間経過した後 $i_S = 0$.
したがって一般解は,
$$i = i_S + i_t = A_6 e^{- \frac{R}{L} t}$$

ここで, 初期条件 t = 0 のとき $i = \frac{E}{R}$ を用いれば $A_6 = \frac{E}{R}$ であるから,
$$i = \frac{E}{R} e^{- \frac{R}{L} t} = I e^{- \frac{R}{L} t}$$

[@fig:4.5] にこれらの関係を図示する.

![RL 直列回路の電流](./documents/04-過度現象/images/4.5.jpeg){#fig:4.5 height=50mm}

\clearpage

# 実験方法と結果の整理

## 使用器具

1. PC (TOSHIBA) (管理番号: E-000-B-005)
1. ディジタルオシロスコープ (RIGOL DS1064B) (SERIAL NO. DS1BE121000022)
1. 直流電源(5V 定電圧) (F-4)
1. 発振器 (AFG-2005) (SERIAL NO. GEQ844987)
1. 実験キット (R: $0.995 \unit{k \Omega}$, C: $107.75 \unit{nF}, 28.23 \unit{\micro F}, 83.38 \unit{\micro F}$, L: $1014.0 \unit{mH}$, $9.867 \unit{mH}$)
1. LCR メーター(H9021212)

\clearpage

## 回路シミュレーション

### RC 直列回路のシミュレーション(過渡現象)

![RC直列回路](./documents/04-過度現象/images/4.6.1.png){#fig:4.6.1 height=50mm}

$R_1 = 1\unit{k \Omega}, C_1 = 100 \unit{\micro F}$ として, [@fig:4.6.1] の回路を TINA で作成した.
電圧ジェネレータは, プロパティで [@fig:4.7.1] のように DC レベルを 0V に設定し, シグナルをクリックして「...」を表示させた後, それをクリックしてシグナル・エディタを開き, [@fig:4.7.2] のように「単位ステップ」(2 番目のボタン), 振幅 $= 5\unit{V}$, エッジ開始 $= 0\unit{s}$ とした.
電圧ピンを電源とコンデンサの電位が測れるように配置した.

![電圧ジェネレータの設定](./documents/04-過度現象/images/4.7.1.png){#fig:4.7.1 height=50mm}
![シグナル・エディタ](./documents/04-過度現象/images/4.7.2.png){#fig:4.7.2 height=50mm}

「解析」―「過渡解析」を選び, [@fig:4.8] のように表示開始 $= 0\unit{s}$, 表示終了 $= 0.5\unit{s}$ として過渡解析を実行した.
表示された結果を,「ファイル」―「エクスポート」―「Windows メタファイル」を選択し, 画像ファイルを保存した.

回路定数を $R_1 = 1\unit{k \Omega}, C_1 = 33 \unit{\micro F}$ に変更した.
表示終了時間を適当に変更し, 過渡解析結果の画像ファイルを保存した.

![過渡解析](./documents/04-過度現象/images/4.8.png){#fig:4.8 height=50mm}

![$C_1 = 100 \unit{\micro F}$](./documents/04-過度現象/images/1.c.100u.png){#fig:1.c.100u height=50mm}

![$C_1 = 33 \unit{\micro F}$](./documents/04-過度現象/images/1.c.33u.png){#fig:1.c.33u height=50mm}

\clearpage

### RL 直列回路のシミュレーション(連続波形の応答)

$R_1 = 1\unit{k \Omega}, C_1 = 0.1 \unit{\micro F}$ に設定し, 電圧ジェネレータを DC レベル $2.5\unit{V}$ とし, シグナルを方形波, 振幅 $2.5\unit{V}$, 周波数を $1\unit{kHz}$ とした.表示終了を適当にして過渡解析を行い, 結果を保存した.
次に, 抵抗とコンデンサの位置を取り替えて過渡解析を行い, 結果を保存した.

![抵抗間](./documents/04-過度現象/images/2.1.png){#fig:2.1 height=50mm}

![コンデンサ間](./documents/04-過度現象/images/2.1.png){#fig:2.2 height=50mm}

\clearpage

### RL 直列回路のシミュレーション(連続波形の応答)

![RL 直列回路](./documents/04-過度現象/images/4.9.1.png){#fig:4.9.1 height=50mm}

[@fig:4.9.1] の回路を $R_1 = 1\unit{k \Omega}, L_1 = 1 \unit{mH}$ として TINA で作成した.
電圧ジェネレータは DC レベル $2.5\unit{V}$, シグナルを方形波, 振幅 $2.5\unit{V}$, 周波数を $50\unit{kHz}$ とした.電圧ピンを電源とインダクタンスの電位が測れるように配置した.
表示終了を適当にして過渡解析を行い, 結果を保存した.
次に抵抗とインダクタンスの位置を入れ替えて過渡解析を行い, 結果を保存した.
$L_1 = 10 \unit{mH}, 周波数 10\unit{kHz}$ について同様に解析を行った.

![$L_1 = 1 \unit{mH}$ - 抵抗間](./documents/04-過度現象/images/3.l.10mh.1.png){#fig:3.l.10mh.1 height=50mm}

![$L_1 = 1 \unit{mH}$ - インダクタンス間](./documents/04-過度現象/images/3.l.10mh.2.png){#fig:3.l.10mh.2 height=50mm}

![$L_1 = 10 \unit{mH}$ - 抵抗間](./documents/04-過度現象/images/3.l.1mh.1.png){#fig:3.l.1mh.1 height=50mm}

![$L_1 = 10 \unit{mH}$ - インダクタンス間](./documents/04-過度現象/images/3.l.1mh.2.png){#fig:3.l.1mh.2 height=50mm}

\clearpage

## RC 直列回路の過渡現象(過渡現象)

![RC直列回路の実験回路](./documents/04-過度現象/images/4.10.jpeg){#fig:4.10 height=50mm}

R, C を LCR メーターで計測しておいた. $R = 1\unit{k \Omega}, C = 100 \unit{\micro F}$ について, [@fig:4.10] のようにブレッドボードを組み, タクト・スイッチを押し下げてオシロスコープで波形を観測した.
波形を[@fig:Oscillo0]に示す.
また, コンデンサ $33 \unit{\micro F}$ についても同様の実験を行い, 波形を[@fig:Oscillo1]に示す.

![$C100 \unit{\micro F}$](./documents/04-過度現象/images/Oscillo0.png){#fig:Oscillo0 height=50mm}

![$C33 \unit{\micro F}$](./documents/04-過度現象/images/Oscillo1.png){#fig:Oscillo1 height=50mm}

数値データを Excel で読み取り, 充電電流の時間変化を算出し, 片対数グラフを用いて横軸に時間 t, 縦軸(対数軸)に充電電流 I をとりグラフを描いた. このグラフから次式より時定数を求める.

$$\tau = \frac{1}{2.3 \frac{\log_10 i_1 - \log_10 i_2}{t_2 - t_1}}$$

\clearpage

## RC 直列回路の過渡現象(連続波形)

$R_1 = 1\unit{k \Omega}, C_1 = 0.1 \unit{\micro F}$ の素子を LCR メーターで測定し, [@fig:4.10] の回路の電源を発信器に代えて, 出力を $5\unit{V}$, 周波数 $1\unit{kHz}$ の矩形波にして, オシロスコープで波形を観測し, 波形データを保存した. 抵抗とコンデンサの位置を入れ替えて波形を観測し, 波形データを保存した.

結果をそれぞれ[@fig:Oscillo2;@fig:Oscillo3] に示す.

![抵抗間](./documents/04-過度現象/images/Oscillo2.png){#fig:Oscillo2 height=50mm}

![コンデンサ間](./documents/04-過度現象/images/Oscillo3.png){#fig:Oscillo3 height=50mm}

\clearpage

## RL 直列回路の過渡現象(連続波形)

$R_1 = 1\unit{k \Omega}, L_1 = 1 \unit{mH}$ の素子を LCR メーターで測定し, [@fig:4.9.1] の回路を組み, 発振器の出力を $5\unit{V}$, 周波数 $50\unit{kHz}$ について, オシロスコープで波形を観測し, 波形データを保存した. 抵抗とインダクタンスの位置を入れ替えて波形を観測し, 波形データを保存した.
結果をそれぞれ[@fig:Oscillo4;@fig:Oscillo5] に示す.

また, $L_1 = 10 \unit{mH}$ についても周波数を $10\unit{kHz}$ にして同様に実験を行った.
結果をそれぞれ[@fig:Oscillo6;@fig:Oscillo7] に示す.

![$L_1 = 1 \unit{mH}$ - 抵抗間](./documents/04-過度現象/images/Oscillo4.png){#fig:Oscillo4 height=50mm}

![$L_1 = 1 \unit{mH}$ - インダクタンス間](./documents/04-過度現象/images/Oscillo5.png){#fig:Oscillo5 height=50mm}

![$L_1 = 10 \unit{mH}$ - 抵抗間](./documents/04-過度現象/images/Oscillo6.png){#fig:Oscillo6 height=50mm}

![$L_1 = 10 \unit{mH}$ - インダクタンス間](./documents/04-過度現象/images/Oscillo7.png){#fig:Oscillo7 height=50mm}

\clearpage

# 考察

1. 各実験の理論式と, シミュレーション結果および実測結果を比較検討せよ.

   RC 直列回路における理論式は(4.10)式より $V_R = E e^{-\frac{t}{RC}}, V_C = E(1 - e^{-\frac{t}{RC}})$ である.
   この $V_C = E(1 - e^{-\frac{t}{RC}})$ に 3.2(1)でおこなったシミュレーションの値を代入した.
   すると, $t = 0.1 \unit{s}$ のとき $V_C = 3.16$ となった.
   ここでシミュレーションでとった波形図 4.9 と測定した波形図 4.19 と $t = 0.1 \unit{s}$ のときの $V_C$ をひかくしてみるとほぼ一致していることがわかった.
   また, 3.2 の(2)も同様に比較すると, シミュレーションでとった波形と測定した波形と理論値がほぼ一致した.
   RL 直列回路における理論式は(4.23)式より $V_R = E(1 - e^{-\frac{R}{L} t}), V_L = E e^{-\frac{R}{L} t})$ である.
   この $V_L = E e^{-\frac{R}{L} t})$ に 3.2 の(3)で行ったシミュレーションの値を代入するとシミュレーションで撮った波形図 4.14 と測定した波形図 4.25 とほぼ一致し, 同様に他の実験も比較したがほぼ一致した.

1. 時定数について, 理論式より求められたものと, (4.27)式により求められたものを比較し検討せよ.
<!-- 1. 実験キット (R: $0.995 \unit{k \Omega}$, C: $107.75 \unit{nF}, 28.23 \unit{\micro F}, 83.38 \unit{\micro F}$, L: $1014.0 \unit{mH}$, $9.867 \unit{mH}$) -->
   $C = 100 \unit{\micro F}$ のときの時定数は論理式 $\tau = RC$ より,
   \begin{eqnarray*}
   \tau &=& 0.995 \times 10^3 \times 83.38 \times 10^{－6} \\
   &=& 0.08296 \unit{s}
   \end{eqnarray*}

   また,(4.27)式より
   \begin{eqnarray*}
   \tau &=& \frac{1}{2.3 \frac{{\log}_{10}0.005 - {\log}_{10}0.001}{0.15 - 0}} \\
   &=& 0.09330 \unit{s}
   \end{eqnarray*}

   $C = 33 \unit{\micro F}$ のときの時定数は論理式より,
   \begin{eqnarray*}
   \tau &=& 0.995 \times 10^3 \times 28.23 \times 10^{－6} \\
   &=& 0.02809 \unit{s}
   \end{eqnarray*}

   また,(4.27)式より,
   \begin{eqnarray*}
   \tau &=& \frac{1}{2.3 \frac{{\log}_{10}0.005 - {\log}_{10}0.001}{0.05 - 0}} \\
   &=& 0.031101 \unit{s}
   \end{eqnarray*}

   各実験の理論式より導いた時定数とグラフから導いた時定数を比較してみると, グラフから導いた時定数の方が値が大きくなっていることが分かる.
   また, 時定数は回路中の電圧, 電流の変化の速さを表し, 時定数の値が小さいほどはやく, 値が大きいほど遅いからじっさいに測定した方が回路の応答が遅い.

1. 総合的考察を行え.

   RC 直列回路の実験において $C = 100 \unit{\micro F}$と $C = 33 \unit{\micro F}$のときの波形, 図 4.9 と図 4.10 を比べると, 図 4.10 の方が傾きが大きいことが分かる.
   このことからコンデンサの値を小さくするほどより短い時間で定常状態に達することができる.

# 研究

1. RL 直列回路の時定数の式を求めよ.

   (4.26)式を $t = 0$ で微分すると,
   $$\frac{di}{dt}(t=0) = I(-\frac{R}{L})e^{-\frac{R}{L}0}=-\frac{E}{L}$$
   したがって, $t = 0$ のときの接続の傾きが $- \frac{E}{L}$ であり, (4.26)式から $t = 0$ のときの電流は $I$ となる.
   そのため時間軸の交点は $\frac{R}{L}$ となる.

1. (4.27)式を導出せよ.
   \begin{eqnarray*}
   i &=& I e^{- \frac{1}{RC} t} \\
   \log_{10} i &=& \log_{10} I e^{- \frac{1}{RC} t} \\
   &=& - \frac{1}{RC} t \log_{10} e + \log_{10} I \\
   &=& (- \frac{1}{RC} \log_{10} e)t + \log_{10} I \\
   \end{eqnarray*}

   $- \frac{1}{RC} \log_{10} e$ は傾きとなり, $\log_{10} I$ は切片である.
   傾きについてのみ考えると,

   \begin{eqnarray*}
   \log_{10} i &=& (- \frac{1}{RC} \log_{10} e)t \\
   - \frac{1}{RC} &=& \frac{\log_{10} i}{t \log_{10} e} \\
   t &=& RC より \\
   - \frac{1}{t} &=& \frac{\log_{10} i}{t \log_{10} e} \\
   t &=& - \frac{t \log_{10} e}{\log_{10} i} \\
   &=& - \frac{1}{\log_{10} i} \times \frac{1}{\frac{1}{{t \log_{10} e}}} \\
   &=& - \frac{1}{\frac{\log_{10} i_2 - \log_{10} i_1}{t_2 - t_1} \times \log_{10} e} \\
   \frac{1}{\log_{10} e} &\simeq& 2.3 より \\
   &=& - \frac{1}{2.3 \frac{log_{10} i_1 - log_{10} i_2}{t_2 - t_1}} \\
   \end{eqnarray*}

1. [@fig:4.11]の LC 直列回路について, 時刻 $t = 0$ で S1 を閉じ, 電源電圧 E を印加するとき, 回路に流れる電荷 q と電流 i, インダクタンスとコンデンサの電位 $V_L$ と $V_C$ を表す式を導出せよ. また $L = 1\unit{mH}, C = 1\unit{\micro F}$のときのそれぞれの電圧波形をグラフに描け.

   この回路における回路方程式は次式となる.
   $$L \frac{di}{dt} + \frac{1}{C} \int_i^d t = E$$
   $$L \frac{d^2 q}{d t^2} + \frac{q}{C} = E$$

   $E = 0$ とした過度解 $qt$ は,
   $$L \frac{d^2 q_t}{d t^2} + \frac{q_t}{C} = 0$$
   と表すことができる.

   $qt = A e^{pt}$ とおいたとき, それを(4.34)に代入して,
   $$(L p^2 + \frac{1}{C})qt = 0$$
   $$\therefore p = \pm \sqrt{- \frac{1}{LC}}$$
   ここで,
   $$p_1 = + \sqrt{- \frac{1}{LC}}$$
   $$p_2 = - \sqrt{- \frac{1}{LC}}$$
   とすると(4.34)の解は次のように表せる.

   $$q_t = A e^{p_1} + A e^{p_2}$$
   また, (4.33)における定常解 $qs$ は,
   $$q_s = CE$$
   と表せる.
   (4.33)の一般解 q は過度解 qt と定常解 qs の和であるから,
   $$q = q_s + q_t = CE + A_1 e^{p_1 t} + A_2 e^{p_2 t}$$

   ここで初期条件, $t = 0$ で $q = 0$ とするば, $A_1 + A_2 = -CE$ になる.
   よって,
   $$q = CE \{1 -(e^{p_1 t} + e^{p_2 t})\}$$
   $$i = \frac{dq}{dt} = -\{(- \frac{1}{p_1})CE e^{p_1 t} + (- \frac{1}{p_2})CE e^{p_2 t}\}$$
   $$  = CE(\frac{e^{p_1 t}}{p_1} + \frac{e^{p_2 t}}{p_2})$$

   また, インダクタンスとコンデンサに生ずる電圧はそれぞれ,
   $$V_L = {C^2 E^2(\frac{e^{p_1t }}{p_1} + \frac{e^{p_2 t}}{p_2})}^2$$
   $$VC = E\{1-(e^{p_1 t} + e^{p_2 t})\}$$
   となる.

![LC直列回路](./documents/04-過度現象/images/4.11.png){#fig:4.11 height=50mm}

![LC直列回路 シュミレーション結果](./documents/04-過度現象/images/research.png){#fig:research height=50mm}
