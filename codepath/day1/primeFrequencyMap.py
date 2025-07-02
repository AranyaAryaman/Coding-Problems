#!/bin/python3

import math
import os
import random
import re
import sys
import ast

def is_prime(n):
    if n <= 1:
        return False
    if n <= 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    i = 5
    while i * i <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i += 6
    return True
#
# Complete the 'prime_frequency_map' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts INTEGER_ARRAY matrix as parameter.
#

def prime_frequency_map(matrix):
    # Write your code here
    freq_map = dict()
    for i in range(0,len(matrix)):
        for j in range(0,len(matrix[0])):
            if is_prime(matrix[i][j]):
                if matrix[i][j] in freq_map:
                    freq_map[matrix[i][j]]+=1
                else:
                    freq_map[matrix[i][j]]=1
                
    return freq_map
if __name__ == '__main__':
    outfile = open(os.environ['OUTPUT_PATH'], 'w')
    input_data = sys.stdin.read().strip()
    matrix = ast.literal_eval(input_data)

    result = prime_frequency_map(matrix)
    outfile.write(str(result) + '\n')
    outfile.close()
