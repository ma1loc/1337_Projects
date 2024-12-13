#!/bin/bash

echo "hello guys!" | wall

ARCH=$(uname -a)
P_CPU=$(lscpu | grep -i "Socket(s)" | awk '{print $2}')
V_CPU=$()

MAC=$(ip link show | grep -i ether | awk '{print $2}') #-> IP AND MAC ADDRESS

echo $ARCH
echo $P_CPU
echo $MAC
