class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        if(!root)
            return res;
        helper(root,sum,path,res);
        return res;
    }
    
    void helper(TreeNode* root,int sum,vector<int>& path,vector<vector<int>>& res){
        //if(!root);
        path.push_back(root->val);
        if(!root->left && !root->right){
            if(root->val==sum)
                res.push_back(path);
        }
        else{
            
            if(root->left ) helper(root->left,sum-root->val,path,res);
            if(root->right) helper(root->right,sum-root->val,path,res);
            
        }
        path.pop_back();
    }
};
