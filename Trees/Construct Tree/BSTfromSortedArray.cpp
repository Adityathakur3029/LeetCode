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
    TreeNode* arrayToBST(vector<int>& v,int start, int end){
        if (end<start)
            return NULL;
       
        int mid=(start+end)/2;
        TreeNode *root=new TreeNode(v[mid]);
        
        root->left=arrayToBST(v, start, mid-1);
        root->right=arrayToBST(v, mid+1,end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        return arrayToBST(nums,0,n-1);
       
    }
};
