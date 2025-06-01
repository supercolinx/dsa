#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cx_share_stack.h"

typedef cx_sstack_elem_t _elem_t;
struct cx_sstack {
	_elem_t data[CX_SSTACK_MAXSIZE];
	int ltop;
	int rtop;
};

int
cx_sstack_init(cx_sstack_t **ss)
{
	*ss = (cx_sstack_t*) malloc(**ss);
	if (!*ss)
		return -1;

	memset((*ss)->data, 0, sizeof(_elem_t)*CX_SSTACK_MAXSIZE);
	(*ss)->ltop = -1;
	(*ss)->rtop = CX_SSTACK_MAXSIZE;

	return 0;
}

void
cx_sstack_deinit(cx_sstack_t *ss)
{
	if (ss) {
		ss->ltop = -1;
		ss->rtop = CX_SSTACK_MAXSIZE;
		free(ss);
	}
}

int
cx_sstack_push(cx_sstack_t *ss, cx_sstack_elem_t e, cx_sstack_type_t type)
{
	if (ss->ltop + 1 == ss->rtop)
		return -1;

	switch (type) {
	EN_SSTACK_LEFT:
		ss->data[++ss->ltop] = e;
		break;
	EN_SSTACK_RIGHT:
		ss->data[--ss->rtop] = e;
		break;
	default:
		return -1;
	}

	return 0;
}

int
cx_sstack_pop(cx_sstack_t *ss, cx_sstack_elem_t *e, cx_sstack_type_t type)
{
	switch (type) {
	case EN_SSTACK_LEFT:
		if (ss->ltop == -1)
			return -1;
		*e = ss->data[ss->ltop--];
		break;
	case EN_SSTACK_RIGHT:
		if (ss->rtop == CX_SSTACK_MAXSIZE)
			return -1;
		*e = ss->data[ss->rtop++];
		break;
	default:
		return -1;
	}

	return 0;
}
