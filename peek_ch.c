#include "monty.h"

/**
 * peek_ch - sub top element from its prev
 *
 * @head: stack header
 * @counter: node counter
 *
 * Return: no
*/

void peek_ch(stack_t **head, unsigned int counter)
{
	if (*head == NULL || head == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		goto cleanup;
		return;
	}
	if ((*head)->n >= 0 && (*head)->n <= 127)
	{
		printf("%c\n", (*head)->n);
		return;
	}
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", counter);
		goto cleanup;
		return;
	}

cleanup:
	fclose(bus.file);
	free(bus.content);
	free_stack(*head);
	exit(EXIT_FAILURE);
}
