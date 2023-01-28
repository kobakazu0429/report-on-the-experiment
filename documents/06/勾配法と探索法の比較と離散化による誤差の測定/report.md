---
header-includes:
# - \usepackage[version=3]{mhchem}
metadata:
  reportInfo:
    subject: 勾配法と探索法の比較と離散化による誤差の測定
    reportNo: 2
  writer:
    class: S1
    no: 17
    group:
    chief:
    name: 小畠 一泰
  others:
    date: 2023. 1. 30
    weather:
    temp:
    wet:
  partners:
    collaborator1:
    collaborator2:
    collaborator3:
    collaborator4:
---

# 目的

関数の最小・最大化問題のような最適化問題の解法は, 数学的に関数が微分可能であれば容易に解を得ることができる.
しかし, 関数の微分が困難な場合や不可能な場合は, 関数の最小・最大値を得ることができない.
このような場合, 数値微分を使った勾配法や遺伝的アルゴリズムを応用した探索法などにより解を得る方法がある.
勾配法は傾斜に沿って少ない計算で比較的早く解を発見することができるが多くの局所的な最適解が存在する場合は広域的な最適解を発見することが困難な場合がある.
また, 遺伝的アルゴリズムのような探索法を用いた場合, 広域的な解を発見する確率は上がるが解を得るために多くの計算時間を必要とする場合がある.

本演習は, 勾配法による解の発見や探索法による解の発見を行いその比較を行う.
また, 勾配法に用いる数値微分や遺伝的アルゴリズムを用いる際の探索範囲の離散化による誤差の測定を行う.

# 関数 g1 の確認

```{#lst:g1 .c .numberLines caption="テストプログラム：関数g1の確認処理(g1.c)" include=g1.c}

```

![関数g1の値](./documents/06/勾配法と探索法の比較と離散化による誤差の測定/images/g1.png){#fig:g1 height=50mm}

## 勾配法による解の発見や探索法による解の発見を行いその比較を行う

```{#lst:g1g .c .numberLines caption="勾配法による関数g1の最小値を求める処理(g1g.c)" include=g1g.c}

```

```{#lst:g1-out caption="g1の最小値を求めた結果" include=out/g1g.c.out}

```

## 複数の解を持つ関数の勾配法による解の発見

```{#lst:g2 .c .numberLines caption="勾配法による関数g2解の探索(g2.c)" include=g2.c}

```

![関数g2の値](./documents/06/勾配法と探索法の比較と離散化による誤差の測定/images/g2.png){#fig:g2 height=50mm}

```{#lst:g2g .c .numberLines caption="勾配法による関数g2解の探索(g2g.c)" include=g2g.c}

```

```{#lst:g2g-out caption="初期値にx1=-10を選び回を探索した結果" include=out/g2g.c.out}

```

```{#lst:g2g-x10-out caption="初期値にx1=10を選び回を探索した結果" include=out/g2g-x10.patch.out}

```

```{#lst:g2g-x0-out caption="初期値にx1=0を選び回を探索した結果" include=out/g2g-x0.patch.out}

```

## 多元関数の最小値の探索問題

```{#lst:g3 .c .numberLines caption="テストプログラム：関数g3の確認処理(g3.c)" include=g3.c}

```

![関数g3の値](./documents/06/勾配法と探索法の比較と離散化による誤差の測定/images/g3.png){#fig:g3 height=50mm}

```{#lst:g3g .c .numberLines caption="勾配法による関数g3の最小値を求める処理(g3g.c)" include=g3g.c}

```

```{#lst:g3g-out caption="g3g.cの初期値x0=-10, x1=-10により探索を行った結果" include=out/g3g.c.out}

```

```{#lst:g3g-x00.8-x10.2-out caption="g3g.cの初期値x0=-0.8, x1=0.2により探索を行った結果" include=out/g3g-x00.8-x10.2.patch.out}

```

## GA による探索を用いた解法

```{#lst:ga .c .numberLines caption="GAによる解の探索" include=ga.c}

```

```{#lst:ga-out caption="GAにより探索を行った結果" include=out/ga.c.out lines=1,6003}

```
