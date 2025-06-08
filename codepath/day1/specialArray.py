#!/bin/python3

import math
import os
import random
import re
import sys
import ast



#
# Complete the 'special_array' function below.
#
# The function is expected to return an INTEGER.
# The function accepts INTEGER_ARRAY nums as parameter.
#

import bisect

def special_array(nums):
    # Write your code here
    if len(nums)==0:
        return -1
    nums.sort()
    for num in range(len(nums)+1):
        if num == len(nums) - bisect.bisect_left(nums,num):
            return num
    return -1

if __name__ == '__main__':
    outfile = open(os.environ['OUTPUT_PATH'], 'w')
    input_lines = sys.stdin.read().strip().splitlines()
    
    for input_str in input_lines:
        if input_str.strip() == "":  
            continue
        
        try:
            nums = ast.literal_eval(input_str)

            result = special_array(nums)

            outfile.write(str(result) + '\n')
        except (ValueError, SyntaxError):
            print("Error: Invalid input")
    outfile.close()
