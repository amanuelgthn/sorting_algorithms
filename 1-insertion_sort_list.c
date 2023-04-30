#include"sort.h"
/**
*insertion_sort-that sorts a doubly linked list of integers in ascending order
*list-doubly linked list to be sorted
**/
void insertion_sort_list(listint_t **list)
{
	listint_t *head = NULL,*current = NULL, /**p = NULL*/, *check = NULL;
	bool swap = false;

	if (list == NULL || (*list)->next == NULL)
		return;
	check = *list;
	while(check->next)
	{
		if(check->n > check->next->n)
		{
			swap = true;
			break;
		}
		check = check->next;
	}
	while ((*list)!= NULL && swap == true)
	{
		current = *list;
		(*list) = (*list)->next;
		if (head == NULL || head->n > current->n)
		{
			current->next = head;
			current->prev = NULL;
			head = current;
			print_list(head);
		}
		/*else
		{
			p = head;
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
		}*/
	}
	if(swap == true)
		*list = head;
}
