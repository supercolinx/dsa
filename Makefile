# colinx
#

TARGET	= demo_queue
CFLAGS	= -Wall -g -O2 \
	  -I./src

all: $(TARGET)

demo_queue: test/cx_queue_demo.o src/cx_queue.o
	@$(CC) -o $@ $^

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "CC	$<"

clean:
	@rm -rf $(TARGET)
	@find . -name '*.o' | xargs rm -rf
