#include"sort.h"
/**
*insertion_sort-that sorts a doubly linked list of integers in ascending order
*list-doubly linked list to be sorted
**/
void insertion_sort_list(listint_t **list)
{
	listint_t *current = *list, *prev = NULL, *next = NULL;
	
	if(current->next)
	{
		next= current->next;
		if(prev == NULL)
		{
			prev = current;
			current = next;
		}
	}
	while(current)
	{
		next = current->next;
		if (current->n < prev->n)
		{
			prev->next = current->next;
			if(prev->prev)
				prev->prev->next = current;
			current->prev = prev->prev;
			prev->prev = current;
			prev = current->prev;
			print_list(current);
		}
		current = next;
	}
}
