---
header-includes:
# - \usepackage[version=3]{mhchem}
metadata:
  reportInfo:
    subject: 電子回路設計製作と特性試験
    reportNo: 4
  writer:
    class: E5
    no: 14
    group: 4
    chief:
    name: 小畠 一泰
  others:
    date: 2021. 04. 14
    weather: 晴れ
    temp:
    wet:
  partners:
    collaborator1:
    collaborator2:
    collaborator3:
    collaborator4:
---

# 実験テーマ

Arduino と LCD を用いた簡易時計の作成

# 目的

Arduino の基本的な使い方や割り込み処理についての理解を深めるとともに, LCD を用いて外部出力を行う.

# 実験機器

- マイコン: Arduino Uno
- LCD: $3.3 \unit{V}$ 動作 LCD キャラクタディスプレイモジュール 16x2 行バックライト付白抜き(SC1602BBWB-XA-LB-G)
- 抵抗: $1 \unit{k \Omega}$
- タクトスイッチ

# 要件定義

- 1 秒ごとに画面が更新され hh:mm:ss のフォーマットで時刻が表示されること.
  - 12 時 34 分 56 秒の場合は 12:34:56 となること.
- 2 つのタクトスイッチがあること.
  - 時刻表示モード
    - NEXT_CURSOR: 設定モードへ移行すること.
    - ADD: 動作未割り当て
  - 時刻設定モード
    - NEXT_CURSOR: hh, mm, ss それぞれの下位もしくは決定, キャンセル([@fig:expect_output_config]の下線部)へ移動すること.
    - ADD
      - hh, mm, ss: それぞれ 1 時間, 1 分, 1 秒加算すること.
      - 決定: 時刻を設定した時間へ変更し, 時刻表示モードへ移行すること.
      - キャンセル: 時刻を変更せずに, 時刻表示モードへ移行すること.

