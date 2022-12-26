CC := gcc
subdir1 := 3_1 
subdir2 := 3_2
subdir4 := 3_4
subdir5 := 3_5
subdir6 := 3_6
#subdir9 := 1_9
SUBDIR_ROOTS := $(subdir1) $(subdir2) $(subdir3) $(subdir4) $(subdir5) $(subdir6) \
$(subdir7) $(subdir8) $(subdir9)
DIRS := $(shell find $(SUBDIR_ROOTS) -type d)
GARBAGE_PATTERNS := *.o test ped* .gdb*
GARBAGE := $(foreach DIR,$(DIRS),$(addprefix $(DIR)/,$(GARBAGE_PATTERNS))) 

all:
	$(MAKE) -C $(subdir1)
	$(MAKE) -C $(subdir2)
#	$(MAKE) -C $(subdir3)
	$(MAKE) -C $(subdir4)
	$(MAKE) -C $(subdir5)
	$(MAKE) -C $(subdir6)

clean:
	rm -fr $(GARBAGE) 2>/dev/null
