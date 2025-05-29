#include <stdio.h>
#include "cx_queue.h"

int main(void)
{
	cx_queue_t *queue = NULL;
	cx_queue_elem_t elem = 3;
	cx_queue_elem_t _elem;

	cx_queue_init(&queue);
	if (cx_queue_head(queue, &elem))
		printf("first is empty\n");

	if (cx_queue_enqueue(queue, elem))
		printf("(EE) add elem\n");
	if (cx_queue_head(queue, &_elem) == 0)
		printf("get _elem: %d\n", _elem);

	_elem = 9;
	if (cx_queue_dequeue(queue, &_elem) == 0)
		printf("dequeue: %d\n", _elem);

	cx_queue_deinit(queue);
	return 0;
}
