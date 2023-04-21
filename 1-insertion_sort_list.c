#include"sort.h"
/**
*exchange_nodes-exchange consecutive nodes if the later node has a higher data value
*@node_high: node with a higher data value
*@node_low: node with a lower data value
**/
void exchange_nodes(listint_t *node1, listint_t *node2)
{
	listint_t *tmp;

	tmp = node1->next;
	node1->next = node2->next;
	node2->next = tmp;
	tmp = node1->prev;
	node1->prev = node2->prev;
	node2->prev = tmp;
}
/**
*insertion_sort-that sorts a doubly linked list of integers in ascending order
*list-doubly linked list to be sorted
**/
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp = *list;

	while((*list)->next)
	{
		(*list) = (*list)->next;
		if((*list)->n < (*list)->prev->n)
		{
			exchange_nodes(tmp,(*list)->prev);
			print_list(tmp);
			while (list->prev)
			{
				if ((*list)-n < (*list)->prev->n)
				{
					exchange_nodes(list,list->prev);
					print_list(list);
				}
				list = list->prev;
			}
		}
	}
}
