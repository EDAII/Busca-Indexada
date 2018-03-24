####### Makefile #######

CC:=gcc
CFLAGS:=-Wall

SRCFILES:= $(wildcard src/*.c)
all:$(SRCFILES:src/%.c=obj/%.o)
	$(CC) $(CFLAGS) obj/*.o -o bin/BuscaIndexada

obj/%.o:src/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I../inc

PHONY:clean
clean:
	rm obj/*

PHONY:run
run:
	bin/./BuscaIndexada

