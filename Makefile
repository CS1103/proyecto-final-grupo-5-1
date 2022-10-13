CC = g++

FILES = Board Config Game Player PlayerController Square Turn View

obj:
	mkdir obj

all:  hexx

hexx:  $(FILES).o
	gcc -o hexx $(FILES).o

clean:
	rm -f obj