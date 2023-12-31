#include "monty.h"

/**
 * mul - mul top element from its prev
 *
 * @head: stack header
 * @counter: node counter
 *
 * Return: no
*/

void mul(stack_t **head, unsigned int counter)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	/*--------------------------------------*/

	(*head)->next->n *= (*head)->n;
	pop(head, counter);
}
