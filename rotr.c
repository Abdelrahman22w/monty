#include "monty.h"

/**
 * rotr - Rotate the stack to the bottom using swapping approach.
 *
 * @head: Double linked list representing the stack.
 * @counter: Line number in the Monty bytecode file.
 */
void rotr(stack_t **head, unsigned int counter)
{
	stack_t *current = *head;
	stack_t *last = NULL;

	(void)counter;

	if (!head || !*head || !(*head)->next)
		return;

	/*Find the last element*/
	while (current->next)
		current = current->next;

	last = current;


	while (last != *head)
	{
		int temp = last->n;

		last->n = last->prev->n;
		last->prev->n = temp;
		last = last->prev;
	}
}
