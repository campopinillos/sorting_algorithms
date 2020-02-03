#include "sort.h"
/**
 * selection_sort - Sorts an array in ascending order
 * @array: Array
 * @size: Pointer to the previous element of the list
 *
 * Description: Sorts an array of integers in ascending
 * order using the Selection sort algorithm
 * Return: Void
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0;
	int tmp, index;

	for (j = 0; j < size - 2 && array[j + 1]; j++)
	{
		tmp = array[j];
		for (i = j + 1; i < size && array[i]; i++)
		{
			if (array[i] < array[j] && array[i] < tmp)
			{
				tmp = array[i];
				index = i;
			}
		}
		if (array[j] > tmp)
		{
			array[index] = array[j];
			array[j] = tmp;
			print_array(array, size);
		}
	}
}
