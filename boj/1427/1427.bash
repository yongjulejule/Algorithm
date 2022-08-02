read number
len=${#number}
for ((i=0; i<len; i++)); do arr[$i]=${number:$i:1}; done 

IFS=$'\n' 
sorted=($(sort -r <<<"${arr[*]}"))

for ((i=0; i<len; i++)); do echo -n ${sorted[$i]}; done 
