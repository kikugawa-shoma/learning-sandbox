# devcontainerのbashrcに追記するコマンドをこのファイルに書いている
alias a='./a.out'
alias g='g++'
alias deno='deno@1.35.1 run --allow-read'

export PS1=\
`seasonalEmoji.sh`\
\
" \[\e[1;36;49m\]"\
"\u@kypro-container "\
"\[\e[1;33;49m\]"\
" \w"\
\
"\[\e[0;39;49m\]"\
`echo -e '\U1F6B4'`\
" "\
"\[\e[0;39;49m\]"
