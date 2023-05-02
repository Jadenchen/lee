CC := gcc
EXE := test
CTAG := -g -Wall
SRC := sort.o
MAIN_INSERT := main_insert.o
MAIN_SHELL := main_shell.o
OBJ := $(MAIN_SHELL) $(SRC)

all:$(OBJ)
	$(CC) $(CTAG) -o $(EXE) $(OBJ)
%.o:%.c
	$(CC) $(CTAG) -c $^ -o $@

valgrind_test:
	$(shell valgrind --leak-check=full --show-leak-kinds=all --verbose $(EXE))

.PHONY:clean
clean:
	rm -rf *.o $(EXE)
