#include "monty.h"

/**
 * free_stack - frees a stack
 * @head: double pointer to the head of the stack
 */
void free_stack(stack_t *head)
{
	stack_t *current = head;
	stack_t *next_node;

	while (current != NULL)
	{
		next_node = current->next; /* Store the next node before freeing current */

		free(current); /* Free the current node */

		current = next_node; /* Move to the next node */
	}
}
