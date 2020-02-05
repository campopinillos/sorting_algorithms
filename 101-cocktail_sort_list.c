#include "sort.h"
int sorted_right(listint_t *tmp, listint_t **list);
/**
 * cocktail_sort_list - Sorts an array of integers in ascending order
 * @list: double linked list
 *
 * Description: sorts a doubly linked list of
 * integers in ascending order using
 * the Cocktail shaker sort
 * Return: Void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tmp, *_next, *_prev, *_prev2;
	int flag = 0;

	if (!list || !*list || !(*list)->next)
		return;
	tmp = *list;
	while (tmp && tmp->next)
	{
		flag = sorted_right(tmp, list);
		if (flag == 1)
			tmp = tmp->prev;
		else
			tmp = tmp->next, flag = 0;
	}
	if (tmp)
		tmp = tmp->prev;
	while (tmp)
	{
		_prev = tmp->next;
		_next = tmp->next->next;
		_prev2 = tmp->prev;
		if (tmp->n > tmp->next->n)
		{
			if (_prev2 == NULL)
			{
				_prev->prev = NULL;
				tmp->next = _next;
				_next->prev = tmp;
				_prev->next = tmp;
				tmp->prev = _prev;
				flag = 1;
				*list = _prev;
			}
			else if (_next == NULL)
			{
				_prev2->next = _prev;
				_prev->prev = _prev2;
				tmp->next = NULL;
				_prev->next = tmp;
				tmp->prev = _prev;
				flag = 1;
			}
			else if (_prev2 != NULL && _next != NULL)
			{
				_prev2->next = _prev;
				_prev->prev = _prev2;
				tmp->next = _next;
				_next->prev = tmp;
				_prev->next = tmp;
				tmp->prev = _prev;
				flag = 1;
			}
			print_list(*list);
		}
		tmp = tmp->prev;
	}
	if (flag == 0)
		return;
	cocktail_sort_list(list);
}
/**
 * sorted_right - Sorts an array of integers in ascending order
 * @tmp: pointer to node
 * @list: double linked list
 *
 * Description: Sorts an double linked list in
 * ascending order
 * Return: Void
 */
int sorted_right(listint_t *tmp, listint_t **list)
{
	listint_t *_next, *_prev, *_prev2;
	int flag = 0;

	_prev = tmp->next;
	_next = tmp->next->next;
	_prev2 = tmp->prev;
	if (tmp->n > tmp->next->n)
	{
		if (_prev2 == NULL && _next != NULL)
		{
			_prev->prev = NULL;
			tmp->next = _next;
			_next->prev = tmp;
			_prev->next = tmp;
			tmp->prev = _prev;
			tmp = tmp->prev;
			*list = _prev;
			flag = 1;
		}
		else if (_next == NULL && tmp->prev != NULL)
		{
			_prev2->next = _prev;
			_prev->prev = _prev2;
			tmp->next = NULL;
			_prev->next = tmp;
			tmp->prev = _prev;
			tmp = tmp->prev;
			flag = 1;
		}
		else if (_prev2 != NULL && _next != NULL)
		{
			_prev2->next = _prev;
			_prev->prev = _prev2;
			tmp->next = _next;
			_next->prev = tmp;
			_prev->next = tmp;
			tmp->prev = _prev;
			tmp = tmp->prev;
			flag = 1;
		}
		else if (tmp->prev == NULL && _prev->next == NULL)
		{
			_prev->prev = NULL;
			_prev->next = tmp;
			tmp->prev = _prev;
			tmp->next = NULL;
			*list = _prev;
			flag = 1;
		}
		print_list(*list);
	}
	return (flag);
}
