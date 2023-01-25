#include "sort.h"

/**
 * insertion_sort_list - a function that sorts a doubly linked list of integers
 * @list: A pointer to the head of a doubly-linked list
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *insert, *temp;

	if (list == NULL || *list == NULL)
		return;

	for (curr = (*list)->next; curr != NULL; curr = temp)
	{
		temp = curr->next;
		insert = curr->prev;
		while (insert != NULL && curr->n < insert->n)
		{
			insert->next = curr->next;
			if (curr->next != NULL)
				curr->next->prev = insert;
			curr->prev = insert->prev;
			curr->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = curr;
			else
				*list = curr;
			insert->prev = curr;
			insert = curr->prev;
			print_list(*list);
		}
		curr = curr->next;
	}
}
