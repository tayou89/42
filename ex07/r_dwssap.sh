cat /etc/passwd | grep -v '^#' | sed -n 'n;p'| awk -F ":" '{print $1}' | rev | sort -r |  sed -n -e "$FT_LINE1,${FT_LINE2}p" | paste -s -d "," - | sed s/','/', '/g | sed s/$/./ | tr -d "\n"
