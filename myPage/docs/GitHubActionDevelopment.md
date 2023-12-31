# GitHub Pages にデプロイするための GitHub Action の開発方法

## myPage の静的なページをホストするために使っている環境

- GitHub Pages を使って静的コンテンツを配信している。

- GitHub Pages のために使用しているディレクトリは[こちら](https://github.com/kikugawa-shoma/kikugawa-shoma.github.io)

## デプロイの構成

- このリポジトリの`/.github/workflows/deploy.yml`がデプロイためのワークフロー

- main ブランチの myPage 配下のファイルに変更がプッシュされたことをトリガーとして上記ワークフローが実行される。

## クレデンシャル周り

- 上記ワークフロー内で GitHub Actions の secrets を参照しているので事前に ssh 鍵の生成・登録が必要

## ローカルでの act を使った実行手順

実行コマンド(act をインストールしていることが必要)

```sh
gh act --secret-file act.secrets
```

act.secrets ファイルの中身(クレデンシャルを含むので git 管理していない)

```env
SSH_PRIVATE_KEY="-----BEGIN OPENSSH PRIVATE KEY-----
example_example_example_example_example_example_example_example
example_example_example_example_example_example_example_example
example_example_example_example_example_example_example_example
...
example_example_example_example_example
-----END OPENSSH PRIVATE KEY-----"
```
