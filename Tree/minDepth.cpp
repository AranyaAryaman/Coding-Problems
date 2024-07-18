/*
Min Depth of Binary Tree
Programming
Tree Data Structure
Medium
59.8% Success

239

29
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::minDepth(TreeNode* A) {
    if(A==NULL)
        return 0;
    else if(A && (A->left==NULL && A->right==NULL))
        return 1;
    else if(A && (A->left==NULL && A->right!=NULL))
        return 1 + minDepth(A->right);
    else if(A && (A->left!=NULL && A->right==NULL))
        return 1 + minDepth(A->left);
    else 
        return 1 + min(minDepth(A->left),minDepth(A->right));
}

Problem Description
 
 

Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
NOTE: The path has to end on a leaf node.


Input Format
The first argument is a TreeNode, pointing to the root of the binary tree.


Output Format
Return an integer equal to the minimum depth of the tree.


Example Input
  1
 /
2


Example Output
2


Example Explanation
Minimum Depth is 2, which is from 1 -> 2.

*/

