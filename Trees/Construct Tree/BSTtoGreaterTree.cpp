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
    int sum=0;
    TreeNode* convertBST(TreeNode* root) {
        if(!root)
            return 0;
        else{
        if(root->right) convertBST(root->right);
            sum+=root->val;
            root->val=sum;
        if(root->left) convertBST(root->left);}
        return root;
    }
};


//reverse morris inorder
class Solution {
public:
    int sum=0;
    TreeNode* convertBST(TreeNode* root) {
        if(!root)
            return nullptr;
        TreeNode* curr=root;
        while(curr){
            if(curr->right){
                TreeNode* prev=curr->right;
                while(prev->left && prev->left!=curr)
                    prev=prev->left;
                
                if(!prev->left){
                    prev->left=curr;
                    curr=curr->right;
                }
                else{
                    prev->left=nullptr;
                    sum+=curr->val;
                    curr->val=sum;
                    curr=curr->left;
                }
            }
            else{
                sum+=curr->val;
                curr->val=sum;
                curr=curr->left;
            }
        }
        return root;
    }
};

