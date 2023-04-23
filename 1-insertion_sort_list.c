#include"sort.h"
/**
*insertion_sort-that sorts a doubly linked list of integers in ascending order
*list-doubly linked list to be sorted
**/
void insertion_sort_list(listint_t **list)
{
	listint_t *current = *list, *prev = NULL, *next = NULL;

	while(current->next)
	{
		next= current->next;
		if(prev == NULL)
		{
			prev = current;
			current = next;
		}
		while(current->n < prev->n)
		{
			next = current->next;
			current->next = prev;
			current->prev = NULL;
			print_list(current);
		}
		current = next;
	}
}
