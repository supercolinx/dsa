#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dsa_list.h"

typedef dsa_list_element_t _element_t;
struct dsa_list {
	_element_t data[DSA_LIST_MAXSIZE];
	int length;
};

int
dsa_list_init(struct dsa_list **list)
{
	if (!list) return -1;

	*list = (struct dsa_list*) malloc(sizeof(**list));
	if (!*list) {
		fprintf(stderr, "(EE) %s malloc\n", __func__);
		return -1;
	}

	memset((*list)->data, 0, sizeof(DSA_LIST_MAXSIZE));
	(*list)->length = 0;
	return 0;
}

void
dsa_list_deinit(struct dsa_list *list)
{
	free(list);
}

int
dsa_list_get_element(struct dsa_list *list, int i, _element_t *e)
{
	if (i < 0 || i >= list->length) return -1;

	*e = list->data[i];
	return 0;
}

int
dsa_list_insert(struct dsa_list *list, int i, _element_t e)
{
	if (i < 0 || i + 1 >= DSA_LIST_MAXSIZE) return -1;

	int j = list->length;
	while (i && j >= i) {
		list->data[j--] = list->data[j - 1];
	}
	list->data[j] = e;
	list->length++;

	return 0;
}

int
dsa_list_delete(struct dsa_list *list, int i, _element_t *e)
{
	if (i < 0 || i >= list->length) return -1;

	*e = list->data[i - 1];

	return 0;
}
