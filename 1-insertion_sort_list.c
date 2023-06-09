#include"sort.h"
/**
 * print_head - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_head(const listint_t *list)
{
	int i;

	i = 0;
	while (list)
	{
		if (i > 0)
			printf(", ");
		printf("%d", list->n);
		++i;
		list = list->next;
	}
	printf(", ");
}
/**
*print_sorted-print sorted list
*@head:list containing sorted list
*@list:list containng the remaining unsorted list
**/
void print_sorted(const listint_t *head, const listint_t *list)
{
	if ((list) == NULL)
		print_list(head);
	else
	{
		print_head(head);
		print_list(list);
	}
}
/**
*check_sorted-function to check if a list is sorted
*@list:list to be checked if it is sorted
*Return: True if the list is sorted and False if not
**/
bool check_sorted(const listint_t *list)
{
	while (list->next)
	{
		if (list->n > list->next->n)
		{
			return (true);
		}
		list = list->next;
	}
	return (false);
}
/**
*insertion_sort_list-sorts a doubly linked list of integers in ascending order
*@list:doubly linked list to be sorted
**/
void insertion_sort_list(listint_t **list)
{
	listint_t *head = NULL, *current = NULL, *p = NULL;
	bool swap = false;

	if (list == NULL || (*list)->next == NULL)
		return;
	swap = check_sorted(*list);
	while ((*list) != NULL && swap == true)
	{
		current = *list;
		(*list) = (*list)->next;
		if (head == NULL || head->n > current->n)
		{
			current->next = head;
			current->prev = NULL;
			head = current;
			print_sorted(head, *list);
		}
		else
		{
			p = head;
			while (p != NULL)
			{
				if (p->next == NULL || current->n < p->next->n)
				{
					current->prev = p;
					current->next = p->next;
					if (p->next != NULL)
						p->next->prev = current;
					p->next = current;
					print_sorted(head, *list);
					break;
				}
				p = p->next;
			}
		}
	}
	if (swap == true)
		*list = head;
}
