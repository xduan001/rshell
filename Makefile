#Variables

COMPILE = g++ -Wall -Werror -ansi -pedantic
# OBJS = 
# Add whatever objects I need later

all: main.cpp
	$(COMPILE) -o -a.out main.cpp
