#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cx_stack.h"

typedef cx_stack_elem_t _elem_t;
struct cx_stack {
	_elem_t data[CX_STACK_SIZE];
	int top;
};

int
cx_stack_init(cx_stack_t **s)
{
	*s = (cx_stack_t*) malloc(sizeof(**s));
	if (!*s)
		return -1;
	memset((*s)->data, 0, sizeof(_elem_t)*CX_STACK_SIZE);
	(*s)->top = -1;

	return 0;
}

void
cx_stack_deinit(cx_stack_t *s)
{
	s->top = 0;
	free(s);
}

int
cx_stack_push(cx_stack_t *s, cx_stack_elem_t e)
{
	if (s->top == CX_STACK_SIZE-1)
		return -1;

	s->data[++s->top] = e;
	return 0;
}

int
cx_stack_pop(cx_stack_t *s, cx_stack_elem_t *e)
{
	if (s->top == -1)
		return -1;

	*e = s->data[s->top--];

	return 0;
}
