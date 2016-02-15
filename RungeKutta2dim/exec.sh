#!/bin/bash
	./RK2 1	1 0 100 6.28 > test.dat 
	/Applications/Mathematica.app/Contents/MacOS/./MathKernel -noprompt -run "<<Plot.m"
	cat test.dat
	open Test.eps
