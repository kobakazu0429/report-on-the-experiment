---
header-includes:
  # - \usepackage[version=3]{mhchem}
metadata:
  reportInfo:
    subject: ディジタル信号処理
    reportNo: 8
  writer:
    class: E4
    no: 14
    group: 5
    chief:
    name: 小畠 一泰
  others:
    date: 2020. 10. 07
    weather: 晴れ
    temp:
    wet:
  partners:
    collaborator1:
    collaborator2:
    collaborator3:
    collaborator4:
---

# 目的

MATLAB を用いてディジタル信号処理の基本的な処理演習を行い, 理解を深めることを目的とする.

# 実習 I 〜 1 次元信号処理 〜

## ディジタル・サウンド処理 I 〜基本プログラム〜

[課題 1] List 1 を実行し, 録音した声データの波形を確認せよ.

![声データの波形](./documents/04/0208-ディジタル信号処理/images/ex01.png){#fig:ex01 height=70mm}

## ディジタル・サウンド処理 II 〜エコー効果〜

[課題 2] List 2 のパラメータを適宜変更し, エコー効果の違いについてまとめよ.

| 変数名 | 意味                       | 変更結果                                                                 |
| :----- | :------------------------- | :----------------------------------------------------------------------- |
| ap, as | (初期, 高次)反射音の減衰率 | それぞれ 1 にすると rs の数だけ原音がエコーされた.                       |
| dp, ds | (初期, 高次)反射音の遅延   | それぞれ 1 以上にするとヤマビコのように遠い距離で反射されたようになった. |
| rs     | 高次反射音の数             | 値を大きくするとエコー数が増えた.as,ds の値次第で滑らかにもなった.       |

\clearpage

## 周波数分析

[課題 3] List3.m と HannigWindow\_.m を作成し, 配布する音データに対して周波数分析を実施せよ.

![ハニング窓によるドの音の周波数分析結果](./documents/04/0208-ディジタル信号処理/images/ex03-H-00_guitar_do_c3-1.png){height=70mm}

[課題 4] ハニング窓をブラックマン窓に変更して周波数分析を実行せよ.

```{#lst:awesome-code .c .numberLines caption="ブラックマン窓の関数"}
function w = BlackmanWindow_(window_size)
w = zeros(1, window_size);
for n = 1:window_size, %(8.10)式
w(n) = 0.42 - 0.5*cos(2*pi*(n-1)/window_size) + 0.08*cos(4*pi*(n-1)/window_size);
end
```

\begin{figure}[htbp]
\begin{center}
\begin{tabular}{c}
%1
\begin{minipage}{0.5\hsize}
\begin{center}
\includegraphics[keepaspectratio]{./documents/04/0208-ディジタル信号処理/images/ex03-B-00_guitar_do_c3-1.png}
\hspace{0cm} [1]ド
\end{center}
\end{minipage}
%2
\begin{minipage}{0.5\hsize}
\begin{center}
\includegraphics[keepaspectratio]{./documents/04/0208-ディジタル信号処理/images/ex03-B-01_guitar_re_d3-1.png}
\hspace{0cm} [2]レ
\end{center}
\end{minipage}
\end{tabular}
\end{center}
\end{figure}

\clearpage

\begin{figure}[htbp]
\begin{center}
\begin{tabular}{c}
%3
\begin{minipage}{0.5\hsize}
\begin{center}
\includegraphics[keepaspectratio]{./documents/04/0208-ディジタル信号処理/images/ex03-B-02_guitar_mi_e3-1.png}
\hspace{0cm} [3]ミ
\end{center}
\end{minipage}
%4
\begin{minipage}{0.5\hsize}
\begin{center}
\includegraphics[keepaspectratio]{./documents/04/0208-ディジタル信号処理/images/ex03-B-03_guitar_fa_f3-1.png}
\hspace{0cm} [4]ファ
\end{center}
\end{minipage}
\end{tabular}
\begin{tabular}{c}
%5
\begin{minipage}{0.5\hsize}
\begin{center}
\includegraphics[keepaspectratio]{./documents/04/0208-ディジタル信号処理/images/ex03-B-04_guitar_so_g3-1.png}
\hspace{0cm} [5]ソ
\end{center}
\end{minipage}
%6
\begin{minipage}{0.5\hsize}
\begin{center}
\includegraphics[keepaspectratio]{./documents/04/0208-ディジタル信号処理/images/ex03-B-05_guitar_ra_a3-1.png}
\hspace{0cm} [6]ラ
\end{center}
\end{minipage}
\end{tabular}
\begin{tabular}{c}
%7
\begin{minipage}{0.5\hsize}
\begin{center}
\includegraphics[keepaspectratio]{./documents/04/0208-ディジタル信号処理/images/ex03-B-06_guitar_si_b3-1.png}
\hspace{0cm} [7]シ
\end{center}
\end{minipage}
%8
\begin{minipage}{0.5\hsize}
\begin{center}
\includegraphics[keepaspectratio]{./documents/04/0208-ディジタル信号処理/images/ex03-B-07_guitar_do_c4-1.png}
\hspace{0cm} [8]ド
\end{center}
\end{minipage}
\end{tabular}
\end{center}
\caption{ブラックマン窓による周波数分析結果}
\end{figure}

\clearpage

# 実習 II 〜2 次元信号処理〜

## 画像データについて

[課題 5]「画像の保存形式 BMP, JPEG, GIF, PNG などの違い」「色深度」について簡単に自分の言葉でまとめた上で, 演習 1〜3 の結果についてまとめよ.

1. 画像の保存形式

   1. png

      - Portable Network Graphics
      - gif や tiff を置き換えるように設計された.
      - 可逆圧縮: 最大 48 ビットのトゥルーカラーまたは 16 ビットのグレースケールをサポート.
      - TIFF などとは異なり PNG 仕様では実装者がサポートする機能を選択する余地がなく, 堅牢であり, 完全なファイル整合性チェックと一般的な送信エラーの簡単な検出の両方を提供.
        その結果, 1 つのアプリに保存された PNG 画像は, 他の PNG をサポートするアプリケーションでも読み取ることができる.

   1. gif

      - Graphics Interchange Format
      - 高品質で高解像度の表示することを可能にする.
      - 可逆圧縮: 2 色モノクロから 256 色までの色をサポート.
      - Web 黎明期にはスペーサー gif と呼ばれる 1px サイズの画像を用いて余白調整を行なっていた.
        GIF89a からアニメーション gif などがサポートされた.

   1. jpg

      - Joint Photographic Experts Group
      - デジカメの記録方式としてよく利用されている.
      - 不可逆圧縮方式: ファイルサイズと品質間のトレードオフを調整できる.
      - 階調や色の変化が滑らかでリアルなシーンの写真や絵画に最適.
        しかし再圧縮するたびに画質が失われるため, 複数回の編集が必要なファイルには適していない.
        また隣接するピクセル間のシャープなコントラストが顕著な場合アーチファクトを引き起こすため, 科学・医療画像や特定の技術的な画像処理作業などには適さない.
        - アーチファクト(artifacts): 実際の物体ではない二次的に発生した画像

   1. bmp

      - Microsoft Windows Bitmap Image
      - Microsoft と IBM が共同で開発していた頃に作られた画像ファイル形式.
      - 非圧縮/可逆圧縮: 8bit RLE, 4bit RLE, 24bit RLE, 1bit ハフマン符号圧縮.
        - RLE: ランレングス圧縮, 連長圧縮
      - 圧縮方法について定義されているが無圧縮であることが多い.
        CMYK のカラーモードに対応していないため DTP などの印刷用途として用いられない.

\clearpage

2. 色深度

   - 画面や画素が表示可能な色数を表すもの.
     - グレースケール
       - 1bpp: $2^1$ 色(白と黒のモノクロ)になる.
       - 2bpp 以上: 白と黒のあいだに段階を設け灰色を表現する.
     - カラースケール(ビットを RGB それぞれに割り当て, 色を表現する.)
       - 24bpp: RGB それぞれに 8 ビットずつを割り当ることで 256 ($2^8$) の階調を持ち, 約 1677 万色 (256×256×256) を表現できるようになる.

3. [演習 1] 配布した画像を右クリックし, 画像のサイズ(pix)とビット深さを確認せよ.

   `mae_g.jpg`はサイズが 280×340 であり, ビット深さは 8bit であった.
   画像はモノクロであることから $256(2^8)$ 階調のグレースケールであることが分かる.

4. [演習 2] 配布した 8bit グレースケールの画像データを MATLAB に取り込み, 座標に 255〜0 の数値が格納されていることを確認せよ.グレースケールにおける数値と濃淡の関係を確認せよ.

   0 が黒に, 255 が白に, またその間は $1/256$ ごとに黒から白へ変化し濃淡を表していた.

5. [演習 3] 配布した 24bit カラー画像(RGB 形式)を MATLAB に取り込み, 各座標に赤(R)・緑(G)・ 青(B)に関する 255〜0 数値データが格納されていることを確認せよ. 数値の組み合わせと色の関係を確認せよ.

   16×16 の配列が 3 次元に格納されていることを確認した.
   1 次元から 3 次元に連れて RGB となり, また 24bit = 3 x 8bit であるためそれぞれは 0〜255 の値であった.
   また画像自体は 3 次元の配列(RGB)を足し合わせることで各色を表現していた.

## 2 次元データに対するフィルタ処理

[課題 6] List 4 に加重平均 F3, 無方向のエッジ検出 F4 のフィルタ処理を追加記述し, 1 つのグラフに 6 つの画像(原画像, F1〜F4 処理, E1 処理をした画像)を表示せよ.

$$
F_3 = \frac{1}{4.4} \begin{bmatrix}
0.35 & 0.5 & 0.35 \\
0.5 & 1.0 & 0.5 \\
0.35 & 0.5 & 0.35 \\
\end{bmatrix}, \;
F_4 = \begin{bmatrix}
-1 & -1 & -1 \\
-1 & 8 & -1 \\
-1 & -1 & -1 \\
\end{bmatrix}
$$

![各種フィルタ結果](./documents/04/0208-ディジタル信号処理/images/ex06.png){#fig:ex06 height=70mm}

\clearpage

[課題 7] `MATLAB_de_Photography.mlx`を利用した上で, 自身の写真データを取得せよ. その画像データに対して, List4 の改変プログラムを実行せよ.

![自身の写真と各種フィルタ結果](./documents/04/0208-ディジタル信号処理/images/ex07.png){#fig:ex07 height=70mm}

## 2 次元データの周波数分析

[課題 8] 配布した 2 次元周波数分析学習用の画像データついて周波数分析を行い, 分析結果を確認した上で, 2 次元周波数分析の用途等についてサーベイせよ.

1. 2 次元周波数分析の用途

   画像の圧縮技術: JPEG などは画像に含まれる周波数の偏りを利用して圧縮を行っている.

   画像の生成/フィルタ/ノイズ除去: フィルタやノイズを畳み込むことで任意の画像生成ができるとともに, ノイズの原因がわかっている場合は周波数領域の除算をすることで復元が可能である.

![分析結果 1](./documents/04/0208-ディジタル信号処理/images/ex08-01.png){#fig:ex08-01 height=65mm}

\clearpage

![分析結果 2](./documents/04/0208-ディジタル信号処理/images/ex08-02.png){#fig:ex08-02 height=65mm}

[課題 9] 課題 7 で使った web カメラから画像データを取得するプログラムを用いて, 自信の画像データを取得せよ.その画像データに対して, List 5 を用いて周波数分析の結果を確かめよ.

![分析結果](./documents/04/0208-ディジタル信号処理/images/ex09.png){#fig:ex09 height=70mm}

# 参考文献

- 尾知博,「シミュレーションで学ぶディジタル信号処理」CQ 出版社(2001)
- 青木直史,「ディジタル・サウンド処理入門」CQ 出版社(2006)
- 高谷邦夫,「Matlab の総合応用例題による解説」森北出版(2002)
- 青山貴伸, 蔵本一峰, 森口肇「最新使える MATLAB」講談社(2006)
- Intro to PNG Features (http://www.libpng.org/pub/png/pngintro.html)
- Portable Network Graphics (PNG) Specification (Second Edition) (https://www.w3.org/TR/PNG/)
- Graphics Interchange Format (GIF) Specification(https://www.w3.org/Graphics/GIF/spec-gif87.txt)
- JPEG JFIF (https://www.w3.org/Graphics/JPEG/)
- JPEG - Wikipedia (https://ja.wikipedia.org/wiki/JPEG)
- JPEG - Wikipedia (https://en.wikipedia.org/wiki/JPEG)
- Windows bitmap - Wikipedia (https://ja.wikipedia.org/wiki/Windows_bitmap)
- 色深度 | Programming Place Plus 用語集 (https://programming-place.net/ppp/contents/glossary/a/color_depth.html)
- フーリエ変換と画像圧縮の仕組み (https://www.slideshare.net/ginrou799/ss-46355460)
- 画像と空間周波数 | 画像情報処理工学授業資料 (http://www.riec.tohoku.ac.jp/~shioiri/SHIOIRI/For_Classes_files/slide5.pdf)
