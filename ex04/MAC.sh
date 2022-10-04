ifconfig | grep -w "ether" | sed 's/ether//' | awk '$1=$1'
