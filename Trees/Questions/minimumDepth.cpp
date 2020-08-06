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
    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }else if(root->left == NULL && root->right == NULL){
            return 1;
        }
        int leftDepth= root->left ? minDepth(root->left) : INT_MAX;
        int rightDepth= root->right ? minDepth(root->right) : INT_MAX;
        int smallestDepth=std::min(leftDepth,rightDepth);
        return smallestDepth+1;
    }
};