![時刻表示モード](./documents/05/0104-電子回路設計製作と特性試験/images/expect_output_normal.png){#fig:expect_output_normal height=30mm}

![時刻設定モード](./documents/05/0104-電子回路設計製作と特性試験/images/expect_output_config.png){#fig:expect_output_config height=30mm}

# 実験方法

## 回路

![回路図](./documents/05/0104-電子回路設計製作と特性試験/images/schematic.png){#fig:schematic height=50mm}

[@fig:schematic] のような回路をブレッドボード上などに組む.

実際に作成したブレッドボードが [@fig:schematic_real] である.

![実際の回路](./documents/05/0104-電子回路設計製作と特性試験/images/schematic_real.JPG){#fig:schematic_real height=60mm}

\clearpage

## ソースコード

```{#lst:awesome-code .c .numberLines caption=""}
#include <LiquidCrystal.h> // LCD 制御ライブラリ
#include <MsTimer2.h>      // 割り込み処理ライブラリ

// LiquidCrystal(RS, R/W, Enable, d4, d5, d6, d7)
LiquidCrystal lcd(13, 12, 11, 10, 9, 8, 7);

#define SELECT_NEXT_PIN 2
#define ADD_TIME_PIN 1

boolean isConfig = false;
unsigned long seconds = 0;
unsigned long tmp_seconds = 0;
int cursor = 0;

// col, row
char cursorPostions[5][2] = {
    { 1, 0},  //  hour
    { 4, 0},  //  minute
    { 7, 0},  //  second
    {10, 0},  //  OK
    {10, 1},  //  Cancel
};

void setup() {
  pinMode(SELECT_NEXT_PIN, INPUT);
  pinMode(ADD_TIME_PIN, INPUT);

  MsTimer2::set(1000 /*[ms]*/, countUp);
  MsTimer2::start();

  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(formatTime(seconds));
}
```

```{#lst:awesome-code .c .numberLines caption=""}
void countUp() {
  seconds++;
  if (isConfig == false) {
    lcd.clear();
    lcd.print(formatTime(seconds));
  }
}

// 秒数を受け取って hh:mm:ss にフォーマットする
String formatTime(unsigned long raw_s) {
  int h = raw_s / 3600;
  int m = raw_s / 60 % 60;
  int s = raw_s % 60;

  char time[20];
  sprintf(time, "%02d:%02d:%02d", h, m, s);
  return time;
}

// 時刻の加算をする, 各桁がそれぞれの最大 (hh:23, mm,ss: 59) を超えたら 0 に戻す
void addTime() {
  if (cursor == 0) {
    if (((tmp_seconds + 3600) / 3600) < 24) tmp_seconds += 3600;
    else tmp_seconds -= tmp_seconds / 3600 * 3600;
  }
  if (cursor == 1) {
    if (((tmp_seconds + 60) / 60 % 60) != 0) tmp_seconds += 60;
    else tmp_seconds -= (tmp_seconds / 60 % 60) * 60;
  }
  if (cursor == 2) {
    if (((tmp_seconds + 1) % 60) != 0) tmp_seconds += 1;
    else tmp_seconds -= tmp_seconds % 60;
  }

  lcd.clear();
  lcd.print(formatTime(tmp_seconds) + "  OK");
  lcd.setCursor(0, 1);
  lcd.print("          Cancel");
  lcd.setCursor(cursorPostions[cursor][0], cursorPostions[cursor][1]);
}
```

```{#lst:awesome-code .c .numberLines caption=""}
void ok() {
  seconds = tmp_seconds;
  isConfig = false;
}

void cancel() {
  isConfig = false;
}

void next_cursor() {
  cursor = ++cursor % 5;
  lcd.setCursor(cursorPostions[cursor][0], cursorPostions[cursor][1]);
}

void loop() {
  // 時刻表示モード
  if (isConfig == false) {
    if (digitalRead(SELECT_NEXT_PIN) == HIGH) {
      // 時刻設定モードへ移行
      isConfig = true;
      tmp_seconds = seconds;
      lcd.clear();
      lcd.print(formatTime(tmp_seconds) + "  OK");
      lcd.cursor();
      lcd.setCursor(0, 1);
      lcd.print("          Cancel");
      lcd.setCursor(cursorPostions[cursor][0], cursorPostions[cursor][1]);
    }
    lcd.noCursor();
  }

  // 時刻設定モード
  if (isConfig == true) {
    lcd.cursor();

    if (digitalRead(SELECT_NEXT_PIN) == HIGH) {
      next_cursor();
      delay(300);
    }

    if (digitalRead(ADD_TIME_PIN) == HIGH) {
      if (cursor <= 2) addTime();
      if (cursor == 3) ok();
      if (cursor == 4) cancel();
      delay(300);
    }
  }
}
```

\clearpage

# 成果物

![時刻表示モード](./documents/05/0104-電子回路設計製作と特性試験/images/result_normal.jpg){#fig:result_normal width=70mm}

![時刻設定モード](./documents/05/0104-電子回路設計製作と特性試験/images/result_config.jpg){#fig:result_config width=70mm}

# まとめ

要件通りに設計, 実験することができ成果物として申し分ないものができたと考える.
また普段あまり触る機会のない LCD や割り込み処理を使うことで, Arduino の基本的な使い方だけでなくより深い知識, 知見を得ることができ非常に理解が高まった.

# 参考文献

- SC1602BBWB-XA-LB-G データシート
  - https://akizukidenshi.com/download/ds/sunlike/SC1602BBWB-XA-LB-G.pdf
- LiquidCrystal Library の各ファンクション | ArduinoRef | 電子工作(MAKE)
  - https://www.denshi.club/make/arduinoorg/arduino-ref01c.html
- Arduino を用いて LCD に文字を表示 - Arduino - 基礎からの IoT 入門
  - https://iot.keicode.com/arduino/arduino-project-lcd.php
