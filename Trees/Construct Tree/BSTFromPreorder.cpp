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

//n^2

//n
class Solution {
public:
    TreeNode* helper(vector<int>&preorder,int& index, int maximum){
        if(index>=preorder.size()||preorder[index]>maximum)
            return nullptr;
        int value=preorder[index];
        TreeNode* root= new TreeNode(value);
        
        index++;
        root->left=helper(preorder,index,value);
        root->right=helper(preorder,index,maximum);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index=0;
        return helper(preorder,index,INT_MAX);
        
    }
};
