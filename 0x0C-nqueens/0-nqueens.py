#!/usr/bin/python3
"""
0. N queens; Solves the nqueens problem
"""
import sys


def is_nqueen(cell: list):
    """
    Checks if it's an Nqueen
    """
    row = len(cell) - 1
    diff = 0
    for i in range(0, row):
        diff = cell[i] - cell[row]
        if diff < 0:
            diff *= -1
        if diff in (0, row - i):
            return False
    return True


def nqueens(dimension: int, row: int, cell: list, outcome: list):
    """
    Solves the Nqueens problem recursively
    """
    if row == dimension:
        print(outcome)
    else:
        for col in range(0, dimension):
            cell.append(col)
            outcome.append([row, col])
            if is_nqueen(cell):
                nqueens(dimension, row + 1, cell, outcome)
            cell.pop()
            outcome.pop()


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)
    try:
        N = int(sys.argv[1])
    except BaseException:
        print("N must be a number")
        exit(1)

    if N < 4:
        print("N must be at least 4")
        exit(1)
    else:
        outcome = []
        square = 0
        nqueens(int(N), square, [], outcome)
