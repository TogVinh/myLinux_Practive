#!/bin/bash

character=("+" "-" "x" "/")
num1=$1
num2=$3
cal=$2

function add()
{
	#sum=`expr $num1 + $num2`
	sum=`echo "scale=2;$num1 + $num2"|bc -l`
	echo $sum
}

function sub()
{
	#sub=`expr $num1 - $num2`
	sub=`echo "scale=2;$num1 - $num2"|bc -l`
	echo $sub
}

function mul()
{
	#mul=$((num1*num2))
	mul=`echo "scale=2;$num1 * $num2"|bc -l`
	echo $mul
}

function div()
{
	#div=$((num1/num2))
	div=`echo "scale=2;$num1 / $num2"|bc -l`
	echo $div
}

if [ $cal == ${character[0]} ]; then
	add=`add $num1 $num2`
	echo $add
	
elif [ $cal == ${character[1]} ]; then
	sub=`sub $num1 $num2`
	echo $sub
	
elif [ $cal == ${character[2]} ]; then
	mul=`mul $num1 $num2`
	echo $mul
	
elif [ $cal == ${character[3]} ]; then
	if [ $num2 != 0 ];then
		div=`div $num1 $num2`
		echo $div
	else
		echo "can not divise"
	fi
	
else
	echo "wrong input"
fi

