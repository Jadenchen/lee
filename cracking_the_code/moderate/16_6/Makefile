CC := gcc
EXE := test
CTAG := -g
MAIN := 16_6.o
OBJ := $(MAIN) $(SRC)

all:$(OBJ)
	$(CC) $(CTAG) -o $(EXE) $(OBJ)  
%.o:%.c
	$(CC) $(CTAG) -c $^ -o $@

valgrind_test:
	$(shell valgrind --leak-check=full --show-leak-kinds=all --verbose $(EXE))

.PHONY:clean
clean:
	rm -rf *.o $(EXE)
