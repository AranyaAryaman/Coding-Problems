/*
Level Order
Programming
Graph Data Structure & Algorithms
easy
76.4% Success

143

17

Bookmark
Asked In:
Problem Description
 
 

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).



Problem Constraints
 1 <= number of nodes <= 105



Input Format
First and only argument is root node of the binary tree, A.



Output Format
Return a 2D integer array denoting the zigzag level order traversal of the given binary tree.



Example Input
Input 1:

    3
   / \
  9  20
    /  \
   15   7
Input 2:

   1
  / \
 6   2
    /
   3


Example Output
Output 1:

 [
   [3],
   [9, 20],
   [15, 7]
 ]
Output 2:

 [ 
   [1]
   [6, 2]
   [3]
 ]


Example Explanation
Explanation 1:

 Return the 2D array. Each row denotes the traversal of each level.
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

vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    queue<TreeNode* > q;
    vector<vector<int> > ans;
    q.push(A);
    while(!q.empty()){
        int curr_size = q.size();
        vector<int> temp;
        while(curr_size!=0){
            TreeNode* node = q.front();
            q.pop();
            curr_size--;
            temp.push_back(node->val);
            if(node->left)  q.push(node->left);
            if(node->right) q.push(node->right);
        }
        ans.push_back(temp);
    } 
    return ans;
}
