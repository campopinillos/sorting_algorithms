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
				if (!unsorted(&array[i + 1], size - i))
					break;
			}
		}
	}
}

/**
 * unsorted - Verify if an array is unsorted
 * @array: Array
 *
 * Description: Verify if an array is unsorted
 * Return: 1 if it's unsorted 0 otherwise
 */
int unsorted(int *array, size_t size)
{
	size_t j = 0;

	while (array[j] && array[j + 1] && size > 0)
	{
		if (array[j] > array[j + 1])
			return (1);
		j++;
	}
	return (0);
}
