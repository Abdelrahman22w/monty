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
	int len = 0;
	stack_t *temp;

	while (temp)
	{
		temp = temp->next;
		len++;
	}

	if (*head == NULL || len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
		return;
	}
	temp = *head;
	sum = temp->n + temp->next->n;
	temp->next->n = sum;
	*head = temp->next;
	free(temp);

}
