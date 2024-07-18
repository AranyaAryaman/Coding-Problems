/*
Problem Description

Given a Binary Tree A containing N nodes.

You need to find the path from Root to a given node B.

NOTE:

No two nodes in the tree have same data values.
You can assume that B is present in the tree A and a path always exists.


Problem Constraints
 1 <= N <= 105 

 1 <= Data Values of Each Node <= N

 1 <= B <= N



Input Format
First Argument represents pointer to the root of binary tree A.

Second Argument is an integer B denoting the node number.



Output Format
Return an one-dimensional array denoting the path from Root to the node B in order.



Example Input
Input 1:

 A =

           1
         /   \
        2     3
       / \   / \
      4   5 6   7 


B = 5

Input 2:

 A = 
            1
          /   \
         2     3
        / \ .   \
       4   5 .   6


B = 1




Example Output
Output 1:

 [1, 2, 5]
Output 2:

 [1]


Example Explanation
Explanation 1:

 We need to find the path from root node to node with data value 5.
 So the path is 1 -> 2 -> 5 so we will return [1, 2, 5]
Explanation 2:

 We need to find the path from root node to node with data value 1.
 As node with data value 1 is the root so there is only one node in the path.
 So we will return [1]
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

stack<TreeNode* > sol;

bool doesExist(TreeNode* A, int B){
    if(A==NULL)
        return false;
    if(A && A->left==NULL && A->right==NULL){
        if(A->val==B){
            sol.push(A);
            return true;
        }
        else
            return false;
    }
    if(A!=NULL){
        if(A->val == B){
            //cout<<A->val<<endl;
            sol.push(A);
            return true;
        }
    }
    if(A->left){
        if(doesExist(A->left,B)){
            //cout<<A->left->val;
            if(sol.top()->val != A->left->val)
                sol.push(A->left);
            return true;
        }
    }
    if(A->right){
        if(doesExist(A->right,B)){
            //cout<<A->right->val;
            if(sol.top()->val != A->right->val)
                sol.push(A->right);
            return true;
        }
    }
    return false;
}
 
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    if(A==NULL) return ans;
    ans.push_back(A->val);
    if(A->val == B){
       return ans; 
    }
    if(doesExist(A,B)){
        while(!sol.empty()){
            ans.push_back(sol.top()->val);
            sol.pop();  
        }
    }
    return ans;
}
