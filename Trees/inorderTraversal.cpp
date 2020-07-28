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
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)
            return {};
        vector<int> res;
        helper(root,res);
        return res;
    }
    
    void helper(TreeNode* root, vector<int>& res){
        if(root->left)
            helper(root->left,res);
        res.push_back(root->val);
        if(root->right)
            helper(root->right,res);
    }
};


//Iterative
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        
        while(1){
            while(root){
                s.push(root);
                root=root->left;
            }
            if(s.empty())
                break;
            
            root=s.top();
            s.pop();
            res.push_back(root->val);
            root=root->right;
        }
        return res;
    }
};


//Morris
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        //in inorder left must come before root so we have to join root to righmost of left
        TreeNode* curr= root;          //node to join
        
        while(curr){
            if(curr->left){                         //if left exist else move to right of root
                TreeNode* prev= curr->left;         //now find rightmost for prev
                while(prev->right && prev->right != curr){
                    prev=prev->right;
                }
                
                if(!prev->right){                   //join this rightmost to thr root and cheeck on left sub tree of root
                    prev->right=curr;
                    curr=curr->left;
                }
                else{                               //means left side is covered so push the root in result and check on its right
                    prev->right=nullptr;
                    result.push_back(curr->val);
                    curr=curr->right;
                }
            }
            
            else{
                result.push_back(curr->val);
                curr=curr->right;
            }
        }
        
        return result;
    }
};
