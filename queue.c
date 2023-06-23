#include "monty.h"

/**
 * _queue - changes the behavior of adding nodes to the stack to queue mode
 * @head: pointer to the head of the stack
 * @counter: line number
 * Return: No return value
 */
void _queue(stack_t **head, unsigned int counter)
{
	/* Change the mode to queue */
	bus.lifi = 1;

	/* Unused parameters */
	(void)head;
	(void)counter;
}

/**
 * addqueue - adds a new node at the end of the stack (queue mode)
 * @n: value to be stored in the new node
 * @head: pointer to the head of the stack
 * Return: No return value
 */
void addqueue(stack_t **head, int n)
{
	/* Create a new node */
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		printf("Error: Memory allocation failed\n");
		return;
	}

	/* Set the value of the new node */
	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
	{
		/* If the stack is empty, make the new node the head */
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		/* Find the last node in the stack */
		stack_t *current = *head;

		while (current->next != NULL)
			current = current->next;

		/* Append the new node at the end of the stack */
		current->next = new_node;
		new_node->prev = current;
	}
}
