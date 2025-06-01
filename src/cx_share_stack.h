#ifndef _CX_SHARE_STACK_H
#define _CX_SHARE_STACK_H
#define CX_SSTACK_MAXSIZE 16
typedef int cx_sstack_elem_t;
typedef struct cx_sstack cx_sstack_t;

typedef enum cx_sstack_type {
	EN_SSTACK_LEFT = 0,
	EN_SSTACK_RIGHT,
} cx_sstack_type_t;

int cx_sstack_init(cx_sstack_t **ss);
void cx_sstack_deinit(cx_sstack_t *ss);
int cx_sstack_push(cx_sstack_t *ss, cx_sstack_elem_t e, cx_sstack_type_t type);
int cx_sstack_pop(cx_sstack_t *ss, cx_sstack_elem_t *e, cx_sstack_type_t type);

#endif /* _CX_SHARE_STACK_H */
