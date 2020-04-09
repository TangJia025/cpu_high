#!/bin/sh

num=0
while(($num<100000))
do
	mod=$(($num%100))
	echo "test$num.qq.com 10.132.23.$mod 1" >> rule.txt
	num=$(($num+1));
done
