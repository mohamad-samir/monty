#include "monty.h"

/**
 * f_push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/

void f_push(stack_t **head, unsigned int counter)
{
	int n, j = 0;

	if (!bus.arg)
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	if (bus.arg[0] == '-')
		j++;

	while (bus.arg[j] != '\0')
	{
		if (bus.arg[j] > '9' || bus.arg[j] < '0')
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
		j++;
	}

	n = atoi(bus.arg);

	if (bus.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
