#include "sandpiles.h"
/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
/**
 * stable - functions that checks if the sand pile is stable
 * @grid1: 3x3 grid
 * Return: 1 if stable, 0 if not
 */
int stable(int grid1[3][3])
{
	int i, j, stable = 1;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				stable = 0;
				break;
			}
		}
	}
	return (stable);
}
/**
 * sum - function that adds two 3x3 grids
 * @grid1: 3x3 grid
 * @grid2: 3x3 grid
 */
void sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid1[i][j] = grid1[i][j] + grid2[i][j];
	}
}
/**
 * topple - function that topples the sand pile
 * @grid1: 3x3 grid
 */
void topple(int grid1[3][3])
{
	int i, j;
	int temp[3][3] = {
	    {0, 0, 0},
	    {0, 0, 0},
	    {0, 0, 0}};
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				temp[i][j] -= 4;
				if (i + 1 < 3)
					temp[i + 1][j]++;
				if (i - 1 >= 0)
					temp[i - 1][j]++;
				if (j + 1 < 3)
					temp[i][j + 1]++;
				if (j - 1 >= 0)
					temp[i][j - 1]++;
			}
		}
	}
	sum(grid1, temp);
}
/**
 * sandpiles_sum - function that computes the sum of two sandpiles
 * @grid1: a 3x3 grid
 * @grid2: a 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	sum(grid1, grid2);
	while (!stable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		topple(grid1);
	}
}
