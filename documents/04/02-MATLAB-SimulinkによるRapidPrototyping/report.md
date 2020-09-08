---
header-includes:
# - \usepackage{listings}
metadata:
  reportInfo:
    subject: MATLAB/SimulinkによるRapidPrototyping
    reportNo: 2
  writer:
    class: E4
    no: 14
    group: 2
    chief:
    name: 小畠 一泰
  others:
    date: 2020. 09. 08
    weather: 晴れ
    temp: 26.8
    wet: 62.3
  partners:
    collaborator1: 井上　隆治
    collaborator2: 重見　達也
    collaborator3: 宮崎　拓也
    collaborator4: 森　　和哉
---

# 目的

MATLAB/Simulink の Hardware Support Packages を使うと, programming を行うことなく MATLAB/Simulink から Arduino を動作させることができる.
これを用いて rapid prototyping のさわりを体験することを目的とする.

# 実習

## Digital I/O(Output)

[@fig:01-01-01-c]の回路を Arduino UNO と solderless breadboard を用いて作成した.

![回路図](./documents/04/02-MATLAB-SimulinkによるRapidPrototyping/images/01-01-01-c.png){#fig:01-01-01-c height=55mm}

Simulink を起動し, [@fig:01-01-01]のようにモデルを組み, 動作を確認した.

![ブロック線図](./documents/04/02-MATLAB-SimulinkによるRapidPrototyping/images/01-01-01.png){#fig:01-01-01 width=60mm}

次に [@fig:01-01-02]のようにモデルを組み変えシミュレーションを実行したところ, [@fig:01-01-02-result] のようになった.
なお Pulse Generator はパルスタイプ: サンプルベース, 周期: 100(サンプル数), パルス幅: 50(サンプル数), サンプル時間: 0.01 に変更した.

![ブロック線図](./documents/04/02-MATLAB-SimulinkによるRapidPrototyping/images/01-01-02.png){#fig:01-01-02 height=30mm}

\clearpage

![Scope](./documents/04/02-MATLAB-SimulinkによるRapidPrototyping/images/01-01-02-result.png){#fig:01-01-02-result width=80mm}

## Digital I/O(Input) {#sec:input}

[@fig:01-02-c]の回路を Arduino UNO と solderless breadboard を用いて作成した.

![回路図](./documents/04/02-MATLAB-SimulinkによるRapidPrototyping/images/01-02-c.png){#fig:01-02-c height=60mm}

[@fig:01-02]のようにモデルを組み, シミュレーション中にスイッチを on/off 切り替えることで [@fig:01-02-result] のようになった.
なお Digital Input ブロックの Sample Time は 0.02 に設定した.

![ブロック線図](./documents/04/02-MATLAB-SimulinkによるRapidPrototyping/images/01-02.png){#fig:01-02 width=80mm}

\clearpage

![実験結果](./documents/04/02-MATLAB-SimulinkによるRapidPrototyping/images/01-02-result.png){#fig:01-02-result width=80mm}

## Digital I/O(Input/Output)

[@fig:01-03-c]の回路を, Arduino UNO と breadboard を用いて作成した.

![回路図](./documents/04/02-MATLAB-SimulinkによるRapidPrototyping/images/01-03-c.png){#fig:01-03-c height=60mm}

[@fig:01-03]のようにモデルを組み[@sec:input]のようにシミュレーションすると, [@fig:01-03-result]のような結果が得られた.
なお Digital Input ブロックの Sample Time は 0.02 に設定した.

![ブロック線図](./documents/04/02-MATLAB-SimulinkによるRapidPrototyping/images/01-03.png){#fig:01-03 width=80mm}

\clearpage

![Scope](./documents/04/02-MATLAB-SimulinkによるRapidPrototyping/images/01-03-result.png){#fig:01-03-result width=80mm}

## Analog I/O(Input)

[@fig:01-04-c]の回路を Arduino UNO と soldedless breadboard を用いて作成した.

![回路図](./documents/04/02-MATLAB-SimulinkによるRapidPrototyping/images/01-04-c.png){#fig:01-04-c height=60mm}

[@fig:01-04]のようにモデルを作成し, Analog Input ブロックの Sample Time を 0.02 ぐらいにすると, [@fig:01-04-result]のような結果が得られた.

![ブロック線図](./documents/04/02-MATLAB-SimulinkによるRapidPrototyping/images/01-04.png){#fig:01-04 width=80mm}

\clearpage

![Scope](./documents/04/02-MATLAB-SimulinkによるRapidPrototyping/images/01-04-result.png){#fig:01-04-result width=80mm}

## Analog I/O(Output)

[@fig:01-01-01-c]の回路を利用しモデルを[@fig:01-05-01]のようにすると, [@fig:01-05-01-result]のようになった.
なお Sine Wave は正弦波タイプ: 時間ベース, 振幅: 1, バイアス: 0, 周波数: 1(rad/sec)とした.
負の値を取らないように, バイアスをかけると[@fig:01-05-02-result]のようになった.

![ブロック線図](./documents/04/02-MATLAB-SimulinkによるRapidPrototyping/images/01-05-01.png){#fig:01-05-01 width=80mm}

![Scope](./documents/04/02-MATLAB-SimulinkによるRapidPrototyping/images/01-05-01-result.png){#fig:01-05-01-result width=80mm}

\clearpage

![Scope(1Vのバイアスあり)](./documents/04/02-MATLAB-SimulinkによるRapidPrototyping/images/01-05-02-result.png){#fig:01-05-02-result width=70mm}

Arduino の PWM 出力は, 0〜255 の入力値を 0~100％のデューティ比に変換して出力するため,Gain ブロックを[@fig:01-05-03]のように追加すると, [@fig:01-05-03-result]のようになった.

![ブロック線図](./documents/04/02-MATLAB-SimulinkによるRapidPrototyping/images/01-05-03.png){#fig:01-05-03 height=25mm}

![Scope(128倍)](./documents/04/02-MATLAB-SimulinkによるRapidPrototyping/images/01-05-03-result.png){#fig:01-05-03-result width=70mm}

[@fig:01-05-04]のようにモデルを組み替え, デプロイすると LED を任意の明るさに変えることができた.

![ブロック線図](./documents/04/02-MATLAB-SimulinkによるRapidPrototyping/images/01-05-04.png){#fig:01-05-04 height=20mm}

\clearpage

## Analog I/O(Input/Output)

[@fig:01-06-c]の回路図を Arduino UNO と solderless breadboard を用いて作成した.

![回路図](./documents/04/02-MATLAB-SimulinkによるRapidPrototyping/images/01-06-c.png){#fig:01-06-c height=60mm}

モデルを[@fig:01-06]のように作成し, デプロイして可変抵抗の抵抗値を変化させると LED の明暗が変わるように変化させた.

![ブロック線図](./documents/04/02-MATLAB-SimulinkによるRapidPrototyping/images/01-06.png){#fig:01-06 width=80mm}

## RC servo

RC servo は, 角度指令を与えるだけで軸の角度制御を行なうことができる.
[@fig:01-07-c]を Arduino UNO と solderless breadboard, Tower Pro を用いて作成した.

![servo回路](./documents/04/02-MATLAB-SimulinkによるRapidPrototyping/images/01-07-c.png){#fig:01-07-c width=80mm}

[@fig:01-07]のようなモデルを作成した.
このとき出力に設定されている Standard Servo Write は, 0~180 までの値を入力すると, 軸の角度がその値に追随する.

![ブロック線図](./documents/04/02-MATLAB-SimulinkによるRapidPrototyping/images/01-07.png){#fig:01-07 width=80mm}

# 課題

## アナログ温度センサ LM61BIZ の読み込み

National Semiconductor 製の単一製電源動作温度センサ IC, LM61 を使用して温度を測定するために, [@fig:02-01-c] の回路を作成した.

![LM61を用いた検温計](./documents/04/02-MATLAB-SimulinkによるRapidPrototyping/images/02-01-c.png){#fig:02-01-c width=80mm}

温度センサの出力電圧${V}_{out}$と摂氏温度$T \degree C$の関係は次式のようになる.

$${V}_{out}=(+10mV/ \degree C \times T \degree C )+600mV$$

この IC は $1 \degree C$ ごとに電圧が$10mV$上昇し, 内部で$600mV$のオフセットを持っている.

また, Arduino UNO で A/D 変換の結果は次式で表される.

$$ADC=\frac{{V}_{IN}\times1024}{{V}_{REF}}$$

${V}_{IN}={V}_{OUT}$, ${V}_{REF}={V}_{CC}=5000mV$とすると摂氏温度$T$は次式によって求められる.

$$T=\frac{\frac{5000}{1024} \times ADS-600}{10} \unit{\degree C}$$

ここで$\frac{5000}{1024}$は, ${V}_{CC}=5000mV$を 10 ビットで A/D 変換したときの 1LSB の電圧値を表している.

よって[@fig:02-01]のようなモデルで表すことができる.

![ブロック線図](./documents/04/02-MATLAB-SimulinkによるRapidPrototyping/images/02-01.png){#fig:02-01 width=80mm}

以上のように回路を組み実行した結果, Scope は[@fig:02-01-result]に出力された.

![Scope](./documents/04/02-MATLAB-SimulinkによるRapidPrototyping/images/02-01-result.png){#fig:02-01-result width=80mm}

\clearpage

## 温度通知システムの作成

$27 \degree C$ 以上になると LED が点灯して知らせるシステムを作成せよ.

![回路図](./documents/04/02-MATLAB-SimulinkによるRapidPrototyping/images/02-02-c.png){#fig:02-02-c height=50mm}

![ブロック線図](./documents/04/02-MATLAB-SimulinkによるRapidPrototyping/images/02-02.png){#fig:02-02 height=50mm}

[@fig:02-02-c] のような回路を考え, [@fig:02-02]のようなモデルを作成した.
これは閾値(本実験では実験室の室温を考慮し$27\degree C$とした.)を越えると 1 を, 下回る場合は 0 を出力する Swtich を利用し, それを Degital Output に渡すことで対応した.
実際に途中から手で IC を温めると [@fig:02-02-result]のようになり, 閾値を超えた際に LED が点灯した.

![Scope](./documents/04/02-MATLAB-SimulinkによるRapidPrototyping/images/02-02-result.png){#fig:02-02-result height=50mm}

\clearpage

# 検討課題

1. Pulse Generator のパルスタイプ, 振幅, 周期, パルス幅, サンプル時間は, シミュレーション実行とデプロイ実行それぞれについて, どのような意味をもつと考えられるか.

   - パルスタイプ:
     発生する矩形波のタイプを時間ベースかサンプルベースのどちらかで生成する計算手法.
     時間ベースモードとサンプルベースモードの重要な違いは, 時間ベースモードではブロック出力がシミュレーション時間にもとづくのに対し, サンプルベースモードではブロック出力がシミュレーションの経過時間に関係なくシミュレーションの開始にのみ依存する.

   - 振幅:
     信号の振幅を指定します.

   - 周期:
     パルスタイプが時間ベースの場合は秒単位で指定されたパルス周期.
     パルスタイプがサンプルベースの場合, 周期はサンプル時間の数として指定される.

   - パルス幅:
     時間ベースの場合は信号がオンになっているパルス周期の割合 (％) として指定したデューティ比, サンプルベースの場合はサンプル時間の数として指定したデューティ比.

   - サンプル時間:
     このブロックのサンプル時間の長さ.

   またシミュレーション実行とデプロイ実行について大きな違いは見られなかった.

1. シミュレーション実行とデプロイ実行はそれぞれ, どのような動作を行っていると考えられるか.

   - シミュレーション実行: PC がプログラムを実行する.

   - デプロイ実行: コンパイルされたプログラムが Arduino に書き込まれプログラムを実行するためスタンドアローン化される.
     また, Simulink の入った PC は信号を送受信するだけ.

   したがって, シミュレーション実行は一度しか実行しないが, デプロイ実行は通常の Arduino 同様電源供給がある限り実行され続ける.

1. Sample Time が小さいときと大きいときでどのような違いがあるか.シミュレーション実行とデプロイ実行で試してみよ.

   - シミュレーション実行: Sample Time が小さいと実行時間が短くなり, 大きいと長くなった.

   - デプロイ実行: Sample Time が小さいと LED の明暗の差が細かく滑らかであり, 逆に大きいと激しく飛び飛びになった.

# 参考文献

- 平田光男, Arduino と MATLAB で制御系設計をはじめよう, TechShare(2012)
- 一定の間隔で矩形波パルスを生成 - Simulink - MathWorks 日本 (https://jp.mathworks.com/help/simulink/slref/pulsegenerator.html)
