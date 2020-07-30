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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int posStr=0;
        int posEnd=postorder.size()-1;
        
        int inStr=0;
        int inEnd=inorder.size()-1;
        
        return calculate(inorder,postorder,posStr,posEnd,inStr,inEnd);
    }
    
    TreeNode* calculate(vector<int>& inorder, vector<int>& postorder,int posStr,int posEnd,int inStr,int inEnd){
        if(posStr>posEnd)
            return nullptr;
        int i;
        for( i=inStr;i<inEnd;i++){
            if(inorder[i]==postorder[posEnd])
                break;
        }
        
        TreeNode* root= new TreeNode(postorder[posEnd]);
        root->left=calculate(inorder,postorder,posStr,posEnd+i-inEnd-1,inStr,i-1);
        root->right=calculate(inorder,postorder,posStr+i-inStr,posEnd-1,i+1,inEnd);
        return root;
    }
};
