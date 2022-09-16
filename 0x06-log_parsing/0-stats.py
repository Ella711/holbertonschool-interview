#!/usr/bin/python3
"""
0. Log parsing
Script that reads stdin line by line and computes metrics
"""
import sys

split_line = []
file_size = 0
status = {"200": 0, "301": 0, "400": 0, "401": 0,
          "403": 0, "404": 0, "405": 0, "500": 0}

try:
    # count each line and split it
    for i, line in enumerate(sys.stdin, start=1):
        split_line = line.split()
        # Skip line if it's not correct format
        if len(split_line) < 2:
            continue
        code = split_line[-2]
        # Count how many status codes into dict
        if code in status:
            status[code] = status[code] + 1
        # Add the file sizes
        file_size += int(split_line[-1])
        # Print every 10 lines
        if i % 10 == 0:
            print("File size: {}".format(file_size))
            for key in sorted(status.keys()):
                if status[key] > 0:
                    print("{}: {}".format(key, status[key]))
# Print if there is an interruption
finally:
    print("File size: {}".format(file_size))
    for key in sorted(status.keys()):
        if status[key] > 0:
            print("{}: {}".format(key, status[key]))
