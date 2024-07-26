/*
Add Two Numbers as Lists
Programming
Linked Lists
Medium
53.2% Success

276

7

Bookmark
Asked In:
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)

Output: 7 -> 0 -> 8

    342 + 465 = 807
Make sure there are no trailing zeros in the output list

So, 7 -> 0 -> 8 -> 0 is not a valid response even though the value is still 807.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    ListNode* ans = new ListNode(-3);
    ListNode* tempA = A;
    ListNode* tempB = B;
    ListNode* tempAns = ans;
    int sum =0, carry = 0;
    while(tempA!=NULL && tempB!=NULL){
        sum = (tempA->val + tempB->val + carry)%10;
        carry = (tempA->val + tempB->val + carry)/10;
        tempAns->next = new ListNode(sum);
        tempA = tempA -> next;
        tempB = tempB -> next;
        tempAns = tempAns ->next;
    }
    while(tempA!=NULL){
        sum = (tempA->val + carry)%10;
        carry = (tempA->val + carry)/10;
        tempAns->next = new ListNode(sum);
        tempA = tempA -> next;
        tempAns = tempAns ->next;
    }
    while(tempB!=NULL){
        sum = (tempB->val + carry)%10;
        carry = (tempB->val + carry)/10;
        tempAns->next = new ListNode(sum);
        tempB = tempB -> next;
        tempAns = tempAns ->next;
    }
    if(carry!=0){
        tempAns->next = new ListNode(carry);
    }
    return ans->next;
    
}
