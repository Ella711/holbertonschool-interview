#!/usr/bin/python3
"""
0. Rotate 2D Matrix
"""


def rotate_2d_matrix(matrix):
    """
    Given an n x n 2D matrix, rotate it 90 degrees clockwise

    Return: Nothing
    """
    [(matrix.pop(0),
      matrix.append(list(row))) for row in list(zip(*matrix[::-1]))]
