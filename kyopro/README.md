## 環境構築

### イメージビルド

```sh
cd kyopro/cpp
docker compose build
```

### コンテナ起動

#### CLI

```sh
docker compose up -d
```

#### VS Code GUI

1. `Ctrl + Shift + P`を押してコマンドパレットを開く。

2. コマンドパレットで`Dev Containers: Open Folder in Container`を選択

3. kyopro ディレクトリを選択し、OK を押す

### VS Code Extension

- 2024/03/24 現在、vscode_deno の extension のバージョンは 3.27.0 でインストールすること(@see
  https://github.com/denoland/vscode_deno/?tab=readme-ov-file#compatibility)
  - Deno のバージョンを 2024/03/24 現在で AtCoder で実行可能なバージョン（1.35.1）と合わせており、このバージョンに対応している Deno の extension を採用している。もし、extension がエラー出す場合は、VS Code の extension を管理する GUI からバージョンを指定して再インストールすること

### Execution

#### C++

通常の cpp ファイルのコンパイルと実行

```sh
g filename.cpp  # a.outという実行ファイルが同階層に生成される(g++コマンドのaliasを貼っている)
a               # a.outを実行
```

ユニットテストの実行

```sh
g unittestFilename.cpp -lgtest -lgtest_main  # a.outという実行ファイルが同階層に生成される(g++コマンドのaliasを貼っている)
a                                            # a.outを実行
```

#### Python

```sh
python filename.py
```

### TIPS

root ユーザーで dev container に入りたいとき

```sh
docker container exec -it -u root kyopro_cpp bash
```
