#include"sort.h"
/**
*insertion_sort-that sorts a doubly linked list of integers in ascending order
*list-doubly linked list to be sorted
**/
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *current = (*list)->next, *prev = current->prev, *next = current->next;

    while (current != NULL)
    {
        prev = current->prev;
        next = current->next;

        while (prev != NULL && prev->n > current->n)
        {
            next = current;
            current = prev;
            prev = prev->prev;
            next->prev = current;
            current->next = next;
            current->prev = prev;
            if (prev)
                prev->next = current;
            else
                *list = current;
            print_list(*list);
        }

        current = next;
    }
}

