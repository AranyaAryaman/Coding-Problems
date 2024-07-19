/*
Last Node in a Complete Binary Tree
Programming
Tree Data Structure
Medium
70.7% Success

141

9

Bookmark
Asked In:
Problem Description
 
 

You are given the root of a complete binary tree A.

You have to return the value of the rightmost node in the last level of the binary tree.

Try to find a solution with a better time complexity than O(N).



Problem Constraints
1 <= Number of nodes in the binary tree <= 105


Input Format
The first argument is the root of a binary tree A.


Output Format
Return a single integer denoting the value of the rightmost node in the last level of the binary tree.


Example Input
Input 1:
A = 
    1
   /
  2
Input 2:

A = 
    1
   / \
  2   3


Example Output
Output 1:
2
Output 2:

3


Example Explanation
Explanation 1:
There is only a single node in the last level of the binary tree.
Therefore, the answer is 2.
Explanation 2:

There a two nodes in the last level of the tree.
The rightmost nodes is 3.
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::lastNode(TreeNode* A) {
    queue<TreeNode *> q;
    if(A==NULL) return -1;
    if(A->left==NULL && A->right == NULL)
        return A->val;
    q.push(A);
    vector<int> lvlOrder;
    while(!q.empty()){
        lvlOrder.push_back(q.front()->val);
        if(q.front()->left) q.push(q.front()->left);
        if(q.front()->right)  q.push(q.front()->right);
        q.pop();
    }
    return lvlOrder[lvlOrder.size()-1];
}
