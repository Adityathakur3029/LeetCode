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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        vector<int> res;
        while(1){
            while(root){
                s.push(root);
                root=root->left;
            }
            
            if(s.empty())
                break;
            
            root=s.top();
            res.push_back(root->val);
            if(res.size()==k)
                return res[res.size()-1];
            s.pop();
            
            root=root->right;
            
        }
        return -1;
    }
};


//morris inorder

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* curr=root;
        int count=0;
        int res=-1;
        while(curr){
            if(curr->left){
                TreeNode* prev=curr->left;
                while(prev->right && prev->right!=curr)
                    prev=prev->right;
                
                if(!prev->right){
                    prev->right=curr;
                    curr=curr->left;
                }
                else{
                    prev->right=nullptr;
                    count++;
                    if(count==k)
                        res=curr->val;
                    curr=curr->right;
                }
            }
            else{
                count++;
                if(count==k)
                    res=curr->val;
                curr=curr->right;
            }
        }
        return res;
    }
};
