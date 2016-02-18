#!/bin/bash
echo "reading file: $1"
#read filename
# cat grep awk sort sed cut
cat "$1" | LC_CTYPE=C sed 's/[^0-9A-Za-z ]//g' |
tr '[:upper:]' '[:lower:]' |
sed 's/ /\n/g' |
sed '/^\s*$/d' |
sort |  uniq -c | awk '{print $2", "$1}' > "$2"
echo "---------------"
cat "$2"
#cp $1 output
#cat $1 | tr -cs "[:alpha:]" "\n"

#sed -e 's/[[:alpha].-]//g; /^$/d' output 

#cat output

