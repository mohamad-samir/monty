#include "monty.h"

/**
 * _pall - prints the stack
 * @head: stack head
 * @counter: unused
 * Return: no return
*/

void _pall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void) counter;

	h = *head;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
