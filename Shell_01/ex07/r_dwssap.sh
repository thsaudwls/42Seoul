#A=$(echo $FT_LINE1 | rev | grep -n /etc/passwd)
#B=$(echo $FT_LINE2 | rev | grep -n /etc/passwd)

#echo $A
#echo $B

A=$(echo $FT_LINE1)
B=$(echo $FT_LINE2)


cat /etc/passwd | sed "/^#/d" | awk -F: '{print $1}' | awk 'NR%2==0 { print $0}' | rev | sort -r | sed -n $A','$B'p' | awk '{printf "%s, ",$0}' | sed 's/..$//' | sed -a 's/$/./' | tr -d '\n'


#Q=$(cat /etc/passwd | sed "/^#/d" | sed '1d' | awk -F: '{print$1}' | rev | sort -r)
#echo $Q > p.txt

#cat p.txt | tr ' ' '\n' > q.txt

#A=$(echo $FT_LINE1 | rev)

#B=$(echo $FT_LINE2 | rev)

#echo 'b'
#sed -n -e '/$A/,/$B/p' q.txt


#rm -rf q.txt
#rm -rf p.txt

#A=$(echo $FT_LINE1 | rev)
#a=$(grep -n $A $Q)
#B=$(echo $FT_LINE2 | rev) 
#b=$(grep -n $B $Q)

#echo $uQ | sed -n '$a, $bp' | tr '\n' ',' | sed 's/.$//' | sed -a 's/$/./'


