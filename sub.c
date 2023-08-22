#include "monty.h"

/**
 * sub - sub top element from its prev
 *
 * @head: stack header
 * @counter: node counter
 *
 * Return: no
*/

void sub(stack_t **head, unsigned int counter)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		goto cleanup;
		return;
	}
	/*--------------------------------------*/

	(*head)->next->n -= (*head)->n;
	pop(head, counter);

	/*-------------------------------------*/
	cleanup:
	fclose(bus.file);
	free(bus.content);
	free_stack(*head);
	exit(EXIT_FAILURE);
}
