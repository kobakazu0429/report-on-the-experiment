# #!/bin/bash

TARGET_BUILD_EXPERIMENT=$1

EXPERIMENT_LIST="共振回路の測定 インダクタンス・静電容量の測定 単相電力の測定 過度現象 回路網定理に関する実験 ダイオードの実験 トランジスタ実験 マイコン実習2 ウェブ管理実習 ディジタル論理回路演習I:入出力編 発光ダイオードとフォトトランジスタ実験 マイコン実習3 電解効果トランジスタの基礎実験 OPアンプによる増幅回路実験 PINフォトダイオードを用いた放射線測定 変圧器の特性実験 直流モータの特性実験 直流モータのデューティファクタ制御 ディジタル論理回路演習Ⅱ:組合せ論理回路 ディジタル論理回路演習Ⅱ:順序回路"

if [ ! $TARGET_BUILD_EXPERIMENT ]; then
  select selection in $EXPERIMENT_LIST
    do
      if [ $selection ]; then
        TARGET_BUILD_EXPERIMENT=${REPLY}
        break
      else
        echo "invalid selection."
      fi
    done
fi

array=("01-共振回路の測定" "02-インダクタンス・静電容量の測定" "03-単相電力の測定" "04-過度現象" "05-回路網定理に関する実験" "06-ダイオードの実験" "07-トランジスタ実験" "08-マイコン実習2" "09-ウェブ管理実習" "10-ディジタル論理回路演習I:入出力編" "11-発光ダイオードとフォトトランジスタ実験" "12-マイコン実習3" "13-電解効果トランジスタの基礎実験" "14-OPアンプによる増幅回路実験" "15-PINフォトダイオードを用いた放射線測定" "16-変圧器の特性実験" "17-直流モータの特性実験" "18-直流モータのデューティファクタ制御" "19-ディジタル論理回路演習Ⅱ:組合せ論理回路" "20-ディジタル論理回路演習Ⅱ:順序回路")

echo "Convert now : ${array[TARGET_BUILD_EXPERIMENT - 1]} - md => tex => pdf"

pandoc -F pandoc-crossref -M "crossrefYaml=./crossref_config.yaml" "./documents/${array[TARGET_BUILD_EXPERIMENT - 1]}/report.md" -o "./documents/${array[TARGET_BUILD_EXPERIMENT - 1]}/report.pdf" --pdf-engine=lualatex --template=./mytemplate.tex -N

exit 0
