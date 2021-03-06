---
header-includes:
# - \usepackage[version=3]{mhchem}
metadata:
  reportInfo:
    subject: OPアンプによる増幅回路実験
    reportNo: 14
  writer:
    class: E3
    no: 15
    group: 2
    chief:
    name: 小畠 一泰
  others:
    date: 2019. 10. 21
    weather: 晴れ
    temp: 22.5
    wet: 60.0
  partners:
    collaborator1: 井上　　　　　隆治
    collaborator2: 木下　　　　　拓真
    collaborator3: 重見　　　　　達也
    collaborator4: DANDAR　TUGULDUR
---

# 目的

OP アンプを用いた増幅回路のシミュレーションと実験を行うことで, OP アンプの使い方を学ぶとともに, 電圧増幅度, 利得, 周波数特性など増幅回路の基礎を理解することを目的とする.

# 使用器具

- ノート PC
- 実験セット(直流スイッチング電源($5 \unit{V}$, $+12 \unit{V}$, $-12 \unit{V}$), ブレッドボード, Analog Discovery)

# 実験方法

## TINA によるシミュレーション

### 計測方法

各回路において,「DC 解析」-「DC 伝達特性」と「過渡解析」を行い, 電圧増幅度と位相を確認した.
電源 $VS1, VS2$ は $12 \unit{V}$.
入力信号は正弦波, 振幅 $0.2 \unit{V}$, 周波数 $1 \unit{kHz}$ に設定, 以下すべて同じとする.
また,「AC 解析」-「AC 伝達特性」を実行して周波数特性を確認した.

![DC 解析 - DC 伝達特性 設定](./documents/14-OPアンプによる増幅回路実験/images/Tina/140702.png){width=80mm}

![過渡解析 設定](./documents/14-OPアンプによる増幅回路実験/images/Tina/140802.png){width=80mm}

![AC 解析 - AC 伝達特性 設定](./documents/14-OPアンプによる増幅回路実験/images/Tina/140902.png){width=80mm}

\clearpage

1.  反転増幅回路

    ![反転増幅回路](./documents/14-OPアンプによる増幅回路実験/images/Tina/140601.png){height=50mm}

    ![反転増幅回路 DC 解析 - DC 伝達特性 結果](./documents/14-OPアンプによる増幅回路実験/images/Tina/140701.png){width=80mm}

    ![反転増幅回路 過渡解析 結果](./documents/14-OPアンプによる増幅回路実験/images/Tina/140801.png){width=80mm}

    ![反転増幅回路 AC 解析 - AC 伝達特性 結果](./documents/14-OPアンプによる増幅回路実験/images/Tina/140901.png){width=80mm}

    \clearpage

1.  非反転増幅回路

    ![非反転増幅回路](./documents/14-OPアンプによる増幅回路実験/images/Tina/141001.png){height=50mm}

    ![非反転増幅回路 DC 解析 - DC 伝達特性 結果](./documents/14-OPアンプによる増幅回路実験/images/Tina/141002.png){width=80mm}

    ![非反転増幅回路 過渡解析 結果](./documents/14-OPアンプによる増幅回路実験/images/Tina/141003.png){width=80mm}

    ![非反転増幅回路 AC 解析 - AC 伝達特性 結果](./documents/14-OPアンプによる増幅回路実験/images/Tina/141004.png){width=80mm}

    \clearpage

1.  ボルテージ・フォロワ回路

    ![ボルテージ・フォロワ回路](./documents/14-OPアンプによる増幅回路実験/images/Tina/141101.png){height=50mm}

    ![ボルテージ・フォロワ回路 DC 解析 - DC 伝達特性 結果](./documents/14-OPアンプによる増幅回路実験/images/Tina/141102.png){width=80mm}

    ![ボルテージ・フォロワ回路 過渡解析 結果](./documents/14-OPアンプによる増幅回路実験/images/Tina/141103.png){width=80mm}

    ![ボルテージ・フォロワ回路 AC 解析 - AC 伝達特性 結果](./documents/14-OPアンプによる増幅回路実験/images/Tina/141104.png){width=80mm}

    \clearpage

