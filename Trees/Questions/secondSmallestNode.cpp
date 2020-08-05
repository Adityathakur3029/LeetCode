/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 
 
 
 //tree has property that every node has either 2 childs or 0, and value of root is the minimum of its both the childs.
 //used tounament method
 
 
 
 
class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        long result=UINT_MAX;
        
        int smallest=root->val;
        helper(root,smallest,result);
        
        if(result==UINT_MAX || result==smallest)
            return -1;
        return (int)result;
    }
    
    void helper(TreeNode* root, int smallest, long& result){
        if(!root->left && !root->right)
            return;
        if(root->left->val==root->right->val){              //have to check both the sides if value of root,left child and right child is same
            helper(root->left,smallest,result);
            helper(root->right,smallest,result);
        }
        else if(root->left->val==smallest){               //else check either left subtree of right accordingly
            if(root->right->val<result)
                result=root->right->val;
            helper(root->left,smallest,result);
        }
        else{
            if(root->left->val<result)
                result=root->left->val;
            helper(root->right,smallest,result);
        }
    }
};
