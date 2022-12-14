#include "search_algos.h"

/**
 * print_array - Prints an array recursively
 * @array: pointer to an array of ints
 * @idx: index
 * @size: size of array
 */
void print_array(int *array, size_t idx, size_t size)
{
	if (idx > size)
		return;
	printf("%d", array[idx]);
	if (idx < size)
		printf(", ");
	print_array(array, idx + 1, size);
}

/**
 * advanced_binary - searches for a value in a sorted array of integers
 * @array: pointer to an array of ints
 * @size: number of elements in the array
 * @value: value to search
 *
 * Return: index or null
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t low = 0;
	size_t high = size - 1;
	size_t mid;

	if (!array)
		return (-1);
	while (low <= high)
	{
		printf("Searching in array: ");
		print_array(array, low, high);
		printf("\n");

		mid = (low + high) / 2;
		if (array[mid] == value && array[mid - 1] != value)
			return (mid);
		else if (array[mid] < value)
			low = mid + 1;
		else
			high = mid;
	}
	return (-1);
}
