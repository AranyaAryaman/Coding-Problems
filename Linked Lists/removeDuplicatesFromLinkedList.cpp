/*
Remove Duplicates from Sorted List
Programming
Linked Lists
Easy
70.3% Success

258

6

Bookmark
Asked In:
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,

Given 1->1->2, return 1->2.

Given 1->1->2->3->3, return 1->2->3.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode* temp = A;
    ListNode* temp2 = temp->next; 
    while(temp!=NULL && temp2!=NULL){ 
        if(temp->val==temp2->val)
            temp2=temp2->next;
        else{
            temp->next = temp2;
            ListNode* temp3 = temp2->next;
            temp = temp2;
            temp2 = temp3;
        }
    }
    if(temp!=NULL && temp2==NULL)
        temp->next = NULL;
    return A;
}
