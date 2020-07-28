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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> res;
        while(1){
            while(root){
                res.push_back(root->val);
                s.push(root);
                root=root->left;
            }
            
            if(s.empty())
                break;
            
            root=s.top();
            s.pop();
            root=root->right;
        }
        return res;
    }
};



//Morris
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* curr=root;
        
        while(curr){
           if(curr->left){                  //if left exist else move to right of root
                TreeNode* prev= curr->left;     //now find rightmost for prev
                while(prev->right && prev->right != curr){
                    prev=prev->right;
                }
                
                if(!prev->right){                          //join the rightmost to thr root and push the root value
                    result.push_back(curr->val);                  
                    prev->right=curr;
                    curr=curr->left;
                }
                else{                                      //revert the changes made
                    prev->right=nullptr;                    
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
