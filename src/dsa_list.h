#ifndef _DSA_LIST_H_
#define _DSA_LIST_H_
#define DSA_LIST_MAXSIZE 10

typedef int dsa_list_element_t;
struct dsa_list;

int dsa_list_init(struct dsa_list **list);
void dsa_list_deinit(struct dsa_list *list);
int dsa_list_get_element(struct dsa_list *list, int i, dsa_list_element_t *e);
int dsa_list_insert(struct dsa_list *list, int i, dsa_list_element_t e);

#endif /* _DSA_LIST_H_ */
