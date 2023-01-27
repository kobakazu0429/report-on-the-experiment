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
      codeBlock[codeBlock.length - 1] = src;
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
