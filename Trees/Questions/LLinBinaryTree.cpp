/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    bool isSubPath(ListNode* head, TreeNode* root) {
        vector<TreeNode*> allHeads;
        findHead(head,root,allHeads);
        bool flag=false;
        
        for(auto curr : allHeads){
            ListNode* temp=head;
            temp=temp->next;
            if(temp){
                flag=checkPath(curr->left,temp) || checkPath(curr->right,temp);
            }   
            if(!temp || flag)
                return true;  
        }
        return false;
    }
    
    bool checkPath(TreeNode* root, ListNode* head){
        if(!head){
            return true;
        }
        if(!root)
            return false;
        if(root->val!=head->val){
            return false;
        }
        
        return checkPath(root->left,head->next) || checkPath(root->right,head->next);
       
        
    }
    
    
    
    void findHead(ListNode* head, TreeNode* root, vector<TreeNode*>& allHeads){
        if(!root);
        if(root->left) findHead(head,root->left,allHeads);
        if(root->val==head->val)
            allHeads.push_back(root);
        if(root->right) findHead(head,root->right,allHeads);
    }
};
