#!/bin/python3

import math
import os
import random
import re
import sys
import ast


#
# Complete the 'is_valid' function below.
#
# The function is expected to return a BOOLEAN.
# The function accepts STRING s as parameter.
#

def is_valid(s):
    # Write your code here
    stack = []
    for c in s:
        print(c)
        if(len(stack)>0):
            print(stack[-1])
        if c=='(' or c=='{' or c=='[':
            stack.append(c)
        else:
            if(len(stack)<=0):
                return False
            elif c==')' and stack[-1]=='(':
                stack.pop()
            elif c=='}' and stack[-1]=='{':
                print("Here again")
                stack.pop()
            elif c==']' and stack[-1]=='[':
                stack.pop()
            else:
                return False
    print("Here")        
    if len(stack)==0:
        return True
    else:
        return False
if __name__ == '__main__':
    outfile = open(os.environ['OUTPUT_PATH'], 'w')
    input_lines = sys.stdin.read().strip().splitlines()
    
    for input_str in input_lines:
        if input_str.strip() == "":  
            continue
        
        try:
            s = ast.literal_eval(input_str)

            result = is_valid(s)

            outfile.write(str(result) + '\n')
        except (ValueError, SyntaxError):
            print("Error: Invalid input")
    outfile.close()
