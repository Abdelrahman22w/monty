#include "monty.h"

/**
 * add - adds the sum of the last two elements and store in second top element
 * @head: double pointer to the head of the stack
 * @counter: count the line at which the error occurred
 * Return: Nothing
*/
void add(stack_t **head, unsigned int counter)
{
	int sum;
	stack_t *temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
		return;
	}
	sum = (*head)->n + (*head)->next->n;
	temp = (*head)->next;

	(*head)->next->n = sum;
	(*head)->next = temp->next;

	free(temp);

}
