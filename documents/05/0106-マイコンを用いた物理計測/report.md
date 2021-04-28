---
header-includes:
# - \usepackage[version=3]{mhchem}
metadata:
  reportInfo:
    subject: マイコンを用いた物理計測
    reportNo: 6
  writer:
    class: E5
    no: 14
    group: 4
    chief:
    name: 小畠 一泰
  others:
    date: 2021. 04. 28
    weather: 雨
    temp: 24.22
    wet: 53.77
  partners:
    collaborator1:
    collaborator2:
    collaborator3:
    collaborator4:
---

# 目的

Arduino を用いて温度計測を行う.

# 実験機器

- マイコン: Arduino Leonardo
- 温湿度・気圧センサモジュールキット: BME280

# 実験方法

## 回路

![回路図](./documents/05/0106-マイコンを用いた物理計測/images/schematic.png){#fig:schematic height=50mm}

[@fig:schematic] のような回路をブレッドボード上に組む.

## ソースコード

```{#lst:awesome-code .c .numberLines caption=""}
// ref: https://github.com/finitespace/BME280
#include <BME280I2C.h>
#include <Wire.h>
#define SERIAL_BAUD 115200

BME280I2C bme;
float temp(NAN), hum(NAN), pres(NAN);

void setup() {
  Serial.begin(SERIAL_BAUD);
  while (!Serial); // Wait
  Wire.begin();
  while (!bme.begin()) {
    Serial.println("Could not find BME280 sensor!");
    delay(1000);
  }

  switch (bme.chipModel()) {
    case BME280::ChipModel_BME280:
      Serial.println("Found BME280 sensor! Success.");
      break;
    case BME280::ChipModel_BMP280:
      Serial.println("Found BMP280 sensor! No Humidity available.");
      break;
    default:
      Serial.println("Found UNKNOWN sensor! Error!");
  }

  BME280::TempUnit tempUnit(BME280::TempUnit_Celsius);
  BME280::PresUnit presUnit(BME280::PresUnit_Pa);
}

void loop() {
  bme.read(pres, temp, hum, tempUnit, presUnit);

  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print("°" + String(tempUnit == BME280::TempUnit_Celsius ? 'C' : 'F'));
  Serial.print("\t\tHumidity: ");
  Serial.print(hum);
  Serial.print("% RH");
  Serial.print("\t\tPressure: ");
  Serial.print(pres);
  Serial.println("Pa");
  delay(1000);
}
```

\clearpage

# 成果物

![シリアルモニタの結果](./documents/05/0106-マイコンを用いた物理計測/images/dump.png){#fig:dump height=50mm}

# まとめ

室内の温度と同程度の温度がシリアルモニタに出力されたとともに, センサモジュールを指などで触れることできちんと温湿度の上昇を確認できたことより実験は成功したと考える.

# 参考文献

- AE-BME280 取扱説明書 | 秋月電子通商
  - https://akizukidenshi.com/download/ds/akizuki/AE-BME280_manu_v1.1.pdf
