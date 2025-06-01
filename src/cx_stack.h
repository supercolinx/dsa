/* stack
 * @author	colinx
 * @date	Sun Jun  1 15:36:32 CST 2025
 */
#ifndef _CX_STACK_H
#define _CX_STACK_H
#define CX_STACK_SIZE	16
typedef int cx_stack_elem_t;
typedef struct cx_stack cx_stack_t;

int cx_stack_init(cx_stack_t **s);
void cx_stack_deinit(cx_stack_t *s);
int cx_stack_push(cx_stack_t *s, cx_stack_elem_t e);
int cx_stack_pop(cx_stack_t *s, cx_stack_elem_t *e);

#endif /* _CX_STACK_H */
