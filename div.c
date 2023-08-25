#include "monty.h"

/**
 * f_div - divide the second element by the top element of the stack
 *
 * @head: stack header
 * @counter: node counter
 *
 * Return: no
 */
void f_div(stack_t **head, unsigned int counter)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
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

    /* Perform floating-point division */
    double result = (double)(*head)->next->n / (*head)->n;
    
    /* Pop the top element */
    pop(head, counter);

    /* Push the result back onto the stack */
    push(head, result);

}
