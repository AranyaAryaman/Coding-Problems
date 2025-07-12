#!/bin/python

import math
import os
import random
import re
import sys

class SinglyLinkedListNode:
    def __init__(self, node_data):
        self.data = node_data
        self.next = None

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

# Helper function to print linked list (for testing)
def print_linked_list(head):
    if head is None:
        return 'None'   
    
    current = head
    output = []
    while current:
        output.append(str(current.data))
        current = current.next
    return ' -> '.join(output)

#
# Complete the 'merge_two_lists' function below.
#
# The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
# The function accepts following parameters:
#  1. INTEGER_SINGLY_LINKED_LIST l1
#  2. INTEGER_SINGLY_LINKED_LIST l2
#

#
# For your reference:
#
# SinglyLinkedListNode:
#     int data
#     SinglyLinkedListNode next
#
#

def merge_two_lists(l1, l2):
    # Write your code here
    dummy = SinglyLinkedListNode(0)
    temp = dummy
    while l1 is not None and l2 is not None:
        if l1.data <= l2.data:
            temp2 = SinglyLinkedListNode(l1.data)
            temp.next = temp2
            temp = temp.next
            l1 = l1.next
        else:
            temp2 = SinglyLinkedListNode(l2.data)
            temp.next = temp2
            temp = temp.next
            l2 = l2.next
    
    while l1 is not None:
        temp2 = SinglyLinkedListNode(l1.data)
        temp.next = temp2
        temp = temp.next
        l1 = l1.next
        
    while l2 is not None:
        temp2 = SinglyLinkedListNode(l2.data)
        temp.next = temp2
        temp = temp.next
        l2 = l2.next
        
    return dummy.next
        

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    input_line = input().strip()  # Read the entire input line
    while(input_line != "END"):
        l1_str, l2_str = input_line.split(',')  # Split into two parts

        l1 = SinglyLinkedList()
        for item in l1_str.split('->'):
            item = item.strip()
            if item != 'None':  # Check for 'None' before converting
                l1.insert_node(int(item))

        l2 = SinglyLinkedList()
        for item in l2_str.split('->'):
            item = item.strip()
            if item != 'None':  # Check for 'None' before converting
                l2.insert_node(int(item))

        # Handle the case where both linked lists are empty
        if l1.head is None and l2.head is None:
            fptr.write('None\n')  # Write 'None' directly if both lists are empty
        else:
            result = merge_two_lists(l1.head, l2.head)
            fptr.write(print_linked_list(result) + '\n')
        input_line = input().strip()
    
    fptr.close()
