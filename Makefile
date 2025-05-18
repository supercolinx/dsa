# colinx
#

TARGET	= test_dsa_list
CFLAGS	= -I./src
CSRSC	= test/test_dsa_list.c src/dsa_list.c
OBJS	= $(CSRSC:.c=.o)

all: $(TARGET)

test_dsa_list: $(OBJS)
	@$(CC) -o $@ $^
	@rm -rf $(OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "CC	$<"

clean:
	@rm -rf $(TARGET) $(OBJS)
