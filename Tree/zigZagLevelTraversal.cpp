/*
Given a binary tree, return the zigzag level order traversal of its nodes’ values. (ie, from left to right, then right to left for the next level and alternate between).

Example : 

Given binary tree

    3
   / \
  9  20
    /  \
   15   7
return

[
         [3],
         [20, 9],
         [15, 7]
]
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
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    vector<vector<int>> result;
    if(A==NULL) return result;
    bool ltr = true;
    queue<TreeNode* > q;
    q.push(A);
    while(!q.empty()){
        vector<int> ans;    
        int temp = q.size();
       // cout<<temp<<endl;
        for(int i=0;i<temp;i++){
           // cout<<q.front()->val<<endl;
            ans.push_back(q.front()->val);
            if(q.front()->left) q.push(q.front()->left);
            if(q.front()->right) q.push(q.front()->right);
            q.pop();
        }
        if(ltr){
            result.push_back(ans);
        }        
        else{
            reverse(ans.begin(),ans.end());
            result.push_back(ans);
        }
        ltr = !ltr;
    }
    return result;
    
}
