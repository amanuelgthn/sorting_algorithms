#include"sort.h"
/**
*insertion_sort-that sorts a doubly linked list of integers in ascending order
*list-doubly linked list to be sorted
**/
void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	listint_t *current = (*list)->next;
	while (current != NULL)
	{
		listint_t *insertion_point = current->prev;
		while (insertion_point != NULL && insertion_point->n > current->n)
			insertion_point = insertion_point->prev;

		if (insertion_point != NULL)
			insertion_point->next->prev = current;
		else
			*list = current;

		current->prev->next = current->next;
		if (current->next != NULL)
			current->next->prev = current->prev;

		current->next = insertion_point;
		current->prev = insertion_point ? insertion_point->prev : NULL;
		if (insertion_point != NULL)
			insertion_point->prev = current;

		print_list(*list);

		current = current->prev ? current->prev->next : (*list)->next;
	}
}
