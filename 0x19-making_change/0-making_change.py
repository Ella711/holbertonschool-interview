#!/usr/bin/python3
"""
0. Change comes from within
"""


def makeChange(coins, total):
    """
    Determines the fewest number of coins needed to meet a given amount total

    Args:
        coins: list of values of the coins in your possession
        total: total amount

    Return: fewest number of coins needed to meet total
    """
    if total <= 0:
        return 0

    total_coins = 0
    change = 0
    coins = sorted(coins, reverse=True)

    for coin in coins:
        while change + coin <= total:
            change += coin
            total_coins += 1
        if change == total:
            return total_coins
    return -1
