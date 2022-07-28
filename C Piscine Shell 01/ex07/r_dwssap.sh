cat /etc/passwd | grep -v '#' | sed 's/:.*//g' | awk 'NR % 2 == 0' | rev | sort -r | awk "NR>=$FT_LINE1 && NR<=$FT_LINE2" | tr '\n' ',' | sed 's/,/, /g' | sed 's/, *$/./g' | tr -d '\n'
