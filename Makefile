CC = gcc
CFLAGS = -Wall -Wextra 
OBJ_DIR = ../build/
RM_ALL = rm ../build/*
C_LANG = clang-format -i *.c *.h
MAKE = make

all: 
	$(CC) $(CFLAGS) calc.c rendering.c stack.c parse_exp.c graph.c -o $(OBJ_DIR)graph

build_with_render:
	$(CC) $(CFLAGS) -DrenderString calc.c rendering.c stack.c parse_exp.c graph.c -o $(OBJ_DIR)graph

rebuild:
	$(MAKE) clean
	$(MAKE) all


clang:
	$(C_LANG)

clean:
	$(RM_ALL)