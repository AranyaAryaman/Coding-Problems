#!/bin/python3

import math
import os
import random
import re
import sys
import ast


#
# Complete the 'two_sum' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts following parameters:
#  1. INTEGER_ARRAY numbers
#  2. INTEGER target
#

def two_sum(numbers, target):
    # Write your code here
    # print("Start")
    # print(numbers)
    # print(target)
    # my_map = dict()
    # ans = []
    # my_map[numbers[0]]=0
    # for i in range(1,len(numbers)):
    #     if target-numbers[i] in my_map.keys() and target-numbers[i] != numbers[i]:
    #         ans.append(my_map[target-numbers[i]]+1)
    #         ans.append(i+1)
    #         break
    #     else:
    #         my_map[numbers[i]]=i
    # print(ans)
    # print("End")
    # return ans 
    print(numbers)
    print(target)
    left = 0
    right = len(numbers)-1
    ans = []
    while left<right:
        if numbers[left]+numbers[right]==target:
            ans.append(left+1)
            ans.append(right+1)
            break
        elif numbers[left]+numbers[right]<target:
            left += 1
        elif numbers[left] + numbers[right]>target:
            right -= 1
            
    return ans


if __name__ == '__main__':
    outfile = open(os.environ['OUTPUT_PATH'], 'w')
    input_data = sys.stdin.read().strip().splitlines()
    
    for line in input_data:
        input_list = ast.literal_eval(line)
        nums = input_list[0]
        target = input_list[1]

        result = two_sum(nums, target)
        outfile.write(str(result) + '\n')
    outfile.close()
