#include <stdio.h>
#include "dsa_list.h"

int main(void)
{
	struct dsa_list *list = 0;
	dsa_list_element_t e = 0;

	dsa_list_init(&list);

	dsa_list_insert(list, 0, 3);
	if (dsa_list_get_element(list, 0, &e))
		fprintf(stderr, "(EE) get element\n");
	fprintf(stdout, "e = %d\n", e);

	dsa_list_deinit(list);
	return 0;
}
