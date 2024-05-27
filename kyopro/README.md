## 環境構築

### イメージビルド

```sh
cd kyopro/cpp
docker compose build
```

### コンテナ起動

```sh
docker compose up -d
```

### VS Code Extension

- 2024/03/24現在、vscode_denoのextensionのバージョンは3.27.0でインストールすること(@see
  https://github.com/denoland/vscode_deno/?tab=readme-ov-file#compatibility)
  - Denoのバージョンを2024/03/24現在でAtCoderで実行可能なバージョン（1.35.1）と合わせており、このバージョンに対応しているDenoのextensionを採用している。もし、extensionがエラー出す場合は、VS Codeのextensionを管理するGUIからバージョンを指定して再インストールすること
