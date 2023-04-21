#include"sort.h"
/**
*insertion_sort-that sorts a doubly linked list of integers in ascending order
*list-doubly linked list to be sorted
**/
void insertion_sort_list(listint_t **list)
{
	while(list->next)
	{
		list = list->next;
		if(list->n < list->prev->n)
		{
			tmp = list->prev->n;
			list->prev->n = list->n;
			list->n = tmp;
		}
	}
}
