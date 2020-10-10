---
header-includes:
# - \usepackage[version=3]{mhchem}
metadata:
  reportInfo:
    subject: アナログフィルタ実験
    reportNo: 3
  writer:
    class: E4
    no: 14
    group: 5
    chief:
    name: 小畠 一泰
  others:
    date: 2020. 05. 29
    weather: 晴れ
    temp: 24.0
    wet: 47.0
  partners:
    collaborator1:
    collaborator2:
    collaborator3:
    collaborator4:
---

# 目的

AD 変換前段のアンチエイリアス・フィルタや DA 変換後段のアンチイメージング・フィルタ, あるいは各種センサからの雑音除去など, アナログフィルタの役割はますます重要となってきている.本実験はアナログフィルタの設計や実験を行うことで, それが必要となった時に対応できるようになることを目的とする.

# 理論

## 伝達関数

### RC 回路(パッシブ・ローパスフィルタ)

![RC直列回路](./documents/04/03-アナログフィルタ実験/images/RC.png){#fig:RC width=80mm}

[@fig:RC]の RC 直列回路について, キルヒホッフ第 2 法則より $e_i(t) = Ri(t) + e_o(t)$が得られ,
コンデンサの両端の電圧は $e_o(t) = \frac{1}{C} \int_0^t i(t) dt$であるから $i(t) = C \frac{d e_o(t)}{dt}$となって回路方程式は,

$$e_i(t) = RC \frac{d e_o(t)}{dt} + e_o(t)$$

となる.
入力電圧 $e_i(t)$, 出力電圧 $e_o(t)$ のラプラス変換をそれぞれ $E_i(s), E_o(s)$ とおいて両辺をラプラス変換すると,

$$E_i(s) = sRCE_o(t) + E_o(t) = E_o(t) (sRC + 1)$$

したがって, この回路の伝達関数 $G(s)$ が次のように求まる.

$$G(s) = \frac{E_o(s)}{E_i(s)} = \frac{1}{sRC+1}$${#eq:GRC}

### CR 回路(パッシブ・ハイパスフィルタ)

![CR直列回路](./documents/04/03-アナログフィルタ実験/images/CR.png){#fig:CR width=80mm}

問) [@fig:CR] の CR 直列回路について伝達関数を求めよ.

[@fig:CR]の CR 直列回路について, キルヒホッフ第 2 法則より $e_i(t) = \frac{1}{C} \int_0^t i(t) dt + e_o(t)$が得られ,
抵抗の両端の電圧は $e_o(t) = Ri(t)$ であるから $i(t) = \frac{e_o(t)}{R}$となって回路方程式は,

$$e_i(t) = \frac{1}{C} \int_0^t \frac{e_o(t)}{R} dt + e_o(t)$$

となる.
入力電圧 $e_i(t)$, 出力電圧 $e_o(t)$ のラプラス変換をそれぞれ $E_i(s), E_o(s)$ とおいて両辺をラプラス変換すると,

$$E_i(s) = \frac{1}{sCR} E_o(t) + E_o(t) = E_o(t) (\frac{1}{sCR} + 1)$$

したがって, この回路の伝達関数 $G(s)$ が次のように求まる.

$$G(s) = \frac{E_o(s)}{E_i(s)} = \frac{s}{s+\frac{1}{CR}}$${#eq:GCR}

\clearpage

## 周波数特性

フィルタの特性は, $s = j\omega$ における伝達関数の値 $G(j\omega)$ で与えられる.
これをフェーザ表示で表すと,

$$G(j\omega) = |G(j\omega)|e^{j\angle G(j\omega)}$$

ここで, $G(j\omega)$ の絶対値 $|G(j\omega)|$ は,

$$|G(j\omega)| = \frac{|Y(j\omega)|}{|X(j\omega)|}$$

で, 角周波数 $\omega$ における利得を表す.
また, $G(j\omega)$ の偏角 $\angle G(j\omega)$ は,

$$\angle G(j\omega) = \angle Y(j\omega) - \angle X(j\omega)$$

で, 角周波数 $\omega$ における位相を表す.

### 1 次 LPF(ローパス・フィルタ)

分子に $s$ の項を含まない場合, 一般形は $G(s) = \frac{p}{s+p}$ となる.
利得は,

$$|G(j\omega)| = |\frac{1}{1+j(\frac{\omega}{p})}| = \frac{1}{\sqrt{1+(\frac{\omega}{p})^2}}$$

位相は,

$$\angle G(j\omega) = \angle(p+j0) - \angle(p+j\omega)$$

となる.
$\omega$ を 0 から $\infty$ にしたときの利得と位相を [@tbl:LPF] に示す.

|     $\omega$      |               利得               |                 位相                  |
| :---------------: | :------------------------------: | :-----------------------------------: |
|   $\omega = 0$    |         $\|G(j0)\| = 1$          |          $\angle G(j0) = 0$           |
|   $\omega = p$    | $\|G(jp)\| = \frac{1}{\sqrt{2}}$ |   $\angle G(jp) = - \frac{\pi}{4}$    |
| $\omega = \infty$ |       $\|G(j\infty)\| = 0$       | $\angle G(j\infty) = - \frac{\pi}{2}$ |

: 1 次 LPF の利得と位相 {#tbl:LPF}

[@fig:bodeRC] にボード線図を示す.

各素子のパラメータは次のとおりにした. $R = 1\unit{k\ohm}, C = 33\unit{nF}$

ゲインについては $0\unit{dB}$と$-20\unit{dB/dec}$ の 2 本の直線で近似でき, 折れ線の交点の角周波数は $\omega = p = \frac{1}{RC}$ である.

![1次 LPF 特性](./documents/04/03-アナログフィルタ実験/images/bodeRC.jpg){#fig:bodeRC}

### 1 次 HPF(ハイパス・フィルタ)

分子が定数項を含まない場合の一般形は $G(s) = \frac{s}{s+p}$ となる.
利得は,

$$|G(j\omega)| = |\frac{1}{1-j(\frac{p}{\omega})}| = \frac{1}{\sqrt{1+(\frac{p}{\omega})^2}}$$

位相は,

$$\angle G(j\omega) = \angle(0+j\omega) - \angle(p+j\omega)$$

となる.
$\omega$ を 0 から $\infty$ にしたときの利得と位相を [@tbl:HPF] に示す.

|     $\omega$      |               利得               |              位相              |
| :---------------: | :------------------------------: | :----------------------------: |
|   $\omega = 0$    |         $\|G(j0)\| = 0$          | $\angle G(j0) = \frac{\pi}{2}$ |
|   $\omega = p$    | $\|G(jp)\| = \frac{1}{\sqrt{2}}$ | $\angle G(jp) = \frac{\pi}{4}$ |
| $\omega = \infty$ |       $\|G(j\infty)\| = 1$       |    $\angle G(j\infty) = 0$     |

: 1 次 HPF の利得と位相 {#tbl:HPF}

問)1 次 HPF のボード線図はどのようになるか概略を示せ.

各素子のパラメータは次のとおりにした. $R = 1\unit{k\ohm}, C = 33\unit{nF}$

ゲインについては $0\unit{dB}$と$20\unit{dB/dec}$ の 2 本の直線で近似でき, 折れ線の交点の角周波数は $\omega = p = \frac{1}{RC}$ である.

![1次 HPF 特性](./documents/04/03-アナログフィルタ実験/images/bodeCR.jpg){#fig:bodeCR}

\clearpage

## フィルタ特性による分類

### バタワース型フィルタ

通過域のゲイン特性は平坦だが, 過渡域では急峻ではないフィルタである.

### チェビシェフ型フィルタ

通過域にリプルがあるが過渡域は急峻に減少し, 阻止域での減衰が大きいフィルタである.

$$|G(j\omega)| = \frac{1}{\sqrt{1 + \varepsilon^2 \{C_N (\frac{\omega}{\omega_P})\}}}$${#eq:C}

ここで, $N$ はフィルタの次数, $\omega_P$ は通過域のエッジ周波数, $C_N$ はチェビシェフの多項式, $\varepsilon$ は通過域のリプルに関するパラメータである.

\clearpage

# 実験方法

## フィルタの設計

次節のフィルタについて, パッシブ・フィルタは理論式より, アクティブ・フィルタはツールを用いて設計した.

## Tina によるシミュレーション

設計した各フィルタについて Tina により AC 解析を行った.
抵抗は E24 系列を, コンデンサは E12 系列を使用しシミュレーションした.
またアクティブ・フィルタの OP アンプは TL081 を用いた.

\clearpage

# 結果の整理

## パッシブ LPF

遮断周波数 $5 \unit{kHz}$ のローパス・フィルタを作成し, 結果を整理して考察する.

本実験では [@fig:P_LPF] のような回路を作成し, $5 \unit{kHz}$ での利得を見る.

![パッシブLPF 回路](./documents/04/03-アナログフィルタ実験/images/パッシブLPF/パッシブLPF-回路.png){#fig:P_LPF width=60mm}

[@fig:P_LPF_A] は [@fig:bodeRC] と同様の波形を示している.
また [@fig:P_LPF_G] より遮断周波数での利得は $-3.17 dB$ と読み取られ, 概ね $-3dB$ であることから実験は成功であるといえる.

$\omega = p = \frac{1}{RC}$ より, $C = \frac{1}{\omega R} = \frac{1}{2 \pi f R}$ が得られる.
したがって遮断周波数 $f = 5 \unit{kHz}$, 抵抗 $R = 1\unit{k\ohm}$ とすれば, 理想コンデンサは $C = \frac{1}{2 \pi \times 5 \times 10^3 \times 1 \times 10^3} = 31.8309886... \times 10^{-9} \unit{F}$ となる.
理想コンデンサを用いた際の AC 伝達特性で $5 \unit{kHz}$ での利得を求めると, $-3.01271 dB$ と誤差が減ることから, 誤差の原因は E12 系列のコンデンサを使用したことによるものであることがわかった.

\clearpage

![パッシブLPF 解析結果](./documents/04/03-アナログフィルタ実験/images/パッシブLPF/パッシブLPF-解析結果.bmp){#fig:P_LPF_A}

![パッシブ LPF $5 \unit{kHz}$ での利得と位相](./documents/04/03-アナログフィルタ実験/images/パッシブLPF/キャプチャ.png){#fig:P_LPF_G width=60mm}

\clearpage

## パッシブ HPF

遮断周波数 $5 \unit{kHz}$ のハイパス・フィルタを作成し, 結果を整理して考察する.

本実験も同様に [@fig:P_HPF] のような回路を作成し, $5 \unit{kHz}$ での利得を見る.

![パッシブHPF 回路](./documents/04/03-アナログフィルタ実験/images/パッシブHPF/パッシブHPF-回路.png){#fig:P_HPF width=60mm}

![パッシブHPF 解析結果](./documents/04/03-アナログフィルタ実験/images/パッシブHPF/パッシブHPF-解析結果.bmp){#fig:P_HPF_A}

[@fig:P_HPF_A] は [@fig:bodeCR] と同様の波形を示している.
また [@fig:P_HPF_G] より遮断周波数での利得は $-2.86 dB$ と読み取られ, 概ね $-3dB$ であり, パッシブ LPF も同様に, コンデンサによる誤差であると考えられる.

![パッシブHPF $5 \unit{kHz}$ での利得と位相](./documents/04/03-アナログフィルタ実験/images/パッシブHPF/キャプチャ.png){#fig:P_HPF_G width=60mm}

\clearpage

## バタワース型 LPF

遮断周波数 $5 \unit{kHz}$ のバタワース型 LPF を作成し, 結果を整理して考察する.

### VCVS 型

![Filter Designerでデザインした VCVS 型回路](./documents/04/03-アナログフィルタ実験/images/バタワースVCVS/VCVS_バタワース.png){width=70mm}

![VCVS 型回路の周波数特性](./documents/04/03-アナログフィルタ実験/images/バタワースVCVS/FilterDesigner-VCVS_バタワース.png)

![Tina で設計した回路](./documents/04/03-アナログフィルタ実験/images/バタワースVCVS/バタワースVCVS-回路.png){width=70mm}

\clearpage

![VCVS 型 $5 \unit{kHz}$ での利得と位相](./documents/04/03-アナログフィルタ実験/images/バタワースVCVS/キャプチャ.png){width=60mm}

![VCVS 型解析結果](./documents/04/03-アナログフィルタ実験/images/バタワースVCVS/バタワースVCVS-解析結果.bmp){#fig:B_VCVS_A}

バタワース型の特徴である通過域のゲイン特性が平坦になっており, 遮断周波数での利得は $-3.21 dB$ と読み取られ, 概ね $-3dB$ でありフィルタとして問題なく設計できていることが分かる.
また VCVS 型の特徴である, OP アンプの周波数帯域よりも高周波の信号が入力されると出力がもれていくことが [@fig:B_VCVS_A] と [@fig:B_MFB_A] を比較することで確認できた.

\clearpage

### 多重帰還型

![Filter Designerでデザインした MFB 型回路](./documents/04/03-アナログフィルタ実験/images/バタワースMFB/MFB_バタワース.png){width=70mm}

![MFB 型回路の周波数特性](./documents/04/03-アナログフィルタ実験/images/バタワースMFB/FilterDesigner-MFB_バタワース.png)

![Tina で設計した回路](./documents/04/03-アナログフィルタ実験/images/バタワースMFB/バタワースMFB-回路.png){width=60mm}

\clearpage

![MFB 型 $5 \unit{kHz}$ での利得と位相](./documents/04/03-アナログフィルタ実験/images/バタワースMFB/キャプチャ.png){width=60mm}

![MFB 型解析結果](./documents/04/03-アナログフィルタ実験/images/バタワースMFB/バタワースMFB-解析結果.bmp){#fig:B_MFB_A}

こちらもバタワース型の特徴 VCVS 型同様に見られた.
また遮断周波数での利得は $-3.03 dB$ と読み取られ, 概ね $-3dB$ でありフィルタとして問題なく設計できていることが分かる.
MFB 型の特徴である, 高周波信号は最初の RC フィルタでトラップされる為高周波の漏れが少ないことを [@fig:B_VCVS_A] と [@fig:B_MFB_A] を比較することで確認できた.

\clearpage

## チェビシェフ型 LPF

遮断周波数 $5 \unit{kHz}$ のチェビシェフ型 LPF を作成し, 結果を整理して考察する.

### VCVS 型

![Filter Designerでデザインした VCVS 型回路](./documents/04/03-アナログフィルタ実験/images/チェビシェフVCVS/VCVS_チェビシェフ.png){width=65mm}

![VCVS 型回路の周波数特性](./documents/04/03-アナログフィルタ実験/images/チェビシェフVCVS/FilterDesigner-VCVS_チェビシェフ.png){#fig:FD_C_VCVS}

![Tina で設計した回路](./documents/04/03-アナログフィルタ実験/images/チェビシェフVCVS/チェビシェフVCVS-回路.png){width=60mm}

\clearpage

![VCVS 型 $5 \unit{kHz}$ での利得と位相](./documents/04/03-アナログフィルタ実験/images/チェビシェフVCVS/キャプチャ.png){#fig:C_VCVS_G width=60mm}

![VCVS 型解析結果](./documents/04/03-アナログフィルタ実験/images/チェビシェフVCVS/チェビシェフVCVS-解析結果.bmp){#fig:C_VCVS_A}

[@eq:C] より, 遮断周波数での利得は $-3dB$ とならないことが分かり, [@fig:C_VCVS_G] より示せる.
また, チェビシェフ型の特徴であるリップルが発生していることが [@fig:FD_C_VCVS] や [@fig:C_VCVS_A] から分かる.

\clearpage

### 多重帰還型

![Filter Designerでデザインした MFB 型回路](./documents/04/03-アナログフィルタ実験/images/チェビシェフMFB/MFB_チェビシェフ.png){width=70mm}

![MFB 型回路の周波数特性](./documents/04/03-アナログフィルタ実験/images/チェビシェフMFB/FilterDesigner-MFB_チェビシェフ.png){#fig:FD_C_MBF}

![Tina で設計した回路](./documents/04/03-アナログフィルタ実験/images/チェビシェフMFB/チェビシェフMFB-回路.png){width=60mm}

\clearpage

![MFB 型 $5 \unit{kHz}$ での利得と位相](./documents/04/03-アナログフィルタ実験/images/チェビシェフMFB/キャプチャ.png){#fig:C_MBF_G width=60mm}

![MFB 型解析結果](./documents/04/03-アナログフィルタ実験/images/チェビシェフMFB/チェビシェフMFB-解析結果.bmp){#fig:C_MFB_A}

VCVS 型と同様に [@eq:C] と [@fig:C_MBF_G] より, 遮断周波数での利得は $-3dB$ とならないことが分かるとともに, [@fig:FD_C_MBF] や [@fig:C_MFB_A] からリップルが発生していることが分かる.
また, こちらは位相が反転している.

\clearpage

# 検討課題

1. ベッセル型フィルタ, 逆チェビシェフ型フィルタ, 連立チェビシェフ型フィルタについて調べ, それぞれの特徴を述べよ.

   - ベッセル型フィルタ

     過渡応答 (立ち上がり／立ち下がり) 特性を最適化し, リンギング, オーバシュートが最小.
     また, 立ち上がり同一の次数のフィルタ中で最速.

     波形に情報がある場合や過渡応答をきれいに整えたい場合に使われることが多い.

   - 逆チェビシェフ型フィルタ

     チェビシェフフィルタとは逆で, 阻止域に等リップル性のあるローパスフィルタ.
     また, 遮断域に振動があり透過域はバターワース特性に近い.

   - 連立チェビシェフ型フィルタ

     構成が大きくなると共に設計も高度になるが通過域, 減衰域ともに, リプル (うねり) を持たせることで, 遷移域を最小にできるように考えられた特性.
     また過渡応答でリンギングが大きい.

     できるだけ理想に近いフィルタ特性にしたい場合やオーバサンプリングでない AD コンバータのアンチエイリアスに使われることが多い.

# 参考文献

- 三谷政昭, アナログ・フィルタ理論&設計入門, CQ 出版(2009)
- 川田章弘, やりなおしのための実用アナログ回路設計, CQ 出版(2013)
- WEBENCH® Filter Designer
  - [http://www.tij.co.jp/ja-jp/design-resources/design-tools-simulation/filter-designer.html](http://www.tij.co.jp/ja-jp/design-resources/design-tools-simulation/filter-designer.html)
- フィルタの特性と特徴 - エヌエフ回路設計ブロック
  - [http://www.nfcorp.co.jp/techinfo/keisoku/module/f_chara.html](http://www.nfcorp.co.jp/techinfo/keisoku/module/f_chara.html)
- Engineering Tool Information Blog - 逆チェビシェフ・フィルタ理論
  - [http://okawa-denshi.jp/blog/?th=2008080300](http://okawa-denshi.jp/blog/?th=2008080300)
