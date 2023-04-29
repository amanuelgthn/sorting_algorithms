#include"sort.h"
/**
*insertion_sort-that sorts a doubly linked list of integers in ascending order
*list-doubly linked list to be sorted
**/
void insertion_sort_list(listint_t **list)
{
    listint_t *head = NULL;
    listint_t *current = *list;
    if (list == NULL || *list == NULL || (*list)->next == NULL) {
        return;
    }
    current = (*list);
    while (current != NULL)
    {
        listint_t *next = current->next;
        if (head == NULL || head->n >= current->n)
        {
            current->prev = NULL;
            current->next = head;
            if (head != NULL) {
                head->prev = current;
            }
            head = current;
        }
        else
        {
            listint_t *p = head;
            while (p != NULL && p->n < current->n)
            {
                p = p->next;
            }

            if (p != NULL) {
                current->prev = p->prev;
                current->next = p;
                p->prev->next = current;
                p->prev = current;
            }
        }
        current = next;
    }
    (*list) = head;
}
