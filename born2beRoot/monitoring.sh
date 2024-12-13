#!/bin/bash

echo "hello guys!" | wall

# Variables command:
ARCH=$(uname -a)
P_CPU=$(lscpu | grep -i "Socket(s)" | awk '{print $2}')
V_CPU=$(lscpu | grep -i "CPU(s)" | awk '{print $2}')
Usage_Memory=free #not valid
MAC=$(hostname -I && ip link show | grep -i ether | awk '{print $2}') #-> IP AND MAC ADDRESS "()"

# excute the command:
echo "Architecture:" $ARCH
echo "CPU physical:" $P_CPU
echo "vCPU:" $V_CPU
echo "Memory Usage:"
echo "Network:" $MAC
