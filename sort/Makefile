CC := gcc
EXE := test
CTAG := -g -Wall
SRC := sort.o
MAIN_INSERT := main_insert.o
MAIN_SHELL := main_shell.o
MAIN_SELECT := main_select.o
MAIN_BUBBLE := main_bubble.o
MAIN_SHAKE_SORT := main_shaker_sort.o
MAIN_88 := main_88.o
MAIN_912 := main_912.o
MAIN_274 := main_274.o
OBJ := $(MAIN_274) $(SRC)

all:$(OBJ)
	$(CC) $(CTAG) -o $(EXE) $(OBJ)
%.o:%.c
	$(CC) $(CTAG) -c $^ -o $@

valgrind_test:
	$(shell valgrind --leak-check=full --show-leak-kinds=all --verbose $(EXE))

.PHONY:clean
clean:
	rm -rf *.o $(EXE)
