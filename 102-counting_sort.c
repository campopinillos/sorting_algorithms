#include "sort.h"
/**
 * counting_sort - Sorts an array in ascending order
 * @array: Array
 * @size: Pointer to the previous element of the list
 *
 * Description: Sorts an array of integers in ascending
 * order using the Counting sort algorithm
 * Return: Void
 */
void counting_sort(int *array, size_t size)
{
	int *a;
	size_t max, sum = 0, i = 0, j = 0, n, count = 0;

	if (!array || !size)
		return;
	max = array[0];
	while (array[i])
	{
		if (array[i] > (int) max)
			max = array[i];
		i++;
	}
	a = malloc(sizeof(int) * (max + 1));
	if (!a)
		return;
	for (i = 0; i < max + 1; i++)
		a[i] = 0;
	for (i = 0; i < size; i++)
		a[array[i]] += 1;
	for (i = 0; i < max + 1; i++)
	{
		if (a[i] == 0)
			a[i] = a[i] + sum;
		else
		{
			sum += a[i];
			a[i] = sum;
		}
	}
	print_array(a, max + 1);
	for (i = 0; i < size; i++)
	{
		n = a[j];
		while (a[j++] == (int) n)
			count++;
		array[i] = count++;
	}
}
