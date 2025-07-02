#!/bin/python

import math
import os
import random
import re
import sys
import ast

#
# Complete the 'decode_string' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def decode_string(s):
    # Write your code here
    stack = []
    curNum = 0
    curStr = ''
    
    for c in s:
        if c.isdigit():
            curNum = curNum * 10 + int(c)
        elif c=='[':
            stack.append((curStr,curNum))
            curStr = ''
            curNum = 0
        elif c==']':
            prev_str, num = stack.pop()
            curStr = prev_str + num * curStr
        else:
            curStr += c
    
    return curStr 
            
        
            
if __name__ == '__main__':
    outfile = open(os.environ['OUTPUT_PATH'], 'w')
    input_data = sys.stdin.read().strip().split('\n')
    
    for line in input_data:
        arr = ast.literal_eval(line.strip())   
        result = decode_string(arr)
        outfile.write(str(result) + '\n')
    outfile.close()

