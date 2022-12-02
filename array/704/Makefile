CC := gcc
EXE := test
CTAG := -g
#MAIN := merge_twolist.o
#MAIN := mergesort_recursive.o
#MAIN := mergesort_iter.o
MAIN := 704.o
#MAIN := list_cut.o
#MAIN := merge_klist.o
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
