# specify the compiler
CXX  = gcc  # this is the GNU C compiler

# Build all: default target
all : demo

# Separate compilation to build object files
main.o : main.c functions.h 
	$(CXX) -c -ggdb main.c
# Here -ggdb is for the debugger. It helps to locate and solve the error
functions.o : functions.c functions.h 
	$(CXX) -c -ggdb functions.c

# linking
#demo is a target which depends upon main.o and functions.o 
#"$(CXX) main.o functions.o -o demo" is the command to produce the executable file
#You need to use a TAB before $(CXX) 
demo : main.o functions.o
	$(CXX) main.o functions.o -o demo

# Testing
check : all
	./demo

# Clean up all build targets so that one may get a clean build
clean :
	rm -f *.o demo core.*