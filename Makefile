
COMPILE = g++ -Wall -Werror -ansi -pedantic

all:
	cd src; make

rshell: 
	mkdir bin; cd src; make; mv a.out .. ; cd .. ; mv a.out bin;

