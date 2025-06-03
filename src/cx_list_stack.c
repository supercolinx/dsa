#include <stdlib.h>
#include <string.h>
#include "cx_list_stack.h"

typedef cx_lstack_elem_t _elem_t;
typedef cx_lstack_node_t _node_t;
struct cx_lstack_node {
	_elem_t data;
	cx_lstack_node_t *next;
};

int
cx_lstack_init(cx_lstack_t *ls)
{
	ls->top = NULL;
	ls->size = 0;
	return 0;
}

void
cx_lstack_deinit(cx_lstack_t *ls)
{
	_elem_t e;
	while (cx_lstack_pop(ls, &e) != -1);
}

int
cx_lstack_push(cx_lstack_t *ls, cx_lstack_elem_t e)
{
	_node_t *node = (_node_t *) malloc(sizeof(_node_t));
	if (!node)
		return -1;

	node->data = e;
	node->next = ls->top;
	ls->top = node;
	ls->size++;
	return 0;
}

int
cx_lstack_pop(cx_lstack_t *ls, cx_lstack_elem_t *e)
{
	_node_t *node = NULL;
	if (ls->size <= 0)
		return -1;

	node = ls->top;
	*e = node->data;
	ls->top = node->next;
	ls->size--;
	free(node);
	return 0;
}
