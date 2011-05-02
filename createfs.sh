#! /bin/sh

if [ $# -eq 2 -a -d $1 -a -d "$1/tags_structure" -a -d "$1/tags" ]
then
x=0
while [ $x -lt 10 ]
do
	mkdir "$1/tags_structure/$x"
	x=`expr $x + 1`
done
x=0
while [ $x -lt $2 ]
do
	a=`expr $x % 10`
	b=`expr $x / 10 % 10`
	c=`expr $x / 100 % 10`
	d=`expr $x / 1000 % 10`
	dir=$a
	if [ `expr index $dir $b` -eq 0 ]
	then
		dir="$dir/$b"
	fi
	if [ `expr index $dir $c` -eq 0 ]
	then
		dir="$dir/$c"
	fi
	if [ `expr index $dir $d` -eq 0 ]
	then
		dir="$dir/$d"
	fi
	touch "$1/tags/$dir/$x.txt"
	x=`expr $x + 1`
done
else
	printf "Usage: createfs mountpoint num_tags num_files\n"
fi
