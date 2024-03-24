const input = async () => {
  const decoder = new TextDecoder("utf-8");
  return decoder.decode(await Deno.readFile("/dev/stdin")).split("\n").map((
    line: string,
  ) => line.trim().split(" ")).slice(0, -1) as string[][];
};

const args = await input();

const N = args[0][0];
const A = args[1].map(Number);

const ret: number[] = [];

A.forEach((n, i, arr) => {
  if (i !== arr.length - 1) {
    ret.push(n * arr[i + 1]);
  }
});

console.log(...ret);
