#!usr/bin/bash

i=1
mx=1000
g++ -std=c++17 -Wall -fsanitize=address -fsanitize=undefined -fno-omit-frame-pointer "yo.cpp" -o "yo"
g++ -std=c++17 -Wall -fsanitize=address -fsanitize=undefined -fno-omit-frame-pointer "slow.cpp" -o "slow"
g++ -std=c++17 -Wall -fsanitize=address -fsanitize=undefined -fno-omit-frame-pointer "generator.cpp" -o "generator"
for((i=1; i <= $mx; ++i)); do
	echo $i
	./generator > gen.txt
	./yo < gen.txt > output.txt
	./slow < gen.txt > slowout.txt
	diff -w output.txt slowout.txt || break
done

if [[ $i -gt mx ]]
	then echo "All cases passed"
else 
	echo -e "Error on case $i \nResult:\n$(cat output.txt)"
	echo -e "Expected:\n$(cat slowout.txt)"
fi
	
