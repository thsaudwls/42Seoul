A=$(echo $FT_NBR1 | tr "\\\'\"\?\!" '10234')
B=$(echo $FT_NBR2 | tr 'mrdoc' '01234')

C=$(echo "obase=13;ibase=5;$A+$B" | bc)

echo $C  > dd.txt

E=$(tr '0123456789ABC' 'gtaio luSnemf' < dd.txt)

echo $E > e.txt

awk '{print}' e.txt

rm -rf dd.txt
rm -rf e.txt
