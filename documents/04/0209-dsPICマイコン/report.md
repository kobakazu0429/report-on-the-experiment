---
header-includes:
# - \usepackage[version=3]{mhchem}
metadata:
  reportInfo:
    subject: dsPICマイコン
    reportNo: 9
  writer:
    class: E4
    no: 14
    group: B
    chief:
    name: 小畠 一泰
  others:
    date: 2020. 11. 18
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

マイコンのデータ表示に良く用いられる, Hitachi HD44780 互換コントローラの LCD について, その使用方法を理解することを目的とする.

# 課題

```{#lst:awesome-code .c .numberLines caption="画面クリア関数を作成せよ."}
void clrLCD(void) {
  RS_pin = 0;  // コマンド送信モード
  delayms(15); // 転送に必要な時間を確保

  // 画面をクリアするにはコマンド表よりカーソルホーム(0b00000010)を転送すれば良いことがわかる.
  // また一度に上位4ビットしか転送できないため, 2度に分けて転送する必要がある.
  PORTB = 0x0000;
  dataout();
  PORTB = 0x0010;
  dataout();
}
```

```{#lst:awesome-code .c .numberLines caption="任意の 1 文字を引数として受け取り, LCD に表示する関数を作成せよ."}
void put_char(char x) {
  // C 言語では char 型の文字は ASCII コードによって内部的に数値として扱われるため,
  // 始めに上位 4 ビットを転送する.
  PORTB = x;
  dataout();
  // その後下位 4 ビットシフトすることで上位 4 ビットとして転送する.
  PORTB = x << 4;
  dataout();
  delayms(15);
}
```

```{#lst:awesome-code .c .numberLines caption="前問 put_char を用いて, 文字列表示関数を作成せよ."}
void put_str(char *str) {
  char i;
  // C 言語では文字列の末尾には「ヌル終端文字列(\0)」が挿入されているので,
  // for ループでヌル終端文字列までを出力することで文字列をまとめて出力できる.
  for (i = 0; str[i] != '\0'; i++) {
    put_char(str[i]);
  }
}
```

\clearpage

```{#lst:awesome-code .c .numberLines caption="カーソルを移動する関数を作成せよ."}
void locate(char x, char y) {
  RS_pin = 0;
  delayms(15);

  // コマンド表より, DDRAM にセットするには 0b1xxxxxxx を転送すれば良いことがわかる.
  // また内部アドレス表より, 1 行目には 00〜0F を, 2行目には40〜4F 転送すれば良いので,
  // 行指定は 1行目　: 0b1000, 2行目　 : 0b1100 となる.
  // 列指定は 1文字目: 0x0000, 16文字目: 0b1111 となる.

  // row
  PORTB = y == 0 ? 0b10000000 : 0b11000000;
  dataout();

  // col
  PORTB = x << 4;
  dataout();
}
```

```{#lst:awesome-code .c .numberLines caption="任意の整数 x を受け取り, 液晶にその数値を表示させる関数を作成せよ."}
void put_num1(int n) {
  // 整数を ASCII コードに直すには, ASCII コード上 0 である 0x30 を足せば良い.
  put_char(0x30 + n);
}
```

```{#lst:awesome-code .c .numberLines caption="put_num1を用いて, 3 桁の整数を受け取り, それを各桁に分けて表示させる関数を作成せよ."}
void put_num3(int n) {
  // C 言語において int 型に実数値を代入すると, 切り捨てられることを利用する.
  int a = n / 100;
  int b = n / 10 % 10;
  int c = n % 10;
  put_num1(a);
  put_num1(b);
  put_num1(c);
}
```

\clearpage

```{#lst:awesome-code .c .numberLines caption="数値 000 から 999 までを表示するプログラムを, put_num3() を用いて作成せよ."}
int i;
for (i = 0; i < 1000; i++) {
  // 1文字分のデータを送ると表示アドレスは内部で自動的にインクリメントされるので,
  // locate() を用いて出力場所を設定する.
  locate(0, 0);
  put_num3(i);
  delayms(200);
}
```

# 参考文献

- 小野寺康幸, 液晶表示のディジタル時計を作る, トランジスタ技術, 2007 年 9 月号 pp123-127
- B.W.KerNIhan & D.M.Ritchie, プログラミング言語 C 第 2 版 ANSI 規格準拠, 共立出版 (1989)
