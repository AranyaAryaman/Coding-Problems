/*
Merge Two Sorted Lists
Programming
Linked Lists
easy
64.3% Success

298

4

Bookmark
Asked In:
Merge two sorted linked lists and return it as a new list. 

The new list should be made by splicing together the nodes of the first two lists, and should also be sorted.

For example, given following linked lists :

  5 -> 8 -> 20 
  4 -> 11 -> 15
The merged list should be :

4 -> 5 -> 8 -> 11 -> 15 -> 20
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode* temp1 = A, *temp2 = B;
    ListNode* head;
    if(temp1->val<=temp2->val){
        head = new ListNode(temp1->val);
        temp1 = temp1->next;
    }
    else{
        head = new ListNode(temp2->val);
        temp2 = temp2->next;
    }
    ListNode* temp = head;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->val<=temp2->val){
        temp->next = new ListNode(temp1->val);
        temp1 = temp1->next;
        temp = temp->next;
        }
        else{
            temp->next = new ListNode(temp2->val);
            temp2 = temp2->next;
            temp = temp->next;
        }
    }
    while(temp1!=NULL){
        temp->next = new ListNode(temp1->val);
        temp1=temp1->next;
        temp = temp->next;
    }
    while(temp2!=NULL){
        temp->next = new ListNode(temp2->val);
        temp2=temp2->next;
        temp = temp->next;
    }
    return head;
}
