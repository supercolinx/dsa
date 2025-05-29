#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cx_queue.h"

typedef cx_queue_elem_t _elem_t;
struct cx_queue {
	_elem_t data[CX_QUEUE_SIZE];
	int front;
	int rear;
};

int
cx_queue_init(cx_queue_t **q)
{
	*q = (cx_queue_t*) malloc(sizeof(**q));
	if (!*q)
		return -1;
	cx_queue_clean(*q);

	return 0;
}

void
cx_queue_deinit(cx_queue_t *q)
{
	q->front = 0;
	q->rear = 0;
	free(q);
}

int
cx_queue_clean(cx_queue_t *q)
{
	memset(q->data, 0, sizeof(_elem_t)*CX_QUEUE_SIZE);
	q->front = 0;
	q->rear = 0;

	return 0;
}

int
cx_queue_head(cx_queue_t *q, cx_queue_elem_t *e)
{
	if (q->rear == q->front)
		return -1;

	*e = q->data[q->front];

	return 0;
}

int
cx_queue_enqueue(cx_queue_t *q, cx_queue_elem_t e)
{
	if (((q->rear+1) % CX_QUEUE_SIZE) == q->front)
		return -1;

	q->data[q->rear] = e;
	q->rear = (q->rear+1) % CX_QUEUE_SIZE; 

	return 0;
}

int
cx_queue_dequeue(cx_queue_t *q, cx_queue_elem_t *e)
{
	if (q->rear == q->front)
		return -1;

	*e = q->data[q->front];
	q->front = (q->front+1) % CX_QUEUE_SIZE; 

	return 0;
}
