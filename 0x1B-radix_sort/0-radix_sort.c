#include "sort.h"
/**
 * lsd_sort - lsd sort with no increment
 *
 * @array: array of positive numbers
 * @buff: malloc buffer
 * @size: size of array
 * @lsd: Least significant digit
 */
void lsd_sort(int *array, int **buff, int size, int lsd)
{
	int i, j, csize = 10, num;
	int carr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int carr2[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for (i = 0; i < size; i++)
	{
		num = array[i];
		for (j = 0; j < lsd; j++)
			if (j > 0)
				num = num / 10;
		num = num % 10;
		buff[num][carr[num]] = array[i];
		carr[num] += 1;
	}

	for (i = 0, j = 0; i < csize; i++)
	{
		while (carr[i] > 0)
		{
			array[j] = buff[i][carr2[i]];
			carr2[i] += 1, carr[i] -= 1;
			j++;
		}
	}
	print_array(array, size);
}
/**
 * lsd_inc_sort - lsd sort with increment
 *
 * @array: array of data to be sorted
 * @size: size of array
 * @lsd: Least significant digit
 */
void lsd_inc_sort(int *array, int size, int lsd)
{
	int carr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int i, j, num, csize = 10, **buff;

	for (i = 0; i < size; i++)
	{
		num = array[i];
		for (j = 0; j < lsd; j++)
			if (j > 0)
				num = num / 10;
		num = num % 10;
		carr[num] += 1;
	}

	if (carr[0] == size)
		return;

	buff = malloc(sizeof(int *) * 10);
	if (!buff)
		return;

	for (i = 0; i < csize; i++)
		if (carr[i] != 0)
			buff[i] = malloc(sizeof(int) * carr[i]);

	lsd_sort(array, buff, size, lsd);

	lsd_inc_sort(array, size, lsd + 1);

	for (i = 0; i < csize; i++)
		if (carr[i] > 0)
			free(buff[i]);
	free(buff);
}
/**
 * radix_sort - sorts an array of integers in ascending order
 * using the Radix sort algorithm
 *
 * @array: array
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	lsd_inc_sort(array, size, 1);
}
