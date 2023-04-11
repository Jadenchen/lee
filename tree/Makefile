CC := gcc
EXE := test
CTAG := -g -Wall
SRC := tree.o queue.o stack.o
MAIN_226 := 226.o
MAIN_110 := 110.o
MAIN_543 := 543.o
MAIN_104 := 104.o
MAIN_101 := 101.o
MAIN_572 := 572.o
MAIN_235 := 235.o
MAIN_102 := 102.o
MAIN_105 := 105.o
MAIN_98 := 98.o
MAIN_230 := 230.o
MAIN_199 := 199.o
OBJ := $(MAIN_199) $(SRC)

all:$(OBJ)
	$(CC) $(CTAG) -o $(EXE) $(OBJ)
%.o:%.c
	$(CC) $(CTAG) -c $^ -o $@

valgrind_test:
	$(shell valgrind --leak-check=full --show-leak-kinds=all --verbose $(EXE))

.PHONY:clean
clean:
	rm -rf *.o $(EXE)
