#!/bin/bash

echo "hello guys!" | wall # brodcasting message to all in the server!!!!d
#
# Variables command:
#
Architecture=$(uname -a) # done
Physical_CPU=$(lscpu | grep "Socket(s)" | awk '{print $2}') # done
Virtual_CPU=$(lscpu | grep "Cpu(s)" | awk '{print $2}') # check
Memory_Usage=$(free --mega | grep -i "mem" | awk '{print $3}') # done
Memory_Total=$(free --mega | grep -i "mem" | awk '{print $2}') # done
Memory_Percentage=$(echo "$Memory_Usage $Memory_Total" | awk '{printf "%.2f", ($1 / $2) * 100}')
Disk_Total=$(df -BG | grep "^/dev" | awk '{total += $2} END {print total}') # -BG done check
Disk_Usage=$(df -m | grep "^/dev" | awk '{usage += $3} END {print usage}')  # -m done check
Disk_Total_In_M=$(df -m | grep "^/dev" | awk '{total_m += $2} END {print total_m}') # done
Disk_Percentage=$(echo "$Disk_Usage $Disk_Total_In_M" | awk '{printf "%d", ($1 / $2) * 100}') # done
CPU_Load=$(top -n1 | grep "Cpu(s)" | awk '{printf "%.1f", (100 - $8)}') # done check
Last_Boot=$(who -b | awk '{print $3 " " $4}') # done check
LVM_use=$(lsblk | grep -q "lvm" && echo "yes" || echo "no") # done check
Connections_TCP=$(ss -t state ESTABLISHED | wc -l) # undone
User_log=$(users | wc -w) # done check
IP_Addr=$(echo "IP $(hostname -I)") # done check
MAC_Addr=$(ip link | grep -i "ether" | awk '{print $2}') # done check
Sudo=$(journalctl -q | grep "COMMAND" | wc -l) # undone
#
# excute the command:
#
echo "#Architecture: ${Architecture}"
echo "#CPU physical: ${Physical_CPU}"
echo "#vCPU: ${Virtual_CPU}"
echo "#Memory Usage: ${Memory_Usage}/${Memory_Total}MB (${Memory_Percentage}%)"
echo "#Disk Usage: ${Disk_Usage}/${Disk_Total}Gb (${Disk_Percentage}%)"
echo "#CPU load: ${CPU_Load}%"
echo "#Last boot: ${Last_Boot}"
echo "#LVM use: ${LVM_use}"
echo "#Connections TCP: ${Connections_TCP}"
echo "#User log: ${User_log}"
echo "#Network: ${IP_Addr} (${MAC_Addr})"
echo "#Sudo : ${Sudo} cmd"
