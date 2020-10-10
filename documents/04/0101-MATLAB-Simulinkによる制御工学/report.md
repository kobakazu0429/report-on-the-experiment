---
header-includes:
# - \usepackage[version=3]{mhchem}
metadata:
  reportInfo:
    subject: MATLAB/Simulinkによる制御工学
    reportNo: 1
  writer:
    class: E4
    no: 14
    group: 5
    chief:
    name: 小畠 一泰
  others:
    date: 2020. 06. 04
    weather: 晴れ
    temp: 27.0
    wet: 68.0
  partners:
    collaborator1:
    collaborator2:
    collaborator3:
    collaborator4:
---

# 目的

MATLAB/Simulink による制御工学のシミュレーション方法を習得するとともに, 制御工学を理解することを目的とする.

# 課題

1.  $\frac{1}{s^2 + 0.5s + 1}$ について, ステップ応答, ナイキスト線図, ボード線図, ニコルス線図を作成せよ.

    [@fig:model1] と次のスクリプトコードより, [@fig:untitled1] 〜 [@fig:untitled4] を作成した.

    ![ブロック線図](./documents/04/01-MATLAB-Simulinkによる制御工学/images/1/model.png){#fig:model1 width=80mm}

    ```{#lst:awesome-code .c .numberLines caption="Matlabのスクリプトコード"}
    [num, den] = linmod("model");

    tt = 0.0:0.01:25.0;
    step(num, den, tt)
    nyquist(num, den)
    bode(num, den);
    grid

    nichols(num, den);
    ngrid
    ```

    ![スッテプ応答結果](./documents/04/01-MATLAB-Simulinkによる制御工学/images/1/untitled1.png){#fig:untitled1 height=60mm}

    ![ナイキスト線図結果](./documents/04/01-MATLAB-Simulinkによる制御工学/images/1/untitled2.png){#fig:untitled2 height=60mm}

    ![ボード線図結果](./documents/04/01-MATLAB-Simulinkによる制御工学/images/1/untitled3.png){#fig:untitled3 height=60mm}

    \clearpage

    ![ニコルス線図結果](./documents/04/01-MATLAB-Simulinkによる制御工学/images/1/untitled4.png){#fig:untitled4 height=60mm}

1.  図の回路の電流波形を求めよ. 回路方程式を示し, ブロック線図を作成し, シミュレーション結果を示せ.

    1.  $R-L$直列回路: $R = 1\unit{\ohm}, L = 10\unit{mH}$

        ![RL直列回路](./documents/04/01-MATLAB-Simulinkによる制御工学/images/2/RL-c.png){#fig:RL-c width=80mm}

        回路網に流れる電流を $i(t)$ とすると回路方程式は次のとおりになる.

        $$E = Ri(t) + L\frac{di(t)}{dt}$${#eq:RL}

        これをモデル化すると, [@fig:RL-model] のようになり Simulink でシミュレーションした結果を [@fig:RL-scope] に示す.

        \clearpage

        ![RL直列回路ブロック線図](./documents/04/01-MATLAB-Simulinkによる制御工学/images/2/RL-model.png){#fig:RL-model width=100mm}

        ![RL直列回路シミュレーション結果](./documents/04/01-MATLAB-Simulinkによる制御工学/images/2/RL-scope.png){#fig:RL-scope width=80mm}

        [@eq:RL] をラプラス変換すると,

        $$\frac{E}{s} = sLI(s) + RI(s)$$

        となり, これを $I(s)$ について解くと次のようになる.

        $$I(s) = \frac{E}{s} \frac{1}{sL + R} = \frac{E}{R} (\frac{1}{s} - \frac{1}{s + \frac{R}{L}})$${#eq:RLI}

        [@eq:RLI] を逆ラプラス変換し, $i(t)$ を求める.

        $$i(t) = \mathcal{L}^{-1}[I(s)] = \frac{E}{R} (1 - e^{-\frac{R}{L}t})$${#eq:RLi}

        [@eq:RLi] と初期値 $i(0) = 0$ および, 定常値 $i(\infty) = \frac{E}{R} = \frac{5}{1} = 5$ より, シミュレーション結果は正しいと判断でき実験は成功であるといえる.

        \clearpage

    1.  $R-C$直列回路: $R = 1\unit{\ohm}, C = 1000\unit{\micro F}$

        ![RC直列回路](./documents/04/01-MATLAB-Simulinkによる制御工学/images/2/RC-c.png){#fig:RC-c width=80mm}

        回路方程式は次のとおりである.

        $$E = Ri(t) + \frac{1}{C} \int i(t) dt$${#eq:RC}

        これをモデル化すると, [@fig:RC-model] のようになり Simulink でシミュレーションした結果を [@fig:RC-scope] に示す.

        ![RC直列回路ブロック線図](./documents/04/01-MATLAB-Simulinkによる制御工学/images/2/RC-model.png){#fig:RC-model width=100mm}

        \clearpage

        ![RC直列回路シミュレーション結果](./documents/04/01-MATLAB-Simulinkによる制御工学/images/2/RC-scope.png){#fig:RC-scope width=80mm}

        また$R-L$直列回路と同様に[@eq:RC]から電流を導く.

        $$\frac{E}{s} = RI(s) + \frac{1}{sC}I(s) = (R + \frac{1}{sC})I(s)$$

        $$I(s) = \frac{E}{s} \frac{1}{R + \frac{1}{sC}} = \frac{E}{R} \frac{1}{s + \frac{1}{RC}}$$

        $$i(t) = \mathcal{L}^{-1}[I(s)] = \frac{E}{R} e^{-\frac{1}{RC}t}$${#eq:RCi}

        [@eq:RCi] より初期値は $i(0) = \frac{E}{R} = \frac{5}{1} = 5$, 定常値は $i(\infty) = \frac{E}{R} \frac{1}{\infty} = 0$ となる.
        したがってシミュレーション結果は正しいと判断でき実験は成功であるといえる.

        \clearpage

    1.  $R-L-C$直列回路: $R = 1\unit{\ohm}, L = 10\unit{mH}, C = 1000\unit{\micro F}$

        ![RLC直列回路](./documents/04/01-MATLAB-Simulinkによる制御工学/images/2/RLC-c.png){#fig:RLC-c width=65mm}

        回路方程式は次のとおりである.

        $$E = Ri(t) + L\frac{di(t)}{dt} + \frac{1}{C} \int i(t) dt$${#eq:RLC}

        これをモデル化すると, [@fig:RLC-model] のようになり Simulink でシミュレーションした結果を [@fig:RLC-scope] に示す.

        ![RLC直列回路ブロック線図](./documents/04/01-MATLAB-Simulinkによる制御工学/images/2/RLC-model.png){#fig:RLC-model width=90mm}

        ![RLC直列回路シミュレーション結果](./documents/04/01-MATLAB-Simulinkによる制御工学/images/2/RLC-scope.png){#fig:RLC-scope width=75mm}

        \clearpage

        また$R-L-C$直列回路と同様に[@eq:RLC]から電流を導く.

        $$\frac{E}{s} = RI(s) + sLI(s) + \frac{1}{sC}I(s)$$

        $$I(s) = \frac{E}{s} \frac{1}{R + sL + \frac{1}{sC}} = \frac{E}{s^2L + sR + \frac{1}{C}}$${#eq:RLCIa}

        $$s^2L + sR + \frac{1}{C} = L(s^2 + \frac{R}{L}s + \frac{1}{LC}) = L[(s + \frac{R}{2L})^2 + \{ \frac{1}{LC} - (\frac{R}{2L})^2\}]$${#eq:omega}

        ここで, $\alpha = \frac{R}{2L}$ とおき, [@eq:omega] を

        $$\omega^2 = \frac{1}{LC} - (\frac{R}{2L})^2$$

        とおけば, [@eq:RLCIa] は次のようになる.

        $$I(s) = \frac{E}{L} \frac{1}{(s+\alpha)^2 + \omega^2} = \frac{E}{\omega L} \frac{\omega}{(s+\alpha)^2+\omega^2}$$

        $$i(t) = \mathcal{L}^{-1}[I(s)] = \frac{E}{\omega L} e^{-\alpha t} sin \omega t = \frac{E}{\sqrt{\frac{L}{C} - (\frac{R}{2})^2}} e^{- \frac{R}{2L} t} sin \sqrt{\frac{1}{LC} - (\frac{R}{2L})^2}  t$${#eq:RLCi}

        ここで上次のようにおき, Matlab でプロットすることにした.
        その結果を [@fig:RLCmatlab] に示す.

        \begin{eqnarray}
        \left\{
        \begin{array}{l}
        A = \frac{E}{\sqrt{\frac{L}{C} - (\frac{R}{2})^2}} \nonumber \\
        B = e^{- \frac{R}{2L} t} \nonumber \\
        C = sin \sqrt{\frac{1}{LC} - (\frac{R}{2L})^2} t \nonumber \\
        D = A \times B \times C \nonumber
        \end{array}
        \right.
        \end{eqnarray}

        \clearpage

        <!-- FIX: _ to * -->

        ```{#lst:awesome-code .c .numberLines caption="Matlabのスクリプトコード"}
        t = 0 : 0.001 : 0.15;

        E = 5;
        R = 1;
        L = 0.01;
        C = 0.001;

        A = E / sqrt(L/C - (R/2)^2);
        yline(A); hold on;

        B = exp(-t * R / (2*L));
        plot(t, B, "b--");

        C = sin(sqrt(1/(L*C) - (R/(2*L))^2) \* t);
        plot(t, C, "r--");

        plot(t, A _ B ._ C);

        legend("A", "B", "C", "D"); hold off;
        ```

        \clearpage

        ![[@eq:RLCi]をMatlabでプロットした結果](./documents/04/01-MATLAB-Simulinkによる制御工学/images/2/RLC-matlab.png){#fig:RLCmatlab height=60mm}

        ここで[@fig:RLC-scope]と[@fig:RLCmatlab]を比べると同様の波形を示しており, 実験は成功であることが分かる.

# 参考文献

- 青山貴伸, 蔵元一峰, 森口肇, 最新使える MATLAB, 講談社(2006)
- 杉江俊治, 藤田政之, フィードバック制御入門, コロナ社(1999)
