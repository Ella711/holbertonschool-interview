#!/usr/bin/python3
"""
0. UTF-8 Validation
"""


def validUTF8(data):
    """
    Determines if a given data set represents a valid UTF-8 encoding

    Return: True if data is a valid UTF-8 encoding, else return False
    """
    # Number of bytes in current utf char
    n_bytes = 0

    for num in data:
        # Get binary rep. Only need least 8 significant bits
        bin_rep = format(num, '#010b')[-8:]

        if n_bytes == 0:

            # Get number of 1s in beginning of string
            for bit in bin_rep:
                if bit == '0':
                    break
                n_bytes += 1

            # 1 byte chars
            if n_bytes == 0:
                continue

            # Invalid scenarios
            if n_bytes == 1 or n_bytes > 4:
                return False

        else:
            # Else we are processing ints which represent bytes which are
            # part of a UTF char. So, they must = the pattern '10xxxxxx'.
            if not (bin_rep[0] == '1' and bin_rep[1] == '0'):
                return False

        n_bytes -= 1

    # Case where we might not have complete data for a particular utf char
    return n_bytes == 0
