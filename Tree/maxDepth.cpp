/*
Max Depth of Binary Tree
Programming
Tree Data Structure
Medium
72.6% Success

227

11

Bookmark
Asked In:
Given a binary tree, find its maximum depth.

The maximum depth of a binary tree is the number of nodes along the longest path from the root node down to the farthest leaf node.

NOTE : The path has to end on a leaf node.

Example :

         1
        /
       2
max depth = 2.
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
int Solution::maxDepth(TreeNode* A) {
    if(A==NULL)
        return 0;
    else if(A && A->left==NULL && A->right==NULL)
        return 1;
    else if(A && A->left==NULL && A->right!=NULL)
        return maxDepth(A->right)+1;
    else if(A && A->left!=NULL && A->right==NULL)
        return maxDepth(A->left)+1;
    else
        return 1 + max(maxDepth(A->left),maxDepth(A->right));
}
