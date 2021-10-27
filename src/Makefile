#Makefile - compiler for Lab 1

# compiler flags.  -g for debug, -O3 for optimization
CFLAGS=-g -O3

# first target built by default
all: uimain

# file dependencies
tokenizer.o: tokenizer.h
history.o: history.h
uimain.o: tokenizer.h history.h

# compiles all files
uimain: tokenizer.o history.o uimain.o
	gcc -o $@ $^ $(CFLAGS)

# deltes the files generated from the compilation
clean:
	rm -f *.o uimain
#run UI Main
run: uimain
	./uimain
