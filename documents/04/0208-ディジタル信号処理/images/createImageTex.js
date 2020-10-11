const files = [
  { name: "ド", path: "./documents/04/0208-ディジタル信号処理/images/ex03-B-00_guitar_do_c3-1.png" },
  { name: "レ", path: "./documents/04/0208-ディジタル信号処理/images/ex03-B-01_guitar_re_d3-1.png" },
  { name: "ミ", path: "./documents/04/0208-ディジタル信号処理/images/ex03-B-02_guitar_mi_e3-1.png" },
  { name: "ファ", path: "./documents/04/0208-ディジタル信号処理/images/ex03-B-03_guitar_fa_f3-1.png" },
  { name: "ソ", path: "./documents/04/0208-ディジタル信号処理/images/ex03-B-04_guitar_so_g3-1.png" },
  { name: "ラ", path: "./documents/04/0208-ディジタル信号処理/images/ex03-B-05_guitar_ra_a3-1.png" },
  { name: "シ", path: "./documents/04/0208-ディジタル信号処理/images/ex03-B-06_guitar_si_b3-1.png" },
  { name: "ド", path: "./documents/04/0208-ディジタル信号処理/images/ex03-B-07_guitar_do_c4-1.png" },
]

const column = 2;

const chunk = (arr, size) => arr.reduce(
  (newarr, _, i) => (i % size ? newarr : [...newarr, arr.slice(i, i + size)]),
  []
)

const data = chunk(files.map(({ name, path }, i) => {
  return `%${i + 1}
\\begin{minipage}{${1 / column}\\hsize}
  \\begin{center}
    \\includegraphics[keepaspectratio]{${path}}
    \\hspace{1cm} [${i + 1}]${name}
  \\end{center}
\\end{minipage}`;
}), column);

// console.log(data);

const start = `\\begin{figure}[htbp]
\\begin{center}`;
const tableStart = `\\begin{tabular}{c}`;
const tableEnd = `\\end{tabular}`;
const end = `\\end{center}
\\end{figure}`

console.log(start);

data.forEach(v => {
  console.log(tableStart);
  console.log(v.join("\n"));
  console.log(tableEnd);
});

console.log(end);
