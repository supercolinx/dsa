# colinx
#

TARGET	=
CFLAGS	= -Wall -g -O2 \
	  -I./src

all: $(TARGET)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "CC	$<"

clean:
	@rm -rf $(TARGET)
	@find . -name '*.o' | xargs rm -rf
