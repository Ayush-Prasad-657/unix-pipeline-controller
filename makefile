# makefile
# COMP2019 Systems Programming 1
# This is a sample file for Assignment 2
# modify if needed to compile your solution
# this will build the controller and the 3 child 
# programs
#
# Author: Dr Evan Crawford (e.crawford@westernsydney.edu.au)

# This tells make that these are recipes that should
# always be run
.PHONY: all clean

# The default is to build each of the programs
all: c1 c2 c3 controller

# Undo the build by deleting the files that all will create
# the 'rm ...' line below must begin with a TAB character for 
# make to work correctly. 
clean:
	rm c1 c2 c3 controller


# make is smart enough to know how to turn a .c file into
# an executable of the same name.
controller: controller.c

c1: c1.c

c2: c2.c

c3: c3.c

