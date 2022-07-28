ifconfig -a | grep "ether " | sed 's/ether //g' | awk '{print $1}'
