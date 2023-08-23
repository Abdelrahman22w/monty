#include "monty.h"

/**
 * rotl - Rotate the stack to the left.
 *
 * @head: Double linked list representing the stack.
 * @counter: Line number in the Monty bytecode file.
 */
void rotl(stack_t **head, unsigned int counter)
{
	stack_t *current = *head;

	(void)counter;

	if (!head || !*head || !(*head)->next)
		return;

	while (current->next)
	{
		int temp = current->n;

		current->n = current->next->n;
		current->next->n = temp;
		current = current->next;
	}
}
