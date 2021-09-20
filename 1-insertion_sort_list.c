#include "sort.h"

/**
 * insertion_sort_list - sorts using insertion format
 * @list: the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL;

	current = *list;
	while (current != NULL)
	{
		if (current->prev != NULL && current->n < current->prev->n)
		{
			list = push(current->prev,
				    current->next, current, list);
			print_list(*list);
		}
		else
		{
			current = current->next;
		}
	}
}

/**
 * push - reorders list
 * @tmp: temp
 * @next: next node
 * @current: current node
 * @list: the list
 * Return: list
 */

listint_t **push(listint_t *tmp,
	       listint_t *next, listint_t *current, listint_t **list)
{
	if (list != NULL)
	{
		if ((tmp != NULL) && (current != NULL))
		{
			if (next != NULL)
			{
				next->prev = current->prev;
			}
			current->prev = tmp->prev;
			if (tmp->prev != NULL)
			{
				tmp->prev->next = current;
			}
			tmp->prev = current;
			current->next = tmp;
			tmp->next = next;
			if (current->prev == NULL)
			{
				*list = current;
			}
			return (list);
		}
	}
	return (list);
}
