#!/bin/bash

Architecture=$(uname -a)
Physical_CPU=$(lscpu | grep "Socket(s)" | awk '{print $2}')
Virtual_CPU=$(lscpu | grep "^CPU(s):" | awk '{print $2}')
Memory_Usage=$(free --mega | grep -i "mem" | awk '{print $3}')
Memory_Total=$(free --mega | grep -i "mem" | awk '{print $2}')
Memory_Percentage=$(echo "$Memory_Usage $Memory_Total" | awk '{printf "%.2f", ($1 / $2) * 100}')
Disk_Total=$(df -BG | grep "^/dev" | awk '{total += $2} END {print total}')
Disk_Usage=$(df -m | grep "^/dev" | awk '{usage += $3} END {print usage}')
Disk_Total_In_M=$(df -m | grep "^/dev" | awk '{total_m += $2} END {print total_m}')
Disk_Percentage=$(echo "$Disk_Usage $Disk_Total_In_M" | awk '{printf "%d", ($1 / $2) * 100}')
CPU_Load=$(mpstat | grep "all" | awk '{printf "%.1f", (100 - $13)}')
Last_Boot=$(who -b | awk '{print $3 " " $4}')
LVM_use=$(lsblk | grep -q "lvm" && echo "yes" || echo "no")
Connections_TCP=$(ss -Ht state ESTABLISHED | wc -l)
User_log=$(users | wc -w)
IP_Addr=$(hostname -I)
MAC_Addr=$(ip link | grep -i "ether" | awk '{print $2}')
Sudo=$(journalctl -q | grep "COMMAND" | wc -l)
#
# Execute the command:
#
echo "#Architecture: ${Architecture}"
echo "#CPU physical: ${Physical_CPU}"
echo "#vCPU: ${Virtual_CPU}"
echo "#Memory Usage: ${Memory_Usage}/${Memory_Total}MB (${Memory_Percentage}%)"
echo "#Disk Usage: ${Disk_Usage}/${Disk_Total}Gb (${Disk_Percentage}%)"
echo "#CPU load: ${CPU_Load}%"
echo "#Last boot: ${Last_Boot}"
echo "#LVM use: ${LVM_use}"
echo "#Connections TCP: ${Connections_TCP} ESTABLISHED"
echo "#User log: ${User_log}"
echo "#Network: IP ${IP_Addr}(${MAC_Addr})"
echo "#Sudo : ${Sudo} cmd"

