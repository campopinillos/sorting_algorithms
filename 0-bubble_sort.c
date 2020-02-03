#include "sort.h"
/**
 * bubble_sort - Sorts an array of integers in ascending order
 * @array: Array
 * @size: Pointer to the previous element of the list
 *
 * Description: Sorts an array of integers in
 * ascending order using the Bubble sort algorithm
 * Return: Void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0;
	int aux;

	if (!array || !size)
		return;
	while (unsorted(array, size))
	{
		for (i = 0; i < size && array[i + 1]; i++)
		{
			if (array[i] > array[i + 1])
			{
				aux = array[i];
				array[i] = array[i + 1];
				array[i + 1] = aux;
				print_array(array, size);
				if (!unsorted(&array[i + 1], size))
					break;
			}
		}
	}
}

/**
 * unsorted - Verify if an array is unsorted
 * @array: Array
 * @size: Size
 *
 * Description: Verify if an array is unsorted
 * Return: 1 if it's unsorted 0 otherwise
 */
int unsorted(int *array, size_t size)
{
	size_t j = 0;

	while (j < size - 1)
	{
		if (array[j] > array[j + 1])
			return (1);
		j++;
	}
	return (0);
}
