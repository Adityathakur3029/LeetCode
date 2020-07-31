class Solution {
public:
    TreeNode* tree(vector<int>& preorder, int i, int j) {
        if(i > j) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[i]);
        if(i == j) {
            return root;
        }
        int k = i+1;
        while(k <= j) {
            if(preorder[k] > preorder[i]) {
                break;
            }
            k++;
        }
        root->left  = tree(preorder,i+1,k-1);
        root->right = tree(preorder,k,j);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size() == 0) {
            return NULL;
        }
        return tree(preorder, 0, preorder.size()-1);
    }
};
