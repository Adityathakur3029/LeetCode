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
        vector<int> level;
        if(!root)
            return res;
            
        
        bool ltr=0;
        stack<TreeNode *> s;                                          
        stack<int> rs;                                            //result stack
        
        rs.push(INT_MIN);
        
        while(!q.empty()){
            ltr=!ltr;
            int size=q.size();
            while(size--){
                TreeNode* curr=q.front();
                if(ltr){
                    q.pop();                                     //if left to right simply push in result stack
                    rs.push(curr->val);
                }
                else{                                            //push in another stack then push in result stack
                    s.push(q.front());
                    q.pop();
                }
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            
            while(!s.empty()){
                rs.push(s.top()->val);
                s.pop();
            }
            
            rs.push(INT_MIN);                                    // to differentiate between levels
        }
        
        rs.pop();
        while(!rs.empty()){
            while(rs.top()!=INT_MIN ){
                level.push_back(rs.top());
                rs.pop();
            }
            rs.pop();
            res.push_back(level);
            level.clear();
        }
        return res;
    }
};
