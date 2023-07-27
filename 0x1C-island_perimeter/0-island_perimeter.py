#!/usr/bin/python3
"""
0. Island Perimeter
"""


def island_perimeter(grid):
    """
    Calculates the perimeter of the island described in grid

    Args:
        grid: list of list of integers;
        rectangular, with its width and height not exceeding 100
    """
    perimeter = 0
    for x in range(len(grid)):
        for y in range(len(grid[x])):
            if grid[x][y] == 1:
                perimeter += 4
                if x != 0 and grid[x - 1][y] == 1:
                    perimeter -= 2
                if y != 0 and grid[x][y - 1] == 1:
                    perimeter -= 2
    return perimeter
