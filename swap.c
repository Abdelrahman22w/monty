#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 *@head: double pointer to the head of the stack
 *@counter: counts the line at which the error occurred
 *Return: Nothing
*/
void swap(stack_t **head, unsigned int counter)
{
	stack_t *h = *head;
	int len = 0;

	while (h)/* find the length of the stack */
	{
		h = h->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		goto cleanup;
	}
	/* swaps the top two elements of the stack */
	h = *head;

	stack_t *temp = h->next;

	h->next = h->next->next;
	temp->next = h;

	*head = temp;

	return;

cleanup:
	fclose(bus.file);
	free(bus.content);
	free_stack(*head);
	exit(EXIT_FAILURE);
}
