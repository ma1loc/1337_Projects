#!/bin/bash

echo "hello guys!" | wall # brodcasting message to all in the server!!!!d
#
# Variables command:
#
Architecture=$(uname -a) # done
Physical_CPU=$(lscpu | grep -i "Socket(s)" | awk '{print $2}') # done
Virtual_CPU=$(lscpu | grep -i "CPU(s)" | awk '{print $2}') # check
Memory_Usage=$(free --mega | grep -i "mem" | awk '{print $3}') # done
Memory_Total=$(free --mega | grep -i "mem" | awk '{print $2}') # done
Memory_Percentage=$(echo "$Memory_Usage $Memory_Total" | awk '{printf "%.2f", ($1 / $2) * 100}')
Disk_Total=$(df -BG | grep -i "^/dev" | awk '{total += $2} END {print total}') # -BG done check
Disk_Usage=$(df -m | grep -i "^/dev" | awk '{usage += $3} END {print usage}')  # -m done check
Disk_Total_In_M=$(df -m | grep -i "^/dev" | awk '{total_m += $2} END {print total_m}') # done
Disk_Percentage=$(echo "$Disk_Usage $Disk_Total_In_M" | awk '{printf "%d", ($1 / $2) * 100}') # done

CPU_Load=$(top -n1 | grep -i "Cpu(s)" | )

IP_Addr=$(echo "IP $(hostname -I)")
MAC_Addr=$(ip link | grep -i "ether" | awk '{print $2}')
#
# excute the command:
#
echo "#Architecture: ${Architecture}" # done
echo "#CPU physical: ${Physical_CPU}" # done
echo "#vCPU: ${Virtual_CPU}" # check
echo "#Memory Usage: ${Memory_Usage}/${Memory_Total}MB (${Memory_Percentage}%)" # done
echo "#Disk Usage: ${Disk_Usage}/${Disk_Total}Gb (${Disk_Percentage}%)" # done no
echo "#CPU load: " # working on it.
echo "#Network: ${IP_Addr} (${MAC_Addr})" # check.
