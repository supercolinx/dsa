#ifndef _CX_LIST_STACK_H
#define _CX_LIST_STACK_H
typedef int cx_lstack_elem_t;
typedef struct cx_lstack_node cx_lstack_node_t;

typedef struct cx_lstack {
	cx_lstack_node_t *top;
	int size;
} cx_lstack_t;

int cx_lstack_init(cx_lstack_t *ls);
void cx_lstack_deinit(cx_lstack_t *ls);
int cx_lstack_push(cx_lstack_t *ls, cx_lstack_elem_t e);
int cx_lstack_pop(cx_lstack_t *ls, cx_lstack_elem_t *e);

#endif /* _CX_LIST_STACK_H */
