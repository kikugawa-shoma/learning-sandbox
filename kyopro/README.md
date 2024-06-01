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

3. kyoproディレクトリを選択し、OKを押す

### VS Code Extension

- 2024/03/24現在、vscode_denoのextensionのバージョンは3.27.0でインストールすること(@see
  https://github.com/denoland/vscode_deno/?tab=readme-ov-file#compatibility)
  - Denoのバージョンを2024/03/24現在でAtCoderで実行可能なバージョン（1.35.1）と合わせており、このバージョンに対応しているDenoのextensionを採用している。もし、extensionがエラー出す場合は、VS Codeのextensionを管理するGUIからバージョンを指定して再インストールすること

### Execution

#### C++ 

通常のcppファイルのコンパイルと実行
```sh
g filename.cpp  # a.outという実行ファイルが同階層に生成される(g++コマンドのaliasを貼っている)
a               # a.outを実行
```

ユニットテストの実行
```sh
g unittestFilename.cpp -lgtest -lgtest_main  # a.outという実行ファイルが同階層に生成される(g++コマンドのaliasを貼っている)
a                                            # a.outを実行
```

### Python Execution

```sh
python filename.py
```