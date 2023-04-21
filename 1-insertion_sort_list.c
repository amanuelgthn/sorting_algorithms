#include"sort.h"
listint_t *create_node(void)
{
	listint_t *node = malloc(sizeof(listint_t));

	if (node == NULL)
		return (NULL);
	return (node);
}
/**
*insertion_sort-that sorts a doubly linked list of integers in ascending order
*list-doubly linked list to be sorted
**/
void insertion_sort_list(listint_t **list)
{
	int tmp;

	while((*list)->next)
	{
		(*list) = (*list)->next;
		if((*list)->n < (*list)->prev->n)
		{
			node->n = (*list)->n;
			(*list)->prev->prev = node;
			node
			(*list)->n = tmp;
		}
	}
}
