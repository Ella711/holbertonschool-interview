#!/usr/bin/python3
"""
File for minOperations function
"""


def minOperations(n):
    """
    Given a number n, write a method that calculates the fewest number
    of operations needed to result in exactly n H characters in the file.

    Returns an integer
    If n is impossible to achieve, return 0
    """
    char = 1
    paste = 0
    minop = 0
    if char > n:
        return 0
    while char < n:
        if n % char == 0 and char != paste:
            paste = char
        else:
            char += paste
        minop += 1
    return minop
