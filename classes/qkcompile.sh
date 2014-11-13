#!/bin/sh
#qkcompile.sh - this script depends on qkcompile.cpp for arguments


##-For C++ compiling-##
if [ "$2" == "cpp" ]; then

	g++  $1"."$2 -o  $1
	
	if [ $? -eq 0 ]; then 
		./$1 $3 $4
	fi
fi


##-FOR C compiling-##
if [ "$2" == "c" ]; then

	gcc $1"."$2 -o $1

	if [ $? -eq 0 ]; then
		./$1 $3 $4
	fi
fi
