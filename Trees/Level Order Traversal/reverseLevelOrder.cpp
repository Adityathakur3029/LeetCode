/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 
 /*if we have to use data structure instead of property of vector then we can use stack
 and then we will be able to have reverse level while popping*/
 
 
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
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
            res.insert(res.begin(),level);
            level.clear();
        }
        return res;
    }
};
