Assignment 2
=======

This project is basically just a command shell that can read in commands
and execute them. 

Makefile
-----------

There is a Makefile in the root directory with two targets:  
    1. all - this just compiles the program in the src directory
    2. rshell - this creates a directory called 'bin' in the 
    root directory and places the compiled program there.


Bugs and Errors
----------

There seems to be a problem that happens when you type a command,
backspace, and type over previously the previously written command.
This causes an error. I suspect it has something to do with how the 
commands are being parsed as they are being saved as the command is 
being written.
