#include "monty.h"

/**
 * mod - mod top element from its prev
 *
 * @head: stack header
 * @counter: node counter
 *
 * Return: no
*/

void mod(stack_t **head, unsigned int counter)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	else if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	/*--------------------------------------*/

	(*head)->next->n %= (*head)->n;
	pop(head, counter);

}
