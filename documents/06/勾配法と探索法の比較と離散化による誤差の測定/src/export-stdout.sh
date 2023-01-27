PATCH="./patch.exe"
CC="gcc"
OPTIONS="gene.o -o main"

OUT=out

TARGETS=(
  g1.c
  g1g.c
  g2.c
  g2g.c
  g3.c
  g3g.c
  ga.c
  # ga-ex.c
)

function exec_stdout() {
  target=$1
  out=$2

  touch $out
  echo "$ ./main" >> $out
  $CC $target $OPTIONS
  ./main >> $out

  echo "done $out"
}

function p() {
  target=$1
  patch_file=$2

  out="$OUT/$patch_file.out"

  echo $patch_file

  $PATCH -u --binary $target < $patch_file

  exec_stdout $target $out

  $PATCH -R --binary $target < $patch_file
}

function cleanup() {
  rm main
  rm ./*.csv
}

function main() {
  mkdir -p $OUT

  for target in ${TARGETS[@]}; do
    out="$OUT/$target.out"
    exec_stdout $target $out
  done

  p g1g.c g1g-a0.1.patch
  p g2g.c g2g-x0.patch
  p g2g.c g2g-x10.patch
  p g3g.c g3g-x00.8-x10.2.patch

  cleanup
}


main
