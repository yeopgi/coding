#! /bin/bash

if [ $# = 0 ]
then
	echo "input src"
elif [ $# = 1 ]
then
	echo "working starts" 
	echo "copying to ~/collabo/c++"
	cp $1 ~/collabo/c++
fi


