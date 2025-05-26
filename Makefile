# colinx
#

TARGET	= test_dsa_list
CFLAGS	= -I./src

all: $(TARGET)

test_dsa_list: test/test_dsa_list.o src/dsa_list.o
	@$(CC) -o $@ $^
	@rm -rf $(OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "CC	$<"

clean:
	@rm -rf $(TARGET)
	@find . -name '*.o' | xargs rm -rf
