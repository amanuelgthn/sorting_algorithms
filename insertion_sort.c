#include"sort.h"
/**
*insertion_sort-that sorts a doubly linked list of integers in ascending order
*list-doubly linked list to be sorted
**/
void insertion_sort_list(listint_t **list)
{
	listint_t *head = NULL;
	listint_t *current = NULL;
	listint_t *tmpnext= NULL;

	if (list == NULL || (*list)->next == NULL)
		return;
	while ((*list)!= NULL)
	{
		current = *list;
		(*list) = (*list)->next;
		if (head == NULL || head->n > current->n)
		{
			tmpnext = current->next;
			current->next = head;
			current->prev = NULL;
			head = current;
			head->next = tmpnext;
			print_list(head);
		}
		else
		{
			listint_t *p = head;
			while (p != NULL)
			{
				if (p->next == NULL || current->n < p->next->n)
				{
					current->prev = p;
					current->next = p->next;
					if(p->next != NULL)
						p->next->prev = current;
					p->next = current;
					print_list(head);
					break;
				}
				p = p->next;
			}
		}
	}
	*list = head;
	print_list(*list);
}
