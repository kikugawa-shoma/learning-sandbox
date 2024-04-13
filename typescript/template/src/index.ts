// node_module import
import _ from "lodash";
// relative import
import { msgA } from "./moduleA";
// absolute import
import { msgB } from "./moduleB";

const msg: string = "hoge";

console.log(msg);

console.log(msgA + " " + msgB);
console.log(_.chunk(["a", "b", "c", "d"], 3));
