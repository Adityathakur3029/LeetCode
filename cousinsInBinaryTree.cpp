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
    bool isCousins(TreeNode* root, int x, int y) {
        int foundVal;                                 //x or y
        
        queue<TreeNode*> q;
        bool flag=false;                              //turn true when either x or y is found
        
        q.push(root);
        
        
        while(!q.empty()){
            int size=q.size();
            
            while(size--){                              // one level
                TreeNode* curr= q.front();
                q.pop();
                if(curr->left && curr->right){          //check they are not the child of same parent
                    if((curr->left->val==x && curr->right->val==y) || (curr->right->val==x && curr->left->val==y))
                        return false;
                }
                
                
                if(flag){                             //one of the val have found checking for other
                    if((curr->val==x || curr->val==y) && curr->val!=foundVal )
                        return true;
                }
                
                if(!flag){                             //found first val 
                    if(curr->val==x || curr->val==y){  //turn flag on and set foundVal
                        flag=true;
                        foundVal=curr->val;
                    }
                }
                
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            if(flag)                                // one val found but other was missing in same level
                return false;
        }
        
        return false;
    }
};
