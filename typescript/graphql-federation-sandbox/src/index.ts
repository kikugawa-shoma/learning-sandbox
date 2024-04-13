import _ from "lodash";
import { msg2 } from "./module";
import { msg3 } from "moduleA";

const msg: string = "hello";

console.log(msg);

console.log(msg2);
console.log(msg3);
console.log(_.chunk(["a", "b", "c", "d"], 3));
