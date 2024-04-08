!/bin/bash

make -C ../push_swap/
echo ""
for test in tests/Error.txt
do
	echo $test
	while read -r line
	do
		result=`./../push_swap/push_swap $line`
		if [ "$result" != "Error" ]; then
			echo "Fail test: $line"
		fi
	done < "$test"
	echo ""
done
for test in tests/NotError.txt
do
	echo $test
	while read -r line
	do
		result=`./../push_swap/push_swap $line`
		if [ "$result" == "Error" ]; then
			echo "Fail test: $line"
		fi
	done < "$test"
	echo ""
done
for test in tests/100_random.txt tests/500_random.txt tests/5_random.txt
do
	echo $test
	max=0
	min=100000
	while read -r line
	do
		result=`./../push_swap/push_swap $line | ./../push_swap/checker_linux $line`
		moves=`./../push_swap/push_swap $line | wc -l`
		if [ "$result" != "OK" ]; then
			echo -ne "$result\nOn test: $line"
		fi
		if [[ $moves -gt $max ]]; then
			max=$moves
		fi
		if [[ $moves -lt $min ]]; then
			min=$moves
		fi
	done < "$test"
	echo "min = $((min)); max = $((max))"
	echo ""
done
