## 「ctrl + :」でのエディタとターミナル間の移動ショートカットの登録

1. 「ctrl + shift + p」でコマンドパレットを開き`Open Keyboard Shortcuts (JSON)`をクリック

1. 開いたファイルに以下を追記

```json
[
  {
    "key": "ctrl+oem_1",
    "command": "workbench.action.terminal.focus",
    "when": "editorTextFocus"
  },
  {
    "key": "ctrl+oem_1",
    "command": "workbench.action.focusFirstEditorGroup",
    "when": "terminalFocus"
  },
  // タブの切り替え
  {
    "key": "shift+j",
    "command": "workbench.action.previousEditor",
    "when": "editorFocus && vim.mode == 'Normal'"
  },
  {
    "key": "shift+k",
    "command": "workbench.action.nextEditor",
    "when": "editorFocus && vim.mode == 'Normal'"
  }
]
```

## 参考文献

[【Visual Studio Code】エディターとターミナルのフォーカスを行き来するショートカットの設定方法](https://kamatalog.com/vscode-shortcut-focusmove/)
