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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int x=0;
        int y=0;
        vector<vector<int>> res;
        map<int, vector<pair<int,int>>> mp;
        
        dfs(root,x,y,mp);
        
        for(auto i:mp){
            auto z=i.second;
            sort(z.begin(),z.end(),[](const pair<int,int>& left,const pair<int,int>& right){
                if(left.first==right.first)
                    return left.second<right.second;
                return left.first>right.first;
            });
            static vector<int> temp;
            for(auto ele: z)
                temp.push_back(ele.second);
            res.push_back(temp);
            temp.clear();
        }
        
        return res;
    }
    
    
    void dfs(TreeNode* root, int x, int y, map<int, vector<pair<int,int>>>& mp){
        if(!root);
        else{
            
            mp[x].push_back(make_pair(y,root->val));
            dfs(root->left,x-1,y-1,mp);
            dfs(root->right,x+1,y-1,mp);
        }
    }
};
