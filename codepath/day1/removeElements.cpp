#!/bin/python3

import math
import os
import random
import re
import sys

class SinglyLinkedListNode:
    def __init__(self, node_data=None, next_node=None):
        self.val = node_data
        self.next = next_node  # This should accept next_node as an argument

class SinglyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def insert_node(self, node_data):
        node = SinglyLinkedListNode(node_data)

        if not self.head:
            self.head = node
        else:
            self.tail.next = node

        self.tail = node

def print_singly_linked_list(node, sep=' -> ', fptr=None):
    if node is None:
        if fptr:
            fptr.write('None\n')
        return 'None'
    
    result_str = []
    while node:
        result_str.append(str(node.val))
        node = node.next

    if fptr:
        fptr.write(sep.join(result_str) + '\n')
    return sep.join(result_str)


#
# Complete the 'remove_elements' function below.
#
# The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
# The function accepts following parameters:
#  1. INTEGER_SINGLY_LINKED_LIST head
#  2. INTEGER val
#

#
# For your reference:
#
# SinglyLinkedListNode:
#     int data
#     SinglyLinkedListNode next
#
#

def remove_elements(head, val):
    # Write your code here
    if head is None:
        return head
    elif head.next is None and head.val == val:
        return None
    elif head.next is None and head.val != val:
        return head
    else:
        while head is not None:
            if head.val == val:
                head = head.next
            else:
                break
        
        if head is None:
            return head
        else:
            temp = head
            start = SinglyLinkedListNode(-1)
            start.next = head
            prev = start
            while temp is not None:
                if temp.val == val:
                    prev.next = temp.next
                    temp = temp.next
                else:
                    temp = temp.next
                    prev = prev.next                    
            
            return start.next
                    

import ast
if __name__ == '__main__':
    
    outfile = open(os.environ['OUTPUT_PATH'], 'w')
    
    # Helper function to convert str -> linked list
    def str_to_ll(vals_str):
        if vals_str is None or vals_str == "None":
            return None
        vals = vals_str.split("->")
        temp_head = SinglyLinkedListNode("temp")
        temp_curr = temp_head
        for val in vals:
            temp_curr.next = SinglyLinkedListNode(int(val.strip()))
            temp_curr = temp_curr.next
        return temp_head.next #Don't keep the temp head

    # Helper function to convert linked list -> str
    def ll_to_str(head):
        list_str = ""
        curr = head
        while curr:
            list_str += str(curr.val)
            if curr.next:
                list_str += "->"
            curr = curr.next
        if len(list_str) == 0:
            return "None"
        return list_str
        
    test_str = input()
    while(test_str != "END"):
        # Convert input string to list of param strings
        param_list = ast.literal_eval(test_str)

        # TODO: Edit parameters as needed
        test_ll = str_to_ll(param_list[0])
        arg_2 = int(param_list[1])

        # TODO: Edit function name and prepare result string
        result = ll_to_str(remove_elements(test_ll, arg_2))
        
        # Write output and check for another test case
        outfile.write(str(result) + '\n')
        test_str = input()

    outfile.close()
