#include"sort.h"
/**
*insertion_sort-that sorts a doubly linked list of integers in ascending order
*list-doubly linked list to be sorted
**/
void insertion_sort_list(listint_t **list)	
{
	listint_t *head = NULL;

	if (list == NULL || (*list)->next == NULL)
		return;
	while (list != NULL)
	{
		listint_t *current = *list;
		list = list->next;
		if (head == NULL || head->n > current->n)
		{
			current->next = head;
			current->prev = NULL;
			head = current;
		}
		else
		{
			listint_t *p = head;
			while (p != NULL)
			{
				if (p->next != NULL || current->n < p->next->n)
				{
					current->next = p->next;
					current->prev = p->next->prev;
					p->next = current;
					p->next->prev = current->next->prev;
					break;
				}
				p = p->next;
			}
		}
	}
	(*list) = head;
}
					
				