1.  +単電源の反転増幅回路と過渡解析

    ここまでは $\pm$ の 2 電源で OP アンプを使用する場合についてシミュレーションを行ったが, 実際は単一電源で OP アンプを使用する場合が多い.
    [@fig:141201] は $V_{cc} -$ を GND にした, $V_{cc} +$ 単電源の反転増幅回路である.
    電源 VS1 は $5 \unit{V}$ に設定.
    動作点を $V_{cc}$ の中間にシフトさせるため, $R_3$ と$R_4$ で電源電圧を抵抗分圧し非反転入力端子に加えてある.
    $C_2$ で信号源の直流分はカットされ, 出力 $VF_1$ は $2.5 \unit{V}$ のオフセット電圧を中心に信号の 2 倍の振幅となる.
    また, 出力 $VF_2$ は$C_5$ により直流分がカットされ, $0 \unit{V}$ を中心に信号の 2 倍の振幅となる.
    $C_3$ 入力信号はこれ以降正弦波, 振幅 $0.2 \unit{V}$, 周波数 $1 \unit{kHz}$ とする.

    ![+単電源の反転増幅回路と過渡解析](./documents/14-OPアンプによる増幅回路実験/images/Tina/141201.png){#fig:141201 width=80mm}

    ![+単電源の反転増幅回路と過渡解析 結果](./documents/14-OPアンプによる増幅回路実験/images/Tina/141202.png){width=80mm}

\clearpage

## Analog Discovery を用いた過渡解析実験

### 反転増幅回路

![$R_2 = 20k\Omega$ オシロスコープ](./documents/14-OPアンプによる増幅回路実験/images/AnalogDiscovery/01-反転増幅/01-20k/01-1.png){#fig width=80mm}

![$R_2 = 20k\Omega$ ネットワーク解析](./documents/14-OPアンプによる増幅回路実験/images/AnalogDiscovery/01-反転増幅/01-20k/02-1.png){#fig width=80mm}

![$R_2 = 47k\Omega$ オシロスコープ](./documents/14-OPアンプによる増幅回路実験/images/AnalogDiscovery/01-反転増幅/02-47k/03-1.png){#fig width=80mm}

### 非反転増幅回路

![$R_2 = 10k\Omega$ オシロスコープ](./documents/14-OPアンプによる増幅回路実験/images/AnalogDiscovery/02-非反転増幅/01-10k/01-1.png){#fig width=80mm}

![$R_2 = 10k\Omega$ ネットワーク解析](./documents/14-OPアンプによる増幅回路実験/images/AnalogDiscovery/02-非反転増幅/01-10k/02-1.png){#fig width=80mm}

![$R_2 = 39k\Omega$ オシロスコープ](./documents/14-OPアンプによる増幅回路実験/images/AnalogDiscovery/02-非反転増幅/02-39k/01-1.png){#fig width=80mm}

\clearpage

### ボルテージ・フォロワ回路

![オシロスコープ](./documents/14-OPアンプによる増幅回路実験/images/AnalogDiscovery/03-ボルテージ・フォロワ/01-1.png){#fig width=80mm}

![ネットワーク解析](./documents/14-OPアンプによる増幅回路実験/images/AnalogDiscovery/03-ボルテージ・フォロワ/02-1.png){#fig width=80mm}

### +単電源の反転増幅回路と過渡解析

![オシロスコープ](./documents/14-OPアンプによる増幅回路実験/images/AnalogDiscovery/04-単電源/01-1.png){#fig width=80mm}

# 検討課題

1. ボルテージ・フォロワの用途について調べよ.
   大きく分けて 2 つあり, 1 つ目は, インピーダンス変換と呼ばれ, 信号電圧は変えずに大きな電流を流すことができる.
   2 つ目は, 回路の分離と呼ばれ, 交流の信号を増幅度 1 倍のアンプをつなぐことで前の回路に影響を与えずに一方通行にできる.

1. ネットワーク解析は Analog Discovery 内部でどのようなことが行われているか考えよ.
   回路内で数値に変換されて, グラフとしてプロットしている.

1. ネットワーク解析のゲインの値を確かめよ.
   周波数とゲインは反比例し, $100 \unit{kHz}$ を越えたあたりからゲインが大幅に減少している.

1. 総合的の考察を行え.
   Analog Discovery を用いて得られた波形と TINA によるシミュレーションによって得られた波形はどの波形も同じ波形になっていたので実験は成功したといえる.
