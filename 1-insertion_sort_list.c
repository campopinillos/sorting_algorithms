#include "sort.h"
/**
 * insertion_sort_list - Sorts doubly linked list in ascending order
 * @list: Double Link
 * Description: Sorts a doubly linked list of integers in ascending order
 * Return: Void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp;
	int temp;

	if (!list || !*list || !(*list)->next)
		return;
	tmp = *list;
	while (unsorted_list(list))
	{
		if (tmp->n < tmp->next->n)
			tmp = tmp->next;
		else
		{
			temp = (int)tmp->n;
			*(int *)&tmp->n = tmp->next->n;
			*(int *)&tmp->next->n = temp;
			print_list(*list);
			while (tmp->prev && tmp->n < tmp->prev->n)
			{
				tmp = tmp->prev;
				temp = (int)tmp->n;
				*(int *)&tmp->n = tmp->next->n;
				*(int *)&tmp->next->n = temp;
				print_list(*list);
			}
		}
	}
}

/**
 * unsorted_list - Verify if an list is unsorted
 * @list: Double link list
 *
 * Description: Verify if an list is unsorted
 * Return: 1 if it's unsorted 0 otherwise
 */
int unsorted_list(listint_t **list)
{
	listint_t *tmp = *list;

	while (tmp && tmp->next)
	{
		if (tmp->n > tmp->next->n)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
