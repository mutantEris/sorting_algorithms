#include "sort.h"

/**
 * insertion_sort_list - sorts using insertion format
 * @list: the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *tmp = NULL, *next = NULL, *current = NULL;
	int i = 0;

	current = *list;
	next = current->next;
	while (next->next != NULL)
	{
		tmp = malloc(sizeof(listint_t));
		printf("current node %d\n", current->n);
		printf("next node %d\n", next->n);
		while (current->n < next->n)
		{
			tmp->n = current->n;
			current->n = next->n;
			next->n = tmp->n;
			printf("iteration: %d. tmp->n = %d\n", i, tmp->n);
			printf("current->n = %d\n", current->n);
			printf("next->n = %d\n", next->n);
			next = next->next;
			i++;
		}
		current = current->next;
		print_list(*list);
		free(tmp);
	}
}
