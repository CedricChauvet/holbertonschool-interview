#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: The array to be printed
 * Return: listint_t
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow = head, *fast = head;

	while (fast && fast->next)
	{
		slow = slow->next;          /* Move one step */
		fast = fast->next->next;    /* Move two steps */

		/* If a loop is found */
		if (slow == fast)
		{
			slow = head;            /* Reset slow to head */
			while (slow != fast)    /* Find start of loop */
			{
				slow = slow->next;
				fast = fast->next;
			}
			return (slow);            /* Return loop start */
		}
	}
	return (NULL);    /* No loop found */
}
