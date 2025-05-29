/* queue
 * @author 	colinx
 * @date	Thu May 29 20:49:37 CST 2025
 */
#ifndef _CX_QUEUE_H
#define _CX_QUEUE_H
#define CX_QUEUE_SIZE 16
typedef int cx_queue_elem_t;
typedef struct cx_queue cx_queue_t;

int cx_queue_init(cx_queue_t **q);
void cx_queue_deinit(cx_queue_t *q);
int cx_queue_clean(cx_queue_t *q);
int cx_queue_head(cx_queue_t *q, cx_queue_elem_t *e);
int cx_queue_enqueue(cx_queue_t *q, cx_queue_elem_t e);
int cx_queue_dequeue(cx_queue_t *q, cx_queue_elem_t *e);

#endif /* _CX_QUEUE_H */
