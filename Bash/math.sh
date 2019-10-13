#!/bin/bash

<<COMMENTS
Bash script for various mathematical function
    • factorial()   : f(n) = n * f(n - 1)
    • fibonacci()   : f(n) = f(n-1) + f(n-2)
COMMENTS

function factorial {
	n=$1; res=1;

	for ((i=1; i<=n; i++)); do
		((res = res * i))
	done
	return $res
}

function fibonacci {
	n=$1
	if [ $n -eq 1 ]; then
		return 0
	elif [ $n -eq 2 ]; then
		return 1
	else
		a=0; b=1; res=1;
		for ((i=3; i<=n; i++)); do
			((res = a + b))
			a=$b; b=$res;
		done
		return $res
	fi
}

# Uncomment this block to run this script
: '
# User input with message
read -p "Enter any number " num

# nth Factorial 
factorial $num res
echo "Factorial of $num is : $res"

# nth Fibonacci number
fibonacci $num res
echo "Fibonacci number is : $res"
'