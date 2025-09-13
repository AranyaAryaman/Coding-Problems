/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        deque<TreeNode* > q;
        if(root==NULL)
            return ans;
        q.push_back(root);
        while(!q.empty()){
            int cs = q.size();
            ans.push_back(q.back()->val);
            while(cs--){
                TreeNode* curr = q.front();
                q.pop_front();
                if(curr->left)
                    q.push_back(curr->left);
                if(curr->right)
                    q.push_back(curr->right);
            }
        }
        return ans;
    }
};
