#include "sort.h"
int new_array(int *array, int left, int right, size_t size);
void Qsort(int *array, int left, int right, size_t size);
void swap(int *array, int *left, int *right, size_t size);
/**
 * quick_sort - Sorts an array in ascending order
 * @array: Array
 * @size: Pointer to the previous element of the list
 *
 * Description: Sorts an array of integers in ascending
 * order using the Quick sort algorithm
 * Return: Void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	Qsort(array, 0, size - 1, size);
}

/**
 * Qsort - Recursion to quick sort
 * @array: Array
 * @left: Start point
 * @right: End point
 * @size: Pointer to the previous element of the list
 *
 * Description: New partitions
 * Return: int Pivot
 */
void Qsort(int *array, int left, int right, size_t size)
{
	int pivot;

	if (left < right)
	{
		pivot = new_array(array, left, right, size);
		Qsort(array, left, pivot - 1, size);
		Qsort(array, pivot + 1, right, size);
	}
}

/**
 * new_array - Evaluates new array
 * @array: Array
 * @left: Start point
 * @right: End point
 * @size: Pointer to the previous element of the list
 *
 * Description: New partitions
 * Return: int Pivot
 */
int new_array(int *array, int left, int right, size_t size)
{
	int pivot = array[right];
	int i = left, j = left;

	for (; j < right; j++)
	{
		if (array[j] < pivot)
			swap(array, &array[i++], &array[j], size);
	}
	swap(array, &array[i], &array[right], size);
	return (i);
}

/**
 * swap - Swaps two int values
 * @array: the integer array to sort
 * @left: address of first value
 * @right: address of second value
 * @size: the size of the array
 *
 * Return: Void
 */
void swap(int *array, int *left, int *right, size_t size)
{
	int temp;

	if (*left != *right)
	{
		temp = *left;
		*left = *right;
		*right = temp;
		print_array(array, size);
	}
}
