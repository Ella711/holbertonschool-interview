#include "sort.h"
/**
 * merge_sort - function that sorts an array of integers in ascending order
		using the Merge Sort algorithm
 * @array: array of numbers to be sorted
 * @size: size of the array
*/
void merge_sort(int *array, size_t size)
{
	int *temp = NULL;

	if (array && size > 1)
	{
		temp = malloc(sizeof(int) * size);
		copy_array(array, 0, size, temp);
		split_merge(array, temp, size);
		free(temp);
	}
}
/**
 * split_merge - split merge
 * @left: left side of array
 * @right: right side of array
 * @size: size of entire array
*/
void split_merge(int left[], int right[], size_t size)
{
	int mid = 0;

	if (size < 2)
		return;

	mid = size / 2;

	split_merge(left, right, mid);
	split_merge(left + mid, right, size - mid);
	merge(left, right, size);
}
/**
 * merge - merges 2 sub arrays
 * @left: left side of array
 * @right: right side of array
 * @size: size of array
*/
void merge(int left[], int right[], size_t size)
{
	size_t mid = size / 2;
	size_t i = 0, j = mid, k = 0;

	printf("Merging...\n[left]: ");
	print_array(left, mid);
	printf("[right]: ");
	print_array(left + mid, size - mid);

	for (i = 0; k < size; k++)
	{
		if (i < mid && (j == size || left[i] <= left[j]))
		{
			right[k] = left[i];
			i++;
		}
		else
		{
			right[k] = left[j];
			j++;
		}
	}
	for (i = 0; i < size; i++)
		left[i] = right[i];

	printf("[Done]: ");
	print_array(right, size);
}
/**
 * copy_array - makes a copy of an array
 * @destination: destination of copied array
 * @start: start index
 * @end: end index
 * @src: source of array to be copied
*/
void copy_array(int *destination, int start, int end, int *src)
{
	int i;

	for (i = start; i < end; i++)
		src[i] = destination[i];
}
