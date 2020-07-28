/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> level;
        queue<TreeNode *> q;
        if(root==nullptr)
            return {};
        q.push(root);
        
        while(!q.empty()){
            int size=q.size();
            while(size--){
                TreeNode *curr=q.front();
                int currVal=curr->val;
                level.push_back(currVal);
                q.pop();
                
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            res.push_back(level);
            level.clear();
        }
        return res;
    }
};
