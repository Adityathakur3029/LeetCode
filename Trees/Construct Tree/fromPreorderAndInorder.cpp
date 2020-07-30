/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preStr=0;
        int preEnd=preorder.size()-1;
        
        int inStr=0;
        int inEnd=inorder.size()-1;
        
        return calculate(preorder,inorder,preStr,preEnd,inStr,inEnd);
        
        
    }
    
    TreeNode* calculate(vector<int>& preorder, vector<int>& inorder,int preStr,int preEnd,int inStr,int inEnd){
        if(preStr>preEnd){
            return NULL;
        }
        int i;
        for( i=inStr;i<=inEnd;i++){
            if(inorder[i]==preorder[preStr])
                break;
        }
        
        TreeNode* root= new TreeNode(preorder[preStr]);
        root->left=calculate(preorder,inorder,preStr+1,preStr+i-inStr,inStr,i-1);
        root->right=calculate(preorder,inorder,preStr+i-inStr+1,preEnd,i+1,inEnd);
        
        return root;
    }
};
