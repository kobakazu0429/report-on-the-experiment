const fs = require("node:fs");
const path = require("node:path");
const { Transform } = require("node:stream");
const traverse = require("traverse");

let base = "";

const traverser = (data) => {
  return traverse(data).map((obj) => {
    if (!obj || typeof obj !== "object") return obj;

    if (obj?.meta) {
      base = obj.meta?.base?.c ?? process.cwd();
    } else if (obj?.t === "CodeBlock") {
      const codeBlock = obj?.c;
      if (!codeBlock) return obj;

      const meta = codeBlock.flat(Infinity);

      const includeIndex = meta.findIndex((v) => v === "include");
      if (includeIndex === -1) return obj;

      const filePath = path.resolve(base, meta[includeIndex + 1]);
      const src = fs.readFileSync(filePath, "utf-8");

      const linesIndex = meta.findIndex((v) => v === "lines");
      if (linesIndex === -1) {
        codeBlock[codeBlock.length - 1] = src;
      } else {
        const lines = meta[linesIndex + 1].split(",");
        const srcLines = src.split("\n");
        const splitedSrc = lines.map((line) => {
          if (line.includes("-")) {
            const [start, end] = line.split("-").map((v) => parseInt(v, 10));
            return srcLines.slice(start - 1, end);
          } else {
            return srcLines[parseInt(line, 10) - 1];
          }
        });
        codeBlock[codeBlock.length - 1] = splitedSrc.flat(Infinity).join("\n");
      }
      return obj;
    }
  });
};

const decoder = new TextDecoder();

const transformer = new Transform({
  objectMode: true,
  transform(chunk, _encoding, done) {
    this.push(JSON.stringify(traverser(JSON.parse(decoder.decode(chunk)))));
    done();
  },
});

process.stdin.pipe(transformer).pipe(process.stdout);
