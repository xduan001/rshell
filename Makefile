
COMPILE = g++ -Wall -Werror -ansi -pedantic

all:
	mkdir bin; cd src; make; mv rshell .. ; cd .. ; mv rshell bin;

rshell: 
	mkdir bin; cd src; make; mv rshell .. ; cd .. ; mv rshell bin;

