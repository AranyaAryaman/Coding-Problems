/*
Merge K Sorted Lists
Programming
Heaps And Maps
Hard
69.2% Success

285

7

Bookmark
Asked In:
Merge k sorted linked lists and return it as one sorted list.

Example :

1 -> 10 -> 20
4 -> 11 -> 13
3 -> 8 -> 9
will result in

1 -> 3 -> 4 -> 8 -> 9 -> 10 -> 11 -> 13 -> 20
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> ans;
    for(int i=0;i<A.size();i++){
        ListNode* temp = A[i];
        while(temp!=NULL){
            ans.push_back(temp->val);
            temp = temp->next;
        }
    }
    sort(ans.begin(),ans.end());
    ListNode* res = new ListNode(-1);
    ListNode* temp = res;
    for(int i=0;i<ans.size();i++){
        temp->next = new ListNode(ans[i]);
        temp = temp->next;
    }
    return res->next;
}
