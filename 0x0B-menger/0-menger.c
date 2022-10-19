#include "menger.h"
/**
 * menger - function that draws a sierpinski carpet
 * @level: level of the carpet
*/
void menger(int level)
{
	int i, j, row, col, size;
	char design;

	size = pow(3, level);

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			row = i;
			col = j;
			design = '#';
			while (row > 0)
			{
				if (row % 3 == 1 && col % 3 == 1)
					design = ' ';
				row = row / 3;
				col = col / 3;
			}
			printf("%c", design);
		}
		printf("\n");
	}
}
