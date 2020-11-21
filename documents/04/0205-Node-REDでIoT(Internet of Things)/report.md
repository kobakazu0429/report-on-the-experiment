---
header-includes:
# - \usepackage[version=3]{mhchem}
metadata:
  reportInfo:
    subject: Node-REDでIoT(Internet of Things)
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

ネットワーク機能を持った IoT 機器を開発するために生まれたツール, Node-RED の基本的な使い方を習得することを目的とする.

# 課題

## アナログ温度センサ LM61BIZ の読み込み

National Semiconductor 製の単一正電源動作温度センサ IC, LM61 を使用して温度を測定した.

![ノード](<./documents/04/0205-Node-REDでIoT(Internet of Things)/images/06-01.png>){#fig:06-01 height=50mm}

![結果](<./documents/04/0205-Node-REDでIoT(Internet of Things)/images/06-02.png>){#fig:06-02 height=50mm}

<!-- ```{#lst:awesome-code .c .numberLines caption="任意の整数 x を受け取り, 液晶にその数値を表示させる関数を作成せよ."}
void put_num1(int n) {
  put_char(0x30 + n);
}
``` -->

# 参考文献

- 特集電脳ガシェット’Pi’でラピッド・プログラミング, トランジスタ技術, 2016 年 6 月号 pp.56-128
- Node-RED のウェブサイト http://nodered.org
- Writing Functions http://nodered.org/docs/writing-functions
- National Semiconductor DS012897-14-JP(2005) http://www.national.com/jpn/
