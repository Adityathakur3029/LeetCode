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
    struct res{
        bool balanced;
        int height;
    };
    bool isBalanced(TreeNode* root) {
        res r1;
        return helper(root,r1).balanced;
    }
    
    res helper(TreeNode* root, res r1){
        if(!root)
            return {true,0};
        res l=helper(root->left,r1);
        res r=helper(root->right,r1);
        if(l.balanced && r.balanced && abs(l.height-r.height)<2)
            return {true,max(l.height,r.height)+1};
        return {false,max(l.height,r.height)+1};
    }
};
