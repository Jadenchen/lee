CC := gcc
subdir1 := 1_1 
subdir2 := 1_2
subdir3 := 1_3
subdir4 := 1_4
subdir5 := 1_5
subdir6 := 1_6
subdir7 := 1_7
subdir8 := 1_8
subdir9 := 1_9
SUBDIR_ROOTS := $(subdir1) $(subdir2) $(subdir3) $(subdir4) $(subdir5) $(subdir6) \
$(subdir7) $(subdir8) $(subdir9)
DIRS := $(shell find $(SUBDIR_ROOTS) -type d)
GARBAGE_PATTERNS := *.o test ped*
GARBAGE := $(foreach DIR,$(DIRS),$(addprefix $(DIR)/,$(GARBAGE_PATTERNS))) 

all:
	$(MAKE) -C $(subdir1)
	$(MAKE) -C $(subdir2)
	$(MAKE) -C $(subdir3)
	$(MAKE) -C $(subdir4)
	$(MAKE) -C $(subdir5)
	$(MAKE) -C $(subdir6)
	$(MAKE) -C $(subdir7)
	$(MAKE) -C $(subdir8)
	$(MAKE) -C $(subdir9)

clean:
	rm -fr $(GARBAGE) 2>/dev/null
