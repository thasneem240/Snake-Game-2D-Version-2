##
 # File: Makefile
 # File Created: 03, October 2021
 # Author: A.S.M. Thasneem
 # -----
 # Last Modified: 10, October 2021
 # Modified By: A.S.M. Thasneem
 # -----
 # Purpose: A make file to compile multiple files and get an Execute file
##


# Makefile Variables
CC		 = gcc
EXEC	 = maze
CFLAGS = -Wall -ansi -pedantic -g
OBJ 	 = main.o setmap.o printmap.o input.o terminal.o linkedlist.o freeLinkedList.o setSnake.o


$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)
	
main.o : main.c setmap.h printmap.h input.h linkedlist.h freeLinkedList.h 
	$(CC) -c main.c $(CFLAGS)
	
setmap.o : setmap.c setmap.h
	$(CC) -c setmap.c $(CFLAGS)
	
printmap.o : printmap.c printmap.h
	$(CC) -c printmap.c $(CFLAGS)

input.o : input.c input.h terminal.h setSnake.h
	$(CC) -c input.c $(CFLAGS)	
	
terminal.o : terminal.c terminal.h
	$(CC) -c terminal.c $(CFLAGS)
	
linkedlist.o : linkedlist.c linkedlist.h
	$(CC) -c linkedlist.c $(CFLAGS)
	
freeLinkedList.o : freeLinkedList.c freeLinkedList.h
	$(CC) -c freeLinkedList.c $(CFLAGS)
	
setSnake.o : setSnake.c setSnake.h
	$(CC) -c setSnake.c $(CFLAGS)
	
clean :
	rm -f $(EXEC) $(OBJ)