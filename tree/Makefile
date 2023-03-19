CC := gcc
EXE := test
CTAG := -g -w
SRC := tree.o
MAIN_226 := 226.o
MAIN_110 := 110.o
OBJ := $(MAIN_110) $(SRC)

all:$(OBJ)
	$(CC) $(CTAG) -o $(EXE) $(OBJ)
%.o:%.c
	$(CC) $(CTAG) -c $^ -o $@

valgrind_test:
	$(shell valgrind --leak-check=full --show-leak-kinds=all --verbose $(EXE))

.PHONY:clean
clean:
	rm -rf *.o $(EXE)
