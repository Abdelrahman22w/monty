#include "monty.h"
/**
 * pint - prints the top element in the stack
 * @head: double pointer to the head of the stack
 * @counter: count the line at which the error occurred
 * Return: Nothing
*/

void pint(stack_t **head, unsigned int counter)
{
	int top_value = (*head)->n;

	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		goto cleanup;
		exit(EXIT_FAILURE);
	}

	printf("%d\n", top_value); /* prints the top element */

cleanup:/* close and free file and free the stack to avoid memory leaking */
	fclose(bus.file);
	free(bus.content);
	free_stack(*head);
	exit(EXIT_FAILURE);
}
