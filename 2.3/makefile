all: compilacion

compilacion: main.o linkedlist.o
	gcc main.o linkedlist.o -o compilacion -ggdb

main.o: main.c linkedlist.h
	gcc -c main.c -ggdb

linkedlist.o: linkedlist.c linkedlist.h
	gcc -c linkedlist.c -ggdb


