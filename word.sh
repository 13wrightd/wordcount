#!/bin/bash
echo "reading file: $1"
#read filename
# cat grep awk sort sed cut
cat $1 | sed 's/[^a-zA-Z0-9 _-]//g' > out
#cat out | sed  "s/ /\n/g" > out
tr '[:upper:]' '[:lower:]' < out > out2
sed 's/ /\n/g' out2 > out3

sed '/^\s*$/d' out3 > out4
sort out4 |  uniq -c | awk '{print $2", "$1}' > out5
echo "---------------"
cat out5
#cp $1 output
#cat $1 | tr -cs "[:alpha:]" "\n"

#sed -e 's/[[:alpha].-]//g; /^$/d' output 

#cat output
fi 
