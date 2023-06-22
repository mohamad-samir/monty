#include "monty.h"

/**
 * f_push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_push(stack_t **head, unsigned int counter)
{
	int n, j = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			j++;

		for (; bus.arg[j] != '\0'; j++)
		{
			if (bus.arg[j] > 57 || bus.arg[j] < 48)
				flag = 1;
		}

		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			close_resources(head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		close_resources(head);
		exit(EXIT_FAILURE);
	}

	n = atoi(bus.arg);

	if (bus.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}

/**
 * close_resources - close file, free content and head stack
 * @head: stack head
 * Return: no return
*/
void close_resources(stack_t **head)
{
	fclose(bus.file);
	free(bus.content);
	free_stack(*head);
}
