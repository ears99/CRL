# Makefile for Dungeon, an ASCII Rougelike created in C, using ncurses.
# Created by Jacob Seadorf

CC= gcc
#g sets debugging flags, I includes a directory.
CFLAGS = -g -I$(IDIR) -lncurses
OUT = -o dungeon

IDIR= ./include/
SRCDIR= ./src/
SOURCES= $(SRCDIR)*.c #take any file that ends with .c from the src directory


all: dungeon
	
dungeon: 
	$(CC) $(SOURCES) $(CFLAGS) -o $@

run: 
	@./dungeon

clean: dungeon
	rm dungeon
