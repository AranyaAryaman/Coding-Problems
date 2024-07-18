/*
Problem Description
 
 

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).



Problem Constraints
1 <= number of nodes <= 105



Input Format
First and only argument is the root node of the binary tree.



Output Format
Return 0 / 1 ( 0 for false, 1 for true ).



Example Input
Input 1:

    1
   / \
  2   2
 / \ / \
3  4 4  3
Input 2:

    1
   / \
  2   2
   \   \
   3    3


Example Output
Output 1:

 1
Output 2:

 0


Example Explanation
Explanation 1:

 The above binary tree is symmetric. 
Explanation 2:

The above binary tree is not symmetric.
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
 
bool findSymmetry(TreeNode* A, TreeNode* B)
{
    if(A == NULL && B==NULL)
        return true;
    else if(A==NULL && B!=NULL)
        return false;
    else if(A!=NULL && B==NULL)
        return false;
    else if(A->val == B->val)
        return findSymmetry(A->left,B->right) && findSymmetry(A->right,B->left);
    else
        return false;
}
 
int Solution::isSymmetric(TreeNode* A) {
    if(A==NULL)
        return 1;
    else if(A->left==NULL && A->right==NULL)
        return 1;
    else if(A->left==NULL && A->right!=NULL)
        return 0;
    else if(A->left!=NULL && A->right == NULL)
        return 0;
    else{
        return findSymmetry(A->left,A->right)==true?1:0;
    }
}
