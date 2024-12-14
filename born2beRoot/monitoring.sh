#!/bin/bash

echo "hello guys!" | wall # brodcasting message to all in the server!!!!d

#
# Variables command:
#
Architecture=$(uname -a) # done
Physical_CPU=$(lscpu | grep -i "Socket(s)" | awk '{print $2}') # done
Virtual_CPU=$(lscpu | grep -i "CPU(s)" | awk '{print $2}') # check

Usage_Memory=$(free --mega | grep -i "mem" | awk '{print $3}')
Total_Memory=$(free --mega | grep -i "mem" | awk '{print $2}')

MAC_Addr=$(hostname -I && ip link show | grep -i ether | awk '{print $2}') #-> IP AND MAC ADDRESS "()"
#
# excute the command:
#
echo "Architecture: ${Architecture}"
echo "CPU physical: ${Physical_CPU}"
echo "vCPU: ${Virtual_CPU}"

echo "Memory Usage: ${Usage_Memory}/${Total_Memory}MB" # the used memory {total_memory * (used_memory / 100)}

echo "Network: ${MAC_Addr}"
