CC := gcc
subdir1 := 2_1 
subdir2 := 2_2
subdir5 := 2_5
subdir6 := 2_6
subdir7 := 2_7
subdir8 := 2_8
#subdir9 := 1_9
SUBDIR_ROOTS := $(subdir1) $(subdir2) $(subdir3) $(subdir4) $(subdir5) $(subdir6) \
$(subdir7) $(subdir8) $(subdir9)
DIRS := $(shell find $(SUBDIR_ROOTS) -type d)
GARBAGE_PATTERNS := *.o test ped* .gdb*
GARBAGE := $(foreach DIR,$(DIRS),$(addprefix $(DIR)/,$(GARBAGE_PATTERNS))) 

all:
	$(MAKE) -C $(subdir1)
#	$(MAKE) -C $(subdir2)
#	$(MAKE) -C $(subdir3)
#	$(MAKE) -C $(subdir4)
	$(MAKE) -C $(subdir5)
	$(MAKE) -C $(subdir6)
	$(MAKE) -C $(subdir7)
	$(MAKE) -C $(subdir8)
#	$(MAKE) -C $(subdir9)

clean:
	rm -fr $(GARBAGE) 2>/dev/null
