#!/bin/bash

SEASON_EMOJIS=(
  '\U1F38D'  # 🎍
  '\U1F36B'  # 🍫
  '\U1F38E'  # 🎎
  '\U1F338'  # 🌸
  '\U1F38F'  # 🎏
  '\U2614'   # ☔
  '\U1F320'  # 🌠
  '\U1F31E'  # 🌞
  '\U1F3BE'  # 🎾
  '\U1F47B'  # 👻
  '\U1F342'  # 🍂
  '\U1F385'  # 🎅
)

DAY_EMOJIS=(
  '\U1F319'  # 🌙
  '\U1F525'  # 🔥
  '\U26F2	'  # ⛲
  '\U1F333'  # 🌳
  '\U1F37A'  # 🍺
  '\U1F30F'  # 🌏
  '\U1F31E'  # 🌞
)

# '1F4B0'  # 💰

monthStr=`date +%m`
monthNum=`echo $(( 10#$monthStr ))`

dayStr=`date +%u`
dayNum=`echo $(( 10#$dayStr ))`

echo -en ${SEASON_EMOJIS[$[${monthNum}-1]]}
echo -en ${DAY_EMOJIS[$[${dayNum}-1]]}
