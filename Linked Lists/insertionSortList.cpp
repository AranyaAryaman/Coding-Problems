/*
Insertion Sort List
Programming
Linked Lists
Medium
73.6% Success

233

10

Bookmark
Asked In:
Sort a linked list using insertion sort.

We have explained Insertion Sort at Slide 7 of Arrays

Insertion Sort Wiki has some details on Insertion Sort as well.

Example :

Input : 1 -> 3 -> 2

Return 1 -> 2 -> 3
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::insertionSortList(ListNode* A) {
    ListNode* temp = A;
    vector<int> arr;
    while(temp!=NULL){
        arr.push_back(temp->val);
        temp = temp->next;
    }
    sort(arr.begin(),arr.end());
    temp = A;
    int i =0;
    while(temp!=NULL){
        temp->val = arr[i++];
        temp = temp->next;
    }
    return A;
}
