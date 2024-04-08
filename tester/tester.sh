#!/bin/bash

make -C ../push_swap/
for test in tests/*
do
	echo "$test"
	while read -r line
	do
		result=`./../push_swap/push_swap $line | ./../push_swap/checker_linux $line`
		echo $result
		# if [ "$result" != "OK" ]; then
		# 	echo $result
		# fi
		./../push_swap/push_swap $line | wc -l
	done < "${test}"
	echo ""
done
