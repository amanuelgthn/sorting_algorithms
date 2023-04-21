#include "sort.h"

void exchange_nodes(listint_t *node_high, listint_t *node_low) {
  listint_t *temp;

  if (node_high == node_low) {
    return;
  }

  temp = node_high->next;
  node_high->next = node_low->next;
  node_low->next = temp;

  temp = node_high->prev;
  node_high->prev = node_low->prev;
  node_low->prev = temp;
}

void insertion_sort_list(listint_t **list) {
  listint_t *current = *list;
  listint_t *prev = NULL;

  while (current != NULL) {
    if (current->n < (prev == NULL) ? INT_MAX : prev->n) {
      exchange_nodes(current, prev);

      // Move on to the next node.
      prev = current;
      current = current->next;
    } else {
      // Move on to the next node.
      prev = current;
      current = current->next;
    }
  }
  *list = prev;
}
