CC := gcc
EXE := test
CTAG := -g -w
MAIN := 160.o
OBJ := $(MAIN) $(SRC)

all:$(OBJ)
	$(CC) $(CTAG) -o $(EXE) $(OBJ)  
%.o:%.c
	$(info !!!$(CC)) $(CC) $(CTAG) -c $^ -o $@

valgrind_test:
	$(shell valgrind --leak-check=full --show-leak-kinds=all --verbose $(EXE))

.PHONY:clean
clean:
	rm -rf *.o $(EXE)
