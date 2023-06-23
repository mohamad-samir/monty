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
	stack_t *new_node, *aux;

	aux = *head;
	/* Create a new node */
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error: Failed to allocate memory for new node\n");
		exit(EXIT_FAILURE);
	}

	/* Update the links between the nodes */
	if (aux)
		aux->prev = new_node;

	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;

	/* Update the head of the stack */
	*head = new_node;
}
