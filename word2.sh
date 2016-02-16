#!/bin/bash
echo "reading file: $1"
#read filename
# cat grep awk sort sed cut
cat $1 | sed 's/[^a-zA-Z0-9 _-]//g' |
tr '[:upper:]' '[:lower:]' |
sed 's/ /\n/g' |
sed '/^\s*$/d' |
sort |  uniq -c | awk '{print $2", "$1}' > out2
echo "---------------"
cat out2
#cp $1 output
#cat $1 | tr -cs "[:alpha:]" "\n"

#sed -e 's/[[:alpha].-]//g; /^$/d' output 

#cat output

