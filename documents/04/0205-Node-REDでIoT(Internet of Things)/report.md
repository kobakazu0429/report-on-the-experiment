---
header-includes:
# - \usepackage[version=3]{mhchem}
metadata:
  reportInfo:
    subject: Node-REDでIoT(Internet of Things)
    reportNo: 5
  writer:
    class: E4
    no: 14
    group: B
    chief:
    name: 小畠 一泰
  others:
    date: 2020. 11. 18
    weather: 晴れ
    temp: 24.0
    wet: 65.5
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

$$T = \frac{\frac{5000}{2^{10}} V_{out} - 600}{10}$$

温度センサの出力電圧 $V_{out}$ と摂氏温度 $T$ の関係は上式となることから [@lst:stored] は次のようにかける.

```{#lst:stored .js .numberLines caption="1つ目のfunction"}
msg.payload = (msg.payload * 5000 / 1024 - 600 ) / 10;
// フロー全体で共通のグローバル変数に`temperature` という変数名で気温を格納する.
global.set("temperature", msg.payload);
return msg;
```

```{#lst:awesome-code .js .numberLines caption="2つ目のfunction"}
// コード1 の値を取得し代入する.
// 値が格納されていない場合は 0 を代入する.
msg.payload = global.get("temperature") || 0;
return msg;
```

\clearpage

```{#lst:awesome-code .html .numberLines caption="template (mustache)"}
<html>
  <body>
    気温: {{payload}}

    <script>
      setTimeout(window.location.reload, 3000);
    </script>
  </body>
</html>
```

![結果](<./documents/04/0205-Node-REDでIoT(Internet of Things)/images/06-02.png>){#fig:06-02 height=50mm}

# 参考文献

- 特集電脳ガシェット’Pi’でラピッド・プログラミング, トランジスタ技術, 2016 年 6 月号 pp.56-128
- Node-RED のウェブサイト http://nodered.org
- Writing Functions http://nodered.org/docs/writing-functions
- National Semiconductor DS012897-14-JP(2005) http://www.national.com/jpn/
