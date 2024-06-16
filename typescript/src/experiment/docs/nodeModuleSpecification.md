# Node.js v18 のモジュール仕様を読んで理解する

## 対象ドキュメント

- [CommonJS](https://nodejs.org/docs/latest-v18.x/api/modules.html)
- [ECMAScript module](https://nodejs.org/docs/latest-v18.x/api/esm.html)
- [Packages](https://nodejs.org/docs/latest-v18.x/api/packages.html)
- [node:module API](https://nodejs.org/docs/latest-v18.x/api/module.html)

## [CommonJS](https://nodejs.org/docs/latest-v18.x/api/modules.html)

CommonJS module は Node.js において JavaScript のコードをパッケージ化するオリジナルな方法です。Node.jsはwebブラウザとその他のJavaScriptランタイムで採用されているECMAScript moduleもサポートします。

Node.jsではそれぞれのソースコードファイルは分割されたモジュールとして扱われます。例えば、`foo.js`という名前の以下のコードが書かれたファイルを考えてみましょう。

```js
const circle = require('./circle.js');
console.log(`The area of a circle of radius 4 is ${circle.area(4)}`);
```

最初の一行目で`foo.js`では、`foo.js`と同じディレクトリに存在する`circle.js`モジュールをロードしています。
以下が`circle.js`の内容です。
```js
const { PI } = Math;

exports.area = (r) => PI * r ** 2;

exports.circumference = (r) => 2 * PI * r;
```
`circle.js`モジュールは`area()`と`circumference()`関数をエクスポートしています。
特別な`exports`オブジェクトのプロパティに割り当てることで、関数やオブジェクトをモジュールルートに追加することが可能です。
Node.jsによってモジュールは関数内にラップされる(詳しくは[module wrapper](https://nodejs.org/docs/latest-v18.x/api/modules.html#the-module-wrapper)の節を見てください)ので、モジュール内でローカルな変数はプライベートなものになるでしょう。
上記のコード例だと、`PI`変数は`circle.js`にプライベートな変数になります(=`PI`変数は`foo.js`では参照できないということ)

`module.export`プロパティに対して新たな値(関数やオブジェクト)を割り当てることができます。
以下では、`bar.js`でSquareクラスをエクスポートしている`square`モジュールを使用しています。
```js
const Square = require('./square.js');
const mySquare = new Square(2);
console.log(`The area of mySquare is ${mySquare.area()}`); 
```

`square`モジュールは`square.js`内で以下のように定義されています。

```js
// Assigning to exports will not modify module, must use module.exports
module.exports = class Square {
  constructor(width) {
    this.width = width;
  }

  area() {
    return this.width ** 2;
  }
};
```
CommonJSのモジュールシステムは[`module`という名前のコアモジュール](https://nodejs.org/docs/latest-v18.x/api/module.html)内で実装されています。

### Enabling

Node.jsは2つのモジュールシステムを持っています。その2つとは、CommonJSモジュールとECMAScriptモジュールです。

デフォルトではNode.jsは以下をCommonJSモジュールとして扱います。
- `.cjs`拡張子のファイル
- `.js`拡張子のファイルであり、最も近い親の`package.json`ファイルにおいてトップレベルの`type`フィールドの値が`commonjs`である場合
- `.js`拡張子のファイルであり、最も近い親の`packages.json`ファイルにといて、トップレベルの`type`フィールドが存在しない場合。パッケージのオーサーは、たとえそのパッケージ内のすべてのソースコードがCommonJSだとしても、`type`フィールドを含めておくべきである。パッケージの`type`について明白になっていることによって、ビルドツールやローダーがそのパッケージがどのように解釈されるかを決めることが簡単になります。
- `.mjs`、`.cjs`、`.json`、`.node`、`.js`の拡張子ではないファイル(ただし、最も近い親の`package.json`がトップレベルの`type`フィールドに`module`という値を持つ場合においては、プログラムのコマンドラインエントリーポイントでｈなく、`require()`を介してインクルードされる場合においてCommonJSとして認識されます。)

より詳しくは[モジュールシステムが決定される方法](https://nodejs.org/docs/latest-v18.x/api/packages.html#determining-module-system)をご参照ください。

`require()`で呼ぶとCommonJSモジュールローダーが使われ、`import()`で呼ぶとECMAScriptモジュールローダーが使われる。

### Accessing the main module

あるファイルがNode.jsに直接実行させるとき、`require.main`がそれ自身の`module`にセットされます。これはつまり、`require.main === module`を試すことにより、そのファイルが直接実行されているのかどうかを判断することが可能ということです。

例えば、`foo.js`で言うと、`node foo.js`のコマンドで実行した場合は先程の評価式は`true`と評価され、`require('./foo')`で実行された場合は`false`と評価されるということです。
エントリーポイントがCommonJSモジュールではない場合は、`require.main`は`undefined`になり、メインモジュールには到達できなくなります。

### Package manager tips

Node.jsの`require()`関数のセマンティクスは、充分に一般的であるように設計されているので、合理的なディレクトリ構造をサポートすることができます。`dpkg`や`rpm`や`npm`などのパッケージマネージャープログラムは、うまくいけば、修正を加えることなく、Node.jsモジュールからネイティブパッケージをビルドすることが可能になるでしょう。

以下にうまく機能する提案されたディレクトリ構造を示します。

`/usr/lib/node/<some-package>/<some-version>`という場所にフォルダを持ち、そのフォルダにパッケージの特定のバージョンを管理したいとしましょう。

パッケージはお互いに依存する可能性があります。`foo`パッケージをインストールするために、`bar`パッケージの特定のバージョンをインストールする必要があるかもしれません。`bar`パッケージはそれ自身もまた依存先を持っていることもありますし、依存関係が衝突したり循環参照になることもありかもしれません。

Node.jsはロードするモジュールの実パスを調べ（つまりシンボリックリンクを解決し）、それから`node_modules`フォルダで依存関係を探すので、この状況は以下のアーキテクチャで解決できる：

- `/usr/lib/node/foo/1.2.3/`: fooパッケージのバージョン1.2.3の内容
- `/usr/lib/node/bar/4.3.2/`: fooパッケージが依存しているbarパッケージの内容
- `/usr/lib/node/foo/1.2.3/node_modules/bar`: `/usr/lib/node/bar/4.3.2/`へのシンボリックリンク
- `/usr/lib/node/bar/4.3.2/node_modules/*`: barパッケージが依存しているパッケージ群へのシンボリックリンク

それゆえ、循環参照があったり、依存関係のコンフリクトがあったりする場合もすべてのパッケージはそのパッケージが使うことのできるバージョンの依存先を取得することができる。

`foo`パッケージのコードで`require('bar')`が書かれてあると、`/usr/lib/node/foo/1.2.3/node_modules/bar`でシンボリックリンクが張られているバージョンを取りに行くでしょう。そして、取得先の`bar`パッケージのコードで`require('quux')`が書かれていると、`/usr/lib/node/bar/4.3.2/node_modules/quux`でシンボリックリンクが張られているバージョンを取りに行くでしょう。




