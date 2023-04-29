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
			insert_node(head, current);
			head->next = tmpnext;
		}
		else
		{
			listint_t *p = head;
			while (p != NULL)
			{
				if (p->next == NULL || current->n < p->next->n)
				{
					insert_node(p, current);
					break;
				}
				p = p->next;
			}
		}
	}
	print_list(*list);
}

void insert_node(listint_t *head, listint_t *node)
{
	listint_t *p = NULL;
	if (head == NULL)
	{
		head = node;
		return;
	}
	if (head->n > node->n)
	{
		node->next = head;
		head = node;
		return;
	}
	p = head;
	while (p->next != NULL && p->next->n < node->n)
	{
		p = p->next;
	}
	node->next = p->next;
	p->next = node;
}
