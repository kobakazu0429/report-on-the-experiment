---
header-includes:
# - \usepackage[version=3]{mhchem}
metadata:
  reportInfo:
    subject: 直流モータのデューティファクタ制御
    reportNo: 18
  writer:
    class: E3
    no: 15
    group: 2
    chief:
    name: 小畠 一泰
  others:
    date: 2019. 12. 9
    weather: 曇り
    temp: 13.2
    wet: 59
  partners:
    collaborator1: 井上　　　　　隆治
    collaborator2: 木下　　　　　拓真
    collaborator3: 重見　　　　　達也
    collaborator4: DANDAR　TUGULDUR
---

# 目的

半導体スイッチング・デバイスを用いた直流モータのデューティファクタ制御を行うことで, パワーエレクトロニクスの基礎を学ぶことを目的とする.

# 使用器具

1. ブレッド・ブレード
1. ディジタルオシロスコープ(RIGOL DS1064B)
1. 直流スイッチング電源(5V: 11-061，12V: No.4)
1. 回転計

# 実験方法と結果の整理

## のこぎり波発生回路

![のこぎり波発生回路](./documents/18-直流モータのデューティファクタ制御/images/183.JPG){#fig:183 width=80mm}

[@fig:183] ののこぎり波発生回路をブレッド・ボードに組み, 出力波形をオシロスコープで観測した.
[@fig:183] において, output にオシロスコープの CH1 をつなぎ, 可変抵抗 $R_1$ をドライバで調整し, 最小, 中間, 最大としたときの波形から周期を読み取り, 計算値と比較検討した.
最後は可変抵抗最大とした.

![R1:最小](./documents/18-直流モータのデューティファクタ制御/images/NewFile0.png){#fig:NewFile0 width=80mm}

![R1:中間](./documents/18-直流モータのデューティファクタ制御/images/NewFile1.png){#fig:NewFile1 width=80mm}

![R1:最大](./documents/18-直流モータのデューティファクタ制御/images/NewFile2.png){#fig:NewFile2 width=80mm}

## オンオフ信号発生回路

![オンオフ信号発生回路](./documents/18-直流モータのデューティファクタ制御/images/184.JPG){#fig:184 width=80mm}

[@fig:184] のオンオフ信号発生回路をブレッド・ボードに組み, のこぎり波発生回路の出力を入力として, 出力波形をオシロスコープで観測した.
オシロスコープの CH1 を input に, CH2 を LM311 の 3 番ピンに, CH3 を output につなぎ可変抵抗 R6 をドライバで調整し $V_{ref2}$ を $0, 1, 2, 3 \unit{V}$に変化させたときの波形からデューティ比を読み取った.

![$V_{ref2} = 0\unit{V}$](./documents/18-直流モータのデューティファクタ制御/images/NewFile3.png){#fig:NewFile3 width=80mm}

![$V_{ref2} = 1\unit{V}$](./documents/18-直流モータのデューティファクタ制御/images/NewFile4.png){#fig:NewFile4 width=80mm}

![$V_{ref2} = 2\unit{V}$](./documents/18-直流モータのデューティファクタ制御/images/NewFile5.png){#fig:NewFile5 width=80mm}

![$V_{ref2} = 3\unit{V}$](./documents/18-直流モータのデューティファクタ制御/images/NewFile6.png){#fig:NewFile6 width=80mm}

## 絶縁回路とスイッチング回路

![スイッチング回路](./documents/18-直流モータのデューティファクタ制御/images/186.JPG){#fig:186 width=80mm}

[@fig:186] の絶縁回路とスイッチング回路を別のブレッド・ボードに組み, オンオフ信号発生回路の出力を人力とした.
オンオフ信号の出力波形をオシロスコープで観測しながら, デューティファクタとモータの回転速度の関係を測定しグラフに描いた.
オシロスコープの CH1 を input に, CH2 を PC817C の 1 番ピンにつなぎ波形の画像を USB にとった.

\clearpage

# 考察

1. のこぎり波発生回路の周期 T の式を導出せよ.

   \begin{eqnarray*}
   V_c(t) &=& \frac{1}{C_1} \int_0^t I_{C2} dt \\
   &=& \frac{1}{C_1} I_{C2} t \\
   &=& \frac{1}{C_1} \frac{V_{CC} - V_{BE}}{R_1 + R_2} t \qquad (\because I_{C1} = I_{C2}) \\
   V_c(T) &=& \frac{R_4}{R_3 + R_4} V_{CC} \\
   T &=& C_1 (R_1 + R_2) \frac{\frac{R_4}{R_3 + R_4} V_{CC}}{V_{CC} - V_{BE}}
   \end{eqnarray*}

1. 絶縁回路では、input が H のとき LED が発光し、フォトトランジスタは ON となる.
   フォトトランジスタが ON のとき、ゲート電圧 VGS = 0 であるから FET は OFF となりモータには電流が流れない.
   input が L のとき LED は消灯、フォトトランジスタは OFF となる.
   フォトトランジスタが OFF のとき、ゲート電圧 VGS = H であるから FET は ON となりモータに電流が流れる.
   この関係を input のパルスを基準に、タイムチャートを描いて説明せよ.

   ![タイムチャート](./documents/18-直流モータのデューティファクタ制御/images/timing.jpg){#fig:timing width=80mm}

   フォトトランジスタが L になると FET により短絡され, モータに電流が流れる.

# 参考文献

1. 江間敏、高橋勲：パワーエレクトロニクス　 pp.130-133 　コロナ社
1. 瀬川毅：絵解き　電子回路入門　トランジスタ技術 4 月号　 pp.71-72

\clearpage
