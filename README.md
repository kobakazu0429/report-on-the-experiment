# report-on-the-experiment

## What is this ?

This is Report on the Experiment tool that markdown to pdf textlint, convert and archive at Kure National College of Technology.

## How to use

1. Shell

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

1. VSCode Build Task

   Press in report.md: `⌘ + ⌃ + B ( + B)`  
   Or, `⌘ + ⌃ + P` → type `Run Build Task (short: build)`

   ⌘: Command  
   ⌃: Shift

So that, your report will be pdf file in the folder.

## Requirements

- pandoc
- pandoc-crossref
- lualatex

```shell
# on Mac
brew install pandoc
brew install pandoc-crossref

# if occurred, pandoc-crossref was compiled with pandoc 2.18 but is being run through 2.19.2.
cd /usr/local/Homebrew/Library/Taps/homebrew/homebrew-core/Formula/
git log --oneline pandoc.rb
# 13c29ad3a1c pandoc 2.19
# 25d00a26e0e pandoc: update 2.18 bottle.
# c243cda1645 pandoc 2.18
# 418b6985490 pandoc: update 2.17.1.1 bottle.
git checkout 25d00a26e0e pandoc.rb
brew unlink pandoc
brew install pandoc

brew install --cask mactex-no-gui
sudo tlmgr update --self --all
sudo tlmgr paper a4
sudo tlmgr install collection-langjapanese
```

## Original Notations

### Units

- `$f \unit{Hz}$` -> $f [Hz]$

↓06〜

- `$f \un{Hz}$` -> $f [Hz]$

### Roman Numbers

- `\rom{1}` -> I
