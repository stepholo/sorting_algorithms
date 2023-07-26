#include "sort.h"
/**
 * swaptail - swap the last nodes
 * @list: list pointer
 * @tail: tail pointer
 * @head: head pointer
 */
void swaptail(listint_t **list, listint_t **tail, listint_t **head)
{
	listint_t *temp = (*tail)->next;
	if ((*tail)->prev != NULL)
		(*tail)->prev->next = temp;
	else
		(*list) = temp;
	temp->prev = (*tail)->prev;
	(*tail)->next = temp->next;
	
	if (temp->next != NULL)
		temp->next->prev = (*tail);
	else
		*head = *tail;
	(*tail)->prev = temp;
	temp->next = (*tail);
	(*tail) = temp;
}

/**
 * swaphead - program that swaps data from the begining of a list
 * @list: list pointer
 * @head: head pointer
 * @tail: tail pointer
 * Return: void
 */
void swaphead(listint_t **list, listint_t **tail, listint_t **head)
{
	listint_t *temp = (*head)->next;

	if ((*head)->next != NULL)
		(*head)->next->prev = temp;
	else
		*tail = temp;
	temp->next = (*tail)->next;
	(*head)->prev = temp->prev;

	if (temp->prev != NULL)
		temp->prev->next = (*head);
	else
		*list = *head;
	(*head)->next = temp;
	temp->prev = (*head);
	(*head) = temp;
}

/**
 * cocktail_sort_list - implementation of the cocktail sort algorithm
 * @list: list pointer
 */
void cocktail_sort_list(listint_t **list)
{
	int flag = 1;
	listint_t *head, *tail;

	for (tail = *list; tail != NULL;)
		tail = tail->next;/*move tail pointer to the last node*/

	while (flag)
	{
		flag = 0;
		head = *list;
		for (; head != tail; head->next)/* iterate from the begining while swapping*/
		{
			if (head->n > head->next->n)
			{
				swaphead(list, &tail, &head);
				print_list((const listint_t *) *list);
			}
		}
		if (!flag)
			break;
		for (head = head->prev; head != *list; head = head->prev)/**iterate from tbe end while swappibg*/
		{
			if (tail->n < tail->prev->n)
			{
				swaptail(list, &tail, &head);
				print_list((const listint_t *) *list);
			}
		}
		flag = 1;
	}
}
