#include "sort.h"

/**
 * insertion_sort_list - sorts using insertion format
 * @list: the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL;
	current = *list;
	while(current->next != NULL)
	{
		if (current->prev != NULL && current->n < current->prev->n)
		{
			push(current->prev, current->next, current, list);
			print_list(*list);
			//current = *list;
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
 */

void push(listint_t *tmp, listint_t *next, listint_t *current, listint_t **list)
{
	if(list != NULL)
	{
		if ((tmp != NULL) && (current != NULL))
		{
			next->prev = current->prev;
			current->prev = tmp->prev;
			tmp->prev->next = current;
			tmp->prev = current;
			current->next = tmp;
			tmp->next = next;
		}
	}


}
