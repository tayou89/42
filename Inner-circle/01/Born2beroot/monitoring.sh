#!/bin/bash

architecture=$(uname -a)
CPU=$(cat /proc/cpuinfo | grep "physical id" | sort -u | wc -l)
VCPU=$(cat /proc/cpuinfor | grep "processor" | sort -u | wv -l)
memory_usage=$(free -m | grep "Mem" | awk '{printf"%d/%dMB (%.2f%%)", $3, $2, $3/$2*100}')
disk_used_MB=$(df -BM | grep "tayou42" | awk '{sum += $3} END {print sum}' | tr -d '\n')
disk_total_Gb=$(df -BG | grep "tayou42" | awk '{sum += $2} END {print sum}' | tr -d '\n')
disk_total_MB=$(df -BM | grep "tayou42" | awk '{sum += $2} END {print sum}' | tr -d '\n')
disk_usage_rate=$[${disk_used_MB} * 100 / ${disk_total_MB}]
CPU_load=$(mpstat | tail -1 | awk '{printf"%.1f", 100 - $NF}')
last_boot=$(who -b | awk '{print $3 " " $4}')
LVM_use=$(lsblk | grep vm | wc -l | awk '{if($1 > 0) print "yes"; else print "no"}')
TCP_connection=$(ss -t | grep ESTAB | wc -l)
user_log_count=$(who | wc -l)
IPv4_address=$(hostname -I)
MAC_address=$(ip link | grep link/ether | awk '{print $2}')
sudo_command_count=$(cat /var/log/auth.log | grep sudo | grep COMMAND | wc -l | tr -d '\n')

wall "	#Architecture: $architecture
		#CPU physical: $CPU
		#VCPU: $VCPU
		#Memory Usage: $memory_usage
		#Disk Usage: ${disk_used_MB}/${disk_total_Gb}Gb ($(disk_usage_rate)%)
		#CPU load: ${CPU_load}%
		#Last boot: $last_boot
		#LVM use: $LVM_use
		#Connection TCP: ${TCP_connection} ESTABLISHED
		#User log: $user_log_count
		#Network: IP $IPv4_address (${MAC_address})
		#Sudo: $sudo_command_count cmd"
