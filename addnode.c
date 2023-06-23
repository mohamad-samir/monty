#include "monty.h"

/**
 * addnode - Add a node to the head of the stack
 * @head: Pointer to the head of the stack
 * @n: Value to be stored in the new node
 *
 * Return: No return value
 */
void addnode(stack_t **head, int n)
{
	/* Create a new node */
	stack_t *new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error: Failed to allocate memory for new node\n");
		exit(EXIT_FAILURE);
	}

	/* Set the value of the new node */
	new_node->n = n;

	/* Connect the new node to the existing list */
	new_node->next = *head;
	new_node->prev = NULL;

	if (*head != NULL)
		(*head)->prev = new_node;

	/* Update the head of the stack */
	*head = new_node;
}
