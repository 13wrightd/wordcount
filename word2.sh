#!/bin/bash
start=$(date +%s%N)


cat "$1" | LC_CTYPE=C sed 's/[^0-9A-Za-z ]//g' |
tr '[:upper:]' '[:lower:]' |
sed 's/ /\n/g' |
sed '/^\s*$/d' |
sort |  uniq -c | awk '{print $2", "$1}' > "$2"


echo "runtime: $(echo "scale=6;($(date +%s%N) - ${start})/(1*10^09)" | bc) seconds" > "$3"



