#include "sort.h"
/**
 * radix_sort - Sorts an array in ascending order
 * @array: Array
 * @size: Pointer to the previous element of the list
 *
 * Description: Sorts an array of integers in ascending
 * order using the Radix sort algorithm
 * Return: Void
 */
void radix_sort(int *array, size_t size)
{
	int *new_array, *count, *output;
	int max, i = 0, j, digits = 10, itter = 1, divisor = 1, try;

	if (!array || size < 2)
		return;
	max = array[0];
	while (i < (int) size)
	{
		if (array[i] > (int) max)
			max = array[i];
		i++; }
	while (max / digits > 0)
	{	itter++;
		digits *= 10; }
	count = malloc(sizeof(int) * (max + 1));
	if (!count)
		return;
	for (i = 0; i < (int) size; i++)
		count[i] = 0;
	new_array = malloc(sizeof(int) * (max + 1));
	if (!new_array)
		return;
	output = malloc(sizeof(int) * (size));
	if (!output)
		return;
	for (try = 0; try < itter; try++, divisor *= 10)
	{
		for (j = 0; j < (int) size; j++)
		{	new_array[j] = ((array[j]) / divisor) % 10;
			count[new_array[j]] += 1; }
		for (i = 1; i < (int)  size; i++)
			count[i] += count[i - 1];
		for (i = size - 1; (int) i >= 0; i--)
		{	output[count[new_array[i]] - 1] = array[i];
			count[new_array[i]] -= 1; }
		for (i = 0; i < (int) size; i++)
		{	array[i] = output[i];
			count[i] = 0; }
		print_array(array, size); }
}
