---
header-includes:
  # - \usepackage[version=3]{mhchem}
metadata:
  reportInfo:
    subject: 振幅変調・復調実験
    reportNo: 6
  writer:
    class: E4
    no: 14
    group: 5
    chief:
    name: 小畠 一泰
  others:
    date: 2020. 10. 14
    weather: 晴れ
    temp:
    wet:
  partners:
    collaborator1:
    collaborator2:
    collaborator3:
    collaborator4:
---

# 実験器具

- 振幅変調・検波実習装置 AMH-105 (管理番号: BH37H17S00000070)
- オシロスコープ DS1064B BH37H21S00000106

# 振幅変調の実習

## 目的

搬送波と信号波および被変調波から振幅変調の様子を理解し, 変調度を求める.

## 実験手順と結果

1. 信号波選択 SW を内部発振の INT. OSC.側に切り換えた.
1. オシロスコープの 1CH を搬送波出力の測定端子(S1)に接続して搬送波の波形を観測し, 波形および電圧, 周波数を測定・記録した.

   ![搬送波の波形](./documents/04/0206-振幅変調・復調実験/images/6.1/6.1.5-3.png){#fig:6.1.5-3 height=50mm}

1. オシロスコープの 1CH を信号波出力の測定端子(S2)に接続し換え, 2CH を被変調波出力の測定端子(S3)に接続した.
1. 内部発振の周波数調節ツマミ(FREQUENCY ADJ.)と信号波のゲイン調節ツマミ(GAIN ADJ.)を反時計方向に回しきり, 最低周波数及び信号波電圧をゼロにした状態の被変調波の波形と電圧を観測・記録した.

   ![被変調波の波形(最低周波数, 信号波電圧ゼロ)](./documents/04/0206-振幅変調・復調実験/images/6.1/6.1.5-4.png){#fig:6.1.5-4 height=50mm}

   \newpage

1. 信号波のゲイン調節ツマミを回し信号波の大きさを色々変え, 各々の信号波電圧に対する被変調波の波形と電圧を観測・記録した.
1. 周波数調節ツマミで信号周波数を色々変え, 同様に測定・記録した.
1. 被変調波の波形から, 各々の信号波の大きさにおける変調度を算出し, [@tbl:6-1] を埋めた.

<!-- prettier-ignore-start -->

\begin{table}[htb]
\begin{center}
\caption{各信号波に対する被変調波の変調度}
\label{tbl:6-1}
\begin{tabular}{|r|r|r|r|r|c|}
\hline
\multicolumn{1}{|c|}{\multirow{2}{*}{信号波周波数 f{[}Hz{]}}} &
  \multicolumn{1}{c|}{\multirow{2}{*}{信号波電圧 Es{[}V{]}}} &
  \multicolumn{2}{c|}{被変調波} &
  \multicolumn{1}{c|}{\multirow{2}{*}{変調度{[}\%{]}}} &
  \multirow{2}{*}{画像番号} \\ \cline{3-4}
\multicolumn{1}{|c|}{} &
  \multicolumn{1}{c|}{} &
  \multicolumn{1}{c|}{E1{[}V{]}} &
  \multicolumn{1}{c|}{E2{[}V{]}} &
  \multicolumn{1}{c|}{} &
   \\ \hline
\multirow{3}{*}{200}  & 0.0878 & 3.92 & 1.96 & 33.33  & 1 \\ \cline{2-6} 
                      & 0.3110 & 5.76 & 0.04 & 98.62  & 2 \\ \cline{2-6} 
                      & 0.3770 & 6.12 & 0.44 & 86.59  & 3 \\ \hline
\multirow{3}{*}{1000} & 0.1120 & 4.12 & 1.84 & 38.26  & 4 \\ \cline{2-6} 
                      & 0.2970 & 5.76 & 0.04 & 98.62  & 5 \\ \cline{2-6} 
                      & 0.3900 & 6.28 & 0.72 & 79.43  & 6 \\ \hline
\multirow{3}{*}{5000} & 0.0823 & 3.88 & 2.12 & 29.33  & 7 \\ \cline{2-6} 
                      & 0.3110 & 5.76 & 0.00 & 100.00 & 8 \\ \cline{2-6} 
                      & 0.3670 & 6.20 & 0.32 & 90.18  & 9 \\ \hline
\end{tabular}
\end{center}
\end{table}

<!-- prettier-ignore-end -->

\newpage

![1](./documents/04/0206-振幅変調・復調実験/images/6.1/200Hz/0.png){#fig:6.1.200Hz-0 height=50mm}

![2](./documents/04/0206-振幅変調・復調実験/images/6.1/200Hz/1.png){#fig:6.1.200Hz-1 height=50mm}

![3](./documents/04/0206-振幅変調・復調実験/images/6.1/200Hz/2.png){#fig:6.1.200Hz-2 height=50mm}

![4](./documents/04/0206-振幅変調・復調実験/images/6.1/1k/0.png){#fig:6.1.1k-0 height=50mm}

![5](./documents/04/0206-振幅変調・復調実験/images/6.1/1k/1.png){#fig:6.1.1k-1 height=50mm}

![6](./documents/04/0206-振幅変調・復調実験/images/6.1/1k/2.png){#fig:6.1.1k-2 height=50mm}

![7](./documents/04/0206-振幅変調・復調実験/images/6.1/5k/NewFile0.png){#fig:6.1.5k-0 height=50mm}

![8](./documents/04/0206-振幅変調・復調実験/images/6.1/5k/NewFile1.png){#fig:6.1.5k-1 height=50mm}

![9](./documents/04/0206-振幅変調・復調実験/images/6.1/5k/NewFile2.png){#fig:6.1.5k-2 height=50mm}

\clearpage

# 検波特性の実習

## 目的

ダイオード検波における抵抗及びコンデンサの値を変え, 検波定数変化による再生信号波の違いを理解する.

## 実験手順と結果

1. 検波部のスピーカボリューム(GAIN ADJ.)を紋って, 音が出ないようにした.
1. 変調部の被変調波の出力端子と検波部の被変調波の入力端子をケーブルで接続した.
1. オシロスコープの 1CH を被変調波出力の測定端子(S3)に, 2CH は信号波出力(S2)に接続した.
1. 変調部の内部発振の周波数調節ツマミ(FREQUENCY ADJ.)で周波数を 500Hz にセットしておき, 被変調波出力の変調度が 100％になるように信号波のゲイン調節ツマミ(GAINADJ. 1CH で確認)を調節した.

   ![被変調波出力](<./documents/04/0206-振幅変調・復調実験/images/6.2/6.2.4(4)/NewFile0.png>){height=50mm}

   信号波周波数 500[Hz], 信号波電圧 Es 3.02[V], 被変調波 E1: 5.76[V], 被変調波 E2: 0[V], 変調度: 100%

1. 次に, 1CH を検波出力の測定端子(S4)に接続し, 検波部定数の抵抗の値(R1〜R3)とコンデンサの値(C1〜C3)を SW で切り換えた.
   抵抗とコンデンサの各組合せの 9 とおりの場合に対する信号波出力と検波出力およびと低周波出力の波形を観測・記録した.

   \clearpage

   ![R1C1 (Vpp: 3.00[V])](<./documents/04/0206-振幅変調・復調実験/images/6.2/6.2.4(5)/R1C1.png>){height=50mm}

   ![R2C1 (Vpp: 3.24[V])](<./documents/04/0206-振幅変調・復調実験/images/6.2/6.2.4(5)/R2C1.png>){height=50mm}

   ![R3C1 (Vpp: 3.36[V])](<./documents/04/0206-振幅変調・復調実験/images/6.2/6.2.4(5)/R3C1.png>){height=50mm}

   ![R1C2 (Vpp: 3.30[V])](<./documents/04/0206-振幅変調・復調実験/images/6.2/6.2.4(5)/R1C2.png>){height=50mm}

   ![R2C2 (Vpp: 3.48[V])](<./documents/04/0206-振幅変調・復調実験/images/6.2/6.2.4(5)/R2C2.png>){height=50mm}

   ![R3C2 (Vpp: 3.60[V])](<./documents/04/0206-振幅変調・復調実験/images/6.2/6.2.4(5)/R3C2.png>){height=50mm}

   ![R1C3 (Vpp: 3.42[V])](<./documents/04/0206-振幅変調・復調実験/images/6.2/6.2.4(5)/R1C3.png>){height=50mm}

   ![R2C3 (Vpp: 3.54[V])](<./documents/04/0206-振幅変調・復調実験/images/6.2/6.2.4(5)/R2C3.png>){height=50mm}

   ![R3C3 (Vpp: 3.42[V])](<./documents/04/0206-振幅変調・復調実験/images/6.2/6.2.4(5)/R3C3.png>){height=50mm}

   \clearpage

1. 周波数調節ツマミ(FREQUENCY ADJ.)を変化させて各々の信号周波数に対して実験(5)と同様に波形を観測・記録した.

   ![(1k[Hz], Vpp: 2.64[V])](<./documents/04/0206-振幅変調・復調実験/images/6.2/6.2.4(6)/NewFile0.png>){height=50mm}

   ![(1k[Hz], Vpp: 3.18[V])](<./documents/04/0206-振幅変調・復調実験/images/6.2/6.2.4(6)/NewFile1.png>){height=50mm}

   ![(1k[Hz], Vpp: 3.42[V])](<./documents/04/0206-振幅変調・復調実験/images/6.2/6.2.4(6)/NewFile2.png>){height=50mm}

   ![(5k[Hz], Vpp: 1.08[V])](<./documents/04/0206-振幅変調・復調実験/images/6.2/6.2.4(6)/NewFile3.png>){height=50mm}

   ![(5k[Hz], Vpp: 2.82[V])](<./documents/04/0206-振幅変調・復調実験/images/6.2/6.2.4(6)/NewFile4.png>){height=50mm}

   ![(5k[Hz], Vpp: 3.48[V])](<./documents/04/0206-振幅変調・復調実験/images/6.2/6.2.4(6)/NewFile5.png>){height=50mm}

   \clearpage

1. 信号波のゲイン調節ツマミ(GAIN ADJ.)を調節し, 被変調波の変調度を変え同様に実験した.

   ![KKOKOK](<./documents/04/0206-振幅変調・復調実験/images/6.2/6.2.4(7)/NewFile6.png>){height=50mm}

   ![KKOKOK](<./documents/04/0206-振幅変調・復調実験/images/6.2/6.2.4(7)/NewFile7.png>){height=50mm}

   ![KKOKOK](<./documents/04/0206-振幅変調・復調実験/images/6.2/6.2.4(7)/NewFile8.png>){height=50mm}

   \newpage

   ![KKOKOK](<./documents/04/0206-振幅変調・復調実験/images/6.2/6.2.4(7)/NewFile9.png>){height=50mm}

1. スピーカボリューム(GAIN ADJ.)を少し上げ, 違いを音で確認した結果を [@tbl:6-2] に記す.

\begin{table}[htb]
\begin{center}
\caption{スピーカー出力による違い (周波数 1{[}kHz{]})}
\label{tbl:6-2}
\begin{tabular}{|c|l|}
\hline
定数 & 違い \\ \hline
R1C1 & 高い気がした \\ \hline
R2C2 & こもっているような音がした \\ \hline
R3C3 & さらにこもっているような音がした \\ \hline
\end{tabular}
\end{center}
\end{table}

\clearpage

# 側波観測の実習

## 目的

振幅変調における被変調波の側波の存在を確認し, 側波帯の意味を理解する.

## 実験手順と結果

1. 変調部の被変調波の出力端子と検波部の被変調波の入力端子および, 変調部のもう 1 つの被変調波出力端子と簡易側波帯観察ユニットの被変調波の入力端子を各々ケーブルで接続した.
1. 周波数計を使用し, 内部発振の周波数調節ツマミ(FREQUENCY ADJ.)を 4kHz にセットした.
1. オシロスコープの 1CH を被変調波出力の測定端子(S3)に接続し, 信号波出力を測定できるようにしておく.
   被変調波出力の変調度が 100％になるよう信号波のゲイン調節ツマミ(GAIN ADJ.)を調節した.
1. 次に, オシロスコープの 1CH を簡易側波帯観察ユニットの被変調波スイープ出力端子(SWEEP OUT.)につなぎ換え, 2CH を簡易側波帶観察ユニットの同期出力端子(SINC.OUT.)に接続した.
1. オシロスコープの 1CH を 1V/DIV, 2CH を 5V/DIV に, スイープは 10ms/DIV に, トリガ信号原を 2CH にし, トリガの立下りで同期がかかるようにセットした.
1. この状態で画面のほぼ中央に搬送波の周波数成分が観察できるので記録した.
   今は, 100％変調であり, 搬送波の両側に側波が出ているのが観察できるので記録した.

   ![側波](<./documents/04/0206-振幅変調・復調実験/images/6.3/6.3.4(6)/NewFile10.png>){height=50mm}

1. また, 1CH を信号波(S2)に合わせ, 0Vpp に設定し, 再度スイープ出力端子に戻し, 波形を観測・記録した.
   これを信号波 1, 2, 3Vpp の場合も観測・記録した.
   ([@fig:3-7-0]〜[@fig:3-7-3]に示す.)

   ![Vpp: 0[V]](<./documents/04/0206-振幅変調・復調実験/images/6.3/6.3.4(7)/0.png>){height=50mm #fig:3-7-0}

   ![Vpp: 1[V]](<./documents/04/0206-振幅変調・復調実験/images/6.3/6.3.4(7)/1.png>){height=50mm}

   ![Vpp: 2[V]](<./documents/04/0206-振幅変調・復調実験/images/6.3/6.3.4(7)/2.png>){height=50mm}

   ![Vpp: 3[V]](<./documents/04/0206-振幅変調・復調実験/images/6.3/6.3.4(7)/3.png>){height=50mm #fig:3-7-3}

1. 周波数調節ツマミを回して信号周波数を変化させ(2, 3kHz それぞれ信号波が 3Vpp のときのみ)側波がどのように変化するかを観察し記録した.
   ([@fig:3-8-2k;@fig:3-8-3k]に示す.)

   ![fs: 2[kHz], Vpp: 3[V]](<./documents/04/0206-振幅変調・復調実験/images/6.3/6.3.4(8)/2k.png>){height=50mm #fig:3-8-2k}

   ![fs: 3[kHz], Vpp: 3[V]](<./documents/04/0206-振幅変調・復調実験/images/6.3/6.3.4(8)/3k.png>){height=50mm #fig:3-8-3k}
