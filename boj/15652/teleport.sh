#!/bin/bash

echo "plz input target"
read person

echo "plz input destination"
read destination

sp="/-\|"
sc=0
spin() {
   printf "%s\b${sp:sc++:1}"
   ((sc==${#sp})) && sc=0
}


sleep 7 &


echo -n "${person} teleport to $destination..."

while [[ -n $(jobs -r) ]]
do
	spin 
	sleep .3
done
echo -en "\033[1K\033[0m"

echo -e "\ncomplete teleport :)"


