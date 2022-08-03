#!/usr/bin/python3
"""
Python Lockboxes Challenge
"""


def canUnlockAll(boxes):
    """ Checks if box can be unlocked from previous keys """
    unlocked = [0]
    for box_num, box in enumerate(boxes):
        if not box:
            continue
        for key in box:
            if key < len(boxes) and key not in unlocked and key != box_num:
                unlocked.append(key)
    if len(unlocked) == len(boxes):
        return True
    return False
