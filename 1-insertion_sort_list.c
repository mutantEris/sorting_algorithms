#include "sort.h"

/**
 * insertion_sort_list - sorts using insertion format
 * @list: the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *next, *current;

	tmp = malloc(sizeof(listint_t));
	current = *list;
/**
 *	current = current->next;
 */
	printf("%d\n", current->n);
	next = current->next;
	printf("%d\n", next->n);
	while (next->n > current->n)
	{
		while (current->next != NULL)
		{
			tmp->n = current->n;
			current->n = next->n;
			next->n = tmp->n;
			next = next->next;
		}
		current = current->next;
		print_list(*list);
	}
}
