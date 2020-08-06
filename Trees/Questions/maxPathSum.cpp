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
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        helper(root,res);
        return res;
    }
    int helper(TreeNode* root,int& res){
        if(!root)
            return 0;
        int leftsum=helper(root->left,res);
        int rightsum=helper(root->right,res);
        res=max(res,leftsum+rightsum+root->val);                      
        return max(0,root->val+max(leftsum,rightsum));                    //what every node should return
    }
};
