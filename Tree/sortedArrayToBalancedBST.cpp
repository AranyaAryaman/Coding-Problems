/*
Sorted Array To Balanced BST
Programming
Tree Data Structure
easy
49.7% Success

183

24

Bookmark
Asked In:
Problem Description
 
 

Given an array where elements are sorted in ascending order, convert it to a height Balanced Binary Search Tree (BBST).

Balanced tree : a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.



Problem Constraints
1 <= length of array <= 100000



Input Format
First argument is an integer array A.



Output Format
Return a root node of the Binary Search Tree.



Example Input
Input 1:

 A : [1, 2, 3]
Input 2:

 A : [1, 2, 3, 5, 10]


Example Output
Output 1:

      2
    /   \
   1     3
Output 2:

      3
    /   \
   2     5
  /       \
 1         10


Example Explanation
Explanation 1:

 You need to return the root node of the Binary Tree.
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
TreeNode* formBST(const vector<int> &A, int l, int r){
    if(l>r || l<0 || r>A.size()-1 || r<0 || l>A.size()-1)
        return NULL;
    int mid = (l+r)/2;
    TreeNode* temp = new TreeNode(A[mid]);
    temp->left = formBST(A,l,mid-1);
    temp->right = formBST(A,mid+1,r);
    return temp;
}
 
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {\
    TreeNode* root = formBST(A,0,A.size()-1);
    return root;
}
