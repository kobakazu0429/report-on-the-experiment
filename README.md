# report-on-the-experiment

## What is this ?

This is Report on the Experiment tool that markdown to pdf textlint, convert and archive at Kure National College of Technology.

## How to use

```bash
% chmod +x ./build.sh

# if you know build report number
# like this: % ./build.sh 3
% ./build.sh <report number>

# or, select report number and enter
% ./build.sh
>  1) 共振回路の測定
   2) インダクタンス・静電容量の測定
   3) 単相電力の測定
   4) 過度現象
   5) 回路網定理に関する実験
   6) ダイオードの実験
   7) トランジスタ実験
   8) マイコン実習(2)
   9) ウェブ管理実習
  10) ディジタル論理回路演習I:入出力編
```

So that, your report will be pdf file in the folder.

## Requirements

- pandoc
- pandoc-crossref
- lualatex
