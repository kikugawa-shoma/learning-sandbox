/**
 * @returns
 * @example
 * // If stdin is like this
 * 3
 * 1 2 3
 * // The output of input() is like this
 * [
 *   ["1"],
 *   ["1", "2", "3"]
 * ]
 */
export const input = async () => {
  const decoder = new TextDecoder("utf-8");
  return decoder.decode(await Deno.readFile("/dev/stdin")).split("\n").map((
    line: string,
  ) => line.trim().split(" ")).slice(0, -1) as string[][];
};
