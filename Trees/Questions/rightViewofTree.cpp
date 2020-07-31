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
    vector<int> rightSideView(TreeNode* root) {
        using info=pair<int,TreeNode*>; 
        
        vector<int> res;
        stack<info> s;
        
        if(!root)
            return {};
        
        info c={0,root};
        
        //reversePreorder ie root right left
        
        
        while(1){
            while(c.second){
                if(c.first==res.size())
                    res.push_back(c.second->val);
                s.push(c);
                c={c.first+1,c.second->right};
            }
            if(s.empty())
                break;
            c=s.top();
            s.pop();
            c={c.first+1,c.second->left};
        }
        return res;
    }
};



//we can perform level order as well
