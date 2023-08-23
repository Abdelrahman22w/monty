#include "monty.h"

/**
 * div - div top element from its prev
 *
 * @head: stack header
 * @counter: node counter
 *
 * Return: no
*/

void div(stack_t **head, unsigned int counter)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		goto cleanup;
		return;
	}
	else if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		goto cleanup;
		return;
	}

	/*--------------------------------------*/

	(*head)->next->n /= (*head)->n;
	pop(head, counter);

	/*-------------------------------------*/
cleanup:
	fclose(bus.file);
	free(bus.content);
	free_stack(*head);
	exit(EXIT_FAILURE);
}
