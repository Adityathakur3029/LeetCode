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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        
        q.push(root);
        vector<vector<int>> res;
        if(!root)
            return res;
        vector<int> level;
        bool ltr=0;                                //means left to right
        stack<TreeNode *> s;
        while(!q.empty()){
            ltr=!ltr;
            int size=q.size();
            while(size--){
                TreeNode* curr=q.front();
                if(ltr){                                 //if left to right then simply push in res
                    q.pop();
                    level.push_back(curr->val);
                }
                else{                                    //if right to left then first push to stack
                    s.push(q.front());
                    q.pop();
                }
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            
            while(!s.empty()){                           //this will give me right to left of one level
                level.push_back(s.top()->val);
                s.pop();
            }
            res.push_back(level);
            level.clear();
        }
        return res;
    }
};
