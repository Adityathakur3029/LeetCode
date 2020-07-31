class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root==p || root==q)
            return root;
        TreeNode* left= lowestCommonAncestor(root->left,p,q);
        TreeNode* right= lowestCommonAncestor(root->right,p,q);
        if(left==nullptr)
            return right;
        if(right==nullptr)
            return left;
        return root;
    }
};



//For BST
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
            return 0;
        
        else if(p->val<root->val && q->val<root->val)
            return lowestCommonAncestor(root->left,p,q);
        
        else if(p->val>root->val && q->val>root->val)
            return lowestCommonAncestor(root->right,p,q);
        
        return root;
    }
};
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
            return 0;
        
        else if(p->val<root->val && q->val<root->val)
            return lowestCommonAncestor(root->left,p,q);
        
        else if(p->val>root->val && q->val>root->val)
            return lowestCommonAncestor(root->right,p,q);
        
        return root;
    }
};
