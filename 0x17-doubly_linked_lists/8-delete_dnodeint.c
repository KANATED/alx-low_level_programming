#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Deletes the node at a given position.
 * @head: Pointer to the address of the head of the doubly linked list.
 * @index: Index of the node that should be deleted.
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp, *to_delete;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	temp = *head;

	if (index == 0)
	{
		*head = (*head)->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(temp);
		return (1);
	}

	for (i = 0; temp != NULL && i < index - 1; i++)
		temp = temp->next;

	if (temp == NULL || temp->next == NULL)
		return (-1);

	to_delete = temp->next;
	temp->next = to_delete->next;
	if (to_delete->next != NULL)
		to_delete->next->prev = temp;
	free(to_delete);

	return (1);
}
