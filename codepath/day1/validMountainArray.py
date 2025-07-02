#!/bin/python

import math
import os
import random
import re
import sys
import ast


# Enter your code here. Read input from STDIN. Print output to STDOUT#
# Complete the 'valid_mtn_arr' function below.
#
# The function is expected to return a BOOLEAN.
# The function accepts INTEGER_ARRAY arr as parameter.
#

def valid_mtn_arr(arr):
    # Write your code here
    print(arr)
    if len(arr) < 3:
        return False
    num = -1
    for i in range(0,len(arr)-1):
        if arr[i+1] > arr[i]:
            continue
        elif arr[i+1] == arr[i]:
            return False
        else:
            num = i
            break
    if num ==0 or num==len(arr)-1:
        return False
    for i in range(num, len(arr)-1):
        if arr[i+1]<arr[i]:
            continue
        else:
            return False
    return True
        
if __name__ == '__main__':
    outfile = open(os.environ['OUTPUT_PATH'], 'w')
    input_data = sys.stdin.read().strip().split('\n')
    
    for line in input_data:
        arr = ast.literal_eval(line.strip())   
        result = valid_mtn_arr(arr)
        outfile.write(str(result) + '\n')
    outfile.close()
