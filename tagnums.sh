#! /bin/sh

if [ $# -eq 2 -a -d $1 ]
then
x=0
while [ $x -lt $2 ]
do
	y=$x
	dir=`expr $y % 10`
	while [ $y -gt 0 ]
	do
		y=`expr $y / 10`
		d=`expr $y % 10`
		if [ `expr index "$dir" $d` -eq 0 ]
		then
			dir="$dir $d"
		fi
	done
	touch "$1/$x.txt"
	addtag "$1/$x.txt" $dir
	x=`expr $x + 1`
done
else
	printf "Usage: createfs mountpoint num_files\n"
fi
